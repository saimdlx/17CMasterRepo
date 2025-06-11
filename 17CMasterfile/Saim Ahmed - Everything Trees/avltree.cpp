#ifndef AVLTREE_H
#define	AVLTREE_H

#include <iostream>
using namespace std;

struct Node{
    int val;
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
        Node* insert(Node *, int );//Insert and balance the tree
        Node* deleteNode(Node*, int );
        void display(Node *, int);    //Funky display root left to right
        void inorder(Node *);         //In order display
        void preorder(Node *);        //Pre order display
        void postorder(Node *);       //Post order display
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
 
Node *AVLTree::insert(Node *root, int value){
    if (root == NULL){
        root = new Node;
        root->val = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else if (value < root->val){
        root->left = insert(root->left, value);
        root = balance (root);
    }else if (value >= root->val){
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

Node *AVLTree::deleteNode(Node* n, int val){
    if(n == NULL){
        return nullptr; 
    }
    if(val < n->val){
        n->left = deleteNode(n->left, val);
    }
    else if (val > n->val){
        n->right = deleteNode(n->right, val);
    }
    else{
        if(!n->left){
            return n->left;
        }
        if(n->right){
            return n->right;
        }
        Node* temp = n->right;
        while(temp->left) {
            temp = temp->left;
            n->val = temp->val;
            n->right = deleteNode(n->right, val);
        }
    }
    return balance(n);
}
 
void AVLTree::display(Node *ptr, int level){
    int i;
    if (ptr!=NULL){
        display(ptr->right, level + 1);
        cout<<endl;
        if (ptr == root)
        cout<<"R -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"     ";
        cout<<ptr->val;
        display(ptr->left, level + 1);
    }
}
 
void AVLTree::inorder(Node *tree){
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->val<<"  ";
    inorder (tree->right);
}

void AVLTree::preorder(Node *tree){
    if (tree == NULL)
        return;
    cout<<tree->val<<"  ";
    preorder (tree->left);
    preorder (tree->right);
}
 
void AVLTree::postorder(Node *tree){
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->val<<"  ";
}

#endif	/* AVLTREE_H */
void menu(){
    cout<<"\n---------------------"<<endl;
    cout<<"AVL Tree Implementation"<<endl;
    cout<<"\n---------------------"<<endl;
    cout<<"1.Insert Element into the tree"<<endl;
    cout<<"2.Delete Element from the tree"<<endl;
    cout<<"3.Display Balanced AVL Tree"<<endl;
    cout<<"4.InOrder traversal"<<endl;
    cout<<"5.PreOrder traversal"<<endl;
    cout<<"6.PostOrder traversal"<<endl;
    cout<<"7.Exit"<<endl;
    cout<<"Enter your Choice: ";
}


int main(){
    int choice, item;
    AVLTree avl;
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to be inserted: ";cin>>item;
                avl.root = avl.insert(avl.root, item);break;
            case 2:
                cout<<"Enter value to be deleted: ";cin>>item;
                avl.root = avl.deleteNode(avl.root, item);break;
            case 3:
                if (avl.root == NULL){cout<<"Tree is Empty"<<endl;continue;}
                cout<<"Balanced AVL Tree:"<<endl;avl.display(avl.root,1);break;
            case 4:
                cout<<"In-order Traversal:"<<endl;avl.inorder(avl.root);
                cout<<endl;break;
            case 5:
                cout<<"Pre-order Traversal:"<<endl;avl.preorder(avl.root);
                cout<<endl;break;
            case 6:
                cout<<"Post-order Traversal:"<<endl;avl.postorder(avl.root);    
                cout<<endl;break;
            default:
                cout<<"Exit Program"<<endl;
        }
    }while(choice>=0&&choice<=6);
    
    //Exit stage right!
    return 0;
}