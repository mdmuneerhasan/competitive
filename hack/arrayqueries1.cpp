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
vector<int> vec2;
vector<int> tree;
vector<int> lazy;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,qry=0;
void build(int start,int end,int node ){
    if(start==end){
        tree[node]=vec[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    tree[node]=(tree[2*node+1]+tree[2*node+2]);
}
void update(int start,int end ,int node ,int l,int r,int val){
    if(start>end || end<l || start>r)return;
    if(lazy[node]!=0){
        int x=lazy[node];
        tree[node]+=(end-start+1)*x;
        lazy[2*node+1]=x;
        lazy[2*node+2]=x;
    }
    if(start>=l && end<=r){
        tree[node]+=val*(end-start+1);
        lazy[2*node+1]=val;
        lazy[2*node+2]=val;
        return;
    }
    int mid=(start+end)/2;
    update(start,mid,2*node+1,l,r,val);
    update(mid+1,end,2*node+2,l,r,val);
    tree[node]=(tree[2*node+1]+tree[2*node+2]);

}
int query(int start,int end ,int node ,int l,int r){
    if(start>end || end<l || start>r)return 0;
      if(lazy[node]!=0){
        int x=lazy[node];
        tree[node]+=(end-start+1)*x;
        lazy[2*node+1]=x;
        lazy[2*node+2]=x;
    }
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return (
    query(start,mid,2*node+1,l,r)+
    query(mid+1,end,2*node+2,l,r));
}
void print(int par=0,string indent="",string child=""){
    if(par>=tree.size())return;
    cout <<"\n"<<indent<<"`---"<<tree[par];
    if(child.size()!=0)cout<<'{'<<child<<"}";
    print(2*par+1,"\t"+indent,"l");
    print(2*par+2,"\t"+indent,"r");
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1>>k>>qry;
        vec.resize(n1,0);
        vec2.resize(n1,0);
        tree.resize(4*n1+5,0);
        lazy.resize(8*n1+5,0);
        for(int q=0;q<n1;q++){
          cin >> vec2[q];
        }
        ans=0;
        for(int i=0;i<k;i++){
            ans+=vec2[i];
        }
        for(int i=0;i<n1;i++){
            vec[(i+k-1)%n1]=ans;
            ans-=vec2[i];
            ans+=vec2[(i+k)%n1];

        }


        

        build(0,n1-1,0);

        int l,r,val,index,cse=1;
        while(qry--){
           cin >> cse;
           switch(cse){
           case 2:
           cin >> l >> r;
        cout <<query(0,n1-1,0,l-1,r-1)<<endl;
           break;
           case 1:
           cin >>index >> val;
           l=index-1;
           r=index+k-2;
           val-=vec2[index-1];
        //    db(l,r,val);
           if(r<n1){
           update(0,n1-1,0,l,r,val);
           }else{
           update(0,n1-1,0,l,n1-1,val);
           update(0,n1-1,0,0,r%n1,val);
               
           }
           vec2[index]+=val;
             
           break;
            }
            // print();
        }
      
    }
    return 0;
}