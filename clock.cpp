#include "clock.h" //taking the info from clock.h so we can use the code
// we use #include <> when we are looking in the system installation
// we use #include " " when we are looking in the current directory

void clockType::setTime(int h, int m, int s) { //we use clockType:: because that is the class that we are tying this function to and the (int, int, int) are the three integer parameters that will be used in our function//we try to name our parameters, its good practice
    if(h < 0 || h > 23) {
        h = 0;
    }
    
    hr = h;

    if(m < 0 || m > 59) { //this and the if statement on line 18 are pretty much identical so when we see this we need to see if we can seperate it into its own function
        m = 0;
    }

    min = m;

    if(s < 0 || s > 59) {
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

clockType::clockType() { //first ct is for the class and after the colon its for teh constructor
    hr = 0;
    min = 0;
    sec = 0;
}

clockType::clockType(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}


 bool clockType::equalTime(const clockType & otherClock) const
 {
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
 }