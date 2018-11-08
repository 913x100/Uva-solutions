#include <cstdio>

long long A[35];

long long play(int k, int n)
{
    if(k == 0) return (n==1)?1:0;
    if(n == 1<<k) return A[k];

    return (n <= 1<<(k-1))? 2*play(k-1, n):play(k-1, n-(1<<(k-1))) + 2*A[k-1];

}

int main()
{
    int k, a, b;

    A[0] = 1;
    for(int i=1; i<32; i++)
        A[i] = 3 * A[i-1];
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++) {
        scanf("%d %d %d", &k, &a, &b);
        printf("Case %d: ", t+1);
        printf("%lld\n", play(k, b) - play(k, a-1));
    }

    return 0;
}
