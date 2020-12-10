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
vector<char> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        string s;
        cin >> s;
        cin >>n1;
        vec.clear();
        vec.resize(n1);
        unordered_map<char,int>dpVec;
        unordered_map<char,int>dpStr;
        char startPoint;
        for(int q=0;q<n1;q++){
          cin >> startPoint;
          dpVec[startPoint]++;
        }
        ans=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            int c=s[i];
            if(dpVec.count(c)>0&&dpVec[c]){
                dpVec[c]--;
                n1--;
                
            }
            while(n1==0){
                if(dpVec.count(s[j])>0){
                    dpVec[s[j]]++;
                    n1++;
                }  
                if(n1!=0){
                    ans+=(j+1)*(s.size()-i); 
                }
                j++;
            }
        }
        cout << ans<<endl;
        
      
    }
    return 0;
}