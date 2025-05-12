#include <iostream>
#include <cmath>
#include <random>
using namespace std;
int main(){

    const int TARGETTAILS = 1;
    int numFlips = 4;
    int trueTail = 0;
    int const trialRuns = 10000;
    double headsBias = 0.6;         //same as last time, with an added probability bias
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> distribute(0.0, 1.0);   //instead of srand, we use real distribution to generate double point values
    
    for (int i = 0 ; i < trialRuns ; i++) {
        int tailcnt = 0;
        for (int j = 0 ; j < numFlips ; j++){

            double randNum = distribute(gen);
            if (randNum > headsBias) {                  //if the real distribution number is greater than 0.6, the flip yields tails.
                tailcnt++;
            }

        }

        if (tailcnt == TARGETTAILS) {
            trueTail++;
        }

    }

    double probability = static_cast<double>(trueTail) / trialRuns;
    cout << "Number of trials with 3 heads and 1 tails: " << trueTail << endl;
    cout << "Experimental probability generated: " << probability << endl;






}