#include<cstdio>
#include<string.h>

int n,m,v[111];
double total;
char c[200],s[10010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        total = 0;
        scanf("%d",&n);
        for (int i=0; i<n; i++)
        {
            getchar();
            scanf("%c %d",&c[i],&v[i]);
        }
        scanf("%d",&m);
        getchar();
        while (m--)
        {
            gets(s);
            for (int j=0; j<n; j++)
                for (int i=0; s[i]; i++)
                    if (c[j]==s[i]) total+=v[j];
        }
        printf ("%.2lf$\n", total/100.0 );
    }
    return 0;
}
