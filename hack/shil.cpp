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
vector<int> vec2;
vector<vector<int>> tree;
vector<int> lazy;
void build(int start,int end,int node ){
    if(start==end){
        tree[node][vec[start]]++;
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    for(int i=0;i<26;i++){
        tree[node][i]=tree[2*node+1][i]+tree[2*node+2][i];
    }
}
void update(int start,int end ,int node ,int index,int val,int old){
    if(start>end || end<index || start>index)return;
    if(start==end){
        tree[node][val]++;
        tree[node][old]--;
        return;
    }
    int mid=(start+end)/2;
    update(start,mid,2*node+1,index,val,old);
    update(mid+1,end,2*node+2,index,val,old);
    
    for(int i=0;i<26;i++){
        tree[node][i]=tree[2*node+1][i]+tree[2*node+2][i];
    }
}
vector<int> query(int start,int end ,int node ,int l,int r){
    vector<int> v(26,0),v2,v1;
    if(start>end || end<l || start>r)return v;
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
   
    v1=query(start,mid,2*node+1,l,r);
    v2=query(mid+1,end,2*node+2,l,r);
    for(int i=0;i<26;i++){
    v[i]=v1[i]+v2[i];
    }
return v;
}
// void print(int par=0,string indent="",string child=""){
//     if(par>=tree.size())return;
//     cout <<"\n"<<indent<<"`---"<<tree[par];
//     if(child.size()!=0)cout<<'{'<<child<<"}";
//     print(2*par+1,"\t"+indent,"l");
//     print(2*par+2,"\t"+indent,"r");
//     return;
// }
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1>>qry;
        vec.clear();
        vec.resize(n1,0);
        tree.resize(4*n1+5,vector<int>(26,0));
        char c;
        for(int q=0;q<n1;q++){
          cin >> c;
          vec[q]=c-'a';
        }
        build(0,n1-1,0);
        int l,r,val,index,cse=1;
        while(qry--){
                       int odd=0;
           cin >> cse;
           switch(cse){
           case 2:
           cin >>l>>r;
           lazy=query(0,n1-1,0,l-1,r-1);

           q=0;
           for(auto x:lazy){
               odd+=(x%2==1);
           }
           if(odd<2){
               cout << "yes"<<endl;
           }else{
               cout << "no"<<endl;
           }
           
             
           break;
           case 1:
           cin >> index >> c;
           update(0,n1-1,0,index-1,c-'a',vec[index-1]);
           vec[index-1]=c-'a';
             
           break;
            }
        }
      
    }
    return 0;
}