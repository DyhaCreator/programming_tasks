s = input()
strs = []

def isP(s):
    if(s[::-1] == s):
        return True
    return False

for l in range(2, 4):
    for x in range(len(s) - l + 1):
        st = s[x:x+l]
        #print(st)
        if(isP(st)):
            strs.append(st)

#for i in range(len(strs)):
    #print(strs[i])

if(len(strs) == 0):
    print(-1)
else:
    minsize = len(strs[0])
    m = strs[0]
    for i in range(len(strs)):
        if(len(strs[i]) > minsize):
            break
        if(strs[i] < m):
            m = strs[i]
    print(m)
