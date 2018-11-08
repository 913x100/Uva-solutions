#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int>adj[105];
bool vis[105], ans[105][105], visOrg[105];
int skip;

void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!vis[adj[u][i]] && adj[u][i]!=skip) {
            vis[adj[u][i]] = true;
            dfs(adj[u][i]);
        }

    }
return;
}

void dfsOrg(int u)
{
    visOrg[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!visOrg[adj[u][i]]) {
            visOrg[adj[u][i]] = true;
            dfsOrg(adj[u][i]);
        }

    }
return;
}

int main()
{
    int kase=0, t, n, m, x;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);

        for(int i=0;i<n;i++)   adj[i].clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d", &x);
                if(x)
                    adj[i].push_back(j);
            }
        }
        memset(ans, 0, sizeof(ans));
        memset(visOrg, 0, sizeof(visOrg));

        dfsOrg(0);
        for(int i=0;i<n;i++)
            if(visOrg[i])
                ans[0][i]=true;

        for(int i=1;i<n;i++)
        {
            skip=i;
            memset(vis, 0, sizeof(vis));
            dfs(0);
            for(int j=0;j<n;j++)
                if((!vis[j] && visOrg[j]))
                    ans[i][j]=true;
        }


        printf("Case %d:\n", ++kase);

        for(int i=0;i<=2*n;i++)
        {
            if(i%2)
            {
                printf("|");
                for(int j=0;j<n;j++)
                {

                    if(ans[i/2][j]) printf("Y");
                    else printf("N");

                    printf("|");
                }

            }
            else
            {
                printf("+");
                for(int j=0;j<2*n-1;j++)
                    printf("-");
                printf("+");
            }
            printf("\n");
        }
    }

    return 0;
}
