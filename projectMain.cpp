#include <bits/stdc++.h>

using namespace std;
/**
Menu
**/

vector<pair<int, int>> grafo[10];

void leer_grafo(){
    ifstream archivo;
    archivo.open("grafo.txt", fstream::in);

    int ini, fin, peso;
    while (archivo >> ini >> fin >> peso)
    {
        
        grafo[ini].push_back(make_pair(peso, fin));
        grafo[fin].push_back(make_pair(peso, ini));
        // grafoMat[ini][fin]=peso;
        // grafoMat[fin][ini]=peso;

    }
}

void agregar_nodo_arista(){
    ofstream archivo;
    archivo.open("grafo.txt", fstream::app);
    int ini,fin,peso;
    cin >> ini >> fin >> peso;
    
    grafo[ini].push_back(make_pair(peso, fin));
    grafo[fin].push_back(make_pair(peso, ini));
    // grafoMat[ini][fin]=peso;
    // grafoMat[fin][ini]=peso;
    
    archivo <<ini <<" "<< fin <<" " << peso<<endl;
    archivo.close();
}

void lugares(){
    cout << "1. Campus UPB" << endl;
    cout << "2. Plaza Humboldt" << endl;
    cout << "3. MegaCenter" << endl;
    cout << "4. Iglesia de San Miguel" << endl;
    cout << "5. UPB Post Grado" << endl;
    cout << "6. Monobloc UMSA" << endl;
    cout << "7. Estadio Hernando Siles" <<endl;
    cout << "8. Plaza del Estudiante" <<endl;
    cout << "9. Terminal de Buses" <<endl;
    cout << "10. Aeropuerto Internacional El Alto" <<endl;
}

void opcion1()
{
    // 1. Añadir nueva ruta
    int ini, fin ,peso;
    cout << "Elija los caminos por donde realizara su nueva ruta" << endl;
    cout << "Inicio - Final - Precio" << endl;
    lugares();
    agregar_nodo_arista();

}
void opcion2()
{
    // 2. elegir punto de partida y destino
    int origen, destino;
    cout << "Elija el punto de partida y el destino" << endl;
    lugares();
    cin >> origen >> destino;
}
void opcion3()
{
    // 3. Viaje rapido
    int destino;
    cout << "Viaje Rápido" << endl;
    cout << "Elija el punto de destino" << endl;    

}
void opcion4()
{
    // 4. Viaje Económico
    cout << "El camino mas economico te costara:";
}
void salir()
{
    // 5. Salir del Programa
    cout << "Saliendo del Programa" << endl;
}


void menu()
{
    cout << "     =Effective Paths=" << endl;
    cout << "---_---_---_---_---_---_---" << endl;
    cout << "1. Añadir nueva ruta" << endl;
    cout << "2. Elegir punto de partida y destino" << endl;
    cout << "3. Viaje Rápido" << endl;
    cout << "4. Viaje Económico" << endl;
    cout << "5. Salir del Programa" << endl;
}

int main()
{
    //menu();
        int opcion;
    menu();
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        opcion1();
    case 2:
        opcion2();
    case 3:
        opcion3();
    case 4:
        opcion4();
    case 5:
        salir();
    default:
        cout << ":c Intente de nuevo" << endl;
        menu();
    }

    return 0;
}
