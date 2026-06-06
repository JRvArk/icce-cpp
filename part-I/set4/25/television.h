#ifndef TELEVSION_H_
#define TELEVSION_H_

class Television
{
public:
    Television();
    void turnOn();
    void turnOff();
    void setChannel(int newChannel);
    int getChannel() const;

private:
    bool isOn;
    int channel;
};

#endif