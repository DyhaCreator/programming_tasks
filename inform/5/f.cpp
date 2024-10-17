name = input()
s = " "
ans = 0
while (True):
    s = input()
    if (s.find(name + ":") == 0):
        ans += 1
    if (s.find(name + " quit") != -1):
        break
print(ans)