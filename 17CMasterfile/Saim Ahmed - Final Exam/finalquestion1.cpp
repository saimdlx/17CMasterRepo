#include <iostream>
#include <cmath>

using namespace std;

struct NumNode{
    string nm;
    NumNode* next;
};

int charToInt(char );
int hashFunc(const string, int);
int insert(NumNode* tbl[], int size, const string &s);



int main(){
    int bucket = 512;
    NumNode* table[bucket];


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