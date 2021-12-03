//Salvador Santana Blanco - A01703523

#include <iostream>
#include <vector>
#include "graph.h"
#include "quadratic.h"

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main(){
    
    //Lista de contraseñas de Cajas Negras de Aviones
    vector<string> listaContrasenas ={"ContrasenaSegura","password","hola","mundo"};

    Quadratic <string, int> quad_hash(10, string("empty"), myHash);
    int ans;
	string q_ans;

    //Se hace un hash para encriptar las las contraseñas
    quad_hash.put(string(listaContrasenas[0]), 11);
	quad_hash.put(string(listaContrasenas[1]), 12);
    quad_hash.put(string(listaContrasenas[2]), 14);
    quad_hash.put(string(listaContrasenas[3]), 16);

    //Sepresentan las contraseñas
    cout << quad_hash.toString().c_str()<<endl <<endl;
    
    Graph g(6);
    //Lista de auropuertos
    vector<string> listaAeropuertos = {"Mexico","EUA","China","Italia","España","Colombia"};
    for (size_t i = 0; i < listaAeropuertos.size(); i++){
        cout << (i) <<".- "<< listaAeropuertos[i] << endl;
    }

    //Se plantean las rutas
	g.addEdgeAdjList(0,3);
    g.addEdgeAdjList(0,1);
    g.addEdgeAdjList(1,2);
    g.addEdgeAdjList(1,3);
    g.addEdgeAdjList(2,4);
    g.addEdgeAdjList(3,4);

    cout<<endl;
    //Se quiere la ruta de México a España
    g.breadthSearchFirst(0,4);

    //Se quiere la ruta de Italia a México
    g.depthSearchFirst(3,0);
}