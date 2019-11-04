lista = []
lista_p = []
lista_i = []
while True:
    num = int(input('Informe um número (zero para sair): '))
    if num is 0:
        break
    lista.append(num)
for i in range(len(lista)):
    if lista[i] % 2 is 0:
        lista_p.append(lista[i])
    else:
        lista_i.append(lista[i])
print('pares: ' + str(lista_p))
print('impares: ' + str(lista_i))
