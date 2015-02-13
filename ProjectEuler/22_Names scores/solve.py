def read_file():
    with open('names.txt', 'r') as f:
        data = f.read().replace('"', '');
    data = data.split(','); 
    return data;

data = read_file();
data = sorted(data);

res = 0;

# print(data);

def get_first_point(word):
    return sum(tuple(map(lambda c: ord(c)- ord('A') + 1, word)));

print(get_first_point('COLIN'));

for i in range(0, len(data)):
    x = get_first_point(data[i]);
    y = i+1;
    res += (x * y);
    
print(res);
