#include <bits/stdc++.h>

using namespace std;
/**
Menu
**/

vector<pair<int, int> > grafoPrecio[20];
vector<pair<int, int> > grafoTiempo[20];
vector<string> nombre_lugares(20);

void leer_grafo(){
    ifstream archivo;
    archivo.open("grafo.txt", fstream::in);

    int ini, fin, precio, tiempo;
    while (archivo >> ini >> fin >> precio >> tiempo)
    {
        
        grafoPrecio[ini].push_back(make_pair(precio, fin));
        grafoPrecio[fin].push_back(make_pair(precio, ini));
        
        grafoTiempo[ini].push_back(make_pair(tiempo, fin));
        grafoTiempo[fin].push_back(make_pair(tiempo, ini));
        // grafoMat[ini][fin]=peso;
        // grafoMat[fin][ini]=peso;

    }
}

void leer_lugares(){
    ifstream archivo;
    archivo.open("nombre_lugares.txt", fstream::in);

    int num;
    string lugar;
    while (cin>>num>>lugar)
    {
        nombre_lugares[num]=lugar;
    }
    
}

void agregar_nodo_arista(){
    ofstream archivo;
    archivo.open("grafo.txt", fstream::app);
    int ini,fin, precio, tiempo;
    cin >> ini >> fin >> precio>> tiempo;
    
    grafoPrecio[ini].push_back(make_pair(precio, fin));
    grafoPrecio[fin].push_back(make_pair(precio, ini));
    //:D
    grafoTiempo[ini].push_back(make_pair(tiempo, fin));
    grafoTiempo[fin].push_back(make_pair(tiempo, ini));
    // grini][fin]=peso;//arreglalo :3
    // grafoMat[fin][ini]=peso;
    archivo << ini <<" "<< fin <<" " << precio<<" " << tiempo <<endl;
    archivo.close();
}

void lugares(){
    
    for (int i = 0; i < nombre_lugares.size(); i++)
    {
        cout<<
    }
    
    
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
    agregar_nodo_arista();

}
void opcion2()
{
    // 2. elegir punto de partida y destino
    int origen, destino;
    cout << "Elija el punto de partida y el destino" << endl;
    cin >> origen >> destino;
}
void opcion3()
{
    // 3. Viaje rapido
    int destino;
    cout << "Viaje Rápido" << endl;
    cout << "Elija el punto de destino" << endl;  
    //Dijkstra tiempo
    cout << "El tiempo en llegar a su destino es de: "<< << " minutos pero tendra un costo de: Bs." << <<endl;
}
void opcion4()
{
    // 4. Viaje Económico
    cout << "Viaje Económico"<<endl;
    //Dijkstra precio
    cout << "El costo mas barato para llegar a su destino es de: Bs."<< << " pero el tiempo sera de: " << <<"minutos"<<endl;
}
void salir()
{
    // 5. Salir del Programa
    cout << "Saliendo del Programa" << endl;
    cout << "Gracias por utilizar Effective Paths"<<endl;
    cout << "¡Hasta pronto! :D" << endl;
}


void menu()
{
    cout << "         -=Effective Paths=-" << endl;
    cout << "========================================" << endl;
    cout << "| 0. Lista de lugares predeterminados  |" << endl;
    cout << "| 1. Añadir nueva ruta                |" << endl;
    cout << "| 2. Elegir punto de partida y destino" << endl;
    cout << "| 3. Viaje Rápido" << endl;
    cout << "| 4. Viaje Económico" << endl;
    cout << "| 5. Salir del Programa" << endl;
    cout << "======================================" << endl;
}

int main()
{
    //menu();
        int opcion;
    menu();
    cin >> opcion;
    switch (opcion)
    {
    case 0:
        lugares();
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
        cout << "Opcion invalida, por favor vuelva a intentar." << endl;
        menu();
    }

    return 0;
}
