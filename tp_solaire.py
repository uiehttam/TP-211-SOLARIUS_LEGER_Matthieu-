# Ne pas oublier les utf8 etc

import time
from adafruit_servokit import ServoKit
from adafruit_circuitplayground.express import cpx
import simpleio

# 1er sénario : 2 servos pour décrire un arc de cercle à notre panneau

import time
from adafruit_servokit import ServoKit

# Dans notre expérience, nous aurons 2 servos

kit = ServoKit(channels=2)

angle_init = 0
# pour le servo 1
def initialisation ():
    """Ici nous allons initliasiter la postion initale
    des 2 servos"""

# Pour le servo 1

    kit.servo[1].angle = angle_init
    time.sleep(1)

# Pour le servo 2

    kit.servo[2].angle = angle_init
    time.sleep(1)

def rotate (): 
    """Notre fonction va permettre la rotation en élipse
    de notre système à l'aide de nos servos"""

    for angle in range(0,180):
        rotate_degree = float(angle_init + 1)
# Pour le servo 1
        kit.servo[1].angle = rotate_degree
        time.sleep(0.5)
# Pour le servo 2
        kit.servo[2].angle = rotate_degree / 4
        time.sleep(1)

    if rotate_degree == 180:
        for angle in range(0,180):
            rotate_degree = float(angle_init + 1)
# Pour le servo 1
            kit.servo[1].angle = rotate_degree
            time.sleep(0.5)
# Pour le servo 2
            kit.servo[2].angle = rotate_degree / 4
            time.sleep(1)
