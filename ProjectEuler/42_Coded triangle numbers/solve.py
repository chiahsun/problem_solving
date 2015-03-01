triangle_number_list = [1];

def get_triangle_number_list(at_least = 100):
    global triangle_number_list;
    while triangle_number_list[-1] < at_least:
        triangle_number_list.append(len(triangle_number_list)+1+triangle_number_list[-1]);
    return triangle_number_list;

def test_triangle_number_list():
    print(get_triangle_number_list());
#    print(get_triangle_number_list(200));

test_triangle_number_list();

def char_to_int(c):
    return ord(c) - ord('A') + 1;

def string_to_int(string):
    return sum(map(char_to_int, string));

def is_triangle_number(string):
    value = string_to_int(string);
    return value in get_triangle_number_list(value);

def test_is_triangle_number():
    print('SKY is triangle number?', is_triangle_number('SKY'));

test_is_triangle_number();

# Reference
# 1. http://stackoverflow.com/questions/5252834/how-to-use-str-replace-as-the-function-in-map
def count_number_of_triangle_number_in_file():
    with open('words.txt', 'r') as f:
#        string_list = map(lambda s: s.replace('"', ''), f.read().split(','));
         string_list = [s.replace('"', '') for s in f.read().split(',')];
         return sum(map(is_triangle_number, string_list));
    raise;


print(count_number_of_triangle_number_in_file());
