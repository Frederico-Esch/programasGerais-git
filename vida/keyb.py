from pynput.keyboard import Key, Controller
keyboard = Controller()
def digit(frase):
    keyboard.type(str(frase))
    keyboard.press(Key.enter)
    keyboard.release(Key.enter)
def pausa():
    keyboard.press(Key.space)
    keyboard.release(Key.space)