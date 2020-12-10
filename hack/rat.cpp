#include<bits/stdc++.h>
using namespace std;
#define int long long int
int row,col;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<vector<char>> arr2;
void go(int r,int c){
    if(r==row-1&&c==col-1){
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
              if(arr2[q][r]=='1')
            cout  << 1<<" ";
            else
            {
                cout<<0<<" ";
            }
          }
          cout <<endl;
        }
        return ;
    }

    // move right
    if(c+1<col && arr2[r][c+1]=='O'){
        arr2[r][c+1]='1';
        go(r,c+1);
        arr2[r][c+1]='0';
    }
    // move down
    if(r+1<row && arr2[r+1][c]=='O'){
        arr2[r+1][c]='1';
        go(r+1,c);
        arr2[r+1][c]='0';
    }
    // move left
    if(c>0 && arr2[r][c-1]=='O'){
        arr2[r][c-1]='1';
        go(r,c-1);
        arr2[r][c-1]='0';
    }
    // move up
    if(r>0&& arr2[r-1][c]=='O'){
        arr2[r-1][c]='1';
        go(r-1,c);
        arr2[r-1][c]='0';
    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>row >> col;
        arr2.resize(row,vector<char>(col,0));
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cin  >> arr2[q][r];
          }
        }   
        arr2[0][0]='1';
      go(0,0);



}
    return 0;
}