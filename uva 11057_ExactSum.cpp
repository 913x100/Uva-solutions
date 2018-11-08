#include <cstdio>
#include <algorithm>

using namespace std;

int a[10010];

int main()
{
    int r1, r2, MN=0;
    int n, money;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        MN = 1<<30;
        sort(a, a+n);
        scanf("%d", &money);
        int l=0, r=n-1;

        while(l < r) {
            //printf("%d %d\n", a[l], a[r]);
            if(a[l] + a[r] > money)
                r--;
            else if(a[l] + a[r] < money)
                l++;
            else {
                if(a[r] - a[l] <= MN) {
                    MN = a[r] - a[l];
                    r1 = a[l];
                    r2 = a[r];
                    l++;
                    r--;
                } else r--;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", r1, r2);
    }
    return 0;
}
