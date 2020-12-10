#include<bits/stdc++.h>
using namespace std;
#define int long long int 
vector<bool> v;

bool isPrime(int n){
    
    if(n<2)
    return false;
    if(n==2||n==3)
    return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
        return false;
    }
    return true;
    
}
int sumof(int i){
    int sum=0;
    while(i){
        sum += i%10;
        i/=10;
    }
    return sum;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        int n;
        cin >> n;
        // if(n==0){
        //     cout << 0 << endl;
        //     return ;
        // }if(n==1){
        //     cout <<0 << endl;
        //     return ;
        // }
        if(n==1){
            cout << 1 << endl;
            return 0;
        }
        int d=n,k=n;
        v.resize(1e9);
        v[0]=1;v[1]=1;
        int sum1=0;
        int i=0;
        for(i=2;i<=k;i++){
           if(isPrime(i)){
                while(k%i==0){
                    sum1+=sumof(i);
                    k/=i;
                }
           }
        }
        // cout <<sum1 << endl;
        int sum2=0;
        while(d){
            sum2 += d%10; d/=10;
        }
        // cout << sum2 << endl ; 
        if(sum1==sum2){
            cout << 1 << endl;
        }else {
            cout << 0 << endl;
        }
    }
    return 0;
}