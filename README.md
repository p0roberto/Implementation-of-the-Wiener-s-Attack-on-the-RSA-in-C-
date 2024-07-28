O RSA se baseia na dificuldade prática de fatorar o produto de dois números primos grandes. Dentre os diversos ataques conhecidos contra o criptossistema, o Ataque de Wiener se destaca por explorar fraquezas em chaves privadas sob determinadas condições. O Ataque de Wiener se apoia em importantes resultados da teoria de frações contínuas. Dados "N" o produto entre dois números primos grandes, e "e" o expoente público escolhido, a chave pública é definida por (N, e). Com uma escolha "inadequada" dos parâmetros da chave, pode-se encontrar "d", expoente privado da chave, como sendo o denominador de um dos convergentes da expansão por frações contínuas de e/N, em complexidade de tempo logarítmica. Ao se encontrar d, a segurança do sistema é comprometida, inviabilizando a troca de informações criptografadas, pois de posse do expoente privado, é possível se obter os demais elementos da chave. Apesar de suas limitações, dado que o ataque é eficiente apenas em casos onde d < N ¼·1⁄3 , o método possui uma excelente complexidade algorítmica, O(log(N)), tornando o Ataque de Wiener uma ferramenta valiosa para a análise de segurança de sistemas RSA, especialmente em ambientes onde as chaves podem ser comprometidas devido a configurações inadequadas.
