def get_number_paths(ngrid):
    res = 1;
#    print('ngrid = ', ngrid);
    for i in range(ngrid*2, ngrid, -1):
#        print('i = ', i);
        res = res * i;
#    print('res = ', res);
    for i in range(ngrid, 1, -1):
        res = res // i;
    return res;

print(get_number_paths(2));
print(get_number_paths(3));
print(get_number_paths(20));
