#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> vec;
int n1,q;
int query(int start,int end,int val,int l,int r){

    if(start>r || end<l || start >end){
        return 0;
    }
    if(start>=l && end <=r){
      if(val<2)return val;
    }
    int mid=(start+end)/2;
    return query(start,mid-1,val/2,l,r)+
        query(mid,mid,val%2,l,r)+
        query(mid+1,end,val/2,l,r);

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        int n,l,r;
        cin >> n >> l >>r;
        int end=1,n1=n;
        while(n1){
            n1/=2;
            end*=2;
        }
        end--;
        cout << query(1,end,n,l,r)<<endl;
        
      
    }
    return 0;
}