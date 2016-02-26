#include <iostream>

using namespace std;

// UVa - 10114
// Loansome Car Buyer

//depreciation records
struct record{
	int mes;
	double p;
};

//prestamo
struct loan{
	int duracion, deprRecords;
	double pago, total;
	struct record records[100];
};


int main(){

	struct loan l;
	double cliente,carro;

	scanf("%i %lf %lf %i",&l.duracion,&l.pago,&l.total,&l.deprRecords);

	while(l.duracion > 0){

		int m = 0;

		
		for(int i = 0; i < l.deprRecords; i++){
			scanf("%i %lf",&l.records[i].mes,&l.records[i].p);
		}

		cliente = carro = l.total;

		int contDeprRec = 0;

		carro += l.pago;

		for(int i = 0; i < l.duracion; i++){



			cliente -= l.pago;
			carro -= (l.total * l.records[contDeprRec].p);  
			l.total = carro;
			m++;

			if(contDeprRec == l.records[contDeprRec].mes){
				contDeprRec++;
			}

			if(cliente < carro){
				if(m == 1){
					cout << "1 month\n";
				}else{
					cout << m << " months\n";
				}

				m = 0;
				contDeprRec = 0;
				break;
			}
		}

		scanf("%i %lf %lf %i",&l.duracion,&l.pago,&l.total,&l.deprRecords);		
	}


	return 0;
}