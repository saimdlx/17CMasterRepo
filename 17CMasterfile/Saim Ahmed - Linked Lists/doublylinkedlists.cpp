/*
    Author: Saim Ahmed
    Date:   April 27th, 2025  1:12pm
    Purpose: Super scuffed doubly linked list design.
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


class DoubleLink {
    
    public:
    int data;            //Some type of data
    DoubleLink *lnkNext; //Next Node in the chain
    DoubleLink *lnkPrev; //Previous node in the chain

    DoubleLink() : data(0), lnkNext(nullptr), lnkPrev(nullptr) {}

    DoubleLink(int val) : data(val), lnkNext(nullptr), lnkPrev(nullptr) {}


    DoubleLink *create(int newVal) {
        return new DoubleLink(newVal);
    }

    void pshFrnt(DoubleLink* nodefront, DoubleLink* newNode) {

        newNode->data = nodefront->data;
        if (nodefront) {
            nodefront->lnkPrev->data = newNode->data;
        }
    }

    void pshBack(DoubleLink* nodeTail , DoubleLink* newNode) {

        newNode->data = nodeTail->data;
        if(nodeTail){
            nodeTail->lnkNext->data = newNode->data;
        }

    }

    DoubleLink *popFrnt(DoubleLink* frontNode) {
        DoubleLink* tempDoubleLink = new DoubleLink;
        tempDoubleLink->data = frontNode->data;
        tempDoubleLink->lnkNext = frontNode->lnkNext;
        tempDoubleLink->lnkPrev = frontNode->lnkPrev;

        delete frontNode;
        return tempDoubleLink;
    }

    DoubleLink *popBack(DoubleLink* backNode) {


        DoubleLink* tempDoubleLink = new DoubleLink;
        tempDoubleLink->data = backNode->data;
        tempDoubleLink->lnkNext = backNode->lnkNext;
        tempDoubleLink->lnkPrev = backNode->lnkPrev;

        delete backNode;
        return tempDoubleLink;

    }
};

DoubleLink *fillLst(int n){
    //Initially create the front pointer/beginning pointer
    DoubleLink *front=new DoubleLink;
    front->data=1;
    front->lnkNext=NULL;
    //If n>1 then fill with the data and Nodes to the next
    DoubleLink *temp=front;
    for(int i=2;i<=n;i++){
        DoubleLink *nxtNode=new DoubleLink;
        nxtNode->data=i;
        temp->lnkNext=nxtNode;
        temp=nxtNode;
    }
    temp->lnkNext=NULL;
    //Return the front of the list
    return front;
}

void prntLst(DoubleLink *next){
    while(next!=NULL){
        cout<<next->data<<endl;
        next=next->lnkNext;
    }
}

void destroy(DoubleLink *front){
    while(front!=NULL){
        DoubleLink *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}

int main(int argc, char** argv) {
    
    DoubleLink *lnk1 = fillLst(5);
    
    prntLst(lnk1);
    
    destroy(lnk1);
    
    return 0;
}