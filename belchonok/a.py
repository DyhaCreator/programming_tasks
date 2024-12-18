import sys
sys.set_int_max_str_digits(2 ** 30)

f = open('a.txt', 'r')
s = f.readline()
print(len(s))
ans = ''
sumS = 0
for i in range(0, len(s) - 1):
    sumS = 0
    for j in range(i + 1, len(s)):
        sumS += int(s[i])
        s2 = s[i:j]
        if (s2[len(s2) - 1] == '0' or s2[len(s2) - 1] == '5') and (sumS <= 50) and (len(s2) > len(ans)):
            ans = s2
            print(s2)
print(ans)