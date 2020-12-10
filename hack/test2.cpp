/* This code is submitted by Muneer Hasan
* Computer-science student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 19:28:55 Friday 04-December:2020*/
#include<bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> vec){
    int ans=0;

    int r=vec.size();
    int c=vec[0].size();

    vector<int> maxVal(c,0);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            maxVal[j]=max(maxVal,vec[i][j]);
        }
    }


}

void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    
    int row,col;vector<vector<int>> vec;
    cin >>row >> col;
    vec.clear();
    vec.resize(row,vector<int>(col,0));
    for(int q=0;q<row;q++){
      for(int r=0;r<col;r++){
        cin  >> vec[q][r];
      }
    }

    cout << solve(vec)<<endl;
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}