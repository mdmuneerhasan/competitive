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

node* buldTree(){

    int d;
    cin>>d;

    node*root=new node(d);

    string left,right;

    cin>>left;

    if(left.compare("true")==0){
        root->left=buldTree();
    }

    cin>>right;

    if(right.compare("true")==0){
        root->right=buldTree();
    }

return root;
}

bool isIdentical(node*root1,node*root2){

    if(root1==NULL&&root2==NULL){
        return true;
    }

    if(root1!=NULL&&root2!=NULL){


        if(isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right)){

            return true;
        }

    }
    return false;

}




int main(){

    node*root1=buldTree();

    node*root2=buldTree();

    if(isIdentical(root1,root2)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }




    return 0;
}