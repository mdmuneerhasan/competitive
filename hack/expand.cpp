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
vector<vector<int>> arr2;
vector<vector<int>> comp;
unordered_map<int,int> cnt;
int n1,q,qry,ans=0;
int row,col;
    
void show(){
    for(int q=0;q<comp.size();q++){
      for(int r=0;r<comp[0].size();r++){
        cnt[comp[q][r]]++;
      }
    }
    cnt[0]=0;

    

    for(int q=0;q<arr2.size();q++){
      for(int r=0;r<arr2[0].size();r++){
        if(arr2[q][r]==0){
            unordered_map<int,int> cntL;
            if(q>0){
                cntL[comp[q-1][r]]=cnt[comp[q-1][r]];
            }
            if(q<row-1){
                cntL[comp[q+1][r]]=cnt[comp[q+1][r]];
            }
            if(r>0){ 
                cntL[comp[q][r-1]]=cnt[comp[q][r-1]];
            }
            if(r<col-1){
                cntL[comp[q][r+1]]=cnt[comp[q][r+1]];
            }

            int s=0;
            for(auto x:cntL){
                s+=x.second;
            }
            ans=max(ans,s);
            
        }
      }
    }


}
void connect(int rowL,int colL,int compName){
    if(comp[rowL][colL])return;
    comp[rowL][colL]=compName;
    if(rowL<row-1 && arr2[rowL+1][colL]){
        connect(rowL+1,colL,compName);
    }
    if(rowL>0 && arr2[rowL-1][colL]){
        connect(rowL-1,colL,compName);
    }
    if(colL<col-1 && arr2[rowL][colL+1]){
        connect(rowL,colL+1,compName);
    }
    if(colL>0 && arr2[rowL][colL-1]){
        connect(rowL,colL-1,compName);
    }
}
void connected(){
    int x=2;
    for(int q=0;q<arr2.size();q++){
      for(int r=0;r<arr2[0].size();r++){
        if(arr2[q][r]==1&&comp[q][r]==0){
            connect(q,r,x++);
        }
      }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        
        cin >>row >> col;
        arr2.resize(row,vector<int>(col,0));
        comp.resize(row,vector<int>(col,0));
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cin  >> arr2[q][r];   
          }
        }
        connected();
        show();
        cout << ans+1<<endl;


      
    }
    return 0;
}