imya = input()
ans = 0
s = ''
while True:
    try:
        s = input() 
        if (s[:len(imya) + 1] == imya + ":"): ans += 1
    except:
        break

print(ans)