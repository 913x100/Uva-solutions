#include <cstdio>

int dp[105][105];
char tmp[105];
int main()
{
    int n, m, res;
    while(1) {
        scanf("%d", &n);
        if(!n) return 0;
        scanf("%d", &m);
        for(int i=1; i<=n; i++) {
            scanf("%s", tmp);
            for(int j=1; j<=m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (tmp[j-1] - '0');
            }
        }
        //printf("x");
        res = 0;
        for(int a=0; a<=n; a++) {
            for(int b=0; b<=m; b++) {
                for(int i=1; i<=n-a; i++) {
                    for(int j=1; j<=m-b; j++) {
                        //printf("x%d\n", dp[i+a][j+b]-dp[i-1][j+b]-dp[i+a][j-1]+dp[i-1][j-1]);
                        //printf("y%d\n", (i+a)*(j+b));
                        if(dp[i+a][j+b]-dp[i-1][j+b]-dp[i+a][j-1]+dp[i-1][j-1] == (a+1)*(b+1))
                            res++;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
