#include <iostream>
#include <ctime>
#include <cstdlib>
#include "MyList.h"
using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0));
    //Lista de inteiros
    MyList<int> lista; 
    //Tamanho da Lista
    int T = atoi(argv[1]);
    // cout << "T = " << T << endl;
    //Numero de percursos
    int X = atoi(argv[2]);
    // cout << "X = " << X << endl;
    //Numero de swaps
    int M = atoi(argv[3]);
    // cout << "M = " << M << endl;
    
    //Preenche a lista
    for(int i=0; i<T; i++){
        lista.push_back(i);
    }

    //Faz X percursos completos
    for(int i=0; i<X; i++){
        MyList<int>::iterator it = lista.begin();
        while(it!=lista.end()){
            // cout << lista.deref(it) << " ";
            it = lista.next(it);
        }
        // cout << endl;
    }

    //Faz M swaps aleatórios
    for(int a=0; a<M; a++){
        int I = rand()%T;
        int J = rand()%T;
        MyList<int>::iterator it1 = lista.begin();
        MyList<int>::iterator it2 = lista.begin();
        for(int i=0; i<I; i++){
            it1 = lista.next(it1);
        }
        for(int i=0; i<J; i++){
            it2 = lista.next(it2);
        }
        swap(lista.deref(it1),lista.deref(it2));
    }
    return 0;
}




  



