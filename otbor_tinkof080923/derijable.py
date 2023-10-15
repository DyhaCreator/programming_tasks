n = int(input())
direct = 0
speed = 0
speedX = 0
speedY = 0
X = 0
Y = 0

for i in range(n):
    c = input()
    if(c == 'Rght' and speedX == 0 and speedY == 0):
        direct += 1
    elif(c == 'Left' and speedY == 0 and speedX == 0):
        direct -= 1
    elif(c == 'Fwrd' and speedX == 0 and speedY == 0):
        speed = 100
    elif(c == 'Back' and speedX == 0 and speedY == 0):
        speed = -100
    elif(c == 'More' and speed > 0):
        speed = min(500, speed + 100)
    elif(c == 'Less' and speed > 0):
        speed = min(500, speed - 100)
    elif(c == 'Stop'):
        speed = 0

    direct = direct % 4
    if(direct == 0):
        speedX = 0
        speedY = speed
    elif(direct == 1):
        speedX = speed
        speedY = 0
    elif(direct == 2):
        speedX = 0
        speedY = -speed
    elif(direct == 3):
        speedX = -speed
        speedY = 0
    X += speedX
    Y += speedY
    #print(direct, speedX, speedY, X, Y)
print(X, Y)