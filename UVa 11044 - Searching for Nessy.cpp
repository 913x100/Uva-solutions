#include <cstdio>

int main()
{
    int a, b;
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", (b/3)*(a/3));
    }
    return 0;
}
