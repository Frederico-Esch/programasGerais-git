def question():
    global idade
    try:
        idade = int(input('Digite o ano de seu nascimento: '))
        if(idade < 1940):
            raise Exception('anoInvalido')
    except:
        print('Digite um ano válido')
        question()
def answer():
    global idade
    return idade
def perg():
    return 'Ano de nascimento:'