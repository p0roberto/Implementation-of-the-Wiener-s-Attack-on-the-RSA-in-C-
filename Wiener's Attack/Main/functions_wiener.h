#ifndef FUNCTIONS_WIENER
#define FUNCTIONS_WIENER
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

void calcular_convergente(vector<pair<ull, ull>>& convergentes, vector<ull> indices, ull& iesimo){
    if(iesimo == 0){ // caso base
        convergentes[0] = {indices[0], 1};
    } else if(iesimo == 1){ // caso base
        convergentes[1] = {indices[0] * indices[1] + 1, indices[1]};
    }
    else{ // calcula os convergentes seguintes
        convergentes.push_back({
        indices[iesimo]*convergentes[iesimo-1].first + convergentes[iesimo-2].first,
        indices[iesimo]*convergentes[iesimo-1].second + convergentes[iesimo-2].second});
    }
}

bool verificar(ld exp_pub, ld mod_N, ld dlinha, ld klinha){ // Verifica se determinado convervente produz a chave privada
    ld phi = (exp_pub * dlinha - 1) / klinha;
    ld x = (mod_N - phi + 1)/2;
    ld y = sqrt(x*x - mod_N);

    if (inteiro(phi) && inteiro(x) && inteiro(y)) {
        return true;
    }
    return false;
}

bool WienerAttack(ull p, ull q, vector<pair<ull, ull>>& convergentes, ull& i) {    
    vector<ull> indices; // Armazena os índidces da fração contínua e/N
    ull exp_pub = p; // auxiliar
    ull mod_N = q; // auxiliar
    ull dmax = (d_max(mod_N));

    while (q != 0) {
        indices.push_back(p / q); // calcula o i-ésimo índice

        calcular_convergente(convergentes, indices, i); // utiliza os índices para calcular o i-ésimo convergente

        if(verificar(exp_pub, mod_N, convergentes[i].second, convergentes[i].first)){
            return true; // o i-ésimo convergente produz as chaves privadas
        }
        if(convergentes[i].second > dmax){
            return false; // o denominador do i-ésimo convergente ultrapassou o d_max
        }
        
        i++;
        ull auxiliar = p % q;
        p = q;
        q = auxiliar; 
    }

    return false;
}

void chaveprivada(vector<pair<ull, ull>>& convergentes, ull iesimo, ull exp_pub, ull mod_N){
    // printa a chave privada quando o algorítmo obtem sucesso
    ull phi = (exp_pub*convergentes[iesimo].second - 1)/convergentes[iesimo].first;
    ull x = (mod_N - phi + 1)/2 ;
    ull y = sqrt(x*x - mod_N);
    ull p = x - y;
    ull q = x + y;
    cout << "(p, q, d) = " << "(" << p << ", " <<  q << ", " << convergentes[iesimo].second << ")\n";
}

#endif FUNCTIONS_WIENER