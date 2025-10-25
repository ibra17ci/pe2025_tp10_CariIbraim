#include <iostream>
#include <string>
using namespace std;
struct paciente{
    string especie;
    string nombre;
    int edad; 
    char sexo;
    string enfermedad; 
};
const int MAX = 100;
typedef paciente aparray[MAX];
void agregar(paciente &x ,int &cant, aparray &z){
    if (cant>=MAX)
    {
        cout << "No hay espacio para agregar un registro de mascota. "<< endl;
    }else{
        z[cant] = x;
        cout << "Nombre de la especie: "<< endl;
        getline(cin, x.especie);
        cout << "Nombre de la mascota: "<< endl;
        getline(cin, x.nombre);
        cout << "Edad de la mascota: "<< endl;
        cin >> x.edad;
        cin.ignore();
        cout << "Sexo = macho (m), hembra(h): "<< endl;
        cin >> x.sexo;
        cin.ignore();
        cout << "Nombre de la enfermedad: "<< endl;
        getline(cin, x.enfermedad);

    }
    
}
void dardeBaja(int &cant,aparray &x ){
    if (cant <= 0)
    {
        cout << "No hay elementos por eliminar. "<< endl ;
    }else{
        int pos;
        cout << "Posicion a eliminar: "<< endl ;
        cin >> pos;
        cin.ignore();
        if (pos<0 || pos>=cant)
        {
            cout << "Posicion invalida. "<< endl ;
        }else{
            for (int i = pos; i < cant-1; i++)
            {
                x[i]= x[i+1];
            }
            cant --;
            cout << "-------Eliminado correctamente-------"<< endl ;
        }
    } 
}
void ordenar(aparray &x,int cant ){
    if (cant<=0)
    {
        cout <<"No hay posiciones por ordenar. "<< endl ;
    }else{
        bool cambiado;
    for (int i = 0; i < cant - 1; i++) {
        cambiado = false;
        for (int j = 0; j < cant - i - 1; j++) {
            if (x[j].nombre > x[j + 1].nombre) {
                swap(x[j], x[j + 1]);
                cambiado = true;
            }
        }
        if (!cambiado) break;
    }
    cout << "----------Orden Alfabetico----------"<< endl ;
    for (int i = 0; i < cant; i++)
    {
        cout << "Paciente N "<< i+1 <<endl ;
        cout << "Especie: "<< x[i].especie<< endl;
        cout << "Nombre: "<< x[i].nombre<< endl;
        cout << "Edad: "<< x[i].edad<< endl;
        cout << "Sexo: "<< x[i].sexo<< endl;
        cout << "Enfermedad: "<< x[i].enfermedad<< endl;
    }
    }
}
int main() {
    

    return 0;
}