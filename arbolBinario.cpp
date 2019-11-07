#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Arbol{
     int numero;
     struct Arbol *izquierdo, *derecho;
};

typedef struct Arbol *ABB;

ABB crearNodo(int x)
{
     ABB nuevoNodo=new(Arbol);
     nuevoNodo->numero=x;
     nuevoNodo->izquierdo=NULL;
     nuevoNodo->derecho=NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol=crearNodo(x);
     }
     else if(x<arbol->numero)
          insertar(arbol->izquierdo,x);
     else if(x>arbol->numero)
          insertar(arbol->derecho,x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout<<arbol->numero<<" ";
          preOrden(arbol->izquierdo);
          preOrden(arbol->derecho);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izquierdo);
          cout<<arbol->numero<<" ";
          enOrden(arbol->derecho);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izquierdo);
          postOrden(arbol->derecho);
          cout<<arbol->numero<<" ";
     }
}
int main()
{
    ABB arbol=NULL;

    int n;
    int x; 

    cout<<":::::::ARBOL BINARIO DE BUSQUEDA:::::::"<<endl;

	cout<<"Ingrese el numero de nodos que desea crear para el arbol: "<<endl;
    cin>>n;
    cout<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Numero del nodo "<<i+1<<": ";
        cin>>x;
        insertar(arbol, x);
    }

    cout << "\n Recorridos del Arbol Binario";

    cout << "\n\n En orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);

    return 0;
}
