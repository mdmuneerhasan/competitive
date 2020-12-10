#include<iostream>
using namespace std;
#define ld long double
#define int long long int
ld powr(ld a,int b){
    ld res=1;
    while(b){
        if(b&1){
            res*=a;
        }
        a*=a;
        b/=2;
    }
return res;
}

int solve(int n,int k){
    int s=1;
    int e=n;
    int ans;
    while(s<=e){
        ld m=(s+e)/2;
        if(powr(m,k)<=n){
            ans=m;
            s=m+1;
        }
        else if(powr(m,k)>n){
            e=m-1;
        }
    }
return ans;
}



int32_t main(){

    int k;
    ld n;
    int t;
    cin>>t;

    while(t--){
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}