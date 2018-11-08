#include <cstdio>
#include <cstring>

char s[50];
int res;

int main()
{

    while(1) {

        scanf("%s", s);
        if(s[0] == '-') break;
        if(s[0] == '0' && s[1] == 'x') {
            sscanf(s, "%x", &res);
            printf("%d\n", res);
        }
        else {
            sscanf(s, "%d", &res);
            printf("0x");
            printf("%X\n", res);
        }

    }
    return 0;
}
