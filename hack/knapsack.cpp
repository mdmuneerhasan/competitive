/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 14:26:58 Thursday 28-April:2022*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define F               first
#define S               second
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MP              make_pair
#define PII             pair<int, int>
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define INF             1e18
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int row,col;vector<vector<int > > vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;
unordered_map<int,int> dp[1000];
int solve(int ind,int w){
	if(ind==n1){
		return 0;
	}

	if(dp[ind][w])return dp[ind][w];

	int a=0;
	if(w>=vec1[ind]){
		a = solve(ind+1,w-vec1[ind])+vec2[ind];
	}

	return dp[ind][w] = max(a,solve(ind+1,w));

}
void Muneer(){
	int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
	
	cin >>n1>>k;
	vec1.clear();
	vec1.resize(n1,0);
	for(int q=0;q<n1;q++){
	  cin >> vec1[q];
	}

	n2=n1;
	vec2.clear();
	vec2.resize(n2,0);
	for(int q=0;q<n2;q++){
	  cin >> vec2[q];
	}

	cout << solve(0,k)<<endl;
	
	
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t=1;
	// cin >>t;    
	while (t--)Muneer();
	return 0;
}