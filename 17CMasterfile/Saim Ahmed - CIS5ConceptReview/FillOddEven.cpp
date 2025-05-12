/* 
 * File:   main.cpp
 * Author: Saim Ahmed
 * Created on 3/16/25 at 5:30PM
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &readEvenVec, vector<int> &readOddVec) {

    int n;
    cout << "Enter number of integers to input." << endl;
    cin >> n;

    cout << "Enter numbers." << endl;
    for (int i = 0; i < n ; i++) {

        int num;
        if (num % 2 == 0) {
            readEvenVec.push_back(num); //Modulo operator to check if number is even or odd;
        }
        else {
            readOddVec.push_back(num);
        }
    }
    
}

void copy(vector<int> copyEven, vector<int>copyOdd, int copyArr[][COLMAX]) {

    int evenSize = copyEven.size(); //use this to determine size of iteration (bigger is needed)
    int oddSize = copyOdd.size();

    for (int i = 0 ; i < max(evenSize, oddSize) ; i++) {
        //needs polishing.
        if (i < evenSize) {

            copyArr[i][0] = copyEven[i];
        }
        else {
            copyArr[i][0] = 0;
        }
        if (i < oddSize) {

            copyArr[i][1] = copyOdd[i];
        }
        else {
            copyArr[i][1] = 0;
        }
    }
}

void prntVec(vector<int> printEven, vector<int> printOdd, int n) {

    cout << setw(n) << "Vector" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    int maxItr = max(printEven.size(), printOdd.size()); //need to determine our own iterative number

    for (int i = 0 ; i < maxItr ; i++) {

        cout << setw(n);
        cout << (i < printEven.size() ? to_string(printEven[i]) : "");
        cout << (i < printOdd.size() ? to_string(printOdd[i]) : "");
        cout << endl;

    }
}


void prntAry(const int prtArr[][COLMAX], int sizeEven, int sizeOdd, int n) {

    cout << setw(n) << "Array" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    int maxItr = max(sizeEven, sizeOdd);
    for (int i = 0 ; i < maxItr ; i++) {
        cout << setw(n);
        cout << (i < sizeEven ? to_string(prtArr[i][0]) : "");
        cout << (i < sizeOdd ? to_string(prtArr[i][1]) : "");
        cout << endl;
    }
}