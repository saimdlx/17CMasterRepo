/* 
 * File:   main.cpp
 * Author: Saim Ahmed
 * Created on 3/16/25 at 5:30PM
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}
void read(int readArr[], int sizeArr) {

    for (int i = 0 ; i < sizeArr ; i++) {
        cin >> readArr[i];
    }
}

int stat(const int statRay[], int statSize, int& max, int& min) {

    int sum = 0;
    max = statRay[0]; //find index in loop
    min = statRay[0]; //find index in loop

    for (int i = 0 ; i < statSize ; i++) {
        sum += statRay[i];
        if (statRay[i] > max) {
            max = statRay[i];
        }
        
        if (statRay[i] < min) {
            min = statRay[i];
        }
    }
    return sum;
}

void print(const int printArr[], int prtSize, int prtSum, int prtMax, int prtMin) {


    for (int i = 0 ; i < prtSize ; i++) {
        cout << "a[" << i << "] = " << printArr[i] << endl;
    }
    
    cout << "Min  = " << prtMin << endl;
    cout << "Max  = " << prtMax << endl;
    cout << "Sum  = " << prtSum << endl;
    
}