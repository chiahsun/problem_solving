from math import log;

#def get_nth_fib(ndigit = 1000):
#    return (ndigit - log(2.236, 10)) / log(1.618, 10);

#print(get_nth_fib(1));
#print(get_nth_fib(2));
#print(get_nth_fib(3));
#print(get_nth_fib(1000));

def get_fib(ndigit = 1000):
    a, b, cnt = 0, 1, 0;
    while len(str(a)) < ndigit:
        a, b, cnt = a+b, a, cnt+1;

    return (cnt, a);

print(get_fib(2));
print(get_fib(3));
print(get_fib(1000));
# print(get_fib(1));
# print(get_fib(2));
# print(get_fib(3));
# print(get_fib(4480));
# print(get_fib(4481));
# print(get_fib(4482));
# print(get_fib(4483));
# print(get_fib(4484));
