//Name: Saim Ahmed
//Date: 3/11/2025
//Purpose: Example for for-loop and formulaic solution for LabA1



#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    //first solution using for-loop:
    int m = 1;                  //index is equal to m
    int C = 25;                 //C is equal to the summation variable
    int n = 10;                 //n is the iterative limit
    int sum = 0;                //sum carries the summation total
    int formCalc = (n - m + 1); //formCalc carries the derived formulas expression

    cout << "The sum of  " << C << " taken " << n << " times using a for-loop is: "; 
    for (m ; m <= n ; m++) {
        sum += C;
    }
    cout << sum << endl;


    cout << "The sum of  " << C << " taken " << n << " times using the derived formula is: "; 
    cout << C * (formCalc) << endl;

     

    return 0;

}