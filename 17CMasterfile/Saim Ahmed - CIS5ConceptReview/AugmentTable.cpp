/* 
 * File:   main.cpp
 * Author: Saim Ahmed
 * Created on 3/16/25 at 5:30PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int readArr[][COLMAX], int &rows, int &cols) {

    cout << "Input a table and output the Augment row,col and total sums." << endl;
    cout << "First input the number of rows and cols. <20 for each" << endl;
    cin >> rows >> cols;

    cout << "Now input the table." << endl;
    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            cin >> readArr[i][j];
        }
    }
}


void sum(const int sumArr[][COLMAX], int rows, int cols, int augAry[][COLMAX]) {

    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < cols ; j++) {
            augAry[i][j] = sumArr[i][j];
        }
    }

    for (int j = 0 ; j < cols ; j++) { //store sum of columns in augArr
        int colSums = 0;
        for (int i = 0 ; i < rows ; i++) {
            colSums += sumArr[i][j];
        }
        augAry[rows][j] = colSums;
    }

    for (int i = 0 ; i < rows ; i++) {  //store sum of rows in augArr
        int rowSums = 0;
        for (int j = 0 ; j < cols ; j++) {
            rowSums += sumArr[i][j];
        }
        augAry[i][cols] = rowSums;
    }

    int total = 0;
    for (int i = 0; i < rows ; i++) {
            total += augAry[i][cols];

    }
    augAry[rows][cols] = total;
}

void print(const int printArr[][COLMAX], int rows, int cols, int n) {
    
    for (int i = 0 ; i < rows ; i++) {

        for (int j = 0 ; j < cols ; j++) {

            cout << setw(n) << printArr[i][j];
        }
        cout << endl;
    }
}

