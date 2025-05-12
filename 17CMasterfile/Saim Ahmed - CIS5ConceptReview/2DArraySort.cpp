/* 
 * File:   main.cpp
 * Author: Saim Ahmed
 * Created on 3/16/25 at 5:30PM
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char readArr[][COLMAX], int &rows) {
    //Can't gage what error with 3rd testcase might be, but chances are the way data is read is flawed?
    cin.ignore(); //clears input buffer to ensure all input is exhausted
    int detCol = 0;
    
    for (int i = 0 ; i < rows ; i++) {

        cin.getline(readArr[i], COLMAX); //exhaust all characters in each row;
        int foundLen = strlen(readArr[i]);

        if (foundLen > detCol) {
            detCol = foundLen;  //ensures the LARGEST found column is kept.
        }

    }
    return detCol; //return number of columns found
}

void sort(char sortArr[][COLMAX], int rows, int cols) {

    for (int i = 0 ; i < rows - 1 ; i++) {      //sorting by rows with i and j.
        for (int j = i + 1 ; j < rows ; j++) {
            //utilize strcmp to swap info
            if ( strcmp(sortArr[i], sortArr[j]) > 0  ) { //strcmp will return greater than zero when the first string is greater

                //perform swap with strcpy
                char temp[COLMAX];
                strcpy(temp, sortArr[i]);
                strcpy(sortArr[i], sortArr[j]);
                strcpy(sortArr[j], temp);

            } 
        }
    }
}

void print(const char printArr[][COLMAX], int rows, int cols) {

    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            if (!(printArr[i][j])) {        //ensures input is validated
                break;
            }
            else {
                cout << printArr[i][j];
            }
        }
        cout << endl;
    }
}