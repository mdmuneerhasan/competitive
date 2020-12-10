#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int n;
vector<int> arr;
int m=1e9;
int i,j,k;
void seter(int l){
    // cout << l<<endl;
    if(l>k){
        if(m>l){
            m=l;
        }
    }
}
struct seg{
    void init(int n){
        v.resize(4*n+5,0);
    }
    void build(){
        build(0,n-1,0);
    }
    void build(int start,int end,int node){
        if(start==end){
            v[node]=arr[start];
            return  ;
        }
        int mid=(start+end)/2;
        build(start,mid,2*node+1);
        build(mid+1,end,2*node+2);
    
    }
    void query(int i,int j){
         finder(0,0,n-1,i,j) ;
    }
    int finder(int node,int start,int end,int i, int j){
        if(start>end || end <i || start > j )return INT_MIN;
        if(start==end){
        seter(v[node]);
        return v[node];
        }
        int mid=(end+start)/2;
        return max(finder(2*node+1,start,mid,i,j),finder(2*node+2,mid+1,end,i,j));        
    }
}s;      
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      cin >>n;
      arr.resize(n+5);
      for(int q=0;q<n;q++){
        cin >> arr[q];
      }
        s.init(n);
        s.build();

    cin >>t;    while (t--)
    {
        cin >> i >>j >> k;
        m=1e9;
        s.query(i-1,j-1);
        if(m==1e9){
            cout << 0<<endl;
            continue;
        }
        cout << m<<endl;
    }
    }
    return 0;
}