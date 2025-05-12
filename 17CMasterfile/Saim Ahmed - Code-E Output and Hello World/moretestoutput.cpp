/* 
 * File: testout.cpp
 * Author: Saim Ahmed
 * Date: 3/13/25
 * Purpose: Testing format in C++
 * Version: 0.0.1
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    double n;
    //Initialize or input data here
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    
    for (int i = 0 ; i <= 3 ; i++) {
        cin >> n;
        cout << fixed;
        if (i < 3) {
            cout << setw(9)  <<  setprecision(0) << n;
            cout << setw(10) << setprecision(1) << n;
            cout << setw(10) << setprecision(2) << n << endl;
        }
        else {
            cout << setw(9) << setprecision(0) <<  n;
            cout << setw(10) << setprecision(1) << n;
            cout << setw(10) << setprecision(2) << n;
        }
            
    }
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}