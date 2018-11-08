#include <cstdio>
#include <cstring>

int sum[200];

void build(int p)
{
    int v;
    scanf("%d", &v);
    if(v == -1) return;
    sum[p] += v;
    build(p - 1);
    build(p + 1);
}

int main()
{
    int t=0, v;
    while(1)
    {
        scanf("%d", &v);
        if(v == - 1) return 0;
        memset(sum, 0, sizeof(sum));

        int pos = 100;
        sum[pos] = v;
        build(pos - 1);
        build(pos + 1);

        int p = 0;
        while(!sum[p]) p++;
        printf("Case %d:\n", ++t);
        printf("%d", sum[p++]);
        while(sum[p])
            printf(" %d", sum[p++]);
        printf("\n\n");
    }
    return 0;
}
