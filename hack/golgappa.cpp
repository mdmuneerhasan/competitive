/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
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
vector<int> vec,primes;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   

        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        int arr[n1+1]={0};
        for(int q=0;q<n1;q++){
          cin >> vec[q];
          arr[vec[q]]=1;
        }
        sort(vec.begin(),vec.end());
        int j=1;
        for(int i=1;i<n1;i++){
            while(arr[j])j++;
            if(vec[i-1]==vec[i]){
                ans+=abs(vec[i]-j);
                arr[j]=1;
            }
        }

        cout << ans<<endl;
          

          
          
    }
    return 0;
}
