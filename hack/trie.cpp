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
        data=INT_MIN;
        left=NULL;
        right=NULL;
    }
};
Node * build(Node * node,int k ,int val){
    if(node==NULL)node=new Node();
    if(k==0){
        node->data=val;
        return node;
    }
    if(k&1){
        node->left=build(node->left,k/2,val);
    }else{
        node->right=build(node->right,k/2,val);
    }
    return node;
}
void print(Node * node,string indent="",string child=""){
    if(node==NULL)return;
    cout <<"\n"<<indent<<"`---"<< node->data;
    if(child.size()!=0)cout<<'{'<<child<<"}";
    print(node->left,"\t"+indent,"l");
    print(node->right,"\t"+indent,"r");
    return;
}
int print(Node * node,int k){
    if(node==NULL)return 0;
    int ans=0;
    if(node->data!=INT_MIN)ans++;
    if(k&1){
        ans+= print(node->left,k/2)+ print(node->right,k/2);
    }else{
        ans+=  print(node->right,k/2);
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    Node * root=NULL;
    cin >>t;    while (t--)
    {
        string s;
        cin >>s >>k;
        if(s=="add"){
            root=build(root,k,k);
        }else if(s=="cnt"){
            cout << print(root,k)<<endl;
        }else{
            root=build(root,k,INT_MIN);
        }

    print(root);
      
    }
    return 0;
}