#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
vector<tuple<int,int,int>> arr;
void set2(){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){            
            if(get<0>(arr[j])<=get<1>(arr[i]) && get<1>(arr[j])<=get<1>(arr[i])){
                get<2>(arr[i])++;
            }
        }
    }
}
int find(){
    int c=0;
    int t=0;
    for(auto x : arr){
        if(!get<2>(x)){
            if(t<=get<0>(x)){
                t=get<1>(x);
            c++;
            }
        }
    }
    return c;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      int n;
      //cin >> n;
      int n1;
      cin >>n1;
      arr.resize(n1);
      for(int q=0;q<n1;q++){
          tuple<int,int,int>p;
        cin >> get<0>(p)>> get<1>(p);
        arr[q]=p;
      }
      sort(arr.begin(),arr.end());
      set2();

    //   for(int q=0;q<n1;q++){
    //     cout << q << ":" << get<0>(arr[q])<< ":" << get<1>(arr[q])<< ":" << get<2>(arr[q])<<",\n";
    //   }
      cout << find()<<endl;







    }
    return 0;
}