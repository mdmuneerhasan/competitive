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
  string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
  char keyPad [][4] = {
      {' ',' ',' ',' '},{' ',' ',' ',' '},{'a','b','c',' '},{'d','e','f',' '},{'g','h','i',' '},
      {'j','k','l',' '},
      {'m','n','o',' '},{'p','q','r',' '},{'s','t','u','v'},{'w','x','y','z'}

    };
    void go(string s,string pat){
        if(s.size()==0){
            for(int i=0;i<11;i++){
              string sear=searchIn[i];
              int j=0,k=0;
              bool flag=false;
                // db(sear,pat);
              while(sear[j]){
                if(sear[j]==pat[k]){
                  k++;
                  if(!pat[k]){
                    flag=true;
                    break;
                  }
                }else{
                  k=0;
                }
                j++;
              }
              if(flag){
                cout << sear<<endl;
              }

            }
            // cout << pat<<endl;
            return;
        }
        int x=s[0]-'0';
        for(int i=0;i<4;i++){
            go(s.substr(1),pat+keyPad[x][i]);
        }

    }
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      string s;
      cin >> s;
      go(s,"");
      
    }
    return 0;
}