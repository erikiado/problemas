#include <iostream>
#include <stdio.h>
using namespace std;

//UVa - 10055
//Hashmat the Brave Warrior

int main(){

	unsigned long int x,y;

	while(scanf("%li %li",&x,&y) != EOF){
		cout << labs(y-x) << "\n";
	}

	return 0;
}	