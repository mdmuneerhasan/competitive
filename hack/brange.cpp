#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> tree;
vector<int> arr;
struct Segment{
    public:
    void init(int n){
        tree.resize(4*n+5,0);

    }
    void build(int n){
        build(0,n-1,0);
    }
    void build(int start,int end ,int node){
        if(start>=end){
            tree[node]=arr[start];
            return ;
        }
        int mid=(start+end)/2;
        build(start,mid,2*node+1);
        build(mid+1,end,2*node+2);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    void increment(int start,int end,int l ,int r,int node,int in){
        if(start>r||end<l||start>end)return ;
        if(start==end){
            // tree[node]+=in ;
        }
        int mid=(start+end)/2;
        
        increment(start,mid,l,r,2*node+1,in);
        increment(mid+1,end,l,r,2*node+2,in);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    
    }
    int sum(int start,int end,int l ,int r,int node){        
        if(start>r||end<l||start>end)return 0;
        if(start>=l && end <=r){
            return tree[node];
        }
        int mid=(start+end)/2;
        
        int q1=sum(start,mid,l,r,2*node+1);
        int q2=sum(mid+1,end,l,r,2*node+2);
        return q1+q2;
    
    }

}seg;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        int n1;
        cin >>n1;
        arr.resize(n1+1,0);
        for(int q=0;q<n1;q++){
          cin >> arr[q];
        }
        seg.init(n1);
        seg.build(n1);
        seg.increment(0,n1-1,0,n1-1,0,5);
        
        int q;
        cin >> q;
        while(q--){
            int l,r;
            cin >> l>>r;
            cout << seg.sum(0,n1-1,l-1,r-1,0)<<endl;    
        //   seg.sum(0,n1-1,l-1,r-1,0);    
        }
    }
    return 0;
}