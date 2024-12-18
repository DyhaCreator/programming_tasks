res = ""
v = int(input())

while True:
    r = v % -2
    v = v // -2
    if r < 0:
        r = r + 2
        v = v + 1
    if r == 1:
        res = "1" + res
    if r == 0:
        res = "0" + res

    if v == 0:
        break

print(res)