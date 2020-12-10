/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 14:14:13 Sunday 12-April:2020
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    cin >>t;    while (t--)
    {   
          
          cin >> n1 >> n2;
          int cMin,cMax;
          cMin=n1/n2;
          cMax=cMin+1;
          int i=0;
          while((i*cMin+(n2-i)*cMax)!=n1){
              i++;
              }


          ans=0;
          for(int j=0;j<i;j++){
              n1-=cMin;
              ans+=cMin*(n1);
          }
          for(int j=i;j<n2;j++){
              n1-=cMax;
              ans+=cMax*(n1);
          }
          cout << ans<<endl;

          
    }
    return 0;
}