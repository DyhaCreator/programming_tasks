N, M, P = map(int, input().split())
A = []
B = []
C = []
D = []

for i in range(N):
    a, b, c, d = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(c)
    D.append(d)

for ost in range(1, P):
    pas = []
    for i in range(len(C)):
        if(ost >= C[i] and ost < D[i]):
            pas.append(i)
    a = [0] * (M + 1)
    for i in range(M + 1):
        a[i] = [0] * (len(pas) + 1)
    for j in range(1, M + 1):
        for i in range(1, len(pas) + 1):
            if(j - 1 >= 0):
                a[j][i] = max(a[j][i - 1] + B[pas[i - 1]], a[j - 1][i - 1] + A[pas[i - 1]])
            else:
                a[j][i] = a[j][i - 1] + B[pas[i - 1]]
            print(a)