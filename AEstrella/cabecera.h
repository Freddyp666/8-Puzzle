#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
#include <iostream>
#include <time.h>

using namespace std;
class Estado {
public:
    //Matriz que se usara para representar los estados del 8 puzle
    int e[3][3];


    Estado() { //Constructor inicializa el puzzle en el orden que deberia estar
        for(int i=0; i<3; i++) {

            for(int j=0; j<3; j++) {

                e[i][j]=0;

            }

        }

        estadoAleatorio();

    };




    Estado(int es[3][3]) { //Constructor

        for(int i=0; i<3; i++) {

            for(int j=0; j<3; j++) {

                e[i][j]=es[i][j];

            }

        }

    };

    ////Retorna un puntero hacia a si mismo
    Estado* autoApuntador() {
        return this;
    };



    //FUNCIONES
    //Metodo para imprimir estados
    void printEstado() {
        int filas = (sizeof(e)/sizeof(e[0]));
        int columnas = (sizeof(e[0])/sizeof(e[0][0]));
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout<< "[" <<e[i][j]<<"] ";
            }

            cout<<endl;
        }
        cout<<endl;


    };


    //METODO PASO SIGUIENTE
    bool pasoSiguiente(int accion) {
        //variables que almacena la posicion f = fila c= columna
        int f,c;

        //primero determinamos la posición en la que se encuentra el espacio vacio
        int filas = (sizeof(e)/sizeof(e[0]));//la posicion en la fila
        int columnas = (sizeof(e[0])/sizeof(e[0][0]));//la posicion en la fila
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if(e[i][j]==0) {
                    f=i;
                    c=j;
                }
            }
        }
        //cout<<"posicion actual vacia ----> "<<f<<" "<<c<<"\n"<<endl;
        //Dependiendo de la variable accion que se recibe
        switch(accion) {
        case 1://Si es hacia arriba
            if((f==0 && c==0)||(f==0 && c==1)||(f==0 && c==2)) { //Si el espacio vacio está en los limite de arriba
                return false;//no realiza la accción
                break;
            }
            //Analiza todos los posibles casillerros donde esta el espacio en blanco [fila, columna]
            if(f==1 && c==0) { //Si el espacio vacio esta en la pos [1,0]
                pasar(f,c,0,0); //Mover el espacio vacio actual hacia arriba -> [0,0]

                break;
            }
            if(f==1 && c==1) {//Si el espacio vacio y esta en la posición [1,1]
                pasar(f,c,0,1);//Mover el espacio vacio actual hacia arriba -> [0,1]

                break;
            }
            if(f==1 && c==2) { //Si el espacio vacio esta y esta la posición [1,2]
                pasar(f,c,0,2);//Mover el espacio vacio actual hacia arriba -> [0,2]

                break;
            }
            if(f==2 && c==0) { //Si el espacio vacio esta en la pos [2,0]
                pasar(f,c,1,0); //Mover el espacio vacio actual hacia arriba -> [1,0]

                break;
            }
            if(f==2 && c==1){ //Si el espacio vacio esta en la pos [2,1]
                pasar(f,c,1,1); //Mover el espacio vacio actual hacia arriba -> [1,1]

                break;
            }
            if(f==2 && c==2) {//Si el espacio vacio esta en la pos [2,2]
                pasar(f,c,1,2); //Mover el espacio vacio actual hacia arriba -> [1,2]

                break;
            }
            break;
         //Analiza todos los posibles casillerros donde esta el espacio en blanco [fila, columna]
        case 2: //Si es hacia abajo
            if((f==2 && c==0)||(f==2 && c==1)||(f==2 && c==2)) { //Cuando el espacio vacio esta en los limites inferiores
                return false;//No se  realiza la accion
                break;
            }
            if(f==1 && c==0) { //Si el espacio vacio esta en la posición [1, 0]
                pasar(f,c,2,0); //Mover el espacio vacio actual hacia abajo -> [2,0]

                break;
            }
            if(f==1 && c==1) { //Si el espacio vacio esta en la posición [1, 1]
                pasar(f,c,2,1);//Mover el espacio vacio actual hacia abajo -> [2,1]

                break;
            }
            if(f==1 && c==2) { //Si el espacio vacio esta en la posición [1, 2]
                pasar(f,c,2,2); //Mover el espacio vacio actual hacia abajo -> [2,2]

                break;
            }
            if(f==0 && c==0) { //Si el espacio vacio esta en la posición [0, 0]
                pasar(f,c,1,0); //Mover el espacio vacio actual hacia abajo -> [1,0]

                break;
            }
            if(f==0 && c==1) { //Si el espacio vacio esta en la posición [0, 1]
                pasar(f,c,1,1);//Mover el espacio vacio actual hacia abajo -> [1,1]

                break;
            }
            if(f==0 && c==2) {//Si el espacio vacio esta en la posición [0, 2]
                pasar(f,c,1,2);//Mover el espacio vacio actual hacia abajo -> [1,2]

                break;
            }
            break;
         //Analiza todos los posibles casillerros donde esta el espacio en blanco [fila, columna]
        case 3: //Si es hacia la izquierda
            if((f==0 && c==0)||(f==1 && c==0)||(f==2 && c==0)) { //Cuando el espacio vacio esta en los limites de la izquierda del tablero
                return false;//No se realiza la accion
                break;
            }
            if(f==0 && c==1) { //Si el espacio vacio esta en la posición [0, 1]
                pasar(f,c,0,0); //Mover el espacio vacio actual hacia la izquierda -> [0,0]

                break;
            }
            if(f==1 && c==1) { //Si el espacio vacio esta en la posición [1, 1]
                pasar(f,c,1,0);//Mover el espacio vacio actual hacia la izquierda -> [1,0]

                break;
            }
            if(f==2 && c==1) { //Si el espacio vacio esta en la posición [2, 1]
                pasar(f,c,2,0);//Mover el espacio vacio actual hacia la izquierda -> [2,0]

                break;
            }
            if(f==0 && c==2) {//Si el espacio vacio esta en la posición [0, 2]
                pasar(f,c,0,1);//Mover el espacio vacio actual hacia la izquierda -> [0,1]

                break;
            }
            if(f==1 && c==2) {//Si el espacio vacio esta en la posición [1, 2]
                pasar(f,c,1,1);//Mover el espacio vacio actual hacia la izquierda -> [1,1]

                break;
            }
            if(f==2 && c==2) { //Si el espacio vacio esta en la posición [2, 2]
                pasar(f,c,2,1);//Mover el espacio vacio actual hacia la izquierda -> [2,1]

                break;
            }
            break;
         //Analiza todos los posibles casillerros donde esta el espacio en blanco [fila, columna]
        case 4: //Si es hacia la derecha
            if((f==0 && c==2)||(f==1 && c==2)||(f==2 && c==2)) { //Cuando el espacio vacio esta en los limites de la derecha del tablero
                return false;//No se realiza la accion
                break;
            }
            if(f==0 && c==1) { //Si el espacio vacio esta en la posicion [ 0, 1]
                pasar(f,c,0,2); //Mover el espacio vacio actual hacia la derecha -> [0,2]

                break;
            }
            if(f==1 && c==1) {//Si el espacio vacio esta en la posicion [ 1, 1]
                pasar(f,c,1,2); //Mover el espacio vacio actual hacia la derecha -> [1,2]

                break;
            }
            if(f==2 && c==1) { //Si el espacio vacio esta en la pos [ 2, 1]
                pasar(f,c,2,2); //Mover el espacio vacio actual hacia la derecha -> [2,2]

                break;
            }
            if(f==0 && c==0) { //Si el espacio vacio esta en la posicion [ 0, 0]
                pasar(f,c,0,1); //Mover el espacio vacio actual hacia la derecha -> [0,1]

                break;
            }
            if(f==1 && c==0) { //Si el espacio vacio esta en la posicion [ 1, 0]
                pasar(f,c,1,1);//Mover el espacio vacio actual hacia la derecha -> [1,1]

                break;
            }
            if(f==2 && c==0) {//Si el espacio vacio esta en la posicion [ 2, 0]
                pasar(f,c,2,1);//Mover el espacio vacio actual hacia la derecha -> [2,1]

                break;
            }
            break;

            }
        return true;
}

    //FUNCION PASAR (INTERCAMNBIO)
    void pasar(int f,int c,int nf,int nc) {
        //f y c = fila y columna actual   && nf y nc = siguiente fila y columna a realizar el cambio.
        //cout<<"pasa ----> "<<f<<" "<<c<<"\n"<<"pasa ----> "<<nf<<" "<<nc<<"\n"<<endl;
        //A continuacion se guarda el numero de la casilla a donde se va mover el espacio vacio
        int aux;
        aux= e[nf][nc];
        e[nf][nc]=e[f][c]; //Se le asigna el espacio vacio  a la nueva casilla
        e[f][c]=aux; //Cambia
    }
    Estado getEstado() {
        return *this;
    }

    //Esta funcion sirve para determinar si el estado actual que cumpla con las condiciones del estado objetivo
    bool testObjetivo() {
        int c=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){

                if(e[i][j]!=c){
                    return false;//Retorna false si estado actual no coicide con el estado final.
                }
                c++;
            }

        }

        return true;//Retorna true si cumple con el estado final
    }


    //Para realizar el numero de inversiones si existe solucion, si no encuentra no existe solucion
    bool existeSolucion() {

        int inversiones=0;
        int aux[9];
        int c=0;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                aux[c]=e[i][j];//almacenar los numeros del tablero en un vector de 1 dimension en el orden en que este el estado actual

                c++;
            }
        }


        for(int i=0; i<9; i++) {
            for(int j=i+1; j<9; j++) {
                //Ejm: [1,2,3,4,_,6,7,5,8] -> Se puede invertir el [6,5], [7,5]
                //Se cuenta como una inversion cuando el numero actual (i) es mayor que el siguiente (i+1) y  son distintos del espacio vacio
                if(aux[i]>aux[j] && aux[i]!=0 && aux[j]!=0 ) {
                    inversiones++;
                }
            }
        }

        return(inversiones%2==0);//Funcion devuelve un True si el estado inicial llega un estado solucion

    }

    //Funcion que escoje un estado de manera aleatorio
    void estadoAleatorio() {
        srand(time(NULL));
        int piezas[]= {0,1,2,3,4,5,6,7,8};//Las piezas en el tablero
        bool asignado=false;
        int t=0;
        int x=-1;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {

                while(!asignado) {//Mientra sea diferente de falso hacer
                    t=(rand()%9);
                    x=piezas[t];
                    if(x!=-1) {//Si la pieza es diferente de -1
                        e[i][j]=x;//se guarda la posición
                        piezas[t]=-1;//se usa -1 para señalar que la pieza ha sido sacada
                        asignado=true;// retorna un true
                    }
                }
                asignado=false;//Si la pieza es igual, retorna false
            }
        }

    }
    //Metodo que devuelve el valor numerico de la distancia Manhattan en el estado actual
    //La distancia Manhattan suma de las ditancias de cada casilla actual que conforman el tablero para llegar a su casilla final o solucion
    int funcionDistanciaManhattan() {
        int distanciaTotal=0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                //Recorre la matriz del estado actual e[][] y va sumando la distancia individual de cada casilla
                distanciaTotal+= calcularDistanciaManhattan(e[i][j],i,j);
            }
        }
        return distanciaTotal;
    };

    //Funcion que recibe el valor numerico de la casilla y su posicion actual en el tablero
    int calcularDistanciaManhattan(int num, int posi, int posj) { //1 al 8
        int aux1, aux2, distancia;
        //Dependiendo del caso el valor numerico de la casilla actual, para determinar la casilla solucion o final
        switch(num) {
        case 0://Si estamos en la casilla [0,0]
            aux1=abs(0-posi);//Calcula la distancia en i
            aux2=abs(0-posj);//Calcula la diatancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        case 1://Si estamos en la casilla [0,1]
            aux1=abs(0-posi);//Calcula la distancia en i
            aux2=abs(1-posj);//Calcula la diatancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        case 2://Si estamos en la casilla [0,2]
            aux1=abs(0-posi);//Calcula la distancia en i
            aux2=abs(2-posj);//Calcula la diatancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        case 3://Si estamos en la casilla [1,0]
            aux1=abs(1-posi);//Calcula la distancia en i
            aux2=abs(0-posj);//Calcula la diatancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        case 4://Si estamos en la casilla [1,1]
            aux1=abs(1-posi);//Calcula la distancia en i
            aux2=abs(1-posj);//Calcula la diatancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        case 5://Si estamos en la casilla [1,2]
            aux1=abs(1-posi);//Calcula la distancia en i
            aux2=abs(2-posj);//Calcula la diatancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        case 6://Si estamos en la casilla [2,0]
            aux1=abs(2-posi);//Calcula la distancia en i
            aux2=abs(0-posj);//Calcula la diatancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        case 7://Si estamos en la casilla [2,1]
            aux1=abs(2-posi);//Calcula la distancia en i
            aux2=abs(1-posj);//Calcula la distancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        case 8://Si estamos en la casilla [2,2]
            aux1=abs(2-posi);//Calcula la distancia en i
            aux2=abs(2-posj);//Calcula la distancia en j
            distancia=aux1+aux2;//Suma las distancia de i + j
            break;
        default:
            cout<<"Numero no posible\n";
        }
        return distancia;//retorna las suma de las distancias i+j
    }
};




class Nodo {
public:

    Estado estado;
    Nodo *padre;//Nodo padre
    Nodo **hijos;//Nodo hijo
    int fr;//factor de ramificacion
    int n;//nivel de profundidad

    int f;
    int h;
    int g;




    Nodo() {//Constructor de nodo
        padre=NULL;
        hijos=NULL;
        fr=0;
        n=0;
        f=0;
        h=0;
        g=0;


    };


    //Sobrecarga de constructor de nodo
    Nodo(Estado es) {
        estado=es;
        padre=NULL;
        hijos=NULL;
        fr=0;
        n=0;
        f=0;
        h=0;
        g=0;

    };

    Nodo(Nodo *nod) {
        estado=nod->estado;
        padre=nod->padre;
        hijos=nod->hijos;
        fr=nod->fr;
        n=nod->n;
        f=nod->f;
        h=nod->h;
        g=nod->g;

    };

    //Retorna un puntero hacia a si mismo
    Nodo* autoApuntador() {
        return this;
    };

    //Sobrecarga de constructor
    Nodo(Nodo *pa,Estado *es) {

        padre=pa;
        estado=es->getEstado();

    };

    //Compara el nodo
    bool comparar(Nodo *n){

        for(int i=0;i<3;i++){
            for(int j=0;i<3;i++){
                //Si nodo es diferente al nivel de profundidad retorna falso
                if(estado.e[i]!=n->estado.e[i]){
                    return false;
                }
            }
        }

        //si el nodo es diferente al nivel de profundida, retorna falso
        if(f!=n->f){
            return false;
        }
        return true;

    }

    //Imprime en consola los estados
    void print(){
        estado.printEstado();

        cout<<"f: "<<f<<endl;
        cout<<"h: "<<h<<endl;
        cout<<"g: "<<g<<endl;
        cout<<"n: "<<g<<endl;


    }

    //Imprime los nodo padres
    void imprimirPadres() {

        Nodo *padres[n+1];
        Nodo *p=NULL;
        p=padre->autoApuntador();


        for(int i=0; i<n; i++) {
            padres[i]=p;
            //p->estado.printEstado();
            p=p->padre;
        }


        for(int i=n-1; i>=0; i--) {
            padres[i]->estado.printEstado();
        }



    }

    //Devuelos toso los estados posibles generados moviendo la pieza
    void expandirNodo() {//funcion succesor
        int nh=0;
        Estado **mes;
        mes=new Estado*[4];

        for(int i=1; i<=4; i++) {

            Estado *es =(new Estado(estado.e));
            //Si
            if(es->pasoSiguiente(i) && es->existeSolucion()) {
                mes[nh]=es;
                nh++;
                //es->printEstado();
            }
            es=nullptr;
        }
        //el factor de ramificaion es al nodo hijo
        fr=nh;
        hijos=new Nodo*[fr];

        //Si el nodo hijo es igual a cero retorna
        if(nh==0) {
            return;
        }

        //por cada hijo
        for(int i=0; i<fr; i++) {
            hijos[i]=new Nodo();//Se crea nodos hijos
            hijos[i]->padre=this;//Apunta hacia el nodo padre
            hijos[i]->n=n+1;//La profundidad de los nodos hijos se ingrementa en 1
            hijos[i]->estado=mes[i]->getEstado();
            //Los nodos hijos calcula la funcion de evaluacion, camino y heurustica
            hijos[i]->h=hijos[i]->estado.funcionDistanciaManhattan();
            hijos[i]->g=this->g+1;
            hijos[i]->f=hijos[i]->h+hijos[i]->g;
        }

    };

    //Devuelve el nodo con menor valor f de los hijos del nodo
    Nodo * menorFValue() {
        Nodo * menor;
        menor=NULL;

        if(fr==0)return NULL;//Si el factor de ramificacion es igual a cero retorna NULL
        menor=hijos[0];
        for(int i=1; i<fr; i++) {
            if(menor->f > hijos[i]->f) {
                menor=hijos[i];
            }
        }
        return menor;//Retorna el nodo del menor valor del resultado
    }

    //devuelve el valor f del segundo mejor nodo de los hijos.
    int segundoMenorFValue() {
        int primero=menorFValue()->f;
        int segundo=9999;

        for(int i=0; i<fr; i++) {
            int x=hijos[i]->f;//Apunta hacia a frontera
            if( x<segundo && x!=primero) {//Si nodo hijo es menor al segundo hijo y diferente al primero
                segundo=x;//Guarda el valor en la variable
            }
        }
        return segundo;//Retorna el valor
    }

};

#endif // CABECERA_H_INCLUDED
