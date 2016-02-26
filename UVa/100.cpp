#include <iostream>
using namespace std;

// UVa - 100
// 3n + 1 Problem

int main(){
	
	int x,y,x0,y0;

	while(scanf("%i %i",&x0,&y0) != EOF){
		int maxCont = 0;
		int n = 0;

		if(x0 > y0){
			x = y0;
			y = x0;
		}else{
			x = x0;
			y = y0;
		}

		for (int i = x; i <= y; i++){
				int cont = 0;
				n = i;
				while(n != 1){
					cont++;
					if(n%2 == 1){
						n = 3*n +1;
					}else{
						n /= 2;
					}
				}
				cont++; 

				if(cont > maxCont){
					maxCont = cont;
				}
		}

		cout << x0 << " " << y0 << " " << maxCont << endl;
	}

	return 0;
}