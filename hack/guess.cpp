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
int depth,n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int start,int end,int depth,bool left){
    if(depth==0)return 1;
    int mid=(start+end)/2;
    if(endPoint>mid){
        if(left){
            return  solve(mid+1,end,depth-1,true)+pow(2,depth);
        }else{
            return  solve(mid+1,end,depth-1,true)+1;
        }
    }else{
        if(left){
            return  solve(start,mid,depth-1,false)+1;            
        }else{
            return  solve(start,mid,depth-1,false)+pow(2,depth);            
        }

    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      cin >> depth>>endPoint;
      
      cout << solve(1,pow(2,depth),depth,1)-1<<endl;
      
    }
    return 0;
}