#include <cstdio>

int main()
{
    int d, k, res, i, q;

    scanf("%d",&q);
    while (q-- )
    {
        scanf("%d %d",&d,&k);
        k--;
        if(d == -1) break;
        for (i=1, res=0; i<d; i++)
        {
            res = res*2;
            res |= k%2;
            k = k/2;
        }
        printf("%d\n",res+(1 << (d-1)));
    }

    return 0;
}
