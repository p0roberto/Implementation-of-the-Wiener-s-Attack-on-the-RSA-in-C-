#include "functions_wiener.h"

int main(){
    ull mod_N; // Módulo N, produto entre os dois primos
    ull exp_pub; // Expoente público
    ull iesimo = 0; // i-ésimo convergente que gera a chave privada

    vector<pair<ull, ull>> convergentes(2); // armazena os convergentes pi/qi da fração continua de e/N

    cout << "Digite o valor de N: ";
    cin >> mod_N;
    cout << "Digite o valor do expoente publico: ";
    cin >> exp_pub;

    if (WienerAttack(exp_pub, mod_N, convergentes, iesimo)){  // existe i-ésimo convergente que produz as chaves privadas?
        chaveprivada(convergentes, iesimo, exp_pub, mod_N);
    } else{
        cout << "Ataque de Wiener ineficiente\n";
    }

    return 0;
}