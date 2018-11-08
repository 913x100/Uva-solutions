#include <cstdio>

using namespace std;

int res[105];

int main()
{
    bool check;
    int n, tmp, cnt;

    for(int i=13; i<=100; i++) {
        cnt=1;
        check = true;
        while(check) {
            check = false;
            tmp = 0;
            for(int j=1; j<i; j++)
                tmp = (tmp+cnt)%j;
            if(tmp != 11)
                check = true;
            cnt++;
        }
        res[i] = cnt-1;
    }

    while(1) {
        scanf("%d", &n);
        if(!n) return 0;
        printf("%d\n", res[n]);
    }
    return 0;
}
