#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
vector<string> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   
          cin   >> n;
          for(int i=0;i<=n;i++){
              vec.push_back(to_string(i));
          }
          sort(vec.begin(),vec.end());
          for(int i=0;i<vec.size();i++){
              cout <<vec[i] << " ";
          }
          cout <<endl;
                    
    }
    return 0;
}