#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// UVa - 272
// TeX Quotes

int main(){

	string entrada, s = "", h = "";
	int flag = 0;
	while(getline(cin,entrada)){
		for(int i = 0; i < entrada.size(); i++){
			char c = entrada[i];
			if(c == '"'){
				if(flag == 0){
					flag = 1;
					s+="``";
				}else{
					flag = 0;
					s+="''";
				}
			}else{
				s+=c;
			}
		}

	cout << s << "\n";
	s = "";
	}

	 

	return 0;
}