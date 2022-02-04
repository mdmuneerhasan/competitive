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
    //cin >>t;    while (t--)
    {   
       
       cin >>n1;
       vec1.clear();
       vec1.resize(n1,0);
       for(int q=0;q<n1;q++){
         cin >> vec1[q];
       }
       
       for(int i=0;i<100;i++){
           cout << i <<":"<<vec1[i] << ", ";
       }
       cout <<endl;
       
       
       
    }  
    return 0;
}