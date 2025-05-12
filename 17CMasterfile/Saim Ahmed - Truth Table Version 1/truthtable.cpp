/* 
 * File:   main.cpp
 * Author: Saim Ahmed
 * Created on: 3/7/25
 * Purpose:  To tell the Truth
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    

    while (cin >> x >> y) {
        cout<<(x?'T':'F')<<     " "
        <<(y?'T':'F')<<         "  "
        <<(!x?'T':'F')<<        "  "
        <<(!y?'T':'F')<<        "   "
        <<(x&&y?'T':'F')<<      "    "
        <<(x||y?'T':'F')<<      "   "
        <<(x^y?'T':'F')<<       "    "
        <<(x^y^x?'T':'F')<<     "     "
        <<(x^y^y?'T':'F')<<     "       "
        <<(!(x&&y)?'T':'F')<<   "      "
        <<(!x||!y?'T':'F')<<    "        "
        <<(!(x||y)?'T':'F')<<   "      "
        <<(!x&&!y?'T':'F')<<    ""
        <<endl;
    }
        
    cout << endl;
    //Exit
    return 0;
}