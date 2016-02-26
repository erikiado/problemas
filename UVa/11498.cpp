#include <iostream>
using namespace std;

// UVa - 11498
// Division of Nlogonia

int main(){
	int k=0, x=0, y=0,e=0,l=0;
/*
	for(int i = 0; i < 1000; i++){
		e[i] = l[i] = 0;
	}
*/
	cin >> k;

	while(k != 0){
		scanf("%i %i",&x,&y);
		for (int i = 0; i < k; i++){
			scanf("%i %i",&e,&l);
			if(e < x && l < y){
				cout << "SO\n"; 
			}else if(e < x && l > y){
				cout << "NO\n"; 
			}else if(e > x && l < y){
				cout << "SE\n"; 
			}else if(e > x && l > y){
				cout << "NE\n"; 
			}else{
				cout << "divisa\n";
			}
		}

		scanf("%i", &k);
	}


}