#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ld long double

bool inteiro(ld num){ // Verifica se determinado valor é inteiro
    return num == static_cast<ull>(num);
}

ull d_max(ull mod_N){ // Calcula o valor máximo de d, para que seja possível obter um convergente válido
    return floor(pow(mod_N, 1.0/4.0) / 3);
}

int main(){
    ull mod_N; // Módulo N, produto entre os dois primos
    ull exp_pub; // Expoente público
    ull iesimo = 0; // i-ésimo convergente que gera a chave privada

    vector<pair<ull, ull>> convergentes; // armazena os convergentes pi/qi da fração continua de e/N
    vector<ull> indices; // Armazena os índices da fração contínua e/N

    cout << "Digite o valor de N: ";
    cin >> mod_N;
    cout << "Digite o valor do expoente publico: ";
    cin >> exp_pub;

    ull dmax = (d_max(mod_N));
    ull q = mod_N; // auxiliar
    ull p = exp_pub; // auxiliar

    while (q != 0) {
        indices.push_back(p / q); // calcula o i-ésimo índice
        // cout << "indice " << p/q << endl;

        if(iesimo == 0){ // caso base
            convergentes.push_back({indices[0], 1});
        } else if(iesimo == 1){ // caso base
            convergentes.push_back({indices[0] * indices[1] + 1, indices[1]});
        }
        else{ // calcula os convergentes seguintes
            convergentes.push_back({
            indices[iesimo]*convergentes[iesimo-1].first + convergentes[iesimo-2].first,
            indices[iesimo]*convergentes[iesimo-1].second + convergentes[iesimo-2].second});
        }
        
        if(iesimo > 0){
            ld phi = (exp_pub * convergentes[iesimo].second - 1) / convergentes[iesimo].first;
            ld x = (mod_N - phi + 1)/2;
            ld y = sqrt(x*x - mod_N);

            if(inteiro(phi) && inteiro(x) && inteiro(y)){
                ull p = x - y;
                ull q = x + y;
                cout << "(p, q, d) = " << "(" << p << ", " <<  q << ", " << convergentes[iesimo].second << ")\n";
                break;
            }
            if(convergentes[iesimo].second > dmax){
                break; // o denominador do i-ésimo convergente ultrapassou o d_max
            }
        }

        // cout << "convergente " << iesimo << ": " << convergentes[iesimo].first << "/" << convergentes[iesimo].second << endl;

        iesimo++;
        ull auxiliar = p % q;
        p = q;
        q = auxiliar; 
    }

    cout << "Algoritmo encerrado\n";

    return 0;
}