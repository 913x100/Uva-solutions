#include <cstdio>

int a[11] = {1, 3, 13, 75, 541, 4683, 47293, 545835, 7087261, 102247563, 1622632573};

int main()
{
    int n, x;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        printf("%d\n", a[x-1]);
    }
    return 0;
}
