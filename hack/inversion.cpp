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
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
#define MOD 1000000007
int merge(int start,int mid,int end){
    int i=start;
    int j=mid+1;
    int ans=0;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(vec[i]>vec[j]){
            ans+=(end-j+1)%MOD;
            ans%=MOD;
            temp.push_back(vec[i]);
            i++;
        }else{
            temp.push_back(vec[j]);
            j++;

        }
    }while(i<=mid){
            temp.push_back(vec[i]);
            i++;
    }while( j<=end){   
            temp.push_back(vec[j]);
            j++;
    }
    for(int l=0;l<temp.size();l++){
        vec[start++]=temp[l];
    }

return ans;
}
int solve(int start,int end){
    if(start>=end)return 0;
    int mid=(start+end)/2;
    int ans=0;

    ans+=solve(start,mid)%MOD;
    ans%=MOD;
    ans+=solve(mid+1,end)%MOD;
    ans%=MOD;
    ans+=merge(start,mid,end)%MOD;
    return ans%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        cout << solve(0,n1-1)<<endl;
      q=0;
      for(auto x:vec){
          cout <<q++<<":"<< x<<", ";
      }
      cout <<endl;
    }
    return 0;
}