#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
struct Node{
  int safe,time,reqTime;
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      int p;
      cin >> p;
      int n1;
      cin >>n1;
      vector<Node> arr(n1);
      for(int q=0;q<n1;q++){
        cin >> arr[q].reqTime;
        arr[q].safe = arr[q].reqTime;
        arr[q].time = 0;
      }
      int time=0,barrier,discover;
      while(p){
        time++;
        for(int i=0;i<n1;i++){
          while(arr[i].reqTime+arr[i].time<=time){
            p--;
            arr[i].time=arr[i].reqTime+arr[i].time;
            arr[i].reqTime+=arr[i].safe;
            if(p==0){
              cout << time<<endl;
              return 0;
            }


          }

        }


      }
    }
    return 0;
}