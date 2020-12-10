#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,int> freq;
unordered_map<int,int> xorBeauty;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    // cin >>t;    while (t--)
    {
          cin >> n1 >> qry;
          char arr[n1];
          cout << "     ";
          for(int i=0;i<n1;i++){
            cin >> arr[i];
            freq[arr[i]-'a']++;
            cout << i+1<< ":"<<arr[i]<<", ";
            xorBeauty[i+1]=xorBeauty[i]^freq[arr[i]-'a'];
          }

          cout <<endl;
          q=0;
          for(auto x:xorBeauty){
              cout <<q<<":"<< xorBeauty[q++]<<", ";
          }
          cout <<endl;
          


          int l,r,val,index,cse=1;
          while(qry--){
              cin >> l >> r;
              r=xorBeauty[r];
              l=xorBeauty[l-1];
              db(l,r);
          }
        
        
      
    }
    return 0;
}