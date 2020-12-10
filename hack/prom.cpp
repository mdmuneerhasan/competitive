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
struct prom
{
    int a,b,index;
};

vector<prom> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
vector<int> vec2;
vector<prom> tree;
vector<int> lazy;
prom func(prom a,prom b){
    if(a.a>b.a){
        return a;
    }else if(a.a==b.a){
        if(a.b<b.b){
            return a;
        }else if(a.b==b.b){
            if(a.index<b.index)return a;
            return b;
        }else{
            return b;
        }
    }
    return b;
}
void build(int start,int end,int node ){
    if(start==end){
        tree[node]=vec[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    tree[node]=func(tree[2*node+1],tree[2*node+2]);
}
prom query(int start,int end ,int node ,int l,int r){
    prom p;
    p.a=INT_MIN;p.b=INT_MAX;p.index=INT_MAX;
    if(start>end || start>r || end<l)return p;
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return func(
    query(start,mid,2*node+1,l,r),
    query(mid+1,end,2*node+2,l,r));
}

void print(int par=0,string indent="",string child=""){
    if(par>=tree.size())return;
    cout <<"\n"<<indent<<"`---"<<tree[par].a<<" "<<tree[par].b<<" "<<tree[par].index<<" ";
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
        cin >>n1;
        vec.resize(n1);
        tree.resize(4*n1+5);
        
        for(int q=0;q<n1;q++){
          cin >> vec[q].a;
        }
        for(int q=0;q<n1;q++){
          cin >> vec[q].b;
          vec[q].index=q;
        }

        build(0,n1-1,0);

        // print();

        cin >> qry;
        int l,r,val,index,cse=1;
        while(qry--){
            cin >> l >> r;
            cout <<query(0,n1-1,0,l-1,r-1).index+1 <<endl;
        }
      
    }
    return 0;
}