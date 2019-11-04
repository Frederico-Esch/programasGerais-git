from pywinauto import application
import keyb
from pynput.mouse import Button, Controller
import time
import random
frase = random.choice(['beatles', 'HUNNY', 'hippo campus', 'bohnes', 'wallows', 'wallows'])
mouse = Controller()
app = application.Application()
app.start('spotify.exe')
time.sleep(15)
# keyb.pausa()
# input('digite o nome de uma banda: ')
mouse.position = (400, 20)
mouse.click(Button.left)
keyb.digit(frase)
# 329, 178
time.sleep(8)
# 522, 163
mouse.position = (329, 178)
time.sleep(1)
mouse.click(Button.left)
time.sleep(1)
mouse.position = (1181, 687)
time.sleep(1)
mouse.click(Button.left)
time.sleep(1)
mouse.position = (1190, 562)
time.sleep(1)
mouse.click(Button.left)
time.sleep(1)
mouse.position = (584, 676)
time.sleep(3)
mouse.click(Button.left)
num = random.randint(0,10)
for i in range(num):
    if random.randint(0,10) % 2 is 0:
        mouse.position = (732, 674)
        time.sleep(1)
        mouse.click(Button.left)