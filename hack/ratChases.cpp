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
unordered_map<int,unordered_map<int,char>> arr2;
int row,col;
bool solve(int i,int j){
    if(i==row-1&&j==col-1){
        arr2[i][j]='1';
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
              if(arr2[q][r]=='1')
            cout  << arr2[q][r]<<" ";
            else
            cout  << 0<<" ";
          }
          cout <<endl;
        }
        cout << endl;
        return true;
        }
    if((arr2[i][j]!='1')){
        arr2[i][j]='1';
        if(j>0)
        if(arr2[i][j-1]!='X'){
            if(solve(i,j-1))
            return true;
        }
        if(j<col-1)
        if(arr2[i][j+1]!='X'){
            if(solve(i,j+1))
            return true;
        }
 
        if(i>0)
        if(arr2[i-1][j]!='X'){
            if(solve(i-1,j))
            return true;
        }
 
        if(i<row-1)
        if(arr2[i+1][j]!='X'){
            if(solve(i+1,j))
            return true;
        }
        arr2[i][j]='0';
    }
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>row >> col;
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cin  >> arr2[q][r];
          }
        }
        bool x=solve(0,0);
        if(!x)cout << "NO PATH FOUND"<<endl;

    
    }
    return 0;
}