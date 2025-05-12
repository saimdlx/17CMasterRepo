/* 
 * File:   main.cpp
 * Author: Saim Ahmed
 * Created on 3/16/25 at 5:30PM
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char arRead[]) {
    cin >> arRead;
    int arrLen = strlen(arRead);
    return arrLen;
}

void sort(char arSort[], int srtSize) {

    //Initially wanted to use bubble sort, but selection sort is faster.

    for (int i = 0 ; i < srtSize - 1; i++) {
        int minidx = i;
        for (int j = i + 1 ; j < srtSize ; j++) {

            if (arSort[j] < arSort[minidx]) {   //If j is less than minidx at pass i, set min index to j.
                minidx = j;
            }

        }
        if (minidx != i) {                      //After each pass, check to see if minidx change, and swap accordingly.
                char temp = arSort[i];
                arSort[i] = arSort[minidx];
                arSort[minidx] = temp;
            }
    }

}

void print(const char prtArr[], int prtSize) {

    for (int i = 0 ; i < prtSize ; i++) {

        cout << prtArr[i];

    }
    cout << "\n";

}