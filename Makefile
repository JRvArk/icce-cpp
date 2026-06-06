CXX      := g++
CXXFLAGS := -std=c++23 -Wall -Wextra

.PHONY: clean

# make X.Y.Z  →  compile all .cpp under part-X/setY/Z/
# e.g. make 1.4.28  →  part-I/set4/28/
#
# Transitively follows cross-directory #include "../../..." paths so that
# exercises that compose earlier classes compile without manual configuration.
%:
	@part=$$(echo $@ | cut -d. -f1); \
	 set=$$(echo $@ | cut -d. -f2); \
	 ex=$$(echo $@ | cut -d. -f3); \
	 case $$part in \
	   1) pdir="part-I" ;; \
	   2) pdir="part-II" ;; \
	   3) pdir="part-III" ;; \
	   *) echo "Unknown part: $$part"; exit 1 ;; \
	 esac; \
	 dir="$$pdir/set$$set/$$ex"; \
	 test -d "$$dir" || { echo "Not found: $$dir"; exit 1; }; \
	 srcs=$$(find "$$dir" -name '*.cpp'); \
	 extra=""; \
	 scanDirs="$$dir"; \
	 changed=1; \
	 while [ $$changed -eq 1 ]; do \
	   changed=0; \
	   for f in $$(find $$scanDirs -name '*.h' 2>/dev/null); do \
	     fdir=$$(dirname "$$f"); \
	     for inc in $$(grep -Eoh '"(\.\./)+[^"]+\.h"' "$$f" 2>/dev/null | tr -d '"'); do \
	       rel=$$(dirname "$$inc"); \
	       absdir=$$(cd "$$fdir/$$rel" 2>/dev/null && pwd); \
	       if [ -n "$$absdir" ]; then \
	         case " $$scanDirs " in \
	           *" $$absdir "*) ;; \
	           *) scanDirs="$$scanDirs $$absdir"; changed=1 ;; \
	         esac; \
	         extra="$$extra $$(find "$$absdir" -maxdepth 1 -name '*.cpp' 2>/dev/null)"; \
	       fi; \
	     done; \
	   done; \
	 done; \
	 all=$$(echo $$srcs $$extra | tr ' ' '\n' | sort -u | tr '\n' ' '); \
	 test -n "$$all" || { echo "No .cpp files for $$dir"; exit 1; }; \
	 $(CXX) $(CXXFLAGS) $$all -o "$$dir/solution" && echo "Built: $$dir/solution"

clean:
	find . -name solution -type f -delete
