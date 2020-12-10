/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 10:41:08 Monday 13-April:2020
*/
#include<bits/stdc++.h>
using namespace std;
stringstream vin,vout;
#define int long long int
#define sf(v) sort(v.begin(),v.end())


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
    cout << "Monday 13-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec,primes;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    cin >>t;    while (t--)
    { int x,y,n,w,p1,p2;
          cin >> x >> y >> n >> w >> p1 >> p2;
          cout << setprecision(1);
          cout<< fixed;


          if(x+y<w){
              cout << 0<<endl;
          }

          if(x>=w){

          }else if(y>=w){

          }else{
              ans=0;
            for(int i=1;i<n;i++){
                ans+=1;
            }  
          }
          cout << ans<<endl;
          
          
    }
    return 0;
}