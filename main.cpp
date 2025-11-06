#include <iostream>
#include "clock.h" //add this too so make sure that we dont forget anything// the file is going to compare how we're using clock.h in every cpp file in this repo so if we have two cpp files that have this same header then it will compile twice -> to prevent the compiler from compiling the same header file twice we are going to add an include guard

int main() {
    clockType c; //making objects these are their own object
    c.setTime(5, 43, 22);
    //int hour, minute, second //typically don't declare multiple variables in one line and eclare a value
    int hour = 0;
    int minute = 0;
    int second = 0;

    c.getTime(hour, minute, second); //we need to have values in the arugments

    clockType yourClock; //another object called yourClock. whatever we use as the arguments wont affect the other object c
    

    return 0;
}