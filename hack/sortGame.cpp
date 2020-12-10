#include<bits/stdc++.h>
using namespace std;
int b;
bool cmp(pair<int,string> a,pair<int,string> b)
{
    if(a.first==b.first)
    {
    return a.second>b.second;
    }
         return a.first<b.first;
    
}
void pairsort(int *a,string *s,int n)
{
    pair<int,string> x[n];
     for(int i=0;i<n;i++)
     {
         x[i].first=a[i];
         x[i].second=s[i];
     }
     sort(x,x+n,cmp);
     for (int i = 0; i < n; i++)  
    { 
        a[i] = x[i].first; 
        s[i] = x[i].second; 
    }
    for(auto x:x){
        cout << x.first <<":"<<x.second<<endl;
    }
    cout <<endl; 
    for (int i = n-1; i>=0; i--)  
    { 
       if(a[i]>b)
       {
           cout<<s[i]<<" "<<a[i]<<endl;
       }
    } 
}
int main() {
	int n;
	cin>>b;
	cin>>n;
	string s[n];
    int a[n];
    for(int i=0;i<n;i++)
	{
		cin>>s[i]>>a[i];
	}
    pairsort(a,s,n);
	return 0;
}