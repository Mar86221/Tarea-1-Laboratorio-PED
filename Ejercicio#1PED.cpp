//Luis Mario Valencia #00086221
#include "2p.hpp"
using namespace std;

int menu()
{
    int opcion;
    cout<<"Elija la opcion que desee"<<endl;
    cout<<"1) Inserte la informacion del estudiante. "<<endl;
    cout<<"2) Carnet de referencia para poder insertar una lista despues de esa lista.(AUN NO FUNCIONA) "<<endl;
    cout<<"3) Desplegar lista iterativamente. "<<endl;
    cout<<"4) Desplegar lista recursivamente. "<<endl;
    cout<<"5) Eliminar nodo de la lista. "<<endl;
    cout<<"6) Ejecutar destructor. "<<endl;
    cout<<"7) Salir "<<endl;
    cout<<"Opcion: ";
    cin>>opcion; cin.ignore();
    return opcion;
}


int main(int argc, char const *argv[])
{
    cout<<"\n"<<"MENU DE OPCIONES "<<"\n"<<endl;

    listasimple listdatos;

    nodo *pInicio = NULL;
    bool continuar=true;
    int carnet = 0;
    int carnetref = 0;
    int edad = 0;
    int tel = 0;
    string d = "";
    string p = "";
    string c = "";
    do
    {
        switch (menu())
        {
        case 1:
            cout<<"Digite el carnet: ";
            cin>>carnet; cin.ignore();
            cout<<"Digite el primer nombre: ";
            getline(cin,d); 
            cout<<"Digite el apellido: ";
            cin>>(cin,p);
            cout<<"Digite la edad: ";
            cin>>edad; cin.ignore();
            cout<<"Digite el numero telefonico: ";
            cin>>tel;
            cout<<"Digite el correo electronico: ";
            cin>>(cin,c);
            listdatos.insinicio(carnet, edad, tel, d, p, c);
            //SOLO CAMBIA EL ORDEN AHORA EL PRIMERO SERA EL PRIMERO Y EN INSINICIO
            //EL PRIMERO ES EL ULTIMO EN MOSTRARSE
            //listdatos.insfinal(carnet, edad, tel, d, p, c);
            cout<<"\n"<<"La informacion ha sido guardada! "<<"\n"<<endl;
            break;
        case 2:
            cout<<"Digite el carnet de referencia: ";
            cin>>carnetref;
            listdatos.insdespueselemento(carnet, carnetref);
            break;
        case 3:
            listdatos.mostrarlistaiter();
            break;
        case 4:
            listdatos.mostrarlistarecur();
            break;
        case 5:
            cout<<"Digite el carnet del que desea eliminar la informacion: ";
            cin>>carnet;
            if(listdatos.borrado(carnet)){
                cout<<"\n"<<"Se elimino satisfactoriamente "<<"\n"<<endl;   
            }else{
                cout<<"\n"<<"No se ha podido eliminar "<<"\n"<<endl;
            }
            break;
        case 6:
            listdatos.~listasimple();
            break;
        case 7:
            continuar = false;
            break;
        default:
            cout<<"La opcion no es valida o no existe, favor intentar denuevo "<<endl;
            break;
        }
    } while (continuar);
    

    return 0;
}