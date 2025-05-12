#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int NUMBERS = 36;
int main(int argc, char** argv) {

    //unload both celcius and fahrenheit files with calculation for b from spreadsheet.
    //run for-loop for numbers n and compute for slope using deg_c = m * deg_f + b.;
    //using least squares method -> requires sumX sumY sumXY and sumX^2
    //formula for m = (sumX x sumY - n x sumXY) / (sumX x sumX - n x sumX^2)
    //formula for b = (sumY - m * sumX) / n
    
    double fetchFah[NUMBERS];
    double fetchCel[NUMBERS];

    ifstream readFah("fahrenheit.txt");     //read in both files.
    ifstream readCel("errorcelcius.txt");

    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double m, b = 0;


    for (int i = 0 ; i < NUMBERS ; i++) {
        
        readFah >> fetchFah[i];
        sumX += fetchFah[i];
        readCel >> fetchCel[i];
        sumY += fetchCel[i];
        sumXY = fetchCel[i] * fetchFah[i];  //compute summation for all x times all y.
    }

    cout << "Sum of X: " << sumX << endl;
    cout << "Sum of Y: " << sumY << endl;
    m = (sumX * sumY - NUMBERS * sumXY) / (sumX * sumX - NUMBERS * pow(sumX, 2));
    b = (sumY - m * sumX) / NUMBERS;
    cout << "Slope of line: " << m << endl;
    cout << "Intercept: " << b << endl;
    return 0;
}