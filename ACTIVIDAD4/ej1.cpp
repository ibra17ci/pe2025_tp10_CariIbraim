#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
struct personajes
{
    string nombre;
    string elemento;
    string clase;
    int vidaMax;
    int danio;
    bool estado;
    string descripcion;
};
typedef personajes aparray[MAX];
void insertarPer(int &cant,aparray &x){

    if (cant>=MAX)
    {
        cout << "Espacio insuficiente para agragar a un nuevo personaje. "<< endl;
    }else{
        cout << "Cantidad de personajes registrados: "<< cant << endl ;
        cout << "Si la posicion supera la cantidad depersonajes registrados se agregara enel ultimo lugar disponible."<< endl;
        int pos;
        cout << "Posicion a insertar: "<< endl;
        cin >> pos;
        cin.ignore();
        if (pos >= MAX || pos < 0)
        {
            cout << "La posicion no existe."<< endl;

        }else{
            if (pos>cant)
            {
                pos = cant;
            }
            
            for (int i = cant; i > pos; i--)
            {
                x[i]=x[i-1];
            }
            cout << "Nombre del personaje: " << endl;
            getline(cin, x[pos].nombre);
            cout << "Nombre del elemento: " << endl;
            getline(cin, x[pos].elemento);
            cout << "Nombre de la clase: " << endl;
            getline(cin, x[pos].clase);
            cout << "Vida maxima: " << endl ;
            cin >> x[pos].vidaMax;
            cin.ignore();
            cout << "Danio: " << endl ;
            cin >> x[pos].danio;
            cin.ignore();
            cout << "Desbloqueado = (1),Bloqueado = (0): " << endl ;
            cin >> x[pos].estado;
            cin.ignore();
            cout << "Descripcion: "<< endl ;
            getline(cin,x[pos].descripcion);
        }
        cant++;
        if (cant > 1 )
        {
            for (int i = 0; i < cant - 1; i++) {
            bool cambio = false; 
            for (int j = 0; j < cant - i - 1; j++) {
                if (x[j].nombre > x[j + 1].nombre) { 
                    swap(x[j],x[j+1]);
                    cambio = true;
                }
            }
        if (!cambio){
            break;
        }
        }
        }
        
        cout << "Listo! " << endl;
        string respuesta;
        cout << "Quiere ver la lista de nombres de personajes regsitrados en orden alfabetico?: "<< endl ;
        cin >> respuesta;
        cin.ignore();
        if (respuesta == "si" || respuesta == "Si"|| respuesta == "SI" || respuesta == "sI")
        {
            cout << "-------Nombres en orden alfabetico-------"<< endl;
        for (int i = 0; i < cant; i++) {
        cout <<">"<< x[i].nombre << endl;
        }
        }else{
            cout << "Bueno ): "<< endl ;
        }
        
    }
}
void buscarpNombre(aparray &x,int &cant){
    if (cant==0)
    {
        cout <<"No hay elementos dentro del registro. "<< endl;
    }else{
        string bname;
        bool aut=false;
        cout << "Dime el nombre que deseas buscar: "<< endl ;
        cin >> bname;
        for (int i = 0; i < cant; i++)
        {
            if (x[i].nombre==bname)
            {
                cout << "El nombre: "<< bname<< " esta en el elemento del registro N: "<< i << endl;
                aut=true;
                break;
            } 
        }
        if (aut!=true)
        {
            cout << "No se encontraron personajes con ese nombre. "<< endl ;
        }   
    }
    
}
void eliminarPer(aparray &x, int &cant){
    if (cant==0)
    {
        cout << "Registro vacio, no hay cosas por eliminar. "<< endl ;
    }else{
        int pos;
        cout << "Decime la posicion a eliminar: "<< endl;
        cin >> pos;
        if (pos<0 || pos>cant-1)
        {
            cout << "Posicion invalida. "<< endl ;
        }else{
            for (int i = pos; i < cant-1; i++)
            {
                x[i]=x[i+1];
            }
            cant--;
            cout << "Listo! "<< endl ;
        }
    }
}
int main (){
    int cant = 0,coso = -1;
    aparray x;
    while (coso!= 0)
    {
        cout << "1.Insertar"<< endl ;
        cout << "2.Buscar por nombre"<< endl ;
        cout << "3.Eliminar personaje"<< endl ;
        cout << "4.Salir "<< endl ;
        cin >> coso;
        cin.ignore();
        switch (coso)
        {
        case 1:
            insertarPer(cant, x);
            break;
        case 2:
            buscarpNombre(x, cant);
            break;
        case 3:
            eliminarPer(x, cant);
            break;
        case 4:
            return 0;
        default:
            cout <<"Opcion invalida. "<< endl;
            break;
        }
    }
    return 0;
}