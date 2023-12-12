file = open('1.txt', 'r')

s = file.readlines()

ans = 0

for i in s:
    a = i.split()
    if (int(a[2]) < 4):
        print(a[0], a[1], a[2])
    ans += int(a[2])
print(ans / len(s))