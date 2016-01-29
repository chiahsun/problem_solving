#include <cstdio>
#include <cstring>

char buf[1000];
int main() {
    int nCase, len;
    scanf("%d", &nCase);
    while ((getchar() != '\n')) { }
    while (nCase--) {
        fgets(buf, sizeof(buf), stdin);
        len = strlen(buf); 
        buf[--len] = '\0'; // ignore newline
        if (!strcmp(buf, "1") or !strcmp(buf, "4") or !strcmp(buf, "78"))
            printf("+");
        else if (len >= 2 and buf[len-1] == '5' and buf[len-2] == '3')
            printf("-");
        else if (len >= 2 and buf[0] == '9' and buf[len-1] == '4')
            printf("*");
        else
            printf("?");
        printf("\n");
    }

    return 0;
}
