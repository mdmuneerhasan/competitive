#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v2;
int create(int k){
    v2.clear();
    v2.push_back(0);
    v2.push_back(1);
    int i2=1,i3=1,i5=1;
    int p2=2,p3=3,p5=5;
    for(int i=2;i<=k;i++){
        int ans=min(2*v2[i2],min(3*v2[i3],5*v2[i5]));
        v2.push_back(ans);
        if(ans==2*v2[i2]){
            i2++;
        }
        if(ans==3*v2[i3]){
            i3++;
        }
        if(ans==5*v2[i5]){
            i5++;
        }
    }
    // for(int i=0;i<v2.size();i++){
    //     cout << i << " " << v2[i] << endl;
    // }
    return v2[k];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    int max =100000;
    cin >>t;
    for (int i = 0; i < t; i++)
    {   int k;
        cin >> k;
        cout << create(k)<< endl;
    }

    return 0;
}