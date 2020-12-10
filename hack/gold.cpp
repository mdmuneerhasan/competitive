/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 00:05:22 Sunday 12-April:2020
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
void signature(bool enable){
    if(!enable)return;
    cout << "Sunday 12-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec,primes;
int n,n1,n2,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   
        int row,col;vector<vector<int>> vec2;
        cin >>row ;
        col=row;
        vec2.clear();
        vec2.resize(row,vector<int>(col,0));
        
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> startPoint >> endPoint;

            vec2[startPoint-1][endPoint-1]=1;
        }

        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
              if(r)vec2[q][r]+=vec2[q][r-1];
          }
        }
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
              if(q)vec2[q][r]+=vec2[q-1][r];
          }
        }
        ans=0;
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
              ans=max(ans,
                    min(vec2[q][r],min(vec2[row-1][r]-vec2[q][r],
                    min(vec2[q][col-1]-vec2[q][r],
                    vec2[row-1][col-1]-vec2[row-1][r]-vec2[q][col-1]
                    +vec2[q][r]
                    ))));
          }
        }


        cout << ans<<endl;


          
          
          
    }
    return 0;
}