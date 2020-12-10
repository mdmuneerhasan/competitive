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
vector<int> post,in;

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

Node * build(int start,int end,int root){
    Node * node=new Node();
    node->data=post[root];
    if(start==end)return node;
    int i=start;
    for(;i<=end;i++){
        if(in[i]==post[root])break;
    }
    db(start,end,i);
    node->left=build(start,i-1,root-(end-i)-1);
    node->right=build(i+1,end,root-1);
    return node;
}
void print(Node * node,string indent="",string child=""){
    if(node==NULL)return;
    cout<< node->data<<" ";
    print(node->left,"\t"+indent,"l");
    print(node->right,"\t"+indent,"r");
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >>n1;
        post.clear();
        post.resize(n1,0);
        in.clear();
        in.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> post[q];
        }
        for(int q=0;q<n1;q++){
          cin >> in[q];
        }
        Node * root=NULL;
        root=build(0,n1-1,n1-1);
        print(root);

      
    }
    return 0;
}