/*Hallar la altura del arbol y sus hojas en que altura*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class arbol {
public:
    char valor;
    arbol *hizq;
    arbol *hmed;
    arbol *hder;

    arbol(char valor);
};

arbol::arbol(char valor) {
    this->valor = valor;
    this->hizq = NULL;
    this->hmed = NULL;
    this->hder = NULL;
}
arbol *nodoPadre;
arbol *nodoBuscado;
int x=0;
int y=0;
//Altura
int obtenerAltura(arbol *raiz){
    if (raiz==NULL){
        return -1;
    }
    int alturaIzq=obtenerAltura(raiz->hizq);
    int alturaDer=obtenerAltura(raiz->hder);
    if (alturaIzq>alturaDer){
        return alturaIzq +1;
    }
    else{
        return alturaDer +1;
    }
}

//busqueda
void busqueda(arbol *raiz,char letra,arbol *padre){
    if (raiz ==NULL){
        return;
    }
    if (raiz->valor==letra){
        nodoBuscado=raiz;
        nodoPadre=padre;
        return;
    }
    busqueda(raiz->hizq,letra,raiz);
    busqueda(raiz->hmed,letra,raiz);
    busqueda(raiz->hder,letra,raiz);
}





//nodo hojas
void Verificador(arbol *raiz, arbol *padre) {
    if (raiz == NULL) {
        return;
    }
    if (raiz->hizq == NULL && raiz->hmed == NULL && raiz->hder == NULL) {
        int contador=0;
        x++;
        busqueda(padre,raiz->valor,NULL);
        while(nodoPadre!=NULL){
            contador++;
            busqueda(padre,nodoPadre->valor,NULL);
        }
        cout <<"Nodo Hoja: "<<raiz->valor<<" su altura es: "<<contador<<endl;
        if(contador==obtenerAltura(padre) || contador==(obtenerAltura(padre)-1)){
            y++;
        }
    }
    Verificador(raiz->hizq,padre);
    Verificador(raiz->hmed,padre);
    Verificador(raiz->hder,padre);
}

int main() {
    //arbol equilibrado
    arbol *ternario = new arbol('R');

    ternario->hizq = new arbol('O');
    ternario->hmed = new arbol('N');
    ternario->hder = new arbol('A');

    ternario->hizq->hizq = new arbol('L');
    ternario->hizq->hmed = new arbol('D');
    ternario->hizq->hder = new arbol('V');

    ternario->hmed->hizq = new arbol('E');
    ternario->hmed->hmed = new arbol('n');
    ternario->hmed->hder = new arbol('T');

    ternario->hder->hizq = new arbol('U');
    ternario->hder->hmed = new arbol('r');
    ternario->hder->hder = new arbol('a');

    ternario->hizq->hizq->hizq = new arbol('v');
    ternario->hizq->hizq->hmed = new arbol('e');
    ternario->hizq->hizq->hder = new arbol('x');

    ternario->hizq->hmed->hder = new arbol('y');
    



    //arbol no equlibrado
    /*
    arbol *ternario = new arbol('R');

    ternario->hizq = new arbol('O');
    ternario->hmed = new arbol('N');
    ternario->hder = new arbol('A');

    ternario->hizq->hizq = new arbol('L');
    ternario->hizq->hmed = new arbol('D');
    ternario->hizq->hder = new arbol('V');

    ternario->hmed->hizq = new arbol('E');
    ternario->hmed->hmed = new arbol('n');
    ternario->hmed->hder = new arbol('T');

    ternario->hder->hizq = new arbol('U');
    ternario->hder->hmed = new arbol('r');
    ternario->hder->hder = new arbol('a');

    ternario->hizq->hizq->hmed = new arbol('v');
    ternario->hder->hder->hmed = new arbol('e');

    ternario->hizq->hizq->hmed->hmed = new arbol('x');

    ternario->hder->hder->hmed->hmed = new arbol('y');
    */
    //altura del arbol
    cout<<"la altura del arbol es: "<<obtenerAltura(ternario)<<endl;
    cout<<endl;
    Verificador(ternario,ternario);
    cout<<endl;
    if(x==y){
        cout<<"El arbol es equilibrado.";
    }
    else{
        cout<<"El arbol no es equilibrado.";
    }
    return 0;
}