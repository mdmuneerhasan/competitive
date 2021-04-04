#include<bits/stdc++.h>
using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<vector<int>> vec1,vec2,vec3,primes;
int row,col;vector<vector<int>> vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;

string s, s1 ,s2;
vector<pair<int,int>> forw,back;
unordered_map<int,vector<vector<int>>> ans;

void solve(int i,int j){
  if(i==forw.size()){
    return;
  }
  if(j==back.size()){
    return;
  }
  solve(i,j+1);

  solve(i+1,j+1);

}

vector<vector<int>> applicationPairs(int deviceCapacity,vector<vector<int>> foregroundAppList,vector<vector<int>> backgroundAppList){

    for(int i=0;i<foregroundAppList.size();i++){
      forw.push_back({foregroundAppList[i][1],foregroundAppList[i][0]});
    }
   for(int i=0;i<backgroundAppList.size();i++){
      back.push_back({backgroundAppList[i][1],backgroundAppList[i][0]});
    }

    sort(forw.begin(),forw.end());
    sort(back.begin(),back.end());

    int szb=back.size();

    int j=szb-1;

    
    for(int i=0;i<forw.size();i++){
      while(forw[i].first+back[j].first<deviceCapacity && i<=forw.size())i++;
      i--;
      while(forw[i].first+back[j].first>deviceCapacity && j>=0)j--;

      if(j>=0){
        ans[forw[i].first+back[j].first].push_back({forw[i].second,back[j].second});
        j--;
      }else{

      }
    }

    for(int i=deviceCapacity;i>=0;i--){\
      db(i);
      if(ans.count(i)>0)return ans[i];
    }

    return ans[deviceCapacity];

}
void Muneer(){
  
    cin >>k;

    cin >>n1;
    for(int q=0;q<n1;q++){
      cin >> stt>>ent;
      vec1.push_back({stt,ent});
    }
    
    cin >>n2;
    
    for(int q=0;q<n2;q++){
      cin >> stt>>ent;
      vec2.push_back({stt,ent});
    }
    vector<vector<int>> ans= applicationPairs(k,vec1,vec2);
    
    for(int q=0;q<ans.size();q++){
      for(int r=0;r<2;r++){
        cout  << ans[q][r]<<" ";
      }
      cout <<endl;
    }
    cout << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}