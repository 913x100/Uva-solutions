#include <cstdio>
#include <cstring>

int n, m, i, j, ans, cnt;
char a[25][25];
bool mark[25][25];

int max(int a, int b)
{
    return (a>b)?a:b;
}

void dfs(int i, int j, char land)
{
    //if(!mark[i][j] || a[i][j] != land) return ;
    cnt++;
    mark[i][j] = true;
    if(i+1 < n && !mark[i+1][j] && a[i+1][j] == land)
        dfs(i+1, j, land);
    if(i-1 >=0 && !mark[i-1][j] && a[i-1][j] == land)
        dfs(i-1, j, land);
    if(j+1 < m && !mark[i][j+1] && a[i][j+1] == land)
        dfs(i, j+1, land);
    if(j+1 == m && !mark[i][0] && a[i][0] == land)
        dfs(i, 0, land);
    if(j-1 >= 0 && !mark[i][j-1] && a[i][j-1] == land)
        dfs(i, j-1, land);
    if(j-1 < 0 && !mark[i][m-1] && a[i][m-1] == land)
        dfs(i, m-1, land);
}
int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(mark, false, sizeof(mark));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf(" %c", &a[i][j]);
        scanf("%d %d", &i, &j);

        char land = a[i][j];
        dfs(i, j, land);
        ans = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                cnt = 0;

                if(!mark[i][j] && a[i][j] == land)
                {
                    dfs(i, j, land);
                    ans = max(ans, cnt);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
