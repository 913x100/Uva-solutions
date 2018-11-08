#include <cstdio>
#include <cstring>

char a[27] = "22233344455566677778889999";
char str[35];

int main()
{
    while(scanf("%s", str) != EOF) {
        int len = strlen(str);
        for(int i=0; i<len; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z')
                printf("%c", a[str[i]-'A']);
            else
                printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}
