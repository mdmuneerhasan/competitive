#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n+1];
        int k;
        cin >>k;
        a[0]=0;
        a[1]=k%n;
        vector<int> v(n+1,0);
        for(int i=2;i<=n;i++){
            cin >>k;
            a[i]=((a[i-1]%n+k%n)+n)%n;
            v[a[i]]++;
        }
        int cnt=0;
        
        for(int i=0;i<=n;i++){
            cout << a[i]<<" ";
        }
        cout << endl;
        for(int i=0;i<=n;i++){
            cout << v[i]<<" ";
        }
        for(int i=0;i<=n;i++){
//            cnt+=v[i];
            if(v[i]>1)
            cnt +=v[i]*(v[i]-1)/2;
        }
        cout << cnt<<endl;
    }
    return 0;
}