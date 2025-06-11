#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

struct NumNode{
    string nm;
    NumNode* next;
};

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

struct Node{
    string val;
    struct Node* right;
    struct Node* left;
};

class AVLTree{
    public:
        Node *root;                   //Root node
        int height(Node *);           //Tree height
        int diff(Node *);             //Difference of right/left subtrees
        Node *rr_rotation(Node *); //Right-Right rotation
        Node *ll_rotation(Node *); //Left-Left   rotation
        Node *lr_rotation(Node *); //Left-Right  rotation
        Node *rl_rotation(Node *); //Right-Left  rotation
        Node* balance(Node *);     //Balance subtrees with diff > 1
        Node* insertAVL(Node *, const string& );//Insert and balance the tree
        void clean(Node*);
        AVLTree(){root = NULL;}          //Constructor
};

int AVLTree::height(Node *temp){
    int h = 0;
    if (temp != NULL){
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
int AVLTree::diff(Node *temp){
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
Node *AVLTree::rr_rotation(Node *parent){
    Node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

Node *AVLTree::ll_rotation(Node *parent){
    Node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
Node *AVLTree::lr_rotation(Node *parent){
    Node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
Node *AVLTree::rl_rotation(Node *parent){
    Node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
Node *AVLTree::balance(Node *temp){
    int bal_factor = diff (temp);
    if (bal_factor > 1){
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }else if (bal_factor < -1){
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
 
Node *AVLTree::insertAVL(Node *root, const string &value){

    if (root == NULL){
        root = new Node;
        root->val = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else if (value < root->val){
        root->left = insertAVL(root->left, value);
        root = balance (root);
    }else if (value >= root->val){
        root->right = insertAVL(root->right, value);
        root = balance (root);
    }
    return root;
}

void AVLTree::clean(Node *root){
    if (!root) return;
    clean(root->right);
    clean(root->left);
    delete root;
}

int searchHash(NumNode* tbl[], int size, const string &s){
    int ind = hashFunc(s, size);
    NumNode* curr = tbl[ind];
    int nodeCnt = 0;
    while (curr){
        nodeCnt++;
        if(curr->nm == s){
            return nodeCnt;
        }
        else {
            curr = curr->next;
        }
    }
    return nodeCnt; //this means it wasn't found btw.
}

int searchTree(Node* root, const string &s){
    int nodeCnt = 0;
    Node* curr = root;
    while (curr){
        nodeCnt++;
        if (curr->val == s){
            return nodeCnt;
        }
        else if(curr->val > s){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return nodeCnt;
}


int main(){
    const int bucket = 512;
    NumNode* table[bucket];
    AVLTree* node = NULL;
    for (int i = 0 ; i < bucket ; i++){
        table[i] = NULL;
    }

    srand(0);
    for (int i = 0 ; i < bucket ; i++){
        string random = randInit();
        insert(table, bucket, random);
        node->insertAVL(node->root, random);
    } 
    string exinit = randInit();

    int hashCnt = searchHash(table, bucket, exinit);
    int treeCnt = searchTree(node->root, exinit);


    cout << "Looking for: " << exinit << endl;
    cout << "Number of Hash Nodes Searched: " << hashCnt << endl;
    cout << "Numvber of Tree Nodes Searched: " << treeCnt << endl;

    node->clean(node->root);
    reset(table, bucket);
    return 0;
}