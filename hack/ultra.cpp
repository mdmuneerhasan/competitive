#include <iostream>
using namespace std;
int main() {
    string s1,s2,s3="";
    int i,j,t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        s3="";
    cin>>s1>>s2;
    for(i=0;i<s1.length();i++)
    {
        if(s1[i]==s2[i])
        s3=s3+"0";
        else 
        s3=s3+"1";
    }
    cout<<s3<<endl;
    }
    return 0;
}
