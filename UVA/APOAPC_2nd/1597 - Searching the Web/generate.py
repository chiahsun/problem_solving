import random;
import string;

DOC_NUM = 99;
LINE_NUM = 15;
NUM_QUERY = 100;

#DOC_NUM = 99;
#LINE_NUM = 15;
#NUM_QUERY = 50000;

string_list = [];
# Reference: 
# http://stackoverflow.com/questions/2257441/random-string-generation-with-upper-case-letters-and-digits-in-python
def get_random_string(strlen = 5):
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(random.randint(1, strlen)));

def get_line(buffer_len = 80):
    global string_list;
    buf = '';
    while len(buf) < buffer_len:
        s = get_random_string();
        if len(buf) + len(s) < buffer_len:
            if len(buf) == 0:
                buf = s;
            else:
                buf = ''.join([buf, ' ', s]);
            string_list.append(s);
        else:
            break;
    return buf;

# print(get_line());


print(DOC_NUM);
for _ in range(DOC_NUM):
    for _ in range(LINE_NUM):
        print(get_line());
    print("**********");


def get_random_string_in_list():
    return string_list[random.randint(0, len(string_list)-1)];

print(NUM_QUERY);
for _ in range(NUM_QUERY):
    choice = random.choice(['AND', 'OR', 'NOT', 'ORG']);
    if choice == 'ORG':
        print(get_random_string_in_list());
    elif choice == 'AND' or choice == 'OR':
        print(get_random_string_in_list(), choice, get_random_string_in_list());
    elif choice == 'NOT':
        print(choice, get_random_string_in_list());

