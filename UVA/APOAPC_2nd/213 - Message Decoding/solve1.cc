#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

// const bool debug = true;
const bool debug = false;

int msg[7+5];
int len_code[3+1];
int offset[8];

int get_digit() {
    char c;
    do { c = getchar(); 
//    printf("c = %c\n", c);
    } while (c != '0' and c != '1');
    return c - '0';
}

int main() {
    std::string header;
    
    memset(offset, 0, sizeof(offset));
    for (int i = 2, prev=2; i < 8; ++i, prev *= 2) {
        offset[i] = offset[i-1] + prev - 1;
    }
#if 0
    for (int i = 0; i < 8; ++i)
        printf("offset[%d] = %d\n", i, offset[i]);
#endif

    while(std::getline(std::cin, header)) {
        if (debug)
            std::cout << "header = " << header << " (" << header.size() << ")" << std::endl;
        while (true) { 
            len_code[0] = get_digit();
            len_code[1] = get_digit();
            len_code[2] = get_digit();
            if (len_code[0] == 0 and len_code[1] == 0 && len_code[2] == 0) {
                // read last newline after 0 or 00 or 000 ...
                printf("\n");
                getchar();
                break;
            }

            int length = (2 * len_code[0] + len_code[1]) * 2 + len_code[2];
            if (debug)
                printf("len = %d%d%d, length = %d\n", len_code[0], len_code[1], len_code[2], length);
            do {
                int end = 1;
                int key = 0;
                for (int i = 0; i < length; ++i) { 
                    key *= 2;
                    msg[i] = get_digit();
                    key += msg[i];
                    if (debug)
                        printf("msg[%d] = %d, key = %d\n", i, msg[i], key);
                    end &= msg[i];
                }
           
                int prev_key = key;
                key = key + offset[length] ;
                if (debug)
                    printf("key(%d) = key(%d) + offset(%d)\n", key, prev_key, offset[length]);
                if (!end) {
                    printf("%c", header[key]);
                    if (debug)
                        printf(", key = %d, ans = %c, offset[%d] = %d\n", key, header[key], length, offset[length]);
                }
                else {
//                    while (getchar() != '\n') { }
//                    printf("end\n");
                    break;
                }

            } while (true);
        }

    }

    return 0;
}
