/*
* This code is submitted by Muneer Hasan
* Computer-scince treeudent ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 13:40:49 Sunday 12-April:2020
*/
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
void signature(bool enable){
    if(!enable)return;
    cout << "Sunday 12-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec,primes;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;
const int N=200005;

int b[N],a[N],c[N];
int tree[N*4];
void update(int l,int r,int indup,int val,int node){
        if(l==r){
            tree[node]=max(val,tree[node]);
            return;
        }
        else{
            int mid=(l+r)/2;
            if(indup>=l&&indup<=mid){
                update(l,mid,indup,val,node*2+1);
            }
            else{
                update(mid+1,r,indup,val,node*2+2);
            }
            tree[node]=max(tree[2*node+1],tree[2*node+2]);  
    }
}

    int query(int si,int se,int l,int r,int node){
        if(se<l||si>r){
            return 0;
        }
        if(si>=l&&se<=r){
            return tree[node];
        }
        int mid=(si+se)/2;
        int q1=query(si,mid,l,r,node*2+1);
        int q2=query(mid+1,se,l,r,node*2+2);
        return max(q1,q2);
    }


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    cin >>t;    while (t--)
    {   
          
             int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
            c[i]=a[i];
        }
        sort(c,c+n);
        for(i=0;i<n;i++){
            a[i]=lower_bound(c,c+n,a[i])-c+1;
        }
        for(i=0;i<n;i++){
            cin>>b[i];                   
        }
        map<int,int> mp;
        for(i=0;i<n;i++){
            int val=b[i];
            val+=query(0,n,0,a[i]-1,0);
            update(0,n,a[i],val,0);
            ans=max(ans,val);
        }
        cout<<ans<<'\n';
        for(int i=0;i<4*N;i++){
            tree[i]=0;       
        }
        mp.clear();
    
          
    }
    return 0;
}