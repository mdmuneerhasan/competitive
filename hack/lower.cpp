/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 18:00:21 Friday 03-April:2020
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
    cout << "Friday 03-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   
        string s;
        cin >> s;
        if(s[0]<='z'&&s[0]>='a'){
            for(int i=0;i<s.size();i++){
                if(!(s[i]<='z'&&s[i]>='a')){
                    cout << "Invalid"<<endl;
                    return 0;
                }
            }
            cout << "lowercase"<<endl;
            return 0;
        }else if(s[0]<='Z'&&s[0]>='A'){
            for(int i=0;i<s.size();i++){
                if(!(s[i]<='Z'&&s[i]>='A')){
                    cout << "Invalid"<<endl;
                    return 0;
                }
            }
            cout << "UPPERCASE"<<endl;
            return 0;
        }
          
                              cout << "Invalid"<<endl;

          
    }
    return 0;
}