/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 13:40:31 Wednesday 01-April:2020
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
    cout << "Wednesday 01-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<vector<string>> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int key;bool rev;string typ;
bool comp(vector<string> a,vector<string> b){
    return true;
    if(rev){
        if(typ=="numeric"){           
        return stoi(a[key-1])<stoi(b[key-1]);  
        }else{
        return a[key-1]<b[key-1];
        }

    }else{
        if(typ=="numeric"){           
        return stoi(a[key-1])>stoi(b[key-1]);  
        }else{
        return a[key-1]>b[key-1];
        }
    }
    return true;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    // cin >>t;    while (t--)
    {   
          cin >>n1;
          vec.clear();
          vec.resize(n1);
          string s;
          getline(cin,s);          
          for(int q=0;q<n1;q++){
            int j=0;
            getline(cin,s);
            stringstream ss(s);
            while(ss>>s)vec[q].push_back(s),j++;
            
          }
          cin >> typ;
          key=stoi(typ);
          cin >> typ;
          rev=(typ=="true");
          cin >> typ;

          sort(vec.begin(),vec.end(),comp);

          for(int q=0;q<n1;q++){
            for(int r=0;r<vec[q].size();r++){
              cout  << vec[q][r]<<" ";
            }
            cout <<endl;
          }
          cout << endl;
          
          
    }
    return 0;
}