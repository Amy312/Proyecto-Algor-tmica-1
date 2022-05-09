#include <bits/stdc++.h>
#define INF 100000010 // 1e9
using namespace std;
/**
Menu
**/

vector<pair<int, int> > grafoPrecio[1000];
vector<pair<int, int> > grafoTiempo[1000];
vector<string> nombre_lugares(1000);

void leer_grafo()
{
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

void leer_lugares()
{
    ifstream archivo;
    archivo.open("nombre_lugares.txt", fstream::in);

    int num;
    char lugar[100];
    while (archivo >> num)
    {
        archivo.getline(lugar, 100);
        nombre_lugares[num] = lugar;
    }
}

void agregar_nodo_arista()
{
    ofstream archivo;
    archivo.open("grafo.txt", fstream::app);
    int ini, fin, precio, tiempo;
    cin >> ini >> fin >> precio >> tiempo;

    archivo << ini << " " << fin << " " << precio << " " << tiempo << endl;
    archivo.close();

    grafoPrecio[ini].push_back(make_pair(precio, fin));
    grafoPrecio[fin].push_back(make_pair(precio, ini));
    //: D
    grafoTiempo[ini].push_back(make_pair(tiempo, fin));
    grafoTiempo[fin].push_back(make_pair(tiempo, ini));

    if (nombre_lugares[ini] == "")
    {
        cout << "Ups! parece que tu lugar de partida no tiene nombre, agrégale uno:" << endl;
        string lugar;
        cin.ignore();
        getline(cin,lugar);
        nombre_lugares[ini] = lugar;
        archivo.open("nombre_lugares.txt", fstream::app);
        archivo << ini << " " << lugar << endl;
        archivo.close();
    }
    if (nombre_lugares[fin] == "")
    {
        cout << "Ups! parece que tu lugar de llegada no tiene nombre, agrégale uno:" << endl;
        string lugar;
        cin.ignore();
        getline(cin,lugar);
        nombre_lugares[fin] = lugar;
        archivo.open("nombre_lugares.txt", fstream::app);
        archivo << fin << " " << lugar << endl;
        archivo.close();
    }
}

void lugares()
{

    for (int i = 0; i < nombre_lugares.size(); i++)
    {
        if (nombre_lugares[i] != "")
        {
            cout << i << ". " << nombre_lugares[i] << endl;
        }
    }
}

void opcion1()
{
    // 1. Añadir nueva ruta
    int ini, fin, peso;
    cout << "Elija los caminos por donde realizara su nueva ruta" << endl;
    cout << "Inicio - Final - Precio - Tiempo" << endl;
    agregar_nodo_arista();
}

int visitados[1000], nivel[1000][3];
void dijkstra(int verticeInicial, bool sw)
{
    memset(nivel, 0 ,sizeof(nivel));
    for(int i = 0; i < 1000; i++){
        nivel[i][2] = INF;
    }
    memset(visitados, 0, sizeof(visitados));

    multiset<pair<int, int> > colaPrioridad; // log(n)sk
    nivel[verticeInicial][2] = 0;
    colaPrioridad.insert(make_pair(0, verticeInicial));
        vector<pair<int, int> > *grafo1;
        vector<pair<int, int> > *grafo5; 
    if(!sw){
        grafo1 = grafoPrecio;
        grafo5 = grafoTiempo;
    }else{
        grafo5 = grafoPrecio; 
        grafo1 = grafoTiempo;
    }

    while (!colaPrioridad.empty())
    {
        pair<int, int> verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin()); 
        int vertice = verticeActual.second;
        if (!visitados[vertice])
        {
            visitados[vertice] = true;
            for (int i = 0; i < grafo1[vertice].size(); i++)
            {
                int verticeVecino = grafo1[vertice][i].second;
                int pesoVecino = grafo1[vertice][i].first;
                //    inf  >                    0 + 60
                // Relajacion 
                if (nivel[verticeVecino][2]> nivel[vertice][2] + pesoVecino )
                {
                    nivel[verticeVecino][2] = nivel[vertice][2] + pesoVecino;
                    nivel[verticeVecino][1] = vertice;
                    nivel[verticeVecino][0] = nivel[vertice][0]+ grafo5[vertice][i].first;
                    colaPrioridad.insert(make_pair(nivel[verticeVecino][2], verticeVecino));
                }
            }
        }
    }
}

void opcion2() // 2. Viaje rapido
{
    //sw = 1;
    cout << "Viaje Rápido" << endl;
    int origen, destino;
    cout << "Elija el punto de partida y el destino" << endl;
    cin >> origen >> destino;
    dijkstra(origen, 1);
    if (visitados[destino])
    {

        int punto = destino;
        vector<int> Ruta;
        Ruta.push_back(destino);
        do{
            Ruta.push_back(nivel[punto][1]);
            punto = nivel[punto][1];
        } while (punto != origen);
        cout << "El tiempo en llegar a su destino es de: " << nivel[destino][2] << " minutos pero tendra un costo de: Bs." << nivel[destino][0] << endl;
        for (int i = Ruta.size() - 1; i >= 1; i--)
        {
            cout << Ruta[i] << " --> ";
        }
        cout << Ruta[0] << endl;
    }
    else
    {
        cout << "No hay camino :c" << endl;
    }
    // Dijkstra tiempo
    
}
void opcion3() // 3. Viaje Económico
{
    //sw = 0
    cout << "Viaje Económico" << endl;
    int origen, destino;
    cout << "Elija el punto de partida y el destino" << endl;
    cin >> origen >> destino;
    dijkstra(origen, 0);
    if (visitados[destino])
    {

        int punto = destino;
        vector<int> Ruta;
        Ruta.push_back(destino);
        do
        {
            Ruta.push_back(nivel[punto][1]);
            punto = nivel[punto][1];
        } while (punto != origen);
        cout << "El costo mas barato para llegar a su destino es de: Bs." << nivel[destino][2] << " pero el tiempo sera de: " << nivel[destino][0] << "minutos" << endl;
        for (int i = Ruta.size() - 1; i >= 1; i--)
        {
            cout << Ruta[i] << " --> ";
        }
        cout << Ruta[0] << endl;
    }
    else
    {
        cout << "No hay camino :c" << endl;
    }

    // Dijkstra precio
    
}

void menu()
{
    cout << "========================================" << endl;
    cout << "|          -=Effective Paths=-         |" << endl;
    cout << "========================================" << endl;
    cout << "| 0. Lista de lugares predeterminados  |" << endl;
    cout << "| 1. Añadir nueva ruta                 |" << endl;
    cout << "| 2. Viaje Rápido                      |" << endl;
    cout << "| 3. Viaje Económico                   |" << endl;
    cout << "| 4. Salir del Programa                |" << endl;
    cout << "========================================" << endl;

    int opcion;
    cin >> opcion;
    cout << "========================================" << endl;
    switch (opcion)
    {
    case 0:
        lugares();
        break;
    case 1:
        opcion1();
        break;
    case 2:
        opcion2();
        break;
    case 3:
        opcion3();
        break;
    case 4:
        cout << "Saliendo del Programa" << endl;
        cout << "Gracias por utilizar Effective Paths" << endl;
        cout << "¡Hasta pronto! :D" << endl;
        exit(1);
        break;
    default:
        cout << "Opcion invalida, por favor vuelva a intentar." << endl;
        break;
        // menu();
    }
}

int main()
{
    leer_lugares();
    leer_grafo();

    while (1)
    {
        menu();
    }

    return 0;
}
