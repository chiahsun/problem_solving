def get_digital_sum(base, exp):
    return sum(map(lambda s: int(s), str(base ** exp)));

def get_max_digital_sum(base_end=100, exp_end=100):
    res = 0;
    for base in range(1, base_end):
        for exp in range(1, exp_end):
           res = max(res, get_digital_sum(base, exp));
    return res;

print(get_max_digital_sum());
