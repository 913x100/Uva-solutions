#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int src, dest, w;
    bool operator<(const node a)const
    {
        return w < a.w;
    }
};


int p[10010], h[10010];

int find_root(int n)
{
    if(p[n] != n)
        p[n] = find_root(p[n]);
    return p[n];
}

void Union(int a, int b)
{
    if(h[a] < h[b]) {
        h[b]++, p[a] = p[b];
    } else {
        h[a]++, p[b] = p[a];
    }
}

int main()
{
    int s, r, w, cost=0, cnt=0;
    int T, n, m ,A;


    scanf("%d", &T);
    for(int t=0; t<T; t++) {
        scanf("%d %d %d", &n, &m, &A);
        vector<node> edge;
        cost = cnt = 0;
        for(int i=0; i<=n; i++) {
            p[i]=i, h[i]=1;
        }
        for(int i=0; i<m; i++) {
            scanf("%d %d %d", &s, &r, &w);
            if(w < A) {
                edge.push_back(node{s, r, w});
                edge.push_back(node{r, s, w});
            }

        }
        printf("Case #%d: ", t+1);
        sort(edge.begin(), edge.end());

        for(int i=0; i<edge.size(); i++) {
            int a = find_root(edge[i].src);
            int b = find_root(edge[i].dest);
            if(a != b) {
                cost += edge[i].w;
                Union(a, b);
            }
        }
        for(int i=1; i<=n; i++)
            if(p[i] == i) cnt++;

        int res = cost + cnt*A;
        printf("%d %d\n", res, cnt);


    }
    return 0;
}
