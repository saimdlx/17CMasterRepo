#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

float h(float);
float g(float);

stack<float> ssin;
stack<float> scos;

int main(){
    
    cout << "Angle" << "\t" << "Sin Calls" << "\t" << "Cos Calls" << endl;
    for (float i = -1.0 ; i <= 1.0 ; i+=0.1){

        while(!ssin.empty() && !scos.empty()){
            ssin.pop();
            scos.pop();
        }

        float hCall = h(i);
        float gCall = g(i);

        int hSize = (int)ssin.size();
        int gSize = (int)scos.size();

        cout << i << ": " << hSize << ", " << gSize << endl;
    }

    return 0;
}


float h(float angR){

    float tol = 1e-6;
    ssin.push(angR);
    if (angR > -tol && angR < tol){
        return angR + angR * angR * angR/6;
    }

    return 2*h(angR/2)*g(angR/2);
}

float g(float angR){

    float tol = 1e-6;
    scos.push(angR);
    if (angR > -tol && angR < tol){
        return 1+angR*angR/2;
    }
    float b = h(angR/2);
    return 1+2*b*b;
}