# Brute force method
# Get all english representation of 1 to 1000 and count the number of literals up
digits = [
    ""
  , "one"
  , "two"
  , "three"
  , "four"
  , "five"
  , "six"
  , "seven"
  , "eight"
  , "nine"
];

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
def get_repr(number):
    global digits;
    if number < 1:
        raise;
    if number < 10:
        return digits[number];
    if number >= 10 and number < 20:
        return teens[number-10];
    if number >= 20 and number < 100:
        return tens[number // 10-2] + " " + digits[number % 10];
    if number >= 100 and number < 1000:
        if number % 100 == 0:
            return digits[number//100] + "hundred";
        else:
            return digits[number//100] + "hundred and " + get_repr(number % 100);
    if number == 1000:
        return "one thousand";
    raise;

def get_length(end=1001):
    cnt = 0;
    for i in range(1, end):
        str_repr = get_repr(i);
        # print();
        cnt += len(str_repr.replace(' ', ''));
    return cnt;
    
print(get_length(10));
print(get_length(100));
print(get_length(1000));
print(get_length(1001));
