import string;
def is_palindrome(stmt):
    stmt = [c for c in stmt if c not in string.punctuation and c not in string.whitespace];
    stmt = ''.join(stmt).lower();
#    print(stmt);
    i, k = 0, len(stmt)-1;
    while True:
        if i >= k:
            break;
        if stmt[i] != stmt[k]:
            return False;
        i, k = i+1, k-1;
    return True;
    # print(stmt);

try:
    while True:
        line = input();
        if line == "DONE":
            break;
        if is_palindrome(line):
            print("You won't be eaten!");
        else: 
            print("Uh oh..");
except EOFError:
    pass;
