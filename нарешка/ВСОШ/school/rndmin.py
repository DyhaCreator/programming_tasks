import random

a = int(input())
b = int(input())

ans = random.randint(-abs(a * b), abs(a * b))
while not((ans == a and ans <= b) or (ans == b and ans < a)):
    ans = random.randint(-abs(a * b), abs(a * b))
    #print(ans)
print(ans)