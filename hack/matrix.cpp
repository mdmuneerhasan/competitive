#include<iostream>
using namespace std;
int main(){
  int m,n;
  cin>>m>>n;
  int a[m][n];
  for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
      cin>>a[i][j];
  }
  }
  int k;
  cin>>k;
  bool flag=false;
  for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){   
      if(a[i][j]==k){
       cout << 1<<endl;
       return 0;
      }
      
  }
  }
  cout << 0<<endl;
 return 0;
}