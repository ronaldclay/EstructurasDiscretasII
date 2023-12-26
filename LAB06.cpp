#include <iostream>
using namespace std;

class arbol {
public:
    char valor;
    arbol *hizq;
    arbol *hmed;
    arbol *hder;

    arbol(char valor);
    void recorridoPreorden(arbol *raiz);
    void recorridoInorden(arbol *raiz);
    void recorridoPostorden(arbol *raiz);
};

arbol::arbol(char valor) {
    this->valor = valor;
    this->hizq = NULL;
    this->hmed = NULL;
    this->hder = NULL;
}

void recorridoPreorden(arbol *raiz) {
    if (raiz == NULL) {
        return;
    }
    cout << raiz->valor << ",";
    recorridoPreorden(raiz->hizq);
    recorridoPreorden(raiz->hmed);
    recorridoPreorden(raiz->hder);
}
arbol *nodoBuscado;
arbol *nodoPadre;
void busquedaDcendiente(arbol *raiz,char letra,arbol *padre){
    if (raiz ==NULL){
        return;
    }
    if (raiz->valor==letra){
        nodoBuscado=raiz;
        nodoPadre=padre;
        return;
    }
    busquedaDcendiente(raiz->hizq,letra,raiz);
    busquedaDcendiente(raiz->hmed,letra,raiz);
    busquedaDcendiente(raiz->hder,letra,raiz);
}

int main() {
    char dletra;
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

    ternario->hizq->hizq->hizq = new arbol('v');
    ternario->hizq->hizq->hmed = new arbol('e');
    ternario->hizq->hizq->hder = new arbol('x');

    ternario->hizq->hmed->hder = new arbol('y');
    */

    arbol *ternario = new arbol('a');

    ternario->hizq = new arbol('b');
    ternario->hmed = new arbol('c');
    ternario->hder = new arbol('d');

    ternario->hizq->hizq = new arbol('e');
    ternario->hmed->hizq = new arbol('f');
    ternario->hmed->hmed = new arbol('g');///
    ternario->hmed->hder = new arbol('h');
    ternario->hder->hder = new arbol('i');

    ternario->hizq->hizq->hizq = new arbol('j');
    ternario->hizq->hizq->hmed = new arbol('k');
    ternario->hizq->hizq->hder = new arbol('l');
    ternario->hmed->hizq->hmed = new arbol('m');
    ternario->hmed->hmed->hmed = new arbol('n');///
    ternario->hmed->hder->hmed = new arbol('o');
    ternario->hder->hder->hizq = new arbol('p');
    ternario->hder->hder->hmed = new arbol('q');
    ternario->hder->hder->hder = new arbol('r');

    ternario->hder->hder->hder->hmed = new arbol('O');
    //decendientres

    cout << "Ingrese el nodo: ";
    cin.get(dletra);
    busquedaDcendiente(ternario, dletra,NULL);
    if (nodoBuscado==NULL){
        cout<<"El nodo "<<dletra<<" no existe.";
        return 0;
    }
    cout<<"Los nodos decendientes de  "<<dletra<<" son: ";
    recorridoPreorden(nodoBuscado->hizq);
    recorridoPreorden(nodoBuscado->hmed);
    recorridoPreorden(nodoBuscado->hder);
    
    //padre de Pletra
    cout<<endl;
    if (nodoPadre==NULL){
        cout<<"El nodo "<<dletra<<" No tiene padre.";
        cout<<endl;
        cout<<"El nodo "<<dletra<<" No tiene ascendienstes.";
        return 0;
    }
    cout<<"El padre de "<<nodoBuscado->valor<<" es: "<<nodoPadre->valor;
    
    //ascendientes
    cout<<endl;
    cout<<"Los ascendientes del nodo "<<dletra<<" son: ";
    while(nodoPadre!=NULL){
        cout<<nodoPadre->valor<<",";
        busquedaDcendiente(ternario,nodoPadre->valor,NULL);
    }

    return 0;
}