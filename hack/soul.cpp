/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 23:55:10 Wednesday 08-April:2020
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
    cout << "Wednesday 08-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
string st;
long long pw[1<<20];
unordered_set <long long> S;
long long s[1<<20];
 
int check(int span)
{
	S.clear();
	for (int i=0;i+span<=st.size();i++)
	{
		long long Q=s[i+span]-s[i];
		Q*=pw[1000000-i];
		if (S.find(Q)!=S.end())
			return true;
		S.insert(Q);
	}
	return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   

        cin>>st;
        pw[0]=1;
        for (int i=1;i<=1000000;i++)
            pw[i]=pw[i-1]*173;   
        for (int i=1;i<=st.size();i++)
            s[i]=s[i-1]+st[i-1]*pw[i-1];
        int l,r;
        l=0;
        r=st.size();
        while (l<r)
        {
            int mid=l+r+1;
            mid/=2;
            if (check(mid))
                l=mid;
            else
                r=mid-1;
        }
        
        cout<<l<<endl;

          
    }
    return 0;
}