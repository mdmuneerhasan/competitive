/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 14:22:23 Sunday 17-May:2020*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define F               first
#define S               second
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MP              make_pair
#define PII             pair<int, int>
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define INF             1e18
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
   
    int r,c;
    
    bool solve(vector<vector<char>>board,string word,int index,int i,int j){
        
        
        if(board[i][j]==word[index]){
            
            if(index+1==word.size()){
                return true;
            }
        
            if(j<c && board[i][j+1]==word[index+1]){
                if(solve(board,word,index+1,i,j+1))return true;
            }
            if(j>0 && board[i][j-1]==word[index+1]){
                if(solve(board,word,index+1,i,j-1))return true;
            }
            if(i<r && board[i+1][j]==word[index+1]){
                if(solve(board,word,index+1,i+1,j))return true;
            }
            if(i>0 && board[i-1][j]==word[index+1]){
                if(solve(board,word,index+1,i-1,j))return true;
            }
        }
        
        return false;
        
       
                
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        r=board.size();
        c=board[0].size();
        
        bool ans;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    ans=solve(board,word,0,i,j);
                    if(ans)return ans;
                }
            }
        }
        
       return ans;
    }
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    int row,col;vector<vector<char>> vec;
    cin >>row >> col;
    vec.clear();
    vec.resize(row,vector<char>(col));
    for(int q=0;q<row;q++){
      for(int r=0;r<col;r++){
        cin  >> vec[q][r];
      }
    }
    string s;
    cin >> s;

    cout <<exist(vec,s) <<endl;
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}