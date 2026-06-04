CXX      := g++
CXXFLAGS := -std=c++23 -Wall -Wextra

.PHONY: clean

# make X.Y.Z  →  compile all .cpp under part-X/setY/Z/
# e.g. make 1.4.28  →  part-I/set4/28/
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
	 test -n "$$srcs" || { echo "No .cpp files in $$dir"; exit 1; }; \
	 $(CXX) $(CXXFLAGS) $$srcs -o "$$dir/solution" && echo "Built: $$dir/solution"

clean:
	find . -name solution -type f -delete
