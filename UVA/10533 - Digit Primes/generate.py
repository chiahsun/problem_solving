
#end = 3+1;
end = 100+1;
n = end-1;
print(int (n * (n+1) / 2));

for i in range(1, end):
    for k in range(1, i+1):
        print(k, i);
