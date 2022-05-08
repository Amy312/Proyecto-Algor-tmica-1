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

void opcion1()
{
    // 1. Añadir nueva ruta
    cout<<"Escriba la ruta en el siguiente formato separado por espacios:"<<endl;
    cout<<"Nodo inicial - Nodo final - Peso"<<endl;

    agregar_nodo_arista();
}
void opcion2()
{
    // 2. elegir punto de partida y destino
}
void opcion3()
{
    // 3. Viaje rapido
}
void opcion4()
{
    // 4. Viaje Económico
}
void salir()
{
    // 5. Salir del Programa
}

void menu()
{
    int opcion;
    cout << "   El menu funciona" << endl;
    cout << "---_---_---_---_---_---_" << endl;
    cout << "1. Añadir nueva ruta" << endl;
    cout << "2. Elegir punto de partida y destino" << endl;
    cout << "3. Viaje Rápido" << endl;
    cout << "4. Viaje Económico" << endl;
    cout << "5. Salir del Programa" << endl;
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
}

int main()
{
    leer_grafo();
    menu();

    return 0;
}
