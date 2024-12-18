a = int(input())
b = int(input())

c = a + b

if(c <= 0 and a > 0):
    c -= 1
elif(c >= 0 and a < 0):
    c += 1

print(c)
