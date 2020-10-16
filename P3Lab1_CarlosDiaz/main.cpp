#include <iostream>
# include <math.h>

using std::cout;
using std::cin;
using std::endl;

//prototipos de funciones
double evaluarSigmoide(double);
double leibnizPi(int);

int main(int argc, char** argv) {
    int op;
    while(op!=3){
        cout<<"          MENU"<<endl
        <<" 1. Función sigmoide con x"<<endl
        <<" 2. Aproximar valor de pi con n"<<endl
        <<" 3. Salir"<<endl
        <<"Ingrese una opción: ";

        cin >> op; 
        while(op < 1 || op > 3){
            cout << " Opción incorrecta, intentá de nuevo: ";
            cin >> op;
        }
        switch(op){
            case 1: {
                double x;
                cout << "Ingresa x para evaluar la función: ";
                cin  >> x;
                
                double resultado = evaluarSigmoide(x);
                cout << "f(" << x << ") = " << resultado << endl;
                break;
            } case 2: {
                double lim;
                cout << "Ingresa lim para hacer el cálculo: ";
                cin  >> lim;
                
                double pi = leibnizPi(lim);
                cout << "π = " << pi << endl;
                break;
            } case 3: {
                cout << "Nos vemos" << endl;
                break;
            }
        }
        cout << "" << endl;
    }
    
    return 0;
}

double evaluarSigmoide(double x){                                               //*No usé librería para probarme con los ciclos for
    double euler = 2.71828182845904523536, eulerElevado=1;                      //aquí está elevado a la 1
    if(x>0){
        for (int i=1; i<=x; i++){                                               //elevado al número que ingresó el usuario
            eulerElevado = (1/euler) * eulerElevado;                            //división por la fórmula de elevado a la -x
        }
                               
    } else if(x<0){
        x=x*-1;                                                                 //hacemos positivo el valor para que no haya problemas con el ciclo for
        for (int i=1; i<=x; i++){
            eulerElevado = (euler) * eulerElevado; 
        }
    } else{
        //se queda como euler^0=1 como viene por defecto
    }
    
    double r = 1/(1 + eulerElevado);
    return r;
}

double leibnizPi(int lim){
    double sumatoria = 0;
    for (int n=0; n<=lim; n++){
        double num = pow(-1, n);                                                //*este sí lo hago con la librería para probar de ambas formas
        sumatoria = sumatoria + ( (pow(-1, n)) / (2*n+1) );
        //cout << "" << num << endl;
    }
    
    double pi = 4 * sumatoria;
    return pi;
}

