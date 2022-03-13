#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<string>v;

void permu( string a ,string out)
{

   //Base case
   if(a.length()==0)
   {

	   cout<<out<<" ";
        // v.push_back(out);
	   return;
   }

	for(int i=0;i<a.length();i++)
	{
		string  choti= a.substr(0,i)+a.substr(i+1);
		 permu(choti,out+a[i]);
	}
}

int main()
{
	string a;

	getline(cin,a);
    // sort(a.begin(),a.end());
	permu(a,"");


    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
