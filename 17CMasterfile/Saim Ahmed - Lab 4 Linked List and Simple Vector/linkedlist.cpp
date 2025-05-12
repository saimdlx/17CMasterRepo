/*
    Author: Saim Ahmed
    Date:   March 29th, 2021  1:12pm
    Purpose:Nodeed from first principles
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


class Link {
    
    public:
    int data;     //Some type of data
    Link *lnkNext; //Next Node in the chain

    Link() : data(0), lnkNext(nullptr) {}

    Link(int val) : data(val), lnkNext(nullptr) {}


    Link *create(int newVal) {
        return new Link(newVal);
    }

    void pshFrnt(Link* nodefront, Link* newNode) {

        nodefront->data = newNode->data;

    }

    void pshBack(Link* nodeTail , Link* newNode) {

        nodeTail->data = newNode->data;

    }

    Link *popFrnt(Link* frontNode) {
        Link* tempLink = new Link;
        tempLink->data = frontNode->data;
        tempLink->lnkNext = frontNode->lnkNext;

        delete frontNode;

        return tempLink;
    }

    Link *popBack(Link* backNode) {


        Link* tempLink = new Link;
        tempLink->data = backNode->data;
        tempLink->lnkNext = backNode->lnkNext;

        delete backNode;

        return tempLink;


    }


};



Link *fillLst(int n){
    //Initially create the front pointer/beginning pointer
    Link *front=new Link;
    front->data=1;
    front->lnkNext=NULL;
    //If n>1 then fill with the data and Nodes to the next
    Link *temp=front;
    for(int i=2;i<=n;i++){
        Link *nxtNode=new Link;
        nxtNode->data=i;
        temp->lnkNext=nxtNode;
        temp=nxtNode;
    }
    temp->lnkNext=NULL;
    //Return the front of the list
    return front;
}

void prntLst(Link *next){
    while(next!=NULL){
        cout<<next->data<<endl;
        next=next->lnkNext;
    }
}

void destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    Link *lnk1 = fillLst(5);
    
    //Printing all the data elements in the Nodeed list
    prntLst(lnk1);
    
    //Delete all the allocated memory
    destroy(lnk1);
    
    //Exit stage right
    return 0;
}

