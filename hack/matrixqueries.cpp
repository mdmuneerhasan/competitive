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
struct Node{
    int a00,a01,a10,a11;
    Node(){
        a00=1;        a01=0;
        a10=0;        a11=1;
    }
};
vector<Node> vec;
int n,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
vector<Node> tree;
void build(int start,int end,int node ){
    if(start==end){
        tree[node]=vec[start];
        return;
    }
    int mid=(start+end)/2;
    build(start,mid,2*node+1);
    build(mid+1,end,2*node+2);
    Node n1=tree[2*node+1];
    Node n2=tree[2*node+2];
    Node n3;
    n3.a00=((n1.a00*n2.a00)%k+(n1.a01*n2.a10)%k)%k;    n3.a01=((n1.a00*n2.a01)%k+(n1.a01*n2.a11)%k)%k;
    n3.a10=((n1.a10*n2.a00)%k+(n1.a11*n2.a10)%k)%k;    n3.a11=((n1.a10*n2.a01)%k+(n1.a11*n2.a11)%k)%k;
    tree[node]=n3;
}

Node query(int start,int end ,int node ,int l,int r){
    Node n1,n2 ,n3;
    if(start>end || end<l || start>r)return n1;
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    
    n1=query(start,mid,2*node+1,l,r);
    n2=query(mid+1,end,2*node+2,l,r);
    n3.a00=((n1.a00*n2.a00)%k+(n1.a01*n2.a10)%k)%k;    n3.a01=((n1.a00*n2.a01)%k+(n1.a01*n2.a11)%k)%k;
    n3.a10=((n1.a10*n2.a00)%k+(n1.a11*n2.a10)%k)%k;    n3.a11=((n1.a10*n2.a01)%k+(n1.a11*n2.a11)%k)%k;
    return n3;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> k >> n >> qry;
        vec.resize(n);
        tree.resize(4*n+5);
        for(int i=0;i<n;i++){
            cin >> vec[i].a00>>vec[i].a01>>vec[i].a10>>vec[i].a11;
        }

        build(0,n-1,0);

        int l,r,val,index,cse=1;
        while(qry--){
            cin >> l >> r;
            l--;r--;
            Node n1=query(0,n-1,0,l,r);
            cout << n1.a00<<" ";
            cout << n1.a01<<endl;
            cout << n1.a10<<" ";
            cout << n1.a11<<endl;

            }
        

      
    }
    return 0;
}