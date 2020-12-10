#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int n,m,x,y,ans=0;
void maxi(int k){
    if(ans<k){
        ans=k;
    }
}
bool possible(int win){
    int los=n-win;
    int coup=m+los*y;
    return win*x<=coup;
        
}
void go(int start,int end){
    if(start==end){
        cout << start<<endl;
        return;
    }
    int mid=(start+end)/2;
    int max=0;
    if(!possible(mid)){
        go(start,mid); 
           
    }else{
        if(possible(mid+1)){
            go(mid+1,end);    
        }else{
            go(mid,mid);
        }
    }
    return ;
}      
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n>>m>>x>>y;
      go(0,n);
      
    }
    return 0;
}