#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
unordered_map<int,vector<int>>dp;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
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
void print(Node * node){
    stack<Node *> current;
    stack<Node *> nextCurrent;
    current.push(node);
    bool flag=true;
    while(!current.empty()){
        Node * node=current.top();current.pop();
        cout << node->data<<" ";
        if(flag){
            if(node->left)
            nextCurrent.push(node->left);
            if(node->right)
            nextCurrent.push(node->right);
        }else{
            if(node->right)
            nextCurrent.push(node->right);
            if(node->left)
            nextCurrent.push(node->left);

        }
        if(current.empty()){
            swap(current,nextCurrent);
            flag=!flag;
        }

    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      Node * root;
      root=build();
      print(root);
      
      
    }
    return 0;
}