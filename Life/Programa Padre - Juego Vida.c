///
//
///              ERICK  IBARRA
///                A00959090
//
///             JUEGO DE LA VIDA
//
/// Es un juego donde se supone que una matriz
/// es un mundo donde las localidades pueden
/// estar vivas o muertas, y dependiendo de su
/// estado inicial se comienza el ciclo de vida.
/// Si la localidad se encuentra viva, muere si:
///     Existe 0 alrededor
///     Existe 1 alrededor
///     Existen mas de 3 alrededor
/// Si la localidad se encuentra muerta, vive si:
///     Existen 3 alrededor
//
/// El ciclo de vida se detiene cuando llega al
/// anio final(2014)
//
/// El programa cuenta con un menu y distintas
/// opciones
/// Es posible:
///     Darle vida a localidades de distintas formas.
///     Cambiar el icono de vida
///     Guardar y Recuperar un mundo de un archivo
///     Comenzar el ciclo de vida
///     Comenzarlo con meteoros cayendo
///     Reiniciar el anio
///     Eliminar la poblacion
//
/// Despues de un ciclo de vida, el resultado esperado
/// es un mundo con el mapeo de una poblacion en
/// determinados anios de vida


#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>


#define Fila 50                         ///Cambiar el tama;o del mundo
#define Columna 50
#define ultimoAnio 2014                 ///Cambiar el Ultimo a;o
int icono = 219;
int anio = 0;

void imprimirMatriz(int mat[Fila][Columna], int icono);
int contarVivo(int mat[Fila][Columna]);
int contarAlrededor(int x, int y, int mat[Fila][Columna]);
void darVida(int mat[Fila][Columna]);
void crearCiudad(int a, int b, int mat[Fila][Columna], int x, int y);
void crearCruz(int x, int y, int mat[Fila][Columna]);
void nacer(int x, int y, int mat[Fila][Columna]);
void morir(int x, int y, int mat[Fila][Columna]);
void crearInvasor(int x,int y,int mat[Fila][Columna]);
void meteoro(int x, int y, int mat[Fila][Columna]);
void guardarDibujo(int mat[Fila][Columna]);
void leerDibujo(int mat[Fila][Columna]);

int main(){
    int i, j;
    int x, y;
    char valorFila='a';
    int mat[Fila][Columna];
    int casos, comoIniciar;
    int asiMas, opc=0;
    int a1, b1, a2, b2;
    int destruccion;

    //Instrucciones
    printf("\n\tJUEGO DE LA VIDA:\n\nReglas:\n\t.Vida = 1\n\t.Muerte = 0\n");
    printf("\nCondiciones:\n\t.Nace si existen 3 vivos alrededor\n\t.Muere si no hay nadie, si solo existe 1 alrededor o \n\t\tsi viven mas de 3 alrededor\n\t.Si hay 2 alrededor se mantiene\n\n\n\n\t\tEste es tu mundo, dale vida!\n\n\n");

        //Iniciar la matriz a muerta
        for(i=0;i<Fila;i++){
            for(j=0;j<Columna;j++){
                mat[i][j]=0;
            }
        }

        imprimirMatriz(mat,icono);
        printf("\n\n\t\t\t\t\t%c SCROLL %c\n\n", 24,24);
        system("pause");
        system("cls");

    do{
        //Mientras no se quiera dar vida a mas localidades
        do{
            imprimirMatriz(mat,icono);
            printf("\n>>Dar Vida a:\n"
                   "\t1. UNOS\n"
                   "\t2. CIUDAD\n"
                   "\t3. CRUZ\n"
                   "\t4. INVASOR\n"
                   ">>OTRAS OPCIONES\n"
                   "\t5. Cambiar Icono ( %c )\n"
                   "\t6. Guardar Dibujo\n"
                   "\t7. Leer Dibujo\n"
                   "\t8. Comenzar\n"
                   "\t9. Comenzar Con Meteoros\n"
                   "\t10. Reiniciar A%co\n"
                   "\t11. Apocalipsis\n"
                   "\t12. Salir\n"
                   ">>Opcion\n",icono,164);
            scanf("%i",&comoIniciar);
                //Si la opcion es 0 se utiliza el procedimiento crearCiudad para dar vida a un bloque
                asiMas=1;

                switch(comoIniciar){
                    //Dar Vida a localidades especificas
                    case 1:
                        darVida(mat);
                        break;
                    //Dar vida a una ciudad(cuadro)
                    case 2:
                        printf("\nDesde:\n\tX1: ");
                        scanf("%i", &a1);
                        printf("\tY1: ");
                        scanf("%i", &b1);
                        printf("\nHasta:\n\tX2: ");
                        scanf("%i", &a2);
                        printf("\tY2: ");
                        scanf("%i", &b2);
                        crearCiudad(a1,b1,mat,a2,b2);
                        break;
                    //Dar vida a una forma de cruz
                    case 3:
                        printf("\t>>X: ");
                        scanf("%i",&x);
                        printf("\t>>Y: ");
                        scanf("%i",&y);
                        crearCruz(x,y,mat);
                        break;
                    //Dar vida a un space invader
                    case 4:
                        printf("\t>>X: ");
                        scanf("%i",&x);
                        printf("\t>>Y: ");
                        scanf("%i",&y);
                        crearInvasor(x,y,mat);
                        break;
                    //Mostrar los iconos disponibles y cambiar el icono que representa vida
                    case 5:
                        system("cls");
                        for(i=1;i<255;i++){
                            printf("%i. %c\t",i,i);
                            if(i%8==0)
                                printf("\n");
                        }
                        printf("\n>>Opcion?\n");
                        scanf("%i", &icono);
                        break;
                    //Guarda el mundo en un archivo de texto llamado dibujo.txt
                    case 6:
                        guardarDibujo(mat);
                        printf("\n\n\t\t>> El dibujo se ha guardado en dibujo.txt <<\n\n\n");
                        system("pause");
                        break;
                    //Recupera un mundo del archivo dibujo.txt
                    case 7:
                        leerDibujo(mat);
                        printf("\n\n\t\t>> Se recupero dibujo de dibujo.txt <<\n\n\n");
                        system("pause");
                        break;
                    //Comienza el ciclo de vida sin destruccion
                    case 8:
                        asiMas=0;
                        destruccion = 0;
                        break;
                    //Comienza el ciclo de vida CON destruccion
                    case 9:
                        asiMas=0;
                        destruccion = 1;
                        break;
                    //Reinicia el a;o a 0
                    case 10: anio = 0;
                        break;
                    //Mata todas las localidades
                    case 11:
                        for(i=0;i<Fila;i++)
                            for(j=0;j<Columna;j++)
                                mat[i][j] = 0;
                        break;
                    //Opcion de salida total
                    case 12: asiMas = 0;
                        break;
                    default:
                        for(i=0;i<50;i++){
                            if(i%10 <= 5)
                                printf("\n\n\n\tNO!\n\t\tNO!\n\t\t\tNO!\n\nNo es una opcion!\n");
                            else
                                printf("\n\n\n\t\t\tNO!\n\tNO!\n\tNO!\n\nNo es una opcion!\n");
                            system("cls");
                        }
                        break;

                }

            system("cls");
        //Mientras no se quiera iniciar el ciclo o salir del juego
        }while(asiMas!=0);

        //Si la opcion es la de salida no entra al ciclo de vida
        if(comoIniciar != 12){

            printf("\n\n\t\t\" Ctrl + C \" para abortar\n\n\n");
            system("pause");


            //Mientras no se llegue al a;o actual
            while(anio < ultimoAnio){
                srand(time(NULL));

                for(i=0;i<Fila;i++){

                    for(j=0;j<Columna;j++){
                        //Si la matriz viene viva solo puede morir, si viene muerta solo puede vivir, o en cualquiera de los casos, mantenerse
                        switch(mat[i][j]){
                            case 0: nacer(i,j,mat);
                                break;
                            case 1: morir(i,j,mat);
                                break;
                        }
                        //imprimirMatriz(mat,icono);                                          ///Si se quiere el proceso (MUY LENTO)
                        //system("cls");
                    }
                }
                //Si es un a;o de meteoro y si la opcion de destruccion esta prendida
                if(destruccion == 1 && anio%10==0){                                             ///Cambiar que tan seguido hay meteoros
                    meteoro((rand()%30)+10, (rand()%30)+10,mat);                                ///Cambiar las posibles localidades del meteoro
                                                                                                ///Localidades actuales:
                                                                                                ///X entre 10 y 40
                                                                                                ///Y entre 10 y 40
                    //imprimirMatriz(mat,icono);                                                /// Detener en  cada meteoro
                    //system("pause");
                }
                anio++;
                if(anio%10==0){                                                     ///Ajustar el cambio de a;o (que tan seguido se muestra el estado del mundo)
                    imprimirMatriz(mat,icono);
                    /**AJUSTAR EL TIEMPO DE ESPERA EN MILISEGUNDOS*/
                    Sleep(10);
                    system("cls");
                }
                if(anio == ultimoAnio){
                    imprimirMatriz(mat,icono);
                    /**AJUSTAR EL TIEMPO DE ESPERA EN MILISEGUNDOS*/
                    Sleep(10);
                    system("cls");
                }
            }
        }
    }while(comoIniciar != 12);

    printf("\n\n\n\t\t>> !!ADIOS!! <<\n\n\n");

    return 0;
}

//Procedimiento que guarda el estado del mundo en un archivo
void guardarDibujo(int mat[Fila][Columna]){
    FILE *pDibujo=fopen("dibujo.txt","w");
    int i, j;

    for(i=0;i<Fila;i++){
        if(i<10)
            printf(" ");
        for(j=0;j<Columna;j++){
            if(mat[i][j]==1)
                fprintf(pDibujo,"%c",icono);
            else
                fprintf(pDibujo," ");
                //printf("%i",mat[i][j]);
        }
        fprintf(pDibujo,"\n");
    }

    fclose(pDibujo);
}

//Procedimiento que recupera el estado del mundo de un archivo
void leerDibujo(int mat[Fila][Columna]){
    FILE *pDibujo=fopen("dibujo.txt","r");
    int i, j;
    char vivo;

    for(i=0;i<Fila;i++){
        for(j=0;j<Columna;j++){
            vivo = fgetc(pDibujo);
            if(vivo == '\n')
                vivo = fgetc(pDibujo);
            if(vivo == ' ')
                mat[i][j]=0;
            else
                mat[i][j]=1;
        }
    }

    fclose(pDibujo);
}

//Crear meteoro dimensiones especificas
//El meteoro mata las localidades donde se estrella
void meteoro(int x, int y, int mat[Fila][Columna]){
    int i,j;

    for(i=x-6;i<=x+6;i++){                      ///Cambiar la altura del meteoro
        for(j=y-6;j<=y+6;j++)                   ///Cambiar el ancho del meteoro
            mat[i][j]=0;
    }
}

//Da vida a la forma de un Space Invader
void crearInvasor(int x,int y,int mat[Fila][Columna]){
    //Antenas
    mat[x-2][y-2]=1;
    mat[x-3][y-3]=1;
    mat[x-2][y+2]=1;
    mat[x-3][y+3]=1;

    //Brazo Derecho
    mat[x][y+4]=1;
    mat[x+1][y+4]=1;
    mat[x+1][y+5]=1;
    mat[x+2][y+5]=1;
    mat[x+3][y+5]=1;

    //Brazo Izquierdo
    mat[x][y-4]=1;
    mat[x+1][y-4]=1;
    mat[x+1][y-5]=1;
    mat[x+2][y-5]=1;
    mat[x+3][y-5]=1;

    //Cuerpo
    mat[x-1][y-1]=1;
    mat[x][y-1]=1;
    mat[x+1][y-1]=1;
    mat[x+2][y-1]=1;
    mat[x-1][y-2]=1;
    mat[x+1][y-2]=1;
    mat[x+2][y-2]=1;
    mat[x-1][y-3]=1;
    mat[x][y-3]=1;
    mat[x+1][y-3]=1;
    mat[x+2][y-3]=1;

    mat[x-1][y]=1;
    mat[x][y]=1;
    mat[x+1][y]=1;
    mat[x+2][y]=1;

    mat[x-1][y+1]=1;
    mat[x][y+1]=1;
    mat[x+1][y+1]=1;
    mat[x+2][y+1]=1;
    mat[x-1][y+2]=1;
    mat[x+1][y+2]=1;
    mat[x+2][y+2]=1;
    mat[x-1][y+3]=1;
    mat[x][y+3]=1;
    mat[x+1][y+3]=1;
    mat[x+2][y+3]=1;

    //Pies
    mat[x+3][y-3]=1;
    mat[x+4][y-2]=1;
    mat[x+4][y-1]=1;

    mat[x+3][y+3]=1;
    mat[x+4][y+2]=1;
    mat[x+4][y+1]=1;
}

//Da vida a la forma de una Cruz
void crearCruz(int x, int y, int mat[Fila][Columna]){
    mat[x-2][y]=1;
    mat[x-1][y]=1;
    mat[x+1][y]=1;
    mat[x+2][y]=1;
    mat[x][y-2]=1;
    mat[x][y-1]=1;
    mat[x][y+1]=1;
    mat[x][y+2]=1;
}

//1.Recorrer las posiciones alrededor de la matriz
//1.1 | x-1 y-1 | x-1 y | x-1 y+1 |
//1.2 | x   y-1 | x   y | x   y+1 |
//1.3 | x+1 y-1 | x+1 y | x+1 y+1 |
//1.4 Si la matriz esta viva y (i diferente x || j diferente y)
//1.4.1  m++
//2. Return m
int contarAlrededor(int x, int y, int mat[Fila][Columna]){
    int m=0;
    int i, j;


    for(i=x-1;i<=x+1;i++){
        for(j=y-1;j<=y+1;j++){

            if(mat[i][j]==1 && (i!=x || j!=y)){
                m++;
            }
        }
    }


    return m;
}

//Recorre toda la matriz y cuenta cada entidad viva
int contarVivo(int mat[Fila][Columna]){
    int i, j;
    int contador=0;

    for(i=0;i<Fila;i++){
        for(j=0;j<Columna;j++)
            if(mat[i][j]==1)
                contador++;

    }

    return contador;
}

//Imprime la matriz con formato
void imprimirMatriz(int mat[Fila][Columna],int icono){
    int i, j;
    char valorFila='a';

     printf("\t\tx\\y   ");

    for(i=0;i<Fila;i++){
        printf("%c", valorFila+i);
    }

     printf("\n\n");
    //printf("\t\tx\\y   abcdefghijklmnopqrstuvwxyz\n\n");
    for(i=0;i<Fila;i++){
        printf("\t\t%c=%i  ",valorFila + i, i);
        if(i<10)
            printf(" ");
        for(j=0;j<Columna;j++){
            if(mat[i][j]==1)
                printf("%c",icono);
            else
                printf(" ");
                //printf("%i",mat[i][j]);
        }
        if(i == 18){
            printf("\tA%cO:",165);
        } else if(i == 20)
            printf("\t  %i", anio);

        printf("\n");
    }
}

//Dadas ciertas condiciones y si la localidad esta viva, puede morir o mantenerse
void morir(int x, int y, int mat[Fila][Columna]){
    if(mat[x][y]==1 && (contarAlrededor(x,y,mat) == 0 || contarAlrededor(x,y,mat) == 1 || contarAlrededor(x,y,mat) > 3))
        mat[x][y]=0;

}

//Dadas ciertas condiciones y si la localidad esta viva, puede morir o mantenerse
void nacer(int x, int y, int mat[Fila][Columna]){

    if(contarAlrededor(x,y,mat) == 3 && mat[x][y]==0)
        mat[x][y]=1;


}

//Da vida a un bloque de localidades
void crearCiudad(int a, int b, int mat[Fila][Columna], int x, int y){
    int i, j;

    for(i=a;i<=x;i++){
        for(j=b;j<=y;j++){
            mat[i][j]=1;
        }
    }
}

//Da vida una localidad a la vez
void darVida(int mat[Fila][Columna]){

    int casos, asiMas;
    int i, j, x ,y;
        system("cls");
        imprimirMatriz(mat,icono);

        printf("\n>>A cuantos quieres darle vida?\n");
        scanf("%i", &casos);

        system("cls");

        for(i=0;i<casos;i++){

            //Actualizar matriz
            imprimirMatriz(mat,icono);
            printf("\n>>A que par ordenado quieres darle vida?\n");
            printf("\tX: ");
            scanf("%i", &x);
            printf("\tY: ");
            scanf("%i", &y);

            mat[x][y] = 1;

            system("cls");

        }


}


/**PARTES REUSABLES*/

/** IF POSICIONES */
    /*  if(mat[x][y] == 1){
        //ARRIBA IZQUIERDA
        if(mat[x-1][y-1] == 1){
            printf("Mat Arriba Izquierda: %i\n",mat[x-1][y-1]);
            m++;
            printf("M: %i\n", m);
        }
        //ARRIBA CENTRO
        if(mat[x-1][y] == 1){
            printf("Mat Arriba Centro: %i\n",mat[x-1][y]);
            m++;
            printf("M: %i\n", m);
        }
        //ARRIBA DERECHA
        if(mat[x-1][y+1] == 1){
            printf("Mat Arriba Derecha: %i\n",mat[x-1][y+1]);
            m++;
            printf("M: %i\n", m);
        }
        //MEDIO IZQUIERDA
        if(mat[x][y-1] == 1){
            printf("Mat Medio Izquierda: %i\n",mat[x][y-1]);
            m++;
            printf("M: %i\n", m);
        }
        //MEDIO DERECHA
        if(mat[x-1][y-1] == 1){
            printf("Mat Medio Derecha: %i\n",mat[x][y+1]);
            m++;
            printf("M: %i\n", m);
        }
        //BAJO IZQUIERDA
        if(mat[x+1][y] == 1)
            m++;
        if(mat[x+1][y-1] == 1){
            printf("Mat Bajo Izquierda: %i\n",mat[x+1][y-1]);
            m++;
            printf("M: %i\n", m);
        }
        //BAJO CENTRO
        if(mat[x+1][y] == 1)
            m++;
        if(mat[x+1][y-1] == 1){
            printf("Mat Bajo Centro: %i\n",mat[x+1][y-1]);
            m++;
            printf("M: %i\n", m);
        }
        //BAJO DERECHA
        if(mat[x+1][y] == 1)
            m++;
        if(mat[x+1][y-1] == 1){
            printf("Mat Bajo Derecha: %i\n",mat[x+1][y-1]);
            m++;
            printf("M: %i\n", m);
        }
    }
*/
/*
    while(contarVivo(mat) > 0){

        for(i=0;i<Fila;i++){

            for(j=0;j<Columna;j++){

                if(contarAlrededor(i, j, mat) > 0){
                    nacer(i,j,mat);
                }
                imprimirMatriz(mat);
                system("cls");
            }
        }


    }*/
/*
    for(i=x-1;i<=x+1;i++){
        for(j=y+1;j>=y-1;j--){
            if(mat[i][j]==0 && revivir==0 && (i!=x || j!=y) && contarAlrededor(x,y,mat) == 3){
                mat[x][y]=1;
                revivir++;
            }
            if(mat[i][j]==1 && revivir==0 && (i!=x || j!=y) && (contarAlrededor(x,y,mat) == 1 || contarAlrededor(x,y,mat) > 3)){
                mat[i][j]=1;
                revivir++;

            }
        }
    }
*/

/*
    while(contarVivo(mat) > 0){

        for(i=0;i<Fila;i++){

            for(j=0;j<Columna;j++){

                if(contarAlrededor(i, j, mat) > 0){
                    nacer(i,j,mat);
                }
                imprimirMatriz(mat);
                system("cls");
            }
        }


    }*/
