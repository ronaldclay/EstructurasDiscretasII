#include <iostream>
#include <queue>
#include <vector>

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
    this->hizq = nullptr;
    this->hmed = nullptr;
    this->hder = nullptr;
}


void mostrarVector(const std::vector<arbol*>& vec) {
    std::cout << "Marcado: ";
    for (const auto& elemento : vec) {
        std::cout << elemento->valor << " ";
    }
    std::cout << std::endl;
}

void mostrarCola(const std::queue<arbol*>& cola) {
    std::cout << "Fila: ";
    std::queue<arbol*> tempCola = cola;

    while (!tempCola.empty()) {
        std::cout << tempCola.front()->valor << " ";
        tempCola.pop();
    }

    std::cout << std::endl;
}
arbol *nodoPadre;
void Bpadre(arbol *raiz,char letra,arbol *padre){
    if (raiz ==NULL){
        return;
    }
    if (raiz->valor==letra){
        nodoPadre=padre;
        return;
    }
    Bpadre(raiz->hizq,letra,raiz);
    Bpadre(raiz->hmed,letra,raiz);
    Bpadre(raiz->hder,letra,raiz);
}

// Busqueda por anchura
bool bfs(arbol* raiz, char valor) {
    if (!raiz) {
        return false;
    }

    std::queue<arbol*> cola;
    std::vector<arbol*> ListaC;

    cola.push(raiz);
    ListaC.push_back(raiz);

    mostrarCola(cola);
    mostrarVector(ListaC);

    while (!cola.empty()) {
        arbol* RaizActual = cola.front();
        cola.pop();

        // Verificar si el nodo actual tiene el valor buscado
        if (RaizActual->valor == valor) {
            Bpadre(raiz, valor,NULL);
            std::cout <<nodoPadre->valor<<"->"<< valor << std::endl;
            return true;
        }
        if (RaizActual->hizq) {
            // Verificar si fue visitado
            bool visito = false;
            for (arbol* node : ListaC) {
                if (node == RaizActual->hizq) {
                    visito = true;
                    break;
                }
            }
            //cuando no visito
            if (!visito) {
                cola.push(RaizActual->hizq);
                ListaC.push_back(RaizActual->hizq);
            }
        }

        if (RaizActual->hmed) {
            // Verificar si fue visitado
            bool visito = false;
            for (arbol* node : ListaC) {
                if (node == RaizActual->hmed) {
                    visito = true;
                    break;
                }
            }
            //cuando no visito
            if (!visito) {
                cola.push(RaizActual->hmed);
                ListaC.push_back(RaizActual->hmed);
            }
        }

        if (RaizActual->hder) {
            // Verificar si fue visitado
            bool visito = false;
            for (arbol* node : ListaC) {
                if (node == RaizActual->hder) {
                    visito = true;
                    break;
                }
            }
            //cuando no se visita
            if (!visito) {
                cola.push(RaizActual->hder);
                ListaC.push_back(RaizActual->hder);
                
            }
        }
        mostrarCola(cola);
        mostrarVector(ListaC);
    }
    //si esque el valor no fue encotrado
    std::cout << "Valor no encontrado: " << valor << std::endl;
    return false;
}

int main() {
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
    
    // Búsqueda por anchura
    std::cout<<"Ingrese el nodo: ";
    char valor ;
    std::cin >> valor;
    std::cout<<std::endl;
    bfs(ternario, valor);
    return 0;
}