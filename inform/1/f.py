n = int(input())
j = 0
sum = 0
l = 0
while (sum < n):
    j += 1
    sum += j
    l += 1

i = 0
while (sum != n):
    if (sum > n):
        i += 1
        sum -= i
        l -= 1
    else:
        j += 1
        sum += j
        l += 1
print(l)