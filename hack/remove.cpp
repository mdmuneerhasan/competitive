#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
struct Node
{
    int data;
    Node * left;
    Node * right;
    Node(){
        left=NULL;
        right=NULL;
    }
};
Node * build(){
    Node * node=new Node();
    cin >>node->data;
    string left,right;
    cin >> left;
    if(left.compare("true")==0){
        node->left=build();
        // cout << node->left->data;
    }
    cin >> right;
    if(right.compare("true")==0){
        node->right=build();
        // cout << node->right->data;
    }
    return node;
}
// void print(Node * node,string indent="",string child=""){
//     if(node==NULL)return;
//     cout <<"\n"<<indent<<"`---"<< node->data;
//     if(child.size()!=0)cout<<'{'<<child<<"}";
//     print(node->left,"\t"+indent,"l");
//     print(node->right,"\t"+indent,"r");
//     return;
// }
void print(Node * node,string indent="",string child=""){
    if(node==NULL)return;
    if(node->left==NULL && node->right==NULL);else{
        if(node->left!=NULL&&!(node->left->left==NULL && node->left->right==NULL))
        cout << node->left->data;
        else cout <<"END";
        cout <<" => " <<node->data<<" <= ";
        if(node->right!=NULL&&!(node->right->left==NULL && node->right->right==NULL))cout << node->right->data;
        else cout <<"END";

        cout <<endl;
        
    }
    print(node->left,"\t"+indent,"l");
    print(node->right,"\t"+indent,"r");
    return;
}void print2(Node * node){
    if(node==NULL)return;
    print(node->left);
    print(node->right);
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        Node *root=NULL;
        root=build();
        print(root);
      
    }
    return 0;
}