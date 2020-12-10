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
vector<int> v;
int n1;
int row,col;
vector<vector<int>> arr2;
      
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      int n;
      //cin >> n;
      cin >>row >> col;
      arr2.resize(row+1,vector<int>(col+1,0));
      for(int q=1;q<=row;q++){
        for(int r=1;r<=col;r++){
          cin  >> arr2[q][r];
        }
      }
      
      vector<vector<int>> boysStart;
      boysStart.resize(row+1,vector<int>(col+1,0));
      for(int q=1;q<=row;q++){
        for(int r=1;r<=col;r++){
          boysStart[q][r]=arr2[q][r]+max(boysStart[q-1][r],boysStart[q][r-1]);
        }
      } 
      vector<vector<int>> boysE;
      boysE.resize(row+1,vector<int>(col+1,0));
      for(int q=row-1;q>0;q--){
        for(int r=col-1;r>0;r--){
          boysE[q][r]=arr2[q][r]+max(boysE[q+1][r],boysE[q][r+1]);
        }
      } 
      
      vector<vector<int>> girlStart;
      girlStart.resize(row+1,vector<int>(col+1,0));
      for(int q=1;q<=row;q++){
        for(int r=col-1;r>0;r--){
          girlStart[q][r]=arr2[q][r]+max(girlStart[q-1][r],girlStart[q][r+1]);
        }
      } 
      vector<vector<int>> girlE;
      girlE.resize(row+1,vector<int>(col+1,0));
      for(int q=row-1;q>0;q--){
        for(int r=1;r<col;r++){
          girlE[q][r]=arr2[q][r]+max(girlE[q+1][r],girlE[q][r-1]);
        }
      } 
      for(int q=0;q<=row;q++){
        for(int r=0;r<=col;r++){
          cout  << boysStart[q][r]<<" ";
        }
        cout <<endl;
      }
      cout << endl;
      
      int best=0;
      for(int q=1;q<row;q++){
        for(int r=1;r<col;r++){
            int ans1=boysStart[q-1][r]+boysE[q+1][r]+girlStart[q][r-1]+girlE[q][r+1];
            int ans2=boysStart[q][r-1]+boysE[q][r+1]+girlStart[q-1][r]+girlE[q+1][r];
            db(ans1,ans2);
            best=max(best,max(ans1,ans2));
        }
      }


      cout << best<<endl; 

    }
    return 0;
}   