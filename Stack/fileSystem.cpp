#include <bits/stdc++.h>
using namespace std;

string simplify_path(string &path){
	stack<string> directories;
	string current_component;

	for (auto c: path){

		if(c == '/'){
			if(!current_component.empty()){
				if(current_component == ".."){
					
					if(!directories.empty()){
						directories.pop();
					}
				}

				else if(current_component != "."){
					directories.push(current_component);
				}

				current_component = "";
			}
		}

		else{
				current_component +=c;
			}
	
		if(!current_component.empty()){
			if(current_component == ".."){
				if(!directories.empty()){
					directories.pop();
				}
			}
			else if(current_component == "."){
				directories.push(current_component);
			}
		}
	}

	string ansPath;
	while(!directories.empty()){
		ansPath  = directories.top() +'/' + ansPath ;
		directories.pop();
	}
	ansPath.pop_back();

return '/' + ansPath;
}

int main() {
	string path = "//home/foo///...////";
	cout<<simplify_path(path);
   return 0;
}
