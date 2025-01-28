#include <iostream>
#include "cabecera.h"

//Busca el mejor nodo de primero es el mejor del menor valor
Nodo* RBFS(Nodo *node,int f_limit,int * f_cost){

    //Estado llama al test objetivo
    if(node->estado.testObjetivo()){
        return node;
    }

    //El nodo escapande
    node->expandirNodo();

    if(node->fr==0){//Si el nodo factor de ramificaciones es igual a cero retorn null
        return NULL;
    }
    Nodo *s=NULL;//Nodo vacio
    Nodo *best=NULL;//Mejor nodo vacio
    Nodo *result=NULL;//Resultado

    //Itera por cada hijo
    for(int i=0;i<node->fr;i++){
        s=node->hijos[i];//Almacena el nodo hijo
        s->f=max(s->g+s->h,node->f);//Escojer el valor maximo entre s.h+a.g y el nodo


    }
    //do loop
    while(true){
        best=node->menorFValue();//el mejor nodo que se tiene
        if(best->f>f_limit){//si best.f es mayor que el limite se retona best.f y nulo
            *f_cost=best->f;

            return NULL;
        }

        //Almacena el valor f del segundo mejor nodo
        int alternative=node->segundoMenorFValue();
        //llamda recuriva
        result=RBFS(best,min(f_limit,alternative),&best->f);

        if(result!=NULL){//si el resultado es diferente de nulo retonar
            return result;
        }
    }
}


//Busca el camino mas corto desde sus estado incial
Nodo * busquedaAEstrella(Nodo *n){
    int x=0;
    return RBFS(n,999,&x);//Retorn el mejor valor

}

//Codigo principal
int main() {

    Nodo n;//Variable de tipo nodo

    //Mientras el estado no tenga solucion generar nuevos estados aleatorios
    while(!n.estado.existeSolucion()) {
        n.estado.estadoAleatorio();

    }
    //Imprime el estado inicial
    cout<<"Estado inicial:"<<endl;
    n.estado.printEstado();


    if(n.estado.existeSolucion()) {
        Nodo *sol;

        //LLama al metodo para buscar el mejor valor desde estado incial
        sol=busquedaAEstrella(n.autoApuntador());

        if(sol==NULL) {//si la solucion es diferente de null imprime
            cout<<"No se encontro la solucion"<<endl;
        } else {//Si no, imprime los pasos, la solucion y el numero de pasos

            cout<<"Pasos:"<<endl;
            sol->imprimirPadres();

            cout<<"Solucion:"<<endl;
            sol->estado.printEstado();

            cout<<"Numero de Pasos:"<<endl;
            cout<<sol->n<<endl;
        }

    } else {// Si no imprime las solucion no alzanda

        cout<<"El estado no alcanzara la solucion"<<endl;
    }

    return 0;
}
