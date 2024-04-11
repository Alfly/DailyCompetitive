from collections import defaultdict

n = int(input())

st = set()
record = defaultdict(int)

for _ in range(n):
    line = list(input().split(sep=','))
    s = line[0] + line[1] + line[2]

    if s in st: continue
    st.add(s)

    p = int(line[3])
    if p < 0 or p > 100: continue

    record[(line[1], line[2])] += p


m = int(input())

price = {}

for _ in range(m):
    line = list(input().split(sep=','))
    price[line[0]] = int(line[1])

res = defaultdict(int)
clients = set()

for k, v in record.items():
    client, factor = k
    res[client] += v * price[factor]
    clients.add(client)

clients = sorted((list(clients)))

for c in clients:
    print(c + "," + str(res[c]))
