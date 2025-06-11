#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;


double randomService(double);


int main(){

    srand((unsigned) time(NULL));
    int baseClerk = 3;
    int actClerk = baseClerk;
    int simMins = 60;
    int maxClerks = 100;
    int maxLine = 0;
    double totalTime = 0;
    int tend = 0;
    queue<double> customers;

    double clerkRate[maxClerks];
    double clerkFree[maxClerks];
 
    clerkRate[0] = 1;
    clerkRate[1] = 0.5;
    clerkRate[2] = 0.75;
    for (int i = 0 ; i < baseClerk ; i++){
        clerkFree[i] = 0.0; //allocate a base number of clerks, in the simulations case, 3
    }

    for (int i = 0 ; i < simMins ; i++){

        int arrive = rand() % 9;
        for (int x = 0 ; x < arrive ; x++){
            customers.push((double) x); //random intervals of customers are pushed onto the queue
        }

        int cNeed = 0;
        int exClerk = 0;
        if (!customers.empty()){
            cNeed = (int)customers.size() / 5;  //assuming the queue isn't empty, the needed clerks is adjusted per 5 customers.
        }
        exClerk = baseClerk + cNeed;

        if (exClerk > actClerk){                //updates activeclerk count, as well as the clerk array
            for (int j = 0 ; j < exClerk ; j++){
                clerkRate[j] = 1.0;
                clerkFree[j] = i;
            } 
            actClerk = exClerk; //"reset" extra clerk counter by updating the amount of active clerks, to be flushed later.
        }
        else if (customers.empty() && actClerk > baseClerk){
            actClerk = baseClerk;
            clerkRate[0] = 1;
            clerkRate[1] = 0.5;
            clerkRate[2] = 0.75;
        }  

        //now to serve and flush the queue of customers
        for (int k = 0 ; k < actClerk ; k++){

            if (!customers.empty() && clerkFree[k] <= i){
                double arrival = customers.front();
                customers.pop();

                double wait = i - arrival;
                totalTime += wait;
                double serve = 1.0/clerkRate[k];
                double stats = randomService(serve);
                clerkFree[k] = k + stats;
                tend++;
            }
        }
        if ((int)customers.size() > maxLine){
            maxLine = (int)customers.size();
        }
    }

    cout << "Results:" << endl;
    cout << "Total served: " << tend << endl;
    cout << "Average Wait: " << (tend > 0 ? totalTime / tend : 0.0) << endl;
    cout << "Maximum customer size: " << maxLine;
    return 0;
}

double randomService(double baseNum){
    double ranFact = 0.5 + ((double) rand() / RAND_MAX);
    return baseNum * ranFact;
}