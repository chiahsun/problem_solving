import random;
random.seed(0); # 4 for 0
ll = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'];

dct = {};
for c in ll:
    dct[c] = [];
def generate_case():

# print(dct);

    for key in dct:
#        nremove = range(random.randint(6, 7));
        cur = [];
        for c in ll:
            if c != key:
                cur.append(c);
        nremove = range(random.randint(0, 3));
        for _ in nremove:
            cur.pop(random.randint(0, len(cur)-1));
        dct[key] = cur;

    is_first = True;
    for key, value in dct.items():
#    print('key : ', key);
#    print('value : ', value);
        if len(value) != 0:
            if is_first:
                is_first = False;
            else:
                print(';', end = '', sep='');
            print(key,':', end = '', sep='');
            for c in value:
                print(c, end = '', sep='');
    print();

for _ in range(1000):
    generate_case();
print('#');
