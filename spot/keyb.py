import pyautogui
import random
def pre(st):
    pyautogui.press(str(st))
def hot():
    pyautogui.hotkey('alt',' ')
def al():
    pyautogui.hotkey('ctrl', 's')
def busc():
    pyautogui.hotkey('ctrl', 'l')
def mus():
    sorti = random.choice(['beatles', 'wallows', 'HUNNY', 'Hippo Campus'])
    pyautogui.typewrite(sorti, 0.2)
    pre('enter')
def cl():
    pyautogui.hotkey('ctrl', 'right')
def pas():
    num = random.randint(0,5)
    for i in range(num):
        if(random.randint(0,10) % 2 is 0):
            cl()