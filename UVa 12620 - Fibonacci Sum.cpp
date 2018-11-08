#include <cstdio>

int fibo[305] = {0, 1};
long long dp[305] = {0, 1};
long long N, M;

int main()
{
    for(int i=2; i<305; i++)
        fibo[i] = (fibo[i-1]+fibo[i-2])%100;
    for(int i=2; i<305; i++)
        dp[i] = dp[i-1] + fibo[i];

    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld", &N, &M);
        if (N % 300 == 0) N++;
        printf("%lld\n", ((M/300)-(N/300))*dp[299] + dp[M%300] - dp[(N+299)%300]);
    }
    return 0;
}
