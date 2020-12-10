/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 18:24:16 Tuesday 07-April:2020
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
    cout << "Tuesday 07-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
   cin >>t;    while (t--)
    {   
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        ans=0;
        int dp1[n1+1],dp2[n1+1];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        int minVal=INT_MAX,MaxVal=INT_MIN,minIndex=0,maxIndex=0;

        for(int i=0;i<n1;i++){
          if(vec[i]<minVal){
            minIndex=i;
            minVal=vec[i];
          }
          if(vec[i]>MaxVal || maxIndex<=minIndex){
            maxIndex=i;
            MaxVal=vec[i];
          }
          if(minIndex<maxIndex){
            ans=max(ans,MaxVal-minVal);
          }
          dp1[i]=ans;
        }

        ans=0;cnt=0;
        minVal=INT_MAX,MaxVal=INT_MIN,minIndex=0,maxIndex=0;


        for(int i=n1-1;i>=0;i--){
          // db(i,minVal,MaxVal);
          if(vec[i]<minVal || minIndex>=maxIndex){
            minIndex=i;
            minVal=vec[i];
          }
          if(vec[i]>MaxVal){
            maxIndex=i;
            MaxVal=vec[i];
          }
          if(minIndex<maxIndex){
            ans=max(ans,MaxVal-minVal);
          }
          dp2[i]=ans;
          cnt=max(cnt,ans+dp1[i]);
        }


        // for(int i=0;i<100;i++){
        //     cout << i <<":"<<dp1[i] << ", ";
        // }
        // cout <<endl;
        // for(int i=0;i<100;i++){
        //     cout << i <<":"<<dp2[i] << ", ";
        // }
        // cout <<endl;
        
        
        
        ans=0;
        for(int i=0;i<n1;i++){
          ans=max(ans,dp1[i]+dp2[i]);
        }
        cout << ans<<endl;

        // cout << cnt<<endl;

        

          
    }
    return 0;
}