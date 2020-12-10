#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	stack<char> a;
	string s;
	cin>>s;
	int n=s.length();
    bool valid=true;
	for(int i=0;i<n;i++){
		if(s[i]=='('||s[i]=='{'||s[i]=='['){
		a.push(s[i]);
		}
		else{
            char x=a.top();
            if(x!='(' && s[i]==')'){
                valid=false;
                break;
            }
            if(x!='{' && s[i]=='}'){
                valid=false;
                break;
            }
            if(x!='[' && s[i]==']'){
                valid=false;
                break;
            }
		}
	}
        if(valid){
            cout << "Yes"<<endl;
        }else{
            cout << "No"<<endl;
        }
	

return 0;
}