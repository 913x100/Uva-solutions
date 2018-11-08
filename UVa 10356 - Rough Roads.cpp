#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct junc
{
    int dest, w, len;

    bool operator<(const junc &a)const
    {
        return w > a.w;
    }
};

vector<junc> edge[510];
priority_queue<junc> q;

bool isRelax[510][2];
int dist[510][2];

int main()
{
    int n, m, u, v, w, len, t=0;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i=0; i<n; i++)
            edge[i].clear();
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            edge[u].push_back(junc{v, w});
            edge[v].push_back(junc{u, w});
        }
        q.push(junc{0, 0, 0});
        memset(isRelax, false, sizeof(isRelax));
        memset(dist, 0, sizeof(dist));
        while(!q.empty())
        {
            u = q.top().dest;
            w = q.top().w;
            len = q.top().len;
            q.pop();
            //printf("now %d\n", u);
            if(!isRelax[u][len>1])
            {
                isRelax[u][len>1] = true;
                dist[u][len>1] = w;
                for(int i=0; i<edge[u].size(); i++)
                {
                    v = edge[u][i].dest;
                    if(!isRelax[v][len>1])
                        q.push(junc{v, w+edge[u][i].w, len+1});
                }
            }
        }
        //for(int i=0; i<n; i++)
        //    printf("%d ", dist[i]);
        printf("Set #%d\n%d\n", ++t, dist[n-1][1]);
    }
    return 0;
}
