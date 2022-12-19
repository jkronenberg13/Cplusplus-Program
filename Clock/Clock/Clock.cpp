// Joshua Kronenberg
// Date: 12/03/2022
#include<iostream>
#include<string>
#include<iomanip>
#include <ctime>
#include <sstream>
using namespace std;
//global variables
int getHour;
int getMinute;
int getSecond;

void getTime(void) { // get time from local machine
    char fill = ':'; 
    string fullTime;
    fullTime = __TIME__;
    getHour = stoi(fullTime.substr(0, 2)); // split hour
    getMinute = stoi(fullTime.substr(3, 2)); // split minute
    getSecond = stoi(fullTime.substr(6)); // split second
} // ent getTime() function

string twoDigitString(unsigned int n) {
    string str = ""; // string to return
    if (n < 10) { // if number is less than 10
        str += "0"; // add leading 0
    } // end if
    str += to_string(n); // add number to string
    return str; // return string
} // end twoDigitString() function

string nCharString(size_t n, char c) {
    string str = "";
    for (size_t i = 0; i < n; i++) { // for the desired length
        str += c; // add character to string
    } // end for
    return str;
} // end nCharString() function

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string str = ""; // string to return
    str += twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s); // add time to string
    return str; // return string
} // end formatTime24() function

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string str = ""; // string to return
    if (h == 0) { // if hour is 0
        str += "12:"; // add "12:"
    }
    else if (h < 12) { // if hour is less than 12
        str += twoDigitString(h) + ":"; // add hour to the string
    }
    else { // if hour is greater than 12
        str += twoDigitString(h - 12) + ":"; // add hour to the string
    } // end if
    str += twoDigitString(m) + ":"; // add minutes to the string
    str += twoDigitString(s); // add seconds to the string
    if (h < 12) { // if hour is less than 12
        str += " A M"; // add " A M"
    }
    else { // if hour is greater than 12
        str += " P M"; // add " P M"
    } // end if
    return str; // return string
} // end formatTime12() function

void printMenu() { // print menu choice
    cout << nCharString(15, ' ') << nCharString(27, '*')<< endl;
    cout << nCharString(15, ' ') << "*  1-Add One Hour         *" << endl;
    cout << nCharString(15, ' ') << "*  2-Add One Minute       *" << endl;
    cout << nCharString(15, ' ') << "*  3-Add One Second       *" << endl;
    cout << nCharString(15, ' ') << "*  4-Exit Program         *" << endl;
    cout << nCharString(15, ' ') << nCharString(27, '*') << endl;
} // end printMenu() function

unsigned int getMenuChoice(unsigned int maxChoice) { // get user's choice
    unsigned int choice = 0; // choice to return
    while (choice < 1 || choice > maxChoice) { // while choice is not between 1 and maxChoice, inclusive
        cout << "Enter your choice: "; // prompt user for choice
        cin >> choice; // get choice
    } // end while
    return choice; // return choice
} // end getMenuChoice() function

void addOneHour() {
    if (getHour < 23) { // if hours is less than 23
        getHour = getHour + 1; // add 1 to hours
    }
    else { // if hours is over 23
        getHour = 0; // set hours to 0
    } // end if
} // end addOneHour() function

void addOneMinute() {
    if (getMinute < 59) { // if minutes is less than 59
        getMinute = getMinute + 1; // add 1 to minutes
    }
    else { // if minutes is 59
        getMinute = 0; // set minutes to 0
        getHour = getHour + 1; // add one hour
    } // end if
} // end addOneMinute() function

void addOneSecond() {
    if (getSecond < 59) { // if seconds is less than 59
        getSecond = getSecond + 1; // add 1 to seconds
    }
    else { // if seconds is 59
        getSecond = 0; // set seconds to 0
        getMinute = getMinute + 1; // add one minute
    } // end if
} // end addOneSecond() function

void displayClocks(unsigned int h, unsigned int m, unsigned int s) { // create the display of the 12 and 24 clocks
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
} // end displayClocks() function

void mainMenu() {  // the menu of options for the program
    printMenu();
    unsigned int choice = 0; // choice to return
    while (choice != 4) { // while choice is not 4
        choice = getMenuChoice(4); // get choice
        switch (choice) { // switch on choice
        case 1: // if choice is 1
            addOneHour(); // add one hour
            break; // break out of switch
        case 2: // if choice is 2
            addOneMinute(); // add one minute
            break; // break out of switch
        case 3: // if choice is 3
            addOneSecond(); // add one second
            break; // break out of switch
        case 4: // if choice is 4
            break; // break out of switch
        } // end switch
    system("CLS"); // clear screan
    displayClocks(getHour, getMinute, getSecond); // display clocks
    printMenu(); // displays the main menu
    } // end while
} // end mainMenu() function


int main() { //main function of the program
    getTime(); // get the time
    displayClocks(getHour, getMinute, getSecond);  // display time the first time
    mainMenu(); // get print main menu and get main menu functions, print clock while in loop
    return 0;
}