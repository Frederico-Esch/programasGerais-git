import pyautogui
# pyautogui.FAILSAFE = False
import keyb
from time import sleep
import op

op.ss()


def corz():
    im = pyautogui.screenshot()
    co = im.getpixel((407, 716))
    return co


#             pyautogui.moveTo(100, 100)
sleep(10)
keyb.hot()
for i in range(0, 5):
    keyb.pre('down')
    sleep(0.3)
keyb.pre('enter')
cor = corz()
sleep(2)
if not (cor[1] > cor[0]) or not (cor[1] > cor[2]):
    pyautogui.moveTo(1176, 693)
    sleep(0.5)
    pyautogui.click(button='left')
    sleep(0.5)
    pyautogui.moveTo(1143, 559)
    sleep(0.5)
    pyautogui.click(button='left')
keyb.busc()
sleep(0.5)
keyb.mus()
sleep(3)
pyautogui.moveTo(336, 179)
pyautogui.click(button='left')
if pyautogui.locateOnScreen('al.png') is not None:
    keyb.al()
    sleep(3)
if pyautogui.locateOnScreen('botao.png') is not None:
    keyb.pre(' ')
    sleep(3)
keyb.pas()