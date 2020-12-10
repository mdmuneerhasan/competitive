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
#define MOD 1000000007
int m= 1000000007;
int power(int a,int p){
	if(p==0){
		return 1;
	}
	int ans=power(a,p/2)%MOD;
	ans=ans*ans;
	ans%=MOD;
	if(p&1){
		ans=ans*a;
		ans%=MOD;
	}
	return ans;
}

struct Node
{
	int val;
	int length;
	Node(){
		val=0;
		length=1;
	}
};
vector<Node> vec;
vector<int> lazy;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
void build(int start,int end,int node){
	if(start==end){
		return;
	}
	int mid=(start+end)/2;
	build(start,mid,2*node+1);
	build(mid+1,end,2*node+2);
	Node n1=vec[2*node+1];
	Node n2=vec[2*node+2];
	vec[node].length=n1.length+n2.length;
}
void update(int start,int end,int node,int left,int right,int val){
	if(lazy[node]!=-1){
		int x=lazy[node];
		vec[node].val=((power(2,vec[node].length)-1)*x)%MOD;

		if(start!=end){
			lazy[2*node+1]=x;
			lazy[2*node+2]=x;			
		}
		lazy[node]=-1;
	}
	if(start>right||end<left||end<start)return;
	if(start>=left && end<=right){
		vec[node].val=((power(2,vec[node].length)-1)%MOD*val)%MOD;

		if(start!=end){
			lazy[2*node+1]=val;
			lazy[2*node+2]=val;			
		}
		return;
	}
	// if(start==end){
	// 	vec[node].val=val;
	// 	return;
	// }
	int mid=(start+end)/2;
	update(start,mid,2*node+1,left,right,val);
	update(mid+1,end,2*node+2,left,right,val);
	Node n1=vec[2*node+1];
	Node n2=vec[2*node+2];
	
	vec[node].val=((vec[2*node+1].val%m
    *((int)power(2,vec[2*node+2].length))%m)%m
    +vec[2*node+2].val)%m;

    vec[node].length=vec[2*node+1].length+vec[2*node+2].length;
    

}
Node query(int start,int end,int node,int l,int r){
	Node n1,n2,n3;
	n1.length=0;
	if(lazy[node]!=-1){
		int x=lazy[node];
		vec[node].val=((power(2,vec[node].length)-1)*x)%MOD;
		if(start!=end){
			lazy[2*node+1]=x;
			lazy[2*node+2]=x;			
		}
		lazy[node]=-1;
	}
	if(start>r||end<l||end<start)return n1;
	if(start>=l && end<=r){
		return vec[node];
	}
	int mid=(start+end)/2;
	n1=query(start,mid,2*node+1,l,r);
	n2=query(mid+1,end,2*node+2,l,r);
    n3.val=((n1.val%MOD*((int)(power(2,n2.length))%MOD)%MOD
	+n2.val))%MOD;
	n3.length=n1.length+n2.length;
	return n3;
}


void print(int par=0,string indent="",string child=""){
	if(par>=vec.size())return;
	cout <<"\n"<<indent<<"`---("<<(vec[par].val);
	if(child.size()!=0)cout<<'{'<<par<<child<<"}";
	print(2*par+1,"\t"+indent,"l");
	print(2*par+2,"\t"+indent,"r");
	return;
}
void print2(int par=0,string indent="",string child=""){
	if(par>=vec.size())return;
	cout <<"\n"<<indent<<"`---("<<(lazy[par]);
	if(child.size()!=0)cout<<'{'<<par<<child<<"}";
	print2(2*par+1,"\t"+indent,"l");
	print2(2*par+2,"\t"+indent,"r");
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	//cin >>t;    while (t--)
	{
	  cin >>n1>>qry;
	  lazy.clear();
	  lazy.resize(4*n1+1,-1);
	  vec.clear();
	  vec.resize(4*n1+1);
	  build(0,n1-1,0);


	  int l,r,val,index,cse=1;
	  while(qry--){
		 cin >> cse>>l>>r;
		 switch(cse){
		 case 0:
		 update(0,n1-1,0,l,r,0);
		 break;
		 case 1:
		 update(0,n1-1,0,l,r,1);	  
		 break;
		 case 2:
		 ans=query(0,n1-1,0,l,r).val;	  
		 cout << ans<<endl;
		 break;
		  }

		//   print();
		//   print2();
		  
	  }


	  

	}
	return 0;
}