#include <stdio.h>
#include <iostream>
using namespace std;
// UVa - 10071
// Backk to HighSchool Physics

int main(){
	int v,t,d;

	while(scanf("%i %i", &v,&t) != EOF){
		d = v*t;
		cout << 2*d <<endl;
	}
}