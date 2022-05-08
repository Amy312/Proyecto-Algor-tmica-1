#include <bits/stdc++.h>

using namespace std;
/**
Menu
**/
void menu()
{
    int opcion;
    cout << "   El menu funciona" << endl;
    cout << "---_---_---_---_---_---_" << endl;
    cout << "1. Añadir nueva ruta" << endl;
    cout << "2. Elegir punto de partida y destino" << endl;
    cout << "3. Viaje Rápido" << endl;
    cout << "4. Viaje Económico" << endl;
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
    default:
        cout << ":c Intente de nuevo" << endl;
        menu();
    }
}

void opcion1()
{
    // 1. Añadir nueva ruta
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

int main()
{
    menu();

    return 0;
}
