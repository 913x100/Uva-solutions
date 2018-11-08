#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

stack<int> in;
queue<int> out;

int main()
{
    int n, x;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        while(1)
        {
            scanf("%d", &x);
            if(x == 0) break;

            while(!in.empty())
                in.pop();
            while(!out.empty())
                out.pop();

            for(int i=1; i<=n; i++)
            {
                if(i > 1)
                    scanf("%d", &x);
                in.push(i);
                out.push(x);

                while(!in.empty() && !out.empty() && in.top()==out.front())
                {
                    in.pop();
                    out.pop();
                }
            }
            if(in.empty())
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
