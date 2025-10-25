#include <iostream>
#include <string>
using namespace std;
struct alumno{ 
string nombre;
string apellido; 
int edad; 
int curso; 
string especialidad;
}; 

struct materia { 
string nombre;
int duracionMeses; 
alumno alumnos[30];
};

void insertar(materia &z, int &cant){
    if (cant >= 30) {
        cout << "El registro esta lleno" << endl;
        return;
    }

    cout << "Ingrese el nombre de la materia: " << endl;
    getline(cin, z.nombre);

    cout << "Ingrese duracion en meses de la materia: " << endl;
    cin >> z.duracionMeses;
    cin.ignore(); 

    alumno &a = z.alumnos[cant];

    cout << "Ingrese nombre del alumno: " << endl;
    getline(cin, a.nombre);

    cout << "Ingrese apellido del alumno: " << endl;
    getline(cin, a.apellido);

    cout << "Ingrese edad del alumno: " << endl;
    cin >> a.edad;
    cin.ignore();

    cout << "Ingrese curso del alumno: " << endl;
    cin >> a.curso;
    cin.ignore();

    cout << "Ingrese especialidad del alumno: " << endl;
    getline(cin, a.especialidad);

    cant++; 
}
void eliminar (materia &z, int &cant){
    if (cant <= 0) {
        cout << "No hay alumnos para eliminar" << endl;
        return;
    }else{
        int pos;
        cout << "Ingrese la posicioin del alumno a eliminar: " << endl;
        cin >> pos;
        if (pos>cant || pos<0)
        {
            cout << "Posicion invalida" << endl;
            return;
        }else{
        for (int i =pos; i < cant-1; i++)
        {
            z.alumnos[i] = z.alumnos[i+1];
        }
        cant --;
    }
}
}
void mostrar(materia &x,int cant){
    if (cant<0)
    {
        return;
    }else{
        mostrar(x,cant-1);
        cout << "------------Datos------------"<< endl ;
        cout << "Nombre: "<< x.alumnos[cant].nombre<< endl;
        cout << "Apellido: "<< x.alumnos[cant].apellido<< endl;
        cout << "Edad: "<< x.alumnos[cant].edad<< endl ;
        cout << "Curso: "<< x.alumnos[cant].curso<< endl ;
        cout << "Especialidad: "<< x.alumnos[cant].especialidad<< endl;   
    }
}

int main (){
    materia x;
    int cant = 0;
    return 0;
}