/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 16, 2020, 7:50 PM
 * Purpose:  To Test and Modify the Simple Vector
 */

//System Libraries
#include <iostream>
using namespace std;

/*
* File:   SimpleVector.h
 * Author: rcc
 * Created on September 16, 2020, 8:10 PM
 */

// SimpleVector class template

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class Link {
    public:
        T data;
        Link *lnkNext;
        Link(T val) : data(val), lnkNext(NULL) {}
    };
    

    template <class T>
    class SimpleVector {
    private:
        Link<T> *head;
        Link<T> *tail;
        int nSize;
        int maxCap;
    
        void resize(int newCap) {maxCap = newCap;}
    
    public:
        SimpleVector(int s) : nSize(0), maxCap(s) {
            head = NULL;
            tail = NULL;
        }
    
        ~SimpleVector() {
            Link<T> *temp;
            while (head != NULL) {
                temp = head;
                head = head->lnkNext;
                delete temp;
            }
        }
    
        int size() const {
            return nSize;
        }
    
        void push_tail(T val) {
            if (nSize == maxCap) {
                resize(maxCap * 2);
            }
    
            Link<T> *newLnk = new Link<T>(val);
            if (head == NULL) {
                head = tail = newLnk;
            } else {
                tail->lnkNext = newLnk;
                tail = newLnk;
            }
            nSize++;
        }
    
        void pop_tail() {
            if (nSize > 0) {
                if (nSize == 1) {
                    delete head;
                    head = tail = NULL;
                } else {
                    Link<T> *temp = head;
                    while (temp->lnkNext != tail) {
                        temp = temp->lnkNext;
                    }
                    delete tail;
                    tail = temp;
                    tail->lnkNext = NULL;
                }
                nSize--;
    
                if (nSize <= maxCap / 4 && maxCap > 1) {
                    resize(maxCap / 2);
                }
            }
        }
    
        T& operator[](int index) {
            if (index >= 0 && index < nSize) {
                Link<T> *temp = head;
                for (int i = 0; i < index; i++) {
                    temp = temp->lnkNext;
                }
                return temp->data;
            } else {
                throw invalid_argument("Invalid input");
            }
        }
    };
    
void prntVec(SimpleVector<char> &sv,int perLine);
void fillVec(SimpleVector<char> &sv);

int main(int argc, char** argv) {
    //Declare Variables
    int size=100;
    SimpleVector<char> sv(size);
    
    //Fill the Vector
    fillVec(sv);
    
    //Print the Vector
    prntVec(sv,10);
    
    //Copy the Vector
    SimpleVector<char> copysv(sv);
    
    //Print the Vector
    prntVec(copysv,10);

    return 0;
}

void prntVec(SimpleVector<char> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<char> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=rand()%26+65;
    }
}