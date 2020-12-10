#include<bits/stdc++.h>
using namespace std;
stringstream vin,vout;
string s,st;
int sz=0;

int n,n1,n2,q=0,ans=0,cnt=0;
unordered_map<char,string> production;
unordered_map<char,unordered_map<char,vector<string>>> parsingTable;

unordered_map<char,int> visited;
unordered_map<char,set<char>> first,follow;
vector<char> Terminals;
set<char> getFirst(char left){
	if(first[left].size()>0)return first[left];
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
	if(Terminals[0]==left){
		s.insert('$');
	}
    
	for(auto pro:production){
		auto right=pro.second;
		bool ft=false;
		for(int i=0;i<=right.size();i++){
			if(right[i]==left){
				ft=true;
			}else if(ft){	
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
				
			
		}
	}
	return follow[left]=s;
}
set<char> getFirst(char left,string right){
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
	return first[left]=s;
}

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
		read("..input");
		cout<< "Name : Muneer Hasan"<<endl;
		cout<< "Roll No.: 17BCS054"<<endl;
		cout<< "\nNote : - Use # for epsilon"<<endl;
	  	cout<< "enter number of production\n"<<endl;
		vin >> n;
		char left; string op,right;
		for(int i=0;i<n;i++){
			vin >>left>>op >> right;
			production[left]=right;
			Terminals.push_back(left);
		}
		cout<< "\nfirst of given grammar"<<endl;
		for(auto x:Terminals){
			first[x]=getFirst(x);
			cout<< x <<" => { ";
			for(auto y:first[x]){
				cout<< y << ", ";
			}
			vout<<" } "<<endl;
		}
		cout<<endl;
		cout<< "follow of given grammar"<<endl;
		visited.clear();
		int t=0;
		for(auto x:Terminals){
			follow[x]=getFollow(x);
			cout<< x <<" => { ";
			for(auto y:follow[x]){
				cout<< y << ", ";
			}
			vout<<" } "<<endl;
		}
		cout<<endl;
        write("../output");
	}
	return 0;
}