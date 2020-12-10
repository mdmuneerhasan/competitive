#include<bits/stdc++.h>
using namespace std;
#define int long long int
int v[2][2];
int v2[2][2];
vector<int> v3;
void setOn(int t){
    if(t==0||t==1){
        return ;
    }

    setOn(t/2);
    int x1,x2,x3,x4;
     x1=v2[0][0]*v2[0][0]+v2[0][1]*v2[1][0]; 
     x2=v2[0][0]*v2[0][1]+v2[0][1]*v2[1][1];
     x3=v2[1][0]*v2[0][0]+v2[1][1]*v2[1][0];
     x4=v2[1][0]*v2[0][1]+v2[1][1]*v2[1][1]; 
    
    v2[0][0]=x1%(1000000007); 
    v2[0][1]=x2%(1000000007);
    v2[1][0]=x3%(1000000007);
    v2[1][1]=x4%(1000000007); 
    
    if(t&1){

    x1=v2[0][0]*v[0][0]+v2[0][1]*v[1][0]; 
    x2=v2[0][0]*v[0][1]+v2[0][1]*v[1][1];
    x3=v2[1][0]*v[0][0]+v2[1][1]*v[1][0];
    x4=v2[1][0]*v[0][1]+v2[1][1]*v[1][1]; 
    v2[0][0]=x1%(1000000007); 
    v2[0][1]=x2%(1000000007);
    v2[1][0]=x3%(1000000007);
    v2[1][1]=x4%(1000000007); 
    }
    v3[t]=v[1][1];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    while(n--){
    v[0][0]=0; v[0][1]=1; v[1][0]=1; v[1][1]=1; 
    v2[0][0]=0; v2[0][1]=1; v2[1][0]=1; v2[1][1]=1; 
        int t;
        cin >> t;
        v3.resize(t);
        if(t==0){
            cout << t<< endl;
            continue; 
        }
        setOn(t-1);
       cout <<v2[1][1]<< endl;
   
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         cout << v2[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    }
    return 0;
}