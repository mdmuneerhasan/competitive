#include<bits/stdc++.h>
using namespace std;
stringstream vin ,vout;
string st;

int n,n1,n2,q=0,ans=0,cnt=0;
unordered_map<char,string> production;
unordered_map<string,string> productionAns;
unordered_map<char,unordered_map<char,vector<string>>> parsingTable;
unordered_map<char,int> visited;
unordered_map<char,unordered_map<string,int>> visited2;
unordered_map<char,set<char>> first,follow,first2;
vector<char> Variables;
void removeLeftRecursion();

char getNextVariable(char par){
	while(production.count(par))par++;
	return par;
}
vector<string> getTerms(string x){
	vector<string> terms;
	string temp="";
	for(int i=0;i<=x.size();i++){
		if(x[i]=='|'||x[i]=='\0'){
			terms.push_back(temp);
			temp="";
		}else{
			temp+=x[i];
		}
	}
	return terms;
}

bool check(string start ,char p,unordered_map<char,int> V ){
	if(p==start[0]||V[start[0]])return false;
	V[start[0]]=1;
	if(production.count(start[0])){
		auto x=production[start[0]];
		vector<string> terms=getTerms(x);
		bool ans=1;
		for(auto y:terms){
			ans&=check(y,start[0],V);
		}
		return ans;
	}
	return true;
}
void leftFactoring(){
	for(auto x:production){
		vector<string> terms=getTerms(x.second);
		for(int i=0;i<terms.size();i++){
			for(int j=i+1;j<terms.size();j++){
				if(terms[i][0]==terms[j][0]){
					string common="";
					int k=0;
					while(terms[i][k]==terms[j][k]){
						common+=terms[i][k];
						k++;
					}
					char next=getNextVariable(x.first);
					production[x.first]=common+next;
					for(int l=0;l<terms.size();l++){
						if(!(l==i||l==j)){
						production[x.first]+="|"+terms[l];
						}
					}
					bool ep=false;
					Variables.push_back(next);
					string temp=terms[i].substr(common.size());
					if(temp.size()>0){
					production[next]+=temp;
					}else{
						ep=true;
					}
					temp=terms[j].substr(common.size());
					if(temp.size()){
					if(production[next].size()>0)	
					production[next]+="|";
					production[next]+=temp;
					}else{
						ep=true;
					}
					if(ep)production[next]+="|#";

					leftFactoring();
					return;
				}
			}
		}

	}
}
void removeLeftHelper(string right,char par,unordered_map<char,int> vis){
	if(par==right[0]){
		char next=getNextVariable(par);
		vector<string> terms=getTerms(production[par]);
		string recurr="";
		production[par]="";
		for(auto term:terms){
			if(term[0]==par){
				recurr=term;
			}else{
				if(production[par].size())production[par]+='|';
				production[par]+=term+next;
			}
		}
		production[next]=recurr.substr(1)+next+"|#";
		Variables.push_back(next);
		if(production[par].size()==0)production[par]+=next;		

	}else if(vis.count(right[0])){
		vector<string> add=getTerms(production[right[0]]);
		vector<string> terms=getTerms(production[par]);
		string temp="";
		for(auto x:terms){
			if(x==right){
				for(auto y:add){
					if(temp.size())temp+='|';
					temp+=y+right.substr(1);	
				}
			}else{
			if(temp.size())temp+='|';
			temp+=x;
			}
		}
		production[par]=temp;
		removeLeftRecursion();
	}else if(production.count(right[0])){
		vector<string> terms=getTerms(production[right[0]]);
		for(auto y:terms){
			vis[right[0]]=1;
			removeLeftHelper(y,right[0],vis);
		}

	}
}
void removeLeftRecursion(){
	for(int i=0;i<Variables.size();i++){
		auto x=production[Variables[i]];
		vector<string> terms=getTerms(x);
		for(auto y:terms){
			unordered_map<char,int> vis;
			vis[Variables[i]]=1;
			removeLeftHelper(y,Variables[i],vis);
		}
	}
}
void removeEpsilon(){
	for(auto x : production){
		for(int i=0;i<x.second.size();i++){
			if(x.second[i]=='#'){
				for(auto y:production){
					vector<string> terms=getTerms(y.second);
					string newVal="";
					bool epsilon=false;
					for(int d=0;d<terms.size();d++){
						auto z=terms[d];
						newVal="";
						for(int i=0;i<z.size();i++){
							if(z[i]==x.first){
								if(z.size()==1){epsilon=1;}
								else{
									newVal=z;
									newVal.erase(newVal.begin()+i);
									terms.push_back(newVal);
								}
							}
						}
					}
					if(epsilon)terms.push_back("#");
					newVal="";
					unordered_map<string,int> mk;
					for(int i=0;i<terms.size();i++){
						if(mk[terms[i]]==0)
						{if(i)newVal+='|';
						newVal+=terms[i];
						}
						mk[terms[i]]=1;
					}
					production[y.first]=newVal;
				}
				production[x.first].erase(production[x.first].begin()+i);
				if(i &&x.second[i-1]=='|')
				production[x.first].erase(production[x.first].begin()+i-1);
				removeEpsilon();
				return ;
			}
		}
	}
}
set<char> getFirst(char left){
	if(visited[left])return first[left];
	visited[left]=1;
	set<char> s;
	bool ft=true;				
	string right=production[left];
	for(int i=0;i<=right.size();i++){
        if(right[i]=='|' || right[i]=='\0'){
            if(ft)s.insert('#');
			ft=true;
		}else{
			if(production.count(right[i])==0){
				if(ft){
				s.insert(right[i]);
				ft=false;}
			}else if(left!=right[i]){
				if(ft){
					ft=false;
					set<char> s2=getFirst(right[i]);
					for(auto x :s2){
						if(x!='#'){
						s.insert(x);
						}else{
							ft=true;
						}
					}
				}
			}
		}
	}
	return first[left]=s;
}
set<char> getFollow(char left){
	
	if(visited[left])return follow[left];
	visited[left]=1;
	set<char> s;
	if(Variables[0]==left){
		s.insert('$');
	}
    
	for(auto pro:production){
		auto right=pro.second;
		bool ft=false;
		for(int i=0;i<=right.size();i++){
			if(ft){	
				if(right[i]=='\0' || right[i]=='|'){
					set<char> fol=getFollow(pro.first);
					for(auto el:fol)s.insert(el);
					ft=false;
				}else{
					if(production.count(right[i])==0&& right[i]!='#'){
						s.insert(right[i]);
						ft=false;
					}else{
						ft=false;
					set<char> fir=first[right[i]];
						for(auto el:fir){
						if(el=='#'){
							ft=true;
						}else{
							s.insert(el);
						}
						}
					}
				}
			}
			if(right[i]==left){
				ft=true;
			}
		}
	}
	return follow[left]=s;
}

set<char> getFirst(char left,string right){
	if(visited2[left][right])return first2[left];
	visited2[left][right]=1;
	set<char> s;
	bool ft=true;				
	for(int i=0;i<=right.size();i++){
        if(right[i]=='\0'){
            if(ft)s.insert('#');
		}else{
			if(production.count(right[i])==0){
				if(ft){
				s.insert(right[i]);
				return s;
				}
			}else if(left!=right[i]){
				if(ft){
					ft=false;
					set<char> s2=getFirst(right[i]);
					for(auto x :s2){
						if(x!='#'){
						s.insert(x);
						}else{
							ft=true;
						}
					}
				}
			}
		}
	}
	return first2[left]=s;
}

string s;
int sz=0;
void read(string path){
		ifstream fin(path);
		string line;
		while (getline(fin,line))
		{
			stringstream kin(line);
			while(kin>>s){
				vin<<s+" ";
				sz++;
			}
		}
		fin.close();
}
void write(string path){
		ofstream fout(path);
		fout<<vout.str();
		fout.close();
}

int32_t main(){
	int t;
	{	
        // input file path
		read("../input");
		vout << "Name : Muneer Hasan"<<endl;
		vout << "Roll No.: 17BCS054"<<endl;
		vout << "\nNote : - Use # for epsilon"<<endl;
	  	vout << "enter number of production\n"<<endl;
		vin >> n;
		string left; string op,right;
		for(int i=0;i<n;i++){
			vin >>left>>op >> right;
			production[left[0]]=right;
			productionAns[left]=right;
			Variables.push_back(left[0]);
		}
		visited.clear();
		visited2.clear();
		for(auto x:Variables){
			first[x]=getFirst(x);
		}
		visited.clear();
		visited2.clear();
		int t=0;
		for(auto x:Variables){
			follow[x]=getFollow(x);
		}
        bool ll1=true;
         
        for(char x1:Variables){
            string right=production[x1];
            vector<string> terms=getTerms(right);
			visited.clear();
			visited2.clear();

            for(int i=0;i<terms.size();i++){

					st="";
					st+=x1;
					st+=" -> "+terms[i];
                if(terms[i]=="#"){
                    for(auto y:follow[x1]){
                    parsingTable[x1][y].push_back(st);
              		}
                }else{
                    set<char> y;
					y=getFirst(x1,terms[i]);
					for(auto z:y){
						if(z=='#'){
							for(auto y1:follow[x1]){
							parsingTable[x1][y1].push_back(st);
							}
						}else{
							parsingTable[x1][z].push_back(st);
						}
					}
                }
            }
        }

        for(auto x:parsingTable){
			for(auto y:x.second){
				if(y.second.size()>1){;ll1=false;}
				for(string z:y.second){
				}
			}
        }
		// check for left rec
		
			for(auto x:production){
				vector<string> terms=getTerms(x.second);
				for(auto y:terms){
					unordered_map<char,int> visited;
					visited[x.first]=1;
					ll1=ll1&check(y,x.first,visited);
				if(!ll1){
					vout << "Grammar has left recursion"<<endl;
					break;
					}
				}
				if(!ll1)break;
			}
		
        if(ll1){
            vout << "Grammar is suitable for LL(1)"<<endl;
        }else{
			vout << "Grammar is not suitable for LL(1)"<<endl;
			removeEpsilon();
			removeLeftRecursion();

			vout <<"Grammar after conversion to suitable LL(1)"<<endl;
			for(int i=0;i<Variables.size();i++){
				vout <<Variables[i]<<" -> "<<production[Variables[i]] <<endl;
			}
			vout <<endl;
        }
	}
	write("../output");
	return 0;
}