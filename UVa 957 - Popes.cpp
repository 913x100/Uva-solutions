#include <cstdio>

int popes[1000100];

int main()
{
    int y, p;
    while (scanf("%ld", &y) != EOF)
    {
        scanf("%d", &p);

        for (int i = 0; i < p; i++)
            scanf("%ld", &popes[i]);

        int counter = 0;
        int x, z;
        for (int i = 0; i < p; i++)
        {
            int j = i;
            int sum = 0;
            int max, min, cnt = 0;
            while (sum < y && j < p - 1)
            {
                max = popes[i];
                sum = sum + popes[j + 1] - popes[j];
                min = popes[j];
                cnt++;
                j++;
            }
            if (cnt > counter)
            {
                counter = cnt;
                x = min;
                z = max;
            }
        }
        printf("%d %d %d\n", counter, z, x);
    }
    return 0;
}
