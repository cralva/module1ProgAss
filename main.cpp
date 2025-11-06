#include <iostream>
#include "clock.h" //add this too so make sure that we dont forget anything// the file is going to compare how we're using clock.h in every cpp file in this repo so if we have two cpp files that have this same header then it will compile twice -> to prevent the compiler from compiling the same header file twice we are going to add an include guard

//need to use g++ -std=c++17 -g main.cpp clock.cpp -o main && ./main to run code

int main() {
    int list[10] = {1}; //using {0} means that every value in that list will be 0, if we used {1} then the first value is 1 and the rest are 0's
    int list2[10];
    //list2 = list; this is not allowed



    clockType c; //making objects these are their own object
    c.setTime(5, 43, 22);
    //int hour, minute, second //typically don't declare multiple variables in one line and eclare a value
    int hour = 0; //these cant be const int
    int minute = 0;
    int second = 0;

    c.getTime(hour, minute, second); //we need to have values in the arugments and not integers or rvalues; this is because its by reference
    std::cout << hour << ":" << minute << ":" <<  second <<  std::endl;

    clockType yourClock(20,1,34); //another object called yourClock. whatever we use as the arguments wont affect the other object c
    clockType newClock(12); //this is filling in 12 for hours
    clockType newClock2(12, 34); //this is filling in 12 for hours and 34 for minutes and second will have its default value (0). we cant skip, teh arguments have to be in order
    newClock = newClock2; //this does work. it copies the data members from newclock2 and putting it in for newClock

    return 0;
}