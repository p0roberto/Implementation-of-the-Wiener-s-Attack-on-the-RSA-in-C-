import math
from typing import List, Tuple

# Define os tipos de dados usados
ull = int
ld = float

def inteiro(num: ld) -> bool:
    # Verifica se determinado valor é inteiro
    return num == int(num)

def d_max(mod_N: int) -> float:
    # Calcula o valor máximo de d, para que seja possível obter um convergente válido
    return math.floor(pow(mod_N, 1.0/4.0) / 3)

mod_N = ull(input("Digite o valor de N: "))  # Módulo N, produto entre os dois primos
exp_pub = ull(input("Digite o valor do expoente público: "))  # Expoente público
iesimo = 0  # i-ésimo convergente que gera a chave privada

indices = []  # Armazena os índices da fração contínua e/N
convergentes = [(0, 0), (0, 0)]  # armazena os convergentes pi/qi da fração contínua de e/N

p = exp_pub  # auxiliar
q = mod_N # auxiliar
dmax = d_max(mod_N)

while q != 0:
    indices.append(p // q)  # calcula o i-ésimo índice
    
    if iesimo == 0:  # caso base
        convergentes[0] = (indices[0], 1)
    elif iesimo == 1:  # caso base
        convergentes[1] = (indices[0] * indices[1] + 1, indices[1])
    else:  # calcula os convergentes seguintes
        convergentes.append((
            indices[iesimo] * convergentes[iesimo-1][0] + convergentes[iesimo-2][0],
            indices[iesimo] * convergentes[iesimo-1][1] + convergentes[iesimo-2][1]))
    
    if iesimo > 0:
            phi = (exp_pub * convergentes[iesimo][1] - 1) / convergentes[iesimo][0]
            x = (mod_N - phi + 1) / 2
            y = math.sqrt(x*x - mod_N)

            if inteiro(phi) and inteiro(x) and inteiro(y):
                p = ull(x - y)
                q = ull(x + y)
                print(f"(p, q, d) = ({p}, {q}, {convergentes[iesimo][1]})")                
                break

            if convergentes[iesimo][1] > dmax:
                break; # o denominador do i-ésimo convergente ultrapassou o d_max
            
    # print(f"convergente {iesimo}, {convergentes[iesimo][0]},/{convergentes[iesimo][1]}")

    iesimo += 1
    auxiliar = p % q
    p = q
    q = auxiliar

print("Algoritmo encerrado")