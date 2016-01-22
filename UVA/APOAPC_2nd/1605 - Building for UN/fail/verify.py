
l = input().split();
nheight, nrow, ncol = int(l[0]), int(l[1]), int(l[2]);

print(nheight, nrow, ncol);

office = [[[[] for _ in range(ncol)] for _ in range(nrow)] for _ in range(nheight)];

for h in range(nheight):
    for r in range(nrow):
        row = "";
        while (len(row) == 0): 
            row = input();
        for c in range(ncol):
#            print("row[", c,']: ', row[c]);
            office[h][r][c] = row[c];
#            print("row[", h, "][", r, "][", c , "] : ", office[h][r][c]);

adj = {};
for h in range(nheight):
    for r in range(nrow):
        for c in range(ncol):
            cur = office[h][r][c];
            d = [[-1, 0, 0], [0, -1, 0], [0, 0, -1]];
            if cur not in adj:
                adj[cur] = set(cur);
            for dd in d:
                nh, nr, nc = h + dd[0], r + dd[1], c + dd[2];
                if nh >= 0 and nc >= 0 and nr >= 0:
                    prev = office[nh][nr][nc];
                    if prev not in adj:
                        adj[prev] = set(prev);
                    adj[cur].add(prev);
                    adj[prev].add(cur);
print(adj);
print(len(adj));
for key, value in adj.items():
    print(key, len(value));
# adj = {for a, b in }
# adj = {'a':[]}
# print(office);
