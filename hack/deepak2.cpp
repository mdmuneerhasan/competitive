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

void solve(int startPoint,int endPoint){
    int pp[1000000];
    fill(pp,pp+1000000,1);
    n=sqrt(endPoint);
    int p[n+1];
    fill(p,p+n+1,1);

    p[0]=0;p[1]=0;
    for(int i=2;i*i*i*i<=endPoint;i++){
        if(p[i]){
            // db(p[i],i);
            for(int j=2*i;j*j<=endPoint;j+=i){
                // db(j);
                p[j]=0;
            }
        }
    }
    // for(int i=0;i<1000;i++){
    // if(p[i])cout << i<<endl;
    // }


    for(int i=2;i*i<=endPoint;i++){
        if(p[i]){
        for(int j=startPoint;j<=endPoint;){
            if(j%i==0&&j>i){
                pp[j-startPoint]=0;
                j+=i;
            }else{
                j++;
            }
        }
    
        }
    }
    int x=(startPoint==1?2:startPoint);
    
    for(int i=x;i<=endPoint;i++){
        // db(i,pp[i-startPoint]);
        if(pp[i-startPoint])cout << i<<endl;
    }

    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >> startPoint >> endPoint;
        solve(startPoint,endPoint);
        cout <<endl;
      
    }
    return 0;
}
