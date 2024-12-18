ans = 0
for i in range(1, 8192):
    sd = 0
    d = i + 1
    while(d > 0):
        sd += d % 2
        d = d // 2
    sb = 0
    b = i
    while(b > 0):
        sb += b % 2
        b = b // 2
    if(sb / sd == 3):
        #print(i)
        ans += 1
print(ans)