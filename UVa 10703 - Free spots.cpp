#include <cstdio>
#include <cstring>

#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

bool a[510][510];
int x1, y1, x2, y2;

void check()
{
    if(x1 > x2 && y1 <= y2)
        SWAP(x1, x2, int);
    else if(x1 >= x2 && y1 >= y2) {
        SWAP(x1, x2, int);
        SWAP(y1, y2, int);
    }
    else if(x1 <= x2 && y1 > y2)
        SWAP(y1, y2, int);
}

void reset()
{
    memset(a, false, sizeof(a));
}

int main()
{
    int w, h, n, res;

    while(1) {
        scanf("%d %d %d", &w, &h, &n);
        if(w == 0 && h == 0 && n == 0) break;
        reset();
        res = w*h;
        while(n--) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            check();


            for(int i=x1; i<=x2; i++) {
                for(int j=y1; j<=y2; j++) {
                    if(a[i][j] == false) {
                        a[i][j] = !a[i][j];
                        res--;
                    }
                }
            }
        }
        if ( res == 0 ) printf ("There is no empty spots.\n");
        else if ( res == 1 ) printf ("There is one empty spot.\n");
        else printf ("There are %d empty spots.\n", res);
    }
    return 0;
}
