#include<bits/stdc++.h>
using namespace std;
vector<int> v(5000,-1);
int fact(int n){
    if(v[n]!=-1){
        return v[n];
    }
    int sum=1;
    for(int i=1;i<=n;i++){
        sum*=i;
    }
    return v[n]=sum;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >>n>>k;
        int count=0;
        for(int i=1;i<=n;i++){
            int num=i;
//            cout << count ;
            while(num%k==0){
                num/=k;
                count++;
            }
        }
        cout << count << endl;
    }
	return 0;
}