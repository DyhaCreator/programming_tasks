n, m = map(int, input().split())

mem = [(0, 0, 0)]
#print(mem)

for i in range(m):
    a = int(input())
    if(a >= 0):
        index = -1
        for j in range(len(mem) - 1):
            endIndex = mem[j][0] + mem[j][1]
            startIndex = mem[j + 1][0]
            #print(startIndex - endIndex)
            if(startIndex - endIndex >= a):
                index = endIndex
                break
        if(index == -1):
            index = mem[len(mem) - 1][0] + mem[len(mem) - 1][1]

        if(index + a > n):
            print(-1)
        else:
            print(index + 1)
            mem.append((index, a, i + 1))
            mem.sort(key = lambda x: x[0])
    else:
        index = -1
        for j in range(len(mem)):
            if(mem[j][2] == -a):
                index = j
                break
        if(index != -1):mem.pop(index)
    #print(mem)
