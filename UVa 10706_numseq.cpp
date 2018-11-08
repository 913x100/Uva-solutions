#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int sum[40000];
char str[1000000];

int main()
{
    int t, n, tmp=0;
    char s[100];
    scanf("%d", &t);


    for(int i=1; i<=40000; i++) {
        sprintf(str, "%d", i);
        printf("%s\n", str);
        tmp += log10(i)+1;
        sum[i] = sum[i-1] + tmp;
    }
    for(int i=0; i<1000; i++)
        printf("%c", str[i]);
    while(t--)
    {
        //scanf("%d", &n);
    }
    return 0;
}
