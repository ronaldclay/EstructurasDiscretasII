/*
rrecorridos de una arbol.
R = raiz
I = izquierda
D = derecha

rrecorrido preorden -> RID
rrecorrido inorden -> IRD
recoorrido posorder -> IDR
*/
#include <iostream>
using namespace std;
class arbol{
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
arbol::arbol(char valor){
    this->valor=valor;
    this->hizq=NULL;
    this->hmed=NULL;
    this->hder=NULL;
}
void recorridoPreorden(arbol *raiz){
    if (raiz==NULL){
        return;
    }
    cout<<raiz->valor<<",";
    recorridoPreorden(raiz->hizq);
    recorridoPreorden(raiz->hmed);
    recorridoPreorden(raiz->hder);
}
void recorridoInorden(arbol *raiz){
    if (raiz==NULL){
        return;
    }
    recorridoInorden(raiz->hizq);
    cout<<raiz->valor<<",";
    recorridoInorden(raiz->hmed);
    recorridoInorden(raiz->hder);
}
void recorridoPostorden(arbol *raiz){
    if (raiz==NULL){
        return;
    }
    recorridoPostorden(raiz->hizq);
    recorridoPostorden(raiz->hmed);
    recorridoPostorden(raiz->hder);
    cout<<raiz->valor<<",";
}
int main(){
    arbol *ternario = new arbol('R');

    ternario->hizq = new arbol('O');
    ternario->hmed = new arbol('N');
    ternario->hder = new arbol('A');

    ternario->hizq->hizq = new arbol('L');
    ternario->hmed->hizq = new arbol('D');
    ternario->hmed->hmed = new arbol('V');
    ternario->hmed->hder = new arbol('E');
    ternario->hder->hder = new arbol('N');

    ternario->hizq->hizq->hizq = new arbol('T');
    ternario->hizq->hizq->hmed = new arbol('U');
    ternario->hizq->hizq->hder = new arbol('R');
    ternario->hmed->hizq->hmed = new arbol('A');
    ternario->hmed->hmed->hmed = new arbol('V');
    ternario->hmed->hder->hmed = new arbol('E');
    ternario->hder->hder->hizq = new arbol('N');
    ternario->hder->hder->hmed = new arbol('E');
    ternario->hder->hder->hder = new arbol('R');

    ternario->hder->hder->hder->hmed = new arbol('O');

    cout<<"Recorrido de Preorden: ";
    recorridoPreorden(ternario);
    cout<<endl;

    cout<<"Recorrido de Inorden: ";
    recorridoInorden(ternario);
    cout<<endl;

    cout<<"Recorrido de Postorden: ";
    recorridoPostorden(ternario);
    cout<<endl;
    return 0;
}
