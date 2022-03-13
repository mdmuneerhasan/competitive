#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<auto> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
typedef long long int lli;
class Solution {
public:
   vector<string>findRepeatedDnaSequences(string s) {
      vector <string> ret;
      int n = s.size();
      set <int> visited;
      set <int> visited2;
      map <char, int> bitVal;
      bitVal['A'] = 0;
      bitVal['C'] = 1;
      bitVal['G'] = 2;
      bitVal['T'] = 3;
      lli mask = 0;
      for(int i = 0; i < n; i++){
         mask <<= 2;
         mask |= bitVal[s[i]];
         mask &= 0xfffff;
         if(i < 9) continue;
         if(visited.count(mask) && !visited2.count(mask)){
            ret.push_back(s.substr(i - 9, 10));
            visited2.insert(mask);
         }
         visited.insert(mask);
      }
      return ret;
   }
};
main(){
   Solution ob;
   print_vector(ob.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
}