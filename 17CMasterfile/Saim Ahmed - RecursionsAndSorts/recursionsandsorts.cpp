#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <chrono>

using namespace std;

void quickSort(vector<int>&, int, int);
int partition(vector<int>&, int, int);
void mergeSort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);
void heapSort(vector<int>&);
void heapify(vector<int>&, int, int);
void shellSort(vector<int>&);
vector<int> genArr(int);


int main(){

    vector<int> sizes = {1000, 2000, 5000, 10000, 20000};
    cout << "Size\tQuickSort\tMergeSort\tHeapSort\tShellSort" << endl;

    
    for (int a : sizes) {
        vector<int> data = genArr(a);

        vector<int> qS = data;
        auto start = chrono::high_resolution_clock::now();
        quickSort(qS, 0, a - 1);
        auto end = chrono::high_resolution_clock::now();
        double qT = chrono::duration<double>(end-start).count();

        vector<int> mD = data;
        start = chrono::high_resolution_clock::now();
        mergeSort(mD, 0, a - 1);
        end = chrono::high_resolution_clock::now();
        double mT = chrono::duration<double>(end - start).count();

        vector<int> hD = data;
        start = chrono::high_resolution_clock::now();
        heapSort(hD);
        end = chrono::high_resolution_clock::now();
        double hT = chrono::duration<double>(end - start).count();

        vector<int> sD = data;
        start = chrono::high_resolution_clock::now();
        shellSort(sD);
        end = chrono::high_resolution_clock::now();
        double sT = chrono::duration<double>(end - start).count();

    
    cout << a << "\t" << qT << "\t" << mT << "\t" << hT << "\t" << sT << endl;
    }
    return 0;
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high ; j++){

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi+1, high);
    }
}

void merge(vector<int>& arr, int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0 ; i < n1 ; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0 ; i < n2 ; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = L[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {

    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);

}

void heapify (vector<int>& arr, int n, int i){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = n;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

}

void heapSort(vector<int>& arr) {

    int n = arr.size();
    for (int i = n/2 - 1 ; i >= 0 ; i--){
        heapify(arr, n, i);
    }
    for (int i = n - 1 ; i > 0 ; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

vector<int> genArr(int n) {
    vector<int> arr(n);
    for (int i = 0 ; i < n ; i++){
        arr[n] = rand() % 10000; 
    }
    return arr;
}

