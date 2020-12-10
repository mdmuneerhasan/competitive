#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void recur(string constructed,string unprocessed){
    if(unprocessed.size()<1){
        cout << constructed<<endl;
        return ;
    }
    int i=unprocessed[0]-'0';
    string s=table[i];
    for(int i=0;i<s.size();i++){
        recur(constructed+s[i],unprocessed.substr(1));
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      int n;
      //cin >> n;
      string s;
      cin >>s;
      recur("",s);
    }
    return 0;
}