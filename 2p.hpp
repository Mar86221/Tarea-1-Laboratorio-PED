#include <iostream>
using namespace std;

struct nodo
{
    int carnet;
    int edad;
    int tel;
    string corr;
    string nam;
    string ape;
    nodo *sig;
};
class listasimple
{
private:
    nodo *pInicio;
public:
    //nodo *pInicio;
    listasimple();
    ~listasimple();
    void insinicio(int, int, int, string, string, string);
    void insfinal(int, int, int, string, string, string);
    void mostrarlistaiter(void);
    void mostrarlistarecur(void);
    void mostrarlistarecurAux(nodo *);
    void insdespueselemento(int, int);
    bool borrado(int);
};

listasimple::listasimple(void)
{
    pInicio = NULL;
}

listasimple::~listasimple()
{
    cout<<"\n"<<"Ejecutando destructor"<<"\n"<<endl;
    nodo *p;
    while (pInicio)
    {
        p=pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
    
}

void listasimple::insinicio(int carnet, int data, int tele, string d, string aux, string c)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->carnet = carnet;
    nuevo->edad = data;
    nuevo->tel = tele;
    nuevo->nam = d;
    nuevo->ape = aux;
    nuevo->corr = c;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void listasimple::insfinal(int carnet, int data, int tele, string d, string aux, string c)
{
    nodo *nuevo, *saltarin;

    nuevo = new nodo;
    nuevo->carnet = carnet;
    nuevo->edad = data;
    nuevo->tel = tele;
    nuevo->nam = d;
    nuevo->ape = aux;
    nuevo->corr = c;

    if (!pInicio)
    {
        pInicio=nuevo;
        pInicio->sig=NULL;
    }else{
        saltarin=pInicio;
        while (saltarin->sig != NULL)
            saltarin=saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->sig=NULL;
    }
}

void listasimple::mostrarlistaiter(void)
{
    nodo *saltarin;
    cout << endl;
    saltarin = pInicio;
    while (saltarin)
    {
        cout << "Carnet: #" << saltarin->carnet << "" << endl;
        cout << "Nombre: " << saltarin->nam << endl;
        cout << "Apellido: " << saltarin->ape << endl;
        cout << "Edad: " << saltarin->edad << " anios" << endl;
        cout << "Telefono: " << saltarin->tel << endl;
        cout << "Correo electronico: " << saltarin->corr << endl;
        cout << endl;
        saltarin = saltarin->sig;
    }
}

void listasimple::mostrarlistarecur(void)
{
    mostrarlistarecurAux(pInicio);
}

void listasimple::mostrarlistarecurAux(nodo *saltarin)
{
    if (saltarin)
    {
        mostrarlistarecurAux(saltarin->sig);
        cout << "Carnet: #" << saltarin->carnet << "" << endl;
        cout << "Nombre: " << saltarin->nam << endl;
        cout << "Apellido: " << saltarin->ape << endl;
        cout << "Edad: " << saltarin->edad << " anios" << endl;
        cout << "Telefono: " << saltarin->tel << endl;
        cout << "Correo electronico: " << saltarin->corr << endl;
        cout << endl;
    }
    
}

void listasimple::insdespueselemento(int carnet, int carnetref)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->carnet=carnet;

    if (!pInicio)
    {
        pInicio=nuevo;
        pInicio->sig=NULL;
    }else{
        nodo *saltarin;
        saltarin = pInicio;
        while (saltarin->sig !=NULL && saltarin->carnet !=carnetref)
        {
            saltarin=saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        saltarin->sig-nuevo;
    }
    
}

bool listasimple::borrado(int carnetb)

{
    if (!pInicio) //Si el pInicio esta vacio=NULL returna falso y pasa cuando no se ha insertado ningun dato
        return false;
    else //si hay dato insertados se pasa al else y se crean dos variables borrar que se iguala a pInicio y el auxiliar
    {    //que es para hacer operaciones
        nodo *borrar = pInicio, *aux;
        if (borrar->carnet == carnetb) //Este se cumple unicamente cuando el dato ingresado es igual al dato del primer nodo
        {                              //lo cual se efectua y se borra
            pInicio = pInicio->sig;
            delete borrar;
            return true;
        }
        else //sino esta en el primer nodo se entra a 2 posibles casos y para eso se usa el while
        {
            while (borrar->sig && borrar->sig->carnet != carnetb) //cuando esto se cumpla se entra al while
                borrar = borrar->sig;                             //y borrar se avanza una posicion mas en la lista 1=1+1 por ejemplo

            if (!borrar->sig) //si el elemento !borrar->sig es nulo pues este se cumple es decir sino hay elementos
                return false;
            else //en cambio si si hay elementos se entra al ultimo posible caso
            {
                aux = borrar->sig; //en esta funcion lo que se hace es pasa al siguiente nodo y si lo encuentra lo borrara
                borrar->sig = borrar->sig->sig;
                delete aux;
                return true;
            }
        }
    }
}