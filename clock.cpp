#include "clock.h" //taking the info from clock.h so we can use the code
// we use #include <> when we are looking in the system installation
// we use #include " " when we are looking in the current directory

void clockType::setTime(int h, int m, int s, timeType f, partType timeOfDay) { //we use clockType:: because that is the class that we are tying this function to and the (int, int, int) are the three integer parameters that will be used in our function//we try to name our parameters, its good practice
    format = f;
    part = timeOfDay;

    if(!validHour(h)) {
        h = 12;
    }
    
    hr = h;

    if(!validMinOrSec(m)) { //this and the if statement on line 18 are pretty much identical so when we see this we need to see if we can seperate it into its own function
        m = 0;
    }

    min = m;

    if(!validMinOrSec(s)) {
        s = 0;
    }

    sec = s;
}

// void setTime(int, int, int) {

// } this isnt related to the class but can exist together, thats bc this cant change any of the int parameters but when its connected to a class then it can


void clockType::getTime(int &h, int &m, int &s) const { //const outside of the parentheses says that we are unallowed to change clock//with setTime() we dont have a const so we can change the clock, set the hours minutes and seconds. getTime() is const so we cant set those, we can just look at them
    // hr = h; this will be an error because lvalue "hr" cannot be changed since this is a const
    h = hr;
    m = min;
    s = sec;

}

std::string clockType::printTime() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    if (format == TWELVE)
    {
        int index;
        for(int i = 0; i < 2; i++)
        {
            if (part == parts[i])
            {
                index = i;
                break;
            }

        }
        out << " " << partToStr[index];
    }
    
    return out.str();
}

clockType::clockType() { //first ct is for the class and after the colon its for teh constructor
    hr = 0;
    min = 0;
    sec = 0;
}

clockType::clockType(int hour, int minute, int second, timeType f, partType timeOfDay)
{
    setTime(hour, minute, second, f, timeOfDay);
}


 bool clockType::equalTime(const clockType & otherClock) const
 {
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
 }

 bool clockType::validHour(int h)
 {
    if(format == TWELVE)
    {
        return h > 0 && h <= 12;
    }
    else
    {
        return h >= 0 && h < 23;
    }
     return false;
 }

 bool clockType::validMinOrSec(int num) 
 {

     return num >= 0 && num <= 59;
 }
