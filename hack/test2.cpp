/* This code is submitted by Muneer Hasan
<<<<<<< HEAD
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 23:09:32 Sunday 16-May:2021*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define N               100000
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int row,col;vector<vector<int>> vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,a=0,b=0;
    
    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }

    cin >>n2;
    vec2.clear();
    vec2.resize(n2,0);
    for(int q=0;q<n2;q++){
      cin >> vec2[q];
    }
    
    int m1=n1-1,m2=n2-1;


    int sum=0,carry=0;

    while(m1>=0 && m2>=0){
        sum=vec1[m1]+vec2[m2]+carry;

        carry+=sum/10;
        vec3.push_back(sum%10);

        m1--;
        m2--;
    }

    while(m2>=0){

        sum=vec2[m2]+carry;

        carry+=sum/10;
        vec3.push_back(sum%10);

        m2--;
    }

    
    while(m1>=0){
        sum=vec1[m1]+carry;
        carry+=sum/10;
        vec3.push_back(sum%10);
        m1--;
    }

    while(carry>0){
        vec3.push_back(carry%10);
        carry/=10;
    }

    for(int i=0;i<vec3.size();i++){
        cout <<vec3[vec3.size()-i-1] << " ";
    }
    cout <<endl;
    
    









=======
* Computer-science student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 19:28:55 Friday 04-December:2020*/
#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> vec){
    int ans=0;

    int r=vec.size();
    int c=vec[0].size();

    vector<int> maxVal(c,0);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            maxVal[j]=max(maxVal,vec[i][j]);
        }
    }


}

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    
    int row,col;vector<vector<int>> vec;
    cin >>row >> col;
    vec.clear();
    vec.resize(row,vector<int>(col,0));
    for(int q=0;q<row;q++){
      for(int r=0;r<col;r++){
        cin  >> vec[q][r];
      }
    }

    cout << solve(vec)<<endl;
    
    
>>>>>>> competitive/master
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}