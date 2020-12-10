#include<bits/stdc++.h>
using namespace std;
bool cb(int a)
{
	if(a==0 || a==1)
	   return false;
	else if(a==2||a==3||a==5||a==7||a==11||a==13||a==17||a==19||a==23||a==29)
        return true;
	else if(a%2==0||a%3==0||a%5==0||a%7==0||a%11==0||a%13==0||a%17==0||a%19==0||a%23==0||a%29==0)
		return false;
        return true;
}
string s;
int n;

int subString(int startIndex, int endIndex){
    if(startIndex==n)return 0;
  
    if(endIndex==n)return subString(startIndex+1,startIndex+1);
  
    if(cb(stoi(s.substr(startIndex,endIndex-startIndex+1)))){
        return subString(endIndex+1,endIndex+1)+1;
    }else if(startIndex<endIndex){
        return max(subString(startIndex,endIndex+1),subString(startIndex+1,endIndex));
    }
    else{
        return subString(startIndex,endIndex+1);
    }
    
}
int main() {
	cin>>n;
	cin>>s;
	int ans=subString(0,0);
    cout << ans<<endl;
	return 0;
}