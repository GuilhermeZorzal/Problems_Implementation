// 25/11/2022 = resolvido
//https://codeforces.com/group/ZkeEs5BdJs/contest/404675/problem/A?f0a28=1

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){

    priority_queue <int> fila;
    
    int tam,cont = 0,x,y;
    cin >> tam;

    for (int i = 0; i<tam; i++){
        x;
        cin >> x;
        if (x != 0) fila.push(x);
    }
    while(fila.size() > 1){
        x = fila.top();
        fila.pop();
        y = fila.top();
        fila.pop();
        x = x-1;
        y = y-1;
        if (x != 0) fila.push(x);
        if (y != 0) fila.push(y);
        cont += 1;

    }
    cout << cont << endl;

    return 0;
}

