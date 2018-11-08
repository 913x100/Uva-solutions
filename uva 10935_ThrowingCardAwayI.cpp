#include <cstdio>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
    int n;
    while(1) {
        while(!q.empty())
            q.pop();
        scanf("%d", &n);
        if(!n) return 0;
        printf("Discarded cards:");

        for(int i=1; i<=n; i++)
            q.push(i);
        while(q.size()-1 != 0) {
            if(q.size() > 2)
                printf(" %d,", q.front());
            else
                printf(" %d", q.front());
            q.pop();
            int x = q.front();
            q.pop();
            q.push(x);
        }
        printf("\nRemaining card: %d\n", q.front());
    }
    return 0;
}
