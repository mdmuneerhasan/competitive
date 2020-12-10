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
unordered_map<int,int> dp;
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
Node * build(Node * node,int val){
    if(node==NULL){
        node =new Node();
        node->data=val;
        return node;
    }else 
    if(val<node->data){
        node->left=build(node->left,val);
    }else 
    {
        node->right=build(node->right,val);
        // cout << node->right->data;
    }
    return node;
}
unordered_map<int,vector<int>>level;
int print(Node * node,int d=0){
    if(node==NULL)return d;
    level[d].push_back(dp[node->data]);
    int a=print(node->left,d+1);
    int b=print(node->right,d+1);
    return max(a,b);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {Node *root=NULL;
    cin >>n;
      while(n!=-1){
          root=build(root,n);
          vec.push_back(n);
          ans+=n;
          cin >> n;
      }
      sort(vec.begin(),vec.end());
      for(auto x:vec){
          dp[x]=(ans-=x);
      }
      ans=print(root);
      for(int i=0;i<ans;i++){
          for(auto x:level[i]){
              cout << x<<endl;
          }
      }
      
    }
    return 0;
}