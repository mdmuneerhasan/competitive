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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        cin >>k;
        set<int> s;
        int i;
        for(i=0;i<k-1;i++){
            s.insert(vec[i]);

        }
    
        for(;i<n1;i++){
            s.insert(vec[i]);
            cout << *--s.end() <<endl;
            s.erase(s.begin() - s.find(vec[i-k-1]));
            q=0;
            for(auto x:s){
                cout <<q++<<":"<< x<<", ";
            }
            cout <<endl;
            
        }

      
    }
    return 0;
}