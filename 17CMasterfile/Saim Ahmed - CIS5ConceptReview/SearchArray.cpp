/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    for (int i = 0 ; i < LINE ; i++) {
        match[i] = -1;
    }
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}


int srch1(const char inSent[], const char outPatt[], int arrPos) {
    
    int senLen = strlen(inSent);
    int pattLen = strlen(outPatt);

    for (int i = arrPos; i <= senLen - pattLen; i++) {
        bool flag = true;
        for (int j = 0; j < pattLen ; j++) {
            if (inSent[i+j] != outPatt[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    } 
    return -1; //throw error if EITHER conditionals do not validate
}


void srchAll(const char allSent[], const char allPatt[], int fMatch[]) {

    int curr = 0;
    int i = 0;
    bool flag = true;
    while (flag) {  
        curr = srch1(allSent, allPatt, curr);
        if (curr == -1) {
            break;          //handles the error thrown by srch1
        }

        fMatch[i++] = curr; 
        curr += 1;
    }
}

void print(const char printArr[]) {
    cout << printArr << endl;
}

void print(const int index[]) {
    bool flag = false; // use to determine if match found
    for (int i = 0 ; i < 81 ; i++) {    //81 specifically to adhere to LINE const in main()
        if (index[i] != -1) {
            cout << index[i] << endl;
            flag = true;   
        }
    }
    if (!flag) {
            cout << "None" << endl;
    }
}
