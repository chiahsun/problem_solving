# Recursive definition method
# Notice that
#  ba...a
# the recursive generation of b based on a...a and
#     a...a on b
def get_single_digits():
    digits = [
        "one"
      , "two"
      , "three"
      , "four"
      , "five"
      , "six"
      , "seven"
      , "eight"
      , "nine"
    ];
    return sum(map(len, digits));

def get_ten_to_nineteen():
    teens = [
        "ten"
      , "eleven"
      , "twelve"
      , "thirteen"
      , "fourteen"
      , "fifteen"
      , "sixteen"
      , "seventeen"
      , "eighteen"
      , "nineteen"
    ];
    return sum(map(len, teens));

def get_tens():
    tens = [
        "twenty"
      , "thirty"
      , "forty"
      , "fifty"
      , "sixty"
      , "seventy"
      , "eighty"
      , "ninety"
    ];

    return (len(tens) + 1) * get_single_digits() + 10 * sum(map(len, tens)) + get_ten_to_nineteen();

def get_hundreds():
    hundred = "hundred";
    return ((9 * len(hundred) + get_single_digits()) # 100 200 ... 900
        # 1xx ~ 9xx -> x hundred and
        +  (get_single_digits() + 9 * (len(hundred) + len('and'))) * 99 
        #  xx ~ 9xx -> xx
        + 10 * get_tens());

def get_all():
    return get_hundreds() + len('onethousand');


print(get_single_digits());
print(get_tens());
print(get_hundreds());
print(get_all());
