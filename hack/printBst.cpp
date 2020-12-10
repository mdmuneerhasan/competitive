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
Node * build(Node * node ,int val){
    if(node==NULL){
    node=new Node();    
    node->data=val;
    return node;
    }
    if(val<node->data){
        node->left=build(node->left,val);
        
    }else{
        node->right=build(node->right,val);
    }
    return node;
}
void print(Node * node,string indent="",string child=""){
    if(node==NULL)return;
    cout << node->data <<" ";
    print(node->left,"\t"+indent,"l");
    print(node->right,"\t"+indent,"r");
    return;
}
void print(Node * node,int k1,int k2,string indent="",string child=""){
    if(node==NULL)return;
    print(node->left,k1,k2,"\t"+indent,"l");
    if(node->data>=k1 &&node->data<=k2)
    cout << node->data <<" ";
    print(node->right,k1,k2,"\t"+indent,"r");
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        Node * root =NULL;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >>k;
            root =build(root,k);
        }
        cout << "# Preorder : ";
        print(root);
        int k1,k2;
        cin >> k1 >> k2;
        cout <<endl;
        cout << "# Nodes within range are : ";
        print(root,k1,k2);
        
        
      
    }
    return 0;
}