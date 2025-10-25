#include <iostream>
using namespace std;

const int MAX = 500;

struct Pelicula{
    string idPelicula;
    string titulo;
    bool disponible;
    float duracion;
    int anioEstreno;
};

typedef Pelicula aparray[MAX];

void agregar(Pelicula &x,int &cant, aparray &z){
    if (cant>=MAX)
    {
        cout << "No hay espacio para agregar un registro de pelicula. "<< endl;
    }else{
        z[cant]=x;
        cout << "Dime el id de la pelicula: "<< endl ;
        getline(cin,x.idPelicula);
        cout << "Dime el titulo: "<< endl ;
        getline(cin,x.titulo);
        cout << "Dime si esta disponible,1(si), o 2(no): "<< endl ;
        cin >> x.disponible;
        cin.ignore();
        cout << "Dime la duracion: "<< endl;
        cin >> x.duracion;
        cin.ignore();
        cout << "Dime el anio de estreno: "<< endl ;
        cin >> x.anioEstreno;
        cin.ignore();
        cant ++;
    }
}
int busquedaSec(aparray x, int ocup, string id){
    if (ocup<0)
    {
        return -1;
    }else{
        if (x[ocup].idPelicula==id){
            return ocup;      
        }
       return busquedaSec(x,ocup-1,id);
    }
}

void mostrar(aparray &x, int cant){
    if (cant==0)
    {
        return ;
    }else{
        mostrar(x,cant-1);
        cout << "ID de la pelicula: "<< x[cant-1].idPelicula<< endl;
        cout << "Titulo: "<< x[cant -1].titulo<<endl ;
        cout << "Disponibilidad (1)si,(2)no: "<< x[cant-1].disponible << endl;
        cout << "Duracion: "<< x[cant -1].duracion << endl;
        cout << "Anio de estreno: " << x[cant-1].anioEstreno<< endl;
    }
    
}

int main (){
    int cant = 0 ;
    Pelicula x;
    aparray z;
    agregar(x,cant,z);
    mostrar(z,cant);

    return 0;
}