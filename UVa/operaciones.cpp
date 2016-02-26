#include <iostream>
using namespace std;

int main(){

	int x,y;

	while(scanf("%i %i", &x, &y) != EOF){
		cout << endl;
		cout << x << " + "<< y <<": " << x + y << endl;
		cout << x << " - "<< y <<": " << x - y << endl;
		cout << x << " * "<< y <<": " << x * y << endl;
		cout << x << " / "<< y <<": " << x / y << endl;
		cout << x << " & "<< y <<": " << (x & y) << endl;
		cout << x << " | "<< y <<": " << (x | y) << endl;
		cout << x << " ^ "<< y <<": " << (x ^ y) << endl;
		cout << "~" << x <<": " << ~x << endl;
		cout << "~" << y <<": " << ~y << endl;
		cout << x << " >> "<< y <<": " << (x >> y) << endl;
		cout << x << " << "<< y <<": " << (x << y) << endl;
	}

}