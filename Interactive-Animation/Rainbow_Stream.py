'''
PC07_Rainbow_Stream.py
Seven rows of colors, ordered in a rainbow from red to violet, is animated to move along with the mouse. 
If the mouse goes to the right, the rows will follow to the right. If the mouse goes to the left, the 
rows will follow to the left.

If user moves mouse to the left, prints "Mouse moving to the left". If user moves mouse to the right,
prints "Mouse moving to the right".

If the user clicks their mouse or presses the space bar, then the rainbow will switch colors from 
violet to red. Then if the user clicks their mouse or presses the space bar again, the rows will switch 
back to its original red to violet order.

Authors: Kai Franks and Catherine Xie  
'''

# Setup
from platform import python_branch
from tkinter import Button
import pygame, math, time, random
pygame.init()

w = 600
h = 600
win = pygame.display.set_mode((w,h))
pygame.display.set_caption("Rainbow Stream") # Setting the caption of the pygame
# Colors
VIOLET = (148,0,211)
PURPLE = (75,0,130)
BLUE = (0,0,255)
GREEN = (0,255,0)
YELLOW = (255,255,0)
ORANGE = (255,127,0)
RED = (255,0,0)

palette = [VIOLET, PURPLE, BLUE, GREEN, YELLOW, ORANGE, RED] # rainbow

clock = pygame.time.Clock() # clock object that controls the flow of our animation

# Define function

def move(x, step, offsetx): # Function that makes several balls with each color of the rainbow.
    # Move from left to right while it pulses
   
    x -= step # x = x + step
     # Could possibly make color and y offset apart of a loop
    pygame.draw.circle(win, palette[0], (x + offsetx,y + 150), 20) # Pygame circle violet
    pygame.draw.circle(win, palette[1], (x + offsetx,y + 100), 20) # Pygame circle purple
    pygame.draw.circle(win, palette[2], (x + offsetx,y + 50), 20) # Pygame circle blue
    pygame.draw.circle(win, palette[3], (x + offsetx,y - 0), 20) # Pygame circle green
    pygame.draw.circle(win, palette[4], (x + offsetx,y - 50), 20) # Pygame circle yellow
    pygame.draw.circle(win, palette[5], (x + offsetx,y - 100), 20) # Pygame cirlce orange
    pygame.draw.circle(win, palette[6], (x + offsetx,y - 150), 20) # Pygame circle red
    x -= step
    return step

def repeat_move(): # A function to repeat the rainbow row while also offseting the x to make it a rainbow.
    b = 650
    for i in range(19): # for loop with a range of 18 to make enough rows to cover the screen.
        b -= 50
        move(x, moving, b)

    # # Animation Variables
moving = 10 # Increment of movement
x = w/2 # horizontal center
y = h/2 # vertical center
cross = 0 # screen cross variable
running = True # Endless condition

def main():
    global running, x, y, moving, cross, palette

    while running:
        win.fill((0,0,0)) # Screen fill to black

        pygame.draw.circle(win, (0,0,0), (x,y + 200), 20) # black tracker ball

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                    running = False # stops animation
                    #pygame.quit() # stops running code & closes window

            if event.type == pygame.MOUSEBUTTONDOWN:
                    palette.reverse() # mouse click, palette switch

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                        palette.reverse() # press space bar, palette switches
                        
            elif event.type == pygame.MOUSEMOTION:
                if event.rel[0] > 0:
                        x += moving
                        print("Mouse moving to the right")
                elif event.pos[0] > 0:
                        x -= moving
                        print("Mouse moving to the left")
                        
            repeat_move()

            if x < 0:
                x = 200
                cross -= 1

            if x > 300:
                x = 200
                cross +=1

            pygame.display.update() # draw all our images onto surface
            clock.tick(30)
main()
