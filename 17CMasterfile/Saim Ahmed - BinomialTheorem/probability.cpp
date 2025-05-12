#include <iostream>
#include <cmath>
#include <random>
using namespace std;
int main(){

    const int TARGETTAILS = 1;  //how many tails we want
    int numFlips = 4;           //number of total flips per trial
    int trueTail = 0;           //how many trials yield HHHT.
    int const trialRuns = 10000;
    srand(time(nullptr));       //set rand seed.
    
    for (int i = 0 ; i < trialRuns ; i++) {
        int tailcnt = 0;        //reset tailcount for current trial
        for (int j = 0 ; j < numFlips ; j++){

            int randNum = rand() % 2;  //heads = 1, tails = 0
            if (randNum == 0) {
                tailcnt++;
            }

        }

        if (tailcnt == TARGETTAILS) {   //if HHHT, successful trial
            trueTail++;
        }

    }

    double probability = static_cast<double>(trueTail) / trialRuns;
    cout << "Number of trials with 3 heads and 1 tails: " << trueTail << endl;
    cout << "Experimental probability generated: " << probability << endl;






}