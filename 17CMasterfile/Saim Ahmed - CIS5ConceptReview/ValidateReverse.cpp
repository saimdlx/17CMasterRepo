/* 
 * File:   main.cpp
 * Author: Saim Ahmed 
 * Created on 3/16/25 at 5:30PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}


bool inRange(const char in[], unsigned short &n) {

    int length = strlen(in); //iterator
    for (int i = 0 ; i < length ; i++) {

        if (!isdigit(in[i])) {
            return false;
            //instructions show that non-digit input is invalid, cannot be reversed
            //handles "101a1"
        }
    }
        int vin = atoi(in);
        if (vin >= 0 && vin <= 65535) { //if the value given input is legit, 65535 represents highest unsigned point
            n = static_cast<unsigned short>(vin);
            return true;
        }

    return false;

}

bool reverse(unsigned short normIn, signed short &revIn) {

    unsigned short conRev = 0;
    unsigned short vtile = normIn;
    int padding = 0; //determine padding based on number

    while (vtile > 0 ) {
        conRev = conRev * 10 + (vtile % 10);
        vtile = vtile / 10;
        padding++;
    }
    
    //need to add edge case for testcase with not enough numerical padding
    while (padding < 5) {
        conRev *= 10;   //for something like 111, the issue should now yield 10101
        padding++;
        
    }

    if (conRev <= 32767) {  //max value of an integer, meaning if true, proceed with conversion
        
        revIn = static_cast<signed short>(conRev); //convert
        return true;
    }

    return false; //default
}

short subtrct(signed short num, int sub) {

    if (num - sub >= 0) {
        return num - sub;
    }

    return num;

}