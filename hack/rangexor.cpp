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
struct qNode
{
    int l;
    int r;
    int val;
};

vector<int> vec;
vector<qNode> qVec;
vector<int> tree(400008,0);
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
void build(int start,int end,int node){
    if(start==end){
        tree[node]=vec[start];
        return ;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
}
int query(int start,int end,int node,int l,int r,int val){
    if(start>end || start>r || end<l ){
        return -1;
    }
    if(start==end){
        return tree[node];
    }
    int mid=(start+end)/2;
    int a=query(start,mid,2*node+1,l,r,val);
    int b=query(mid+1,end,2*node+2,l,r,val);
    int aXor=val^a;
    int bXor=val^b;

    if(aXor>=bXor){
        return a;
    }
    return b;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      //cin >> n;
      cin >> qry;
      int l,r,val,index,cse=1;
      while(qry--){
         cin >> cse;
         switch(cse){
         case 0:
         cin >> startPoint;
         vec.push_back(startPoint);
         break;
         case 1:
         qNode q;
         cin >> q.l >> q.r >>q.val;
         qVec.push_back(q);
         break;
          }
      }
      n=vec.size()-1;
      build(0,n,0);

      for(auto x: qVec){
          cout << query(0,n,0,x.l-1,x.r-1,x.val)<<endl;
      }

      
    }
    return 0;
}