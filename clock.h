//#pragma once //this is not recommended bc sometimes it will get flagged
#ifndef CLOCK_H //telling the preprocessor to write this down
#define CLOCK_H //and to do this if its not defined yet
#include <string>
#include <sstream>
#include <iomanip>

//turning this into a 24 hour clock using enumerations
enum timeType //unscoped enums. the variables are global and can be used anywhere
{
    TWELVE = 12, //bc this is unscoped 'global' then no other enum value can have 'twelve' as a variable name
    TWENTYFOUR = 24
};

enum class partType //because we have 'class' it means its a scoped enum. belongs tightly to partType 
{
    AM = 4,
    //we cant print enumerations. if you try itll just print out the values
    PM = 8
};
const partType parts[2] = {partType::AM, partType::PM};
const std::string partToStr[2] = {"AM", "PM"};
const timeType formats[2] = {TWELVE, TWENTYFOUR};


class clockType {
public:
    clockType(); //default constructor
    clockType(int, int = 0, int = 0, timeType = TWENTYFOUR, partType = partType::PM); //the PM needs partType:: before the pm for it to work since its scoped. it cant be just 'PM'
    void setTime(int h, int m, int s, timeType, partType);
    void getTime(int &h, int &m, int &s) const;
    std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType&) const; //const is everywhere in this function. we can put const in different places and it plays a different role depending on where it is
    bool validHour(int);
    bool validMinOrSec(int);

private:
    int hr;
    int min;
    int sec;
    timeType format; 
    partType part;
};

#endif //we started the block with #ifndef and are ending it with #endif. and everything in the if block then it will be protected

//basically this is just an if statement that checks to see if the compiler has analyzed this file. if it has then it will skip it, if it has not then it will analyze it