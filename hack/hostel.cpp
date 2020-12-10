#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;  
     while (t--)
    {
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 0:
            int a;
            cin >> a;
            v.push_back(a);
            break;
        case 1:
            // for(auto x : v){
            //     cout << x << endl;
            // }
            int l,r,x;
            cin >> l>>r>>x;
                        int max=v[l];
            for(int i=l;i<r;i++){
                if(x^v[i]>max^x){
                    max=v[i];                   
                }
            }
            cout << max <<endl;
            break;
        }
    }
    return 0;
}