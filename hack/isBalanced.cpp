#include<iostream>
using namespace std;

class node{
public:

    int data;
    node*left;
    node*right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }


};


node* buildTree(){

    int d;
    string left,right;
    cin>>d>>left;

    node*root=new node(d);
    if(left.compare("true")==0)
    root->left=buildTree();
    cin >>right;
    if(right.compare("true")==0)
    root->right=buildTree();
    return root;



}
void print(node * n){
    if(n==NULL)return;
    cout << n->data<<endl;
    print(n->left);
    print(n->right);
}

int height(node*root){

    if(root==NULL){
        return 0;
    }

    int h1=height(root->left);
    int h2=height(root->right);

    return max(h1,h2)+1;
}

bool isBalenced(node*root){

    if(root==NULL){
        return true;
    }

    int h1=height(root->left);
    int h2=height(root->right);

    return (abs(h1-h2)<=1&&isBalenced(root->left)&&isBalenced(root->right));
    
}

int main(){
    
    node*root=buildTree();
    // print(root);

    if(isBalenced(root)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}