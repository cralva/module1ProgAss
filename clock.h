//#pragma once //this is not recommended bc sometimes it will get flagged
#ifndef CLOCK_H //telling the preprocessor to write this down
#define CLOCK_H //and to do this if its not defined yet

class clockType {
public:
    clockType(); //default constructor
    clockType(int, int = 0, int = 0); 
    void setTime(int h, int m, int s);
    void getTime(int &h, int &m, int &s) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const; //const is everywhere in this function. we can put const in different places and it plays a different role depending on where it is

private:
    int hr;
    int min;
    int sec;
};

#endif //we started the block with #ifndef and are ending it with #endif. and everything in the if block then it will be protected

//basically this is just an if statement that checks to see if the compiler has analyzed this file. if it has then it will skip it, if it has not then it will analyze it