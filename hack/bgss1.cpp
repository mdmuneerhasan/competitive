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
struct tree{
    int pre,suf,total,best;
};
vector<tree> treearr;
vector<int> arr;
void build(int start,int end,int node){
    if(start==end){
        treearr[node].pre=arr[start];
        treearr[node].suf=arr[start];
        treearr[node].total=arr[start];
        treearr[node].best=arr[start];
        return ;
    }
    int mid=(start+end)/2;
    int l=2*node+1,r=2*node+2;
    build(start,mid,l);
    build(mid+1,end,r);
        treearr[node].pre=max(treearr[l].pre,treearr[l].total+treearr[r].pre);
        treearr[node].suf=max(treearr[r].suf,treearr[l].suf+treearr[r].total);
        treearr[node].total=treearr[l].total+treearr[r].total;
        treearr[node].best=max(treearr[l].suf+treearr[r].pre,max(treearr[l].best,treearr[r].best));
    
}
tree query(int start,int end,int node,int l ,int r){
    tree t;
    if(start>r || end <l || end <start){
        t.pre=t.suf=t.best=INT_MIN;
        t.total=0;
        return t;
    }
    if(start>=l && end <=r){
        return treearr[node];

    }

    int mid=(start+end)/2;
    tree t1=query(start,mid,2*node+1,l,r);
    tree t2=query(mid+1,end,2*node+2,l,r);
        t.pre=max(t1.pre,t1.total+t2.pre);
        t.suf=max(t2.suf,t1.suf+t2.total);
        t.total=t1.total+t2.total;
        t.best=max(t1.suf+t2.pre,max(t1.best,t2.best));
    return t;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      int n;
      cin >>n;
      arr.resize(n,0);
      for(int q=0;q<n;q++){
        cin >> arr[q];
      }
      treearr.resize(4*n+5);
      build(0,n-1,0);
      cin>>t;
      while(t--){
          int l,r;
          cin >> l>>r;
          tree tr=query(0,n-1,0,l-1,r-1);
          cout << tr.best<<endl;




      }





      
    }
    return 0;
}