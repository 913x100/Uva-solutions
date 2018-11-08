#include <cstdio>
#include <queue>

int n;
char a[30][30];
int d[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};

void dfs(int x, int y)
{
    //a[x][y] = '0';

    for(int k=0; k<8; k++)
    {
        int i = x+d[k][0];
        int j = y+d[k][1];
        if(i < 0 || j < 0 || i >=n || j >= n) continue;

        if(a[i][j] == '1')
        {
            a[i][j] = '0';
            dfs(i, j);
        }

    }

}

int main()
{
    int kase = 0, cnt;
    while (scanf("%d", &n) != EOF){
        cnt = 0;
        for (int i = 0; i < n; i++)
            scanf("%s", a[i]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == '1'){
                    a[i][j] = '0';
                    dfs(i, j);
                    cnt++;
                }
        printf("Image number %d contains %d war eagles.\n", ++kase, cnt);
    }
    return 0;
}
