def question():
    global ano
    import quest2
    import datetime
    ano = datetime.datetime.now().year - quest2.answer()
def answer():
    global ano
    return ano
def perg():
    return 'Idade:'