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