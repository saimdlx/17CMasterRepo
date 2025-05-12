#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout << "N " << " M " << " Permutation Replacement " << " Permutation " << " Combination Replacement " << " Combination " << endl;
    for (int n = 2 ; n <= 26 ; n++) {
        for (int m = 0 ; m <= n ; m++) {
            float permOM = tgamma(n+1)/tgamma(n-m+1);
            float combODNM = tgamma(n+1)/tgamma(n-m+1)/tgamma(m+1);
            float permWR = pow(n,m);
            float combWR = tgamma(n+m)/tgamma(n)/tgamma(m+1);
            //As opposed to writing a factorial function, tgamma performs that operation.
            cout << n << " " <<  m << " " << permWR << " " << permOM << " " << combWR << " " << combODNM << endl;
        }
    }

}