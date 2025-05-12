/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}


int read (char readArray[][COLMAX], int &row) {

    int col = 0;
    for (int i = 0 ; i < row ; i++) {

        cin >> readArray[i];
        col = strlen(readArray[i]);
    }

    return col;

}

int strcmp(char ca[], char cb[], const char replace[], const char with[]) {

    int widx = 0;
    while (ca[widx] != '\0' && cb[widx] != '\0') {

        char a = ca[widx];
        char b = cb[widx];

        for (int i = 0 ; replace[i] != '\0' ; i++){

            if (a == replace[i]) {
                a = with[i];
                break;
            }
        }

        for (int i = 0 ; i < replace[i] != '\0'; i++) {
            if (b == replace[i]) {
                b = with[i];
                break;
            }

        }
        if (a != b) {
            return a - b; //handle failure;
        }
        widx++;
    }
    return ca[widx] - cb[widx];
}


void print(const char arr[][COLMAX], int rows, int cols) {
    for (int i = 0 ; i < rows ; i++) {
        cout << arr[i] << endl;
    }
}

void sort(char sortArr[][COLMAX], int rows, int cols, const char rep[], const char with[]) {

    for (int i = 0 ; i < rows - 1; i++) {
        for (int j = i + 1 ; j < rows; j++) {
            if (strcmp(sortArr[i], sortArr[j], rep, with) > 0) {
                char temp[COLMAX];
                strcpy(temp, sortArr[i]);
                strcpy(sortArr[i], sortArr[j]);
                strcpy(sortArr[j], temp);
            }
        } 
    }
}