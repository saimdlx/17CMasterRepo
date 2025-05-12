#include <iostream>
#include <list>
#include <map>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

void testList();
void testMap();
void testDeque();


int main() {

    testList();
    testMap();
    testDeque();

}

void testList() {

    list<char> alpha; //A humble list.

    for (char alp = 'a' ; alp <= 'z' ; alp++) {

        alpha.push_back(alp);


    }

    while (!alpha.empty()){

        cout << alpha.front() << ' ';   //YAY!
        alpha.pop_front();

    }

    cout << endl;

}

void testMap() {

    typedef map<string, float> stringFloatMap;  //Declare a container of our data type map.

    stringFloatMap test;

    test["VAT"] = 0.15;
    test["Pi"] = 3.1415;
    test["An arbitrary number"] = 4989.98;
    test["NULL"] = 0;

    stringFloatMap::iterator pos;
    for (pos = test.begin() ; pos != test.end() ; pos++) {

        cout << "key: " << pos->first << "\n";
        cout << "value" << pos->second << endl;


    }

}

void testDeque() {

    deque<string> test;

    test.assign(3, string("string"));
    test.push_back("last string");
    test.push_front("first string");

    copy(test.begin(), test.end(), ostream_iterator<string>(cout, "\n"));   //print deque in order, hence copy.
    cout << endl;

    test.pop_front();
    test.pop_back();

    for (unsigned int i = 1 ; i < test.size() ; i++) {

        test[i] = "another " + test[i];                                    //reformat elements for whatever reason lmao.

    }

    test.resize(4, "resized string");
    copy(test.begin(), test.end(), ostream_iterator<string>(cout, "\n"));



}