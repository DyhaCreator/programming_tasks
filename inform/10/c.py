s = input()

ss = []
al = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"

for i in s:
    ss.append(al.index(i))

for k in range(0, len(al)):
    ss2 = []
    for i in ss:
        ss2.append((i + k) % len(al))
    st = ""
    for i in ss2:
        st += al[i]
    #print(st)
    for n in range(1, len(s)):
        mat = [""]
        for i in st:
            if (len(mat[-1]) >= n):
                mat.append("")
            mat[-1] += i
        if (len(mat[-1]) == n):
            ans = ""
            for i in range(n):
                for j in mat:
                    ans += j[i]
            #print(ans)
            if (ans.count("АЛГОРИТМ")):
                print(ans)