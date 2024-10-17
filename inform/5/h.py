n = int(input())

for i in range(n):
    s = input()
    print("URL #", i + 1, sep='')
    print("Protocol = ", s.split("://")[0])
    print("Host     = ", s.split("://")[1].split('/')[0])