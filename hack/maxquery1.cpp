#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> vec;
int n1;
template<typename T>class Tree{
    vector<vector<int>> tree;
    public :
        Tree(int n=100000){
            tree.clear();
            tree.resize(n+5,vector<int>());
        }
        void build(int start,int end,int node){
            if(start==end){
                tree[node].push_back(vec[start]);
                return ;
            }
            int mid=(start+end)/2;
            build(start,mid,2*node+1);
            build(mid+1,end,2*node+2);
            copy(tree[2*node+1].begin(), tree[2*node+1].end(), back_inserter(tree[node])); 
            copy(tree[2*node+2].begin(), tree[2*node+2].end(), back_inserter(tree[node])); 
        }
        int query(int start,int end , int node ,int l ,int r,int val){
            if(start>r || end<l || start>end){
                return 0;
            }
            if(start>=l && end<=r){
              int c=0;
              for(auto x: tree[node]){
                if(x>=val)c++;
              }
              // for(int q=0;q<tree[node].size();q++){
              //   cout << q << ":" <<tree[node][q]<<", ";
              // }
              // cout << endl;
                return c;
            }
            int v1,v2;
            int mid=(start+end)/2;
            v1=query(start,mid,2*node+1,l,r,val);
            v2=query(mid+1,end,2*node+2,l,r,val);
            return v2+v1;
        }
        // void update(int start,int end,int node,int index,int val){
        //     if(start>index || end < index || start>end ){return ;}
        //     if(start==end){
        //         tree[node]=val;
        //         return;
        //     }
        //     int mid=(start+end)/2;
        //     update(start,mid,2*node+1,index,val);
        //     update(mid+1,end,2*node+2,index,val);
        //     tree[node]=min(tree[2*node+1],tree[2*node+2]);
    
        // }

};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int q,a;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        Tree<int>t(4*n1+5);
        t.build(0,n1-1,0);
        cin >>q;
        while(q--){
          int l,r;
            cin >>l>>r>>a;
            int c=t.query(0,n1-1,0,l-1,r-1,a);
            cout << c<<endl;
           
        }
    }
    return 0;
}