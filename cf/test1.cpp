#include<iostream>
#include<vector>
#include<iostream>
#include<iostream>

using namespace std;

int n,n1,n2,q=0,ans=0,cnt=0;
vector<int> vec1;
int32_t main(){
   int t;
   //signature(true);
    cin >>t;    while (t--)
    {   
       
       cin >> n >>n1 >> n2;
       if(n1>=n && n1>=n2){
        cout << "Yes"<<endl;
       }else{
        cout << "No"<<endl;
       }
       
       
    }  
    return 0;
}