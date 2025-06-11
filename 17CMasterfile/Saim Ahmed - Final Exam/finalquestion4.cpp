#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

void mrgSort(int[], int , int);
void selSort(int[], int, int);
void mrgArr(int[], int, int, int);
void randGen(int[], int);


int main(){
    int size = 100000;
    int p = 8;
    int arr[size];
    int arr1[size];

    randGen(arr, size);
    for (int i = 0 ; i < size ; i++){
        arr[i] = arr1[i];
    }

    auto start = high_resolution_clock::now();
    mrgSort(arr, 0, size-1);
    auto end = high_resolution_clock::now();
    double mrgTime = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    selSort(arr1, size, p);
    end = high_resolution_clock::now();
    double selTime = duration<double>(end - start).count();

    cout << "Merge Sort Time: " << mrgTime << "secs" << endl;
    cout << "Selection Sort Time given P = " << p << " - " << selTime << endl;
    return 0;
}

void randGen(int tbl[], int sz){
    srand(time(0));
    for (int i = 0 ; i < sz ; i++){
        tbl[i] = ((short int)rand() % 100);
    }
}

void mrgArr(int arr[], int L, int M, int R) {
    int n1 = M - L + 1;
    int n2 = R - M;
    int *left = new int[n1];
    int *right = new int[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = arr[L + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = arr[M + 1 + j];
    }
    int i = 0, j = 0, k = L;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void mrgSort(int arr[], int L, int R) {
    if (L < R) {
        int M = (L + R) / 2;
        mrgSort(arr, L, M);
        mrgSort(arr, M + 1, R);
        mrgArr(arr, L, M, R);
    }
}

void selSort(int arr[], int n, int p) {
    for (int i = 0; i < p; i++) {
        int mx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[mx]) mx = j;
        }
        int tmp = arr[i];
        arr[i] = arr[mx];
        arr[mx] = tmp;
    }
}

