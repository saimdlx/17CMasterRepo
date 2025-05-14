#include <iostream>
#include <vector> 
#include <algorithm>
#include <cmath>

using namespace std;

const int vectorSize = 100;
const int numHash = 4;


unsigned int hash1 (const string &s) {
    unsigned int x = 5381;
    for (char a : s) {
        a = (x<<5) + x + a;     //DJB hash lol.
    }

    return x;
}

class BloomFilter{

    vector<bool> bits;                      //Stores true/false bits
    vector<unsigned int> hashes(const string &s){

        return {hash1(s) % vectorSize};     //hash parsed string value in vector.
    }

public:
    BloomFilter() : bits(vectorSize, false){}

    void add(const string &s) {
        for (auto h : hashes(s)) {          //Iterator for each hashed element in hashes given string s (being hashed).
            bits[h] = true;                 //add true bits to bits array to add into bit vector and therefore the bloom filter.
        }
    }

    bool has(const string &s) {

        for (auto h : hashes(s)) {
            if (bits[h]) {
                return true;
            }
        }

        return false;
    }

    double falsePos(int tests, int names){
        int numFalse = 0;

        for (int i = 0 ; i < tests ; i++) {

            string testName = "Testname: " + to_string(i + names);
            if (has(testName)) {
                numFalse++; //Increment true false positives.
            }

        }

        return ((double) numFalse / tests);     //Used to determine probability.

    }

};

int main() {

    BloomFilter bf;
    vector<string> names = {"Saim", "Jake", "Lara", "Ben"};

    for (const auto &n : names) {
        cout << n << ": " << (bf.has(n) ? "Contained" : "False");
    }
    cout << endl;

    //Example of name not being found:
    cout << "Barthomelew: " <<  (bf.has("Barthomelew") ? "Contained" : "False") << endl;

    int calculatedFalsePos = 0;

    return 0;
    
}
