import pygame, random
from pygame.locals import *

#pygame.init()

rev_posx = random.randint(0,100)
rev_posy = random.randint(0,100)
rev_movement= random.random()
_SIZE = 600

screen = pygame.display.set_mode((_SIZE,_SIZE))
pygame.display.set_caption('fredgame')
rev = pygame.image.load('ata.jpg')
rev = pygame.transform.scale(rev, (100, 100))
RECT = rev.get_rect()

#rev = pygame.Surface((10,10))
#rev.fill((255,255,255))
print(RECT)

def change(pos):
    pos+= rev_movement
    if(pos + RECT[3] > _SIZE):
        return 0
    else:
        return pos

def event_handler():
    for event in pygame.event.get():
        if ((event.type == QUIT) or (event.type == KEYDOWN and event.key == K_ESCAPE)):
            pygame.quit()
            quit()

while True:
    event_handler()
    screen.fill((100,100,100))
    screen.blit(rev, (rev_posx, rev_posy))
    rev_posx = change(rev_posx)
    rev_posy = change(rev_posy)
    pygame.display.update()