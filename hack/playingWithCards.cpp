/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 23:04:39 Thursday 09-April:2020
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
    cout << "Thursday 09-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<stack<int>>staB;
stack<int>staA,staTemp,staTemp2;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;
vector<int> primes;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;

    bool seive[100001]={0};
    for(int i=2;i<100001;i++){
        if(seive[i]==0){
            primes.push_back(i);
            for(int j=i*i;j<100001;j+=i){
                seive[j]=1;
            }
        }
    }
    {   
          cin >>n1>>k;
          staB.resize(k+1);
          for(int q=0;q<n1;q++){
            cin >> x;
            staA.push(x);
          }

          for(int i=1;i<=k;i++){
              
            while(!staA.empty()){
                staTemp2.push(staA.top());
                staA.pop();
            }
            while(!staTemp2.empty()){
                staTemp.push(staTemp2.top());
                staTemp2.pop();
            }

              while (!staTemp.empty())
              {
                  int top=staTemp.top();
                  staTemp.pop();
                  if(top%primes[i-1]==0){
                      staB[i].push(top);
                  }else{
                      staA.push(top);
                  }
              }
            

          }

          for(int i=1;i<=k;i++){
          while(!staB[i].empty()){
              cout << staB[i].top()<<endl;
              staB[i].pop();
              
          }          
          }
          cout <<endl;
          while(!staA.empty()){
              cout << staA.top()<<endl;
              staA.pop();
          }





          
          
    }
    return 0;
}