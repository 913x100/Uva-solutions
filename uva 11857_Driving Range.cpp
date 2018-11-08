#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct node
{
    int t, w;

    bool operator<(const node a)const
    {
        return w > a.w;
    }
};


priority_queue<node> q;

bool isRelax[10001000];
vector<node> adj[10001000];


int main()
{
    bool isPossible = false;
    int n, m, u, v, w;
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n==0 && m==0) return 0;
        memset(isRelax, false, sizeof(isRelax));
        for(int i=0; i<n; i++)
            adj[i].clear();
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(node{v, w});
            adj[v].push_back(node{u, w});
        }
        q.push(node{0, 0});
        int res = 0;
        while(!q.empty())
        {
            u = q.top().t;
            w = q.top().w;
            q.pop();

            if(!isRelax[u])
            {
                if(w > res)
                    res = w;
                isRelax[u] = true;
                for(int i=0; i<adj[u].size(); i++)
                {
                    v = adj[u][i].t;
                    if(!isRelax[v])
                        q.push(node{v, adj[u][i].w});
                }
            }
        }
        for(int i=0; i<n; i++)
            if(!isRelax[i]) res = -1;
        if(res == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", res);

    }
    return 0;
}
