#include <bits/stdc++.h>
//opcion 3 y 4
using namespace std;

vector<pair <int,int> > grafoM[100000], grafoT[100000];
map<string, int> Lugar;
int main(){
    int aris, vertices, costo, tiempo, a, b;
    cin >> aris >> vertices;
    for(int i=0; i<vertices; i++){
        cin >> a>> b>> costo >> tiempo;
        grafoM[a].push_back(make_pair(costo, b));
        

    }
    
}