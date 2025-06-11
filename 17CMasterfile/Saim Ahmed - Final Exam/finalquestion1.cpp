#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

struct NumNode{
    string nm;
    NumNode* next;
};

int charToInt(char );
int hashFunc(const string&, int);
string randInit();
void insert(NumNode*[] , int , const string&);
void statistics(NumNode*[] , int );
void reset(NumNode*[], int );

int main(){
    const int bucket = 512;
    NumNode* table[bucket];
    for (int i = 0 ; i < bucket ; i++){
        table[i] = NULL;
    }

    srand(0);
    for (int i = 0 ; i < bucket ; i++){

        string random = randInit();
        insert(table, bucket, random);
    } 

    statistics(table, bucket);
    reset(table, bucket);
    return 0;
}

int charToInt(char c){
    return (c - 'A') / 3 + 2 - (c > 'R');
}

int hashFunc(const string &s, int size){
    int h = 0;
    for (int i = 0; i < (int)s.size(); i++){
        h = h * 10 + charToInt(s[i]);
    }
    return h % size;
}

void insert(NumNode* tbl[], int sz, const string &s){
    NumNode* newNode = new NumNode;
    int next = hashFunc(s, sz);
    newNode->nm = s;
    newNode->next = tbl[next];
    tbl[next] = newNode;
}

string randInit(){
    string init = "";
    for (int i = 0 ; i < 3 ; i++){
        init += (char)('A' + rand() % 26 );
    }
    return init;
}

void statistics(NumNode* tbl[], int size){

    int colnums = 0;
    int empty = 0;
    int total = 0;
    
    for (int i = 0 ; i < size ; i++) {
        int cnt = 0;
        NumNode* curr = tbl[i];
        while(curr){
            cnt++;
            curr = curr->next;
        }
        if (cnt == 0){empty++;}
        if (cnt > colnums){colnums = cnt;}
        total += cnt;
    }

    cout << "Empty NumNode buckets: " << empty << endl;
    cout << "Maximum collisions: " << colnums << endl;
    cout << "Average elements: " << (double)total / size << endl;
}

void reset(NumNode* tbl[], int size){
    for (int i = 0 ; i < size ; i++){
        NumNode* toDel = tbl[i];
        while (toDel){
            NumNode* curr = toDel;
            toDel->next;
            delete curr;
        }
    }
}