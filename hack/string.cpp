#include<bits/stdc++.h> 
using namespace std; 
vector<int> vstr(256,0);
vector<int> vpat(256,0);
const int no_of_chars = 256; 
string findSubString(string str, string pat) 
{ 
	int len1 = str.length(); 
	int len2 = pat.length(); 
	if (len1 < len2) 
	{     
		return ""; 
	} 
        for(int i=0;i<=len2;i++){
            vpat[pat[i]]++;
        }
        
    int start=0,end=0;
    int r=0,l=0;
    bool matched=false;
    int minLength=len1;
    while(str[r] && l<=r){
        
        matched=true;
        for(int i=0;i<len2;i++){
            if(vpat[pat[i]]>vstr[pat[i]]){
            //    cout <<pat[i]<<":"<<pat[i]<<"-"<<
            //    vpat[pat[i]]<<":"<<vstr[pat[i]]<<", ";
                matched=false;
                break;
            }
        }
        if(!matched){
            vstr[str[r]]++;
            r++;
        }else{
            if(r-l<minLength){
                minLength=r-l;
                start=l;
                // cout <<minLength<<" ";
            }
            // cout <<"matched at "<<l<<"-"<<r<<"\n";
            vstr[str[l]]--;
            l++;
        }
    }
    return str.substr(start,minLength);
} 

int main() 
{  string str,pat;
	getline(cin ,str);
	getline(cin ,pat);
	cout << findSubString(str, pat); 
	return 0; 
} 
