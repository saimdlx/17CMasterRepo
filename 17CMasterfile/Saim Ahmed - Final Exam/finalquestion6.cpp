#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std; 
const int N = 7;
const int E = 13;

struct graphE{
    int x,y,z;
};

//Vertex: 0 SFO 1 BOS 2 ORD 3 JFK 4 DFW 5 MIA 6 LAX
graphE edges[E] = {
    {0, 1, 2703}, {0, 2, 1847}, {2, 1, 868}, {2, 3, 743}, {3, 1, 189}, {0, 4, 1465}, {4, 2, 803}, {4, 5, 1124}, {5, 3, 1093}, {5, 1, 1257}, {0, 6, 338}, {6, 4, 1234}, {6, 5, 2341}
};

int adj[N][N];
int distArr[N];
bool isVisit[N];

int parent[N];
int rnk[N];

void makeSet(){
    for (int i = 0 ; i < N ; i++){
        parent[i] = i;
        rnk[i] = 0;
    }
}

int find(int x){
    if (parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void uni(int x, int y){

    x = find(x);
    y = find(y);
    
    if (x != y){
        if(rnk[x] > rnk[y]) {
            parent[y] = x;
        }
        else if(rnk[y] > rnk[x]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rnk[x]++;
        }
    }
}

void buildList(){

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < N ; j++){
            if (i == j){
                adj[i][j] = 0;
            }
            else{
                adj[i][j] = 9999999;
            }
        }
    }

    for (int i = 0 ; i < E ; i++){
        int x = edges[i].x;
        int y = edges[i].y;
        int z = edges[i].z;
        adj[x][y] = z;
        adj[y][x] = z;
    }
}

//Dijkstras implementation
void dijkstra(int start) {
    for (int i=0; i<N; i++){
        distArr[i]=9999999;
        isVisit[i]=false;
    }
    distArr[start]=0;
    for (int count=0; count<N-1; count++) {
        int mn=9999999;
        int x=-1;
        for (int i=0; i<N; i++){
            if(!isVisit[i] && distArr[i]<mn) {
                mn=distArr[i];
                x=i;
            }
        }
        if(x==-1) break;
        isVisit[x]=true;

        for (int y=0; y<N; y++){
            if(!isVisit[y] && adj[x][y]<9999999) {
                int nd=distArr[x]+adj[x][y];
                if(nd<distArr[y]) distArr[y]=nd;
            }
        }
    }
}

void kruskal() {
    // Bubble sort edges by weight for minimum spanning tree.
    for (int i=0; i<E-1; i++) {
        for (int j=0; j<E-1-i; j++) {
            if (edges[j].z > edges[j+1].z) {
                graphE tmp=edges[j]; edges[j]=edges[j+1]; edges[j+1]=tmp;
            }
        }
    }
    //Vertex: 0 SFO 1 BOS 2 ORD 3 JFK 4 DFW 5 MIA 6 LAX
    makeSet();
    int totalW=0;
    const char* nm[]={"SFO","BOS","ORD","JFK","DFW","MIA","LAX"};

    cout<<"MST edges:\n";
    for (int i=0; i<E; i++) {
        int x=edges[i].x,y=edges[i].y;
        if (find(x)!=find(y)) {
            uni(x,y);
            totalW+=edges[i].z;
            cout<<nm[x]<<" - "<<nm[y]<<" : "<<edges[i].z<<" miles\n";
        }
    }
    cout<<"Total MST Weight: "<<totalW<<" miles\n";
}

int main() {
    // Map city names to indices
    // Vertex: 0 SFO 1 BOS 2 ORD 3 JFK 4 DFW 5 MIA 6 LAX
    unordered_map<string,int> cityIdx;
    cityIdx["SFO"]=0;cityIdx["BOS"]=1;cityIdx["ORD"]=2;cityIdx["JFK"]=3;
    cityIdx["DFW"]=4;cityIdx["MIA"]=5;cityIdx["LAX"]=6;

    buildList();

    // Part A: shortest distance ORD-LAX
    dijkstra(cityIdx["ORD"]);
    cout<<"Shortest dist ORD-LAX: "<<distArr[cityIdx["LAX"]]<<" miles\n";

    // Part B: shortest distance JFK-SFO
    dijkstra(cityIdx["JFK"]);
    cout<<"Shortest dist JFK-SFO: "<<distArr[cityIdx["SFO"]]<<" miles\n";

    // Part C: Minimum Spanning Tree
    kruskal();

    return 0;
}