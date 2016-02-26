#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// UVa - 458
// The Decoder

int main(){

	string s, h ="";
	while(getline(cin,s)){
		for(int i = 0; i < s.size(); i++){
			char c = s[i];
			c -= 7;
			h+= c;
		}
		cout << h << "\n";
		h = "";

	}	 

	return 0;
}