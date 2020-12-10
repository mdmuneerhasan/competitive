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
string s;
bool isValid(int i1,int i2,int i3){
    int n1=stoi(s.substr(i1,i2-i1));
    int n2=stoi(s.substr(i2,i3-i2));
    string n3=to_string(n1+n2);
    int i3kept=i3;
    while(s[i3]=='0')i3++;
    int i=0;
    while (n3[i]&&s[i3]&&n3[i]==s[i3])i3++,i++;
    if(s[i3]=='\0'){
        if(n3[i]=='\0')return true;
        return false;
    }
    if(n3[i]=='\0'){
        return isValid(i2,i3kept,i3);
    }

    return false;
   
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        bool valid=false;
        cin >> s;
        n=s.size();
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isValid(0,i,j)){
                    cout << "true"<<endl;
                    valid=true;
                    break;
                }

            }
            if(valid)break;
        }
        if(!valid){
            cout << "false"<<endl;
        }
      
    }
    return 0;
}