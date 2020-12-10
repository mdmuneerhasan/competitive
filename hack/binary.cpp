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
        
          cin >> n1;
          int arr[n1];
          for(int i=0;i<n1;i++){
            cin >> arr[i];
          }
        
        
        cin >> k;
        int start=0,end=n1;
        bool flag=false;
        int mid=0;
        while(start<end){
             mid=(start+end)/2;
            if(k>arr[mid]){
                start=mid+1;
            }else if(k<arr[mid]){
                end=mid;
            }else{
                flag=true;
                break;
            }

        }
        if(flag){
            cout << mid<<endl;
        }else{
            cout << -1<<endl;
        }
        
        
    }
    return 0;
}