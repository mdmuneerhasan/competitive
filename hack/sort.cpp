/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 00:07:16 Friday 10-April:2020
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
    cout << "Friday 10-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<pair<string,int>> vec,primes;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;
bool comp(pair<string,int> a,pair<string,int> b){
    if(a.second==b.second){
        return a.first<=b.first;
    }
    return a.second>b.second;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   
          cin >> x ;

          cin >>n1;
          vec.clear();
          vec.resize(n1);
          for(int q=0;q<n1;){
            cin >> vec[q].first >> vec[q].second;
            if(vec[q].second>=x){
                q++;
            }else{
                n1--;
                vec.pop_back();
            }
          }
          sort(vec.begin(),vec.end(),comp);
          for(auto x:vec){
              cout << x.first <<" "<<x.second<<endl;
          }
          cout <<endl;
          
          
    }
    return 0;
}