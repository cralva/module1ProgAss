#include <iostream>
#include <cstdlib> //using rand func here
#include "clock.h" //add this too so make sure that we dont forget anything// the file is going to compare how we're using clock.h in every cpp file in this repo so if we have two cpp files that have this same header then it will compile twice -> to prevent the compiler from compiling the same header file twice we are going to add an include guard

//need to use g++ -std=c++17 -g main.cpp clock.cpp -o main && ./main to run code


clockType createClock();


int main() {
    int list[10] = {1}; //using {0} means that every value in that list will be 0, if we used {1} then the first value is 1 and the rest are 0's
    int list2[10];
    //list2 = list; this is not allowed


    //we sandwich line 18 and 19 in curly bracelets and now its a scope
    clockType c; //making objects these are their own object
    c.setTime(5, 43, 22, TWELVE, partType::AM);
    
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
    for (int i = 0; i < 100; i++)
    {
        clockType a = createClock();
        std::cout << a.printTime() << std::endl;
    }
    // std::cout << a.printTime() << std::endl; this wont be work because 'a' is locked into the curly braces of our for loop line 34

    return 0;
}

clockType createClock()
{
    static int noClocks = 0; //will not lose its value since its 'static'. if it wasnt for 'static' then each time this func was called it would go back to 0 but bc its static then the program will remember the last iteration (hence counting 1-100 clocks) 
    int hour;
    int minute;
    int second;
    int format;
    format = rand() % 2;
    partType tod = partType::PM;
    if(!format)
    {
        hour = (rand() % 12) + 1; 
        int time = rand() % 2;
        tod = parts[time];



    }
    else {
        hour = rand() % 24;   
    }

    minute = rand() % 60;
    second = rand() % 60;

   
    clockType newClock(hour, minute, second, formats[format], tod);
    noClocks++;
    std::cout << noClocks << " clocks created in the program." << std::endl;



    return newClock;
}
