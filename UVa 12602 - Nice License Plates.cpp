#include <stdio.h>

char s[3];
int D;

int abs(int n)
{
    return (n<0)?-n:n;
}

int getChar(char c)
{
    return c-'A';
}

int main()
{
    int n, tmp;
    scanf("%d", &n);
    while(n--) {
        scanf("%3s-%d", s, &D);
        int L = getChar(s[0])*26*26 + getChar(s[1])*26 + getChar(s[2]);
        tmp = L-D;
        if(abs(tmp) <= 100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}
