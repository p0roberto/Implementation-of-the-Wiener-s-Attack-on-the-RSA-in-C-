import math

def inteiro(num: int) -> bool:
    # Verifica se determinado valor é inteiro
    return num == int(num)

def int_root(x: int, n: int) -> int:
    # Calcula a raiz n-ésima inteira de x usando busca binária
    low, high = 1, x
    while low < high:
        mid = (low + high + 1) // 2
        if mid**n > x:
            high = mid - 1
        else:
            low = mid
    return low

def d_max(mod_N: int) -> int:
    # Calcula o valor máximo de d usando uma aproximação inteira
    return int_root(mod_N, 4) // 3

# Entrada de dados
mod_N = int(input("\nDigite o valor de N: "))  # Módulo N, produto entre os dois primos
exp_pub = int(input("\nDigite o valor do expoente público: "))  # Expoente público

iesimo = 0  # i-ésimo convergente que gera a chave privada
indices = []  # Armazena os índices da fração contínua e/N
convergentes = [(0, 0), (0, 0)]  # Armazena os convergentes pi/qi da fração contínua de e/N

p = exp_pub  # auxiliar
q = mod_N  # auxiliar
dmax = d_max(mod_N)

while q != 0:
    indices.append(p // q)  # Calcula o i-ésimo índice
    
    if iesimo == 0:  # Caso base
        convergentes[0] = (indices[0], 1)
    elif iesimo == 1:  # Caso base
        convergentes[1] = (indices[0] * indices[1] + 1, indices[1])
    else:  # Calcula os convergentes seguintes
        convergentes.append((
            indices[iesimo] * convergentes[iesimo-1][0] + convergentes[iesimo-2][0],
            indices[iesimo] * convergentes[iesimo-1][1] + convergentes[iesimo-2][1]
        ))
    
    if iesimo > 0:
        # Trabalhar com inteiros ao calcular phi
        phi_num = exp_pub * convergentes[iesimo][1] - 1
        phi_den = convergentes[iesimo][0]

        if phi_num % phi_den == 0:  # Verifica se phi é um inteiro
            phi = phi_num // phi_den
            x_num = mod_N - phi + 1
            x_den = 2

            if x_num % x_den == 0:  # Verifica se x é um inteiro
                x = x_num // x_den
                y_square = x * x - mod_N

                if y_square >= 0:
                    y = int(math.isqrt(y_square))

                    if y * y == y_square:
                        p = x - y
                        q = x + y
                        print(f"\n(p, q, d) = ({p}, {q}, {convergentes[iesimo][1]})")
                        break
        
        if convergentes[iesimo][1] > dmax:
            break  # O denominador do i-ésimo convergente ultrapassou o d_max
    
    iesimo += 1
    p, q = q, p % q

print("\nAlgoritmo encerrado")