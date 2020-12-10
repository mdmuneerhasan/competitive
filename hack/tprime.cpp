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
vector<bool> vec;
vector<int> tPrime;
int n=1000000,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        vec.resize(n,0);

        for(int i=2;i*i<n;i++){
                if(vec[i]==0){
                for(int j=i*i;j<n;j+=i){
                    vec[j]=1;
                }
            }
        }

        // q=0;
        // for(auto x:vec){
        //     cout <<q++<<":"<< x<<", ";
        // }
        
        // cout <<endl;
        

        

        cin >> qry;
        int l,r,val,index,cse=1;
        while(qry--){
            cin >> n;
            int r=sqrt(n);
            if(r*r==n){
                if(vec[r]==0){
                    cout << "YES"<<endl;
                }else{
                    cout << "NO"<<endl;
                }
            }else{
                cout << "NO"<<endl;
            }
        }        
    }
    return 0;
}