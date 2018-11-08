#include<cstdio>
#include<cstring>

using namespace std;

int N, M, S, tot;
char graph[300][300];
char dirs[51000];
char D[256];
char E[256];
int x[256];
int y[256];

void search(int r, int c, char d, int n) {
	if(graph[r][c] == '*') {
		tot++;
		graph[r][c] = '.';
	}
	if(n == S) return;

	switch(dirs[n]) {
		case 'F':
			if(r + x[d] >= 0 && r + x[d] < N && c + y[d] >= 0 \
					&& c + y[d] < M \
					&& graph[r + x[d]][c + y[d]] != '#')
				search(r + x[d], c + y[d], d, n + 1);
			else
				search(r, c, d, n + 1);
			break;
		case 'D':
			search(r, c, D[d], n + 1);
			break;
		case 'E':
			search(r, c, E[d], n + 1);
			break;
	}
}

void start() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(graph[i][j] == 'N' \
					|| graph[i][j] == 'S' \
					|| graph[i][j] == 'L' \
					|| graph[i][j] == 'O') {
				search(i, j, graph[i][j], 0);
				return;
			}
		}
	}
}

int main() {
	D['N'] = E['S'] = 'L';
	D['S'] = E['N'] = 'O';
	D['L'] = E['O'] = 'S';
	D['O'] = E['L'] = 'N';
	y['N'] = y['S'] = x['L'] = x['O'] = 0;
	y['L'] = x['S'] = 1;
	y['O'] = x['N'] = -1;

	for(;;) {
		scanf("%d %d %d\n", &N, &M, &S);
		if(N == 0 && M == 0 && S == 0)
			break;
		for(int i = 0; i < N; i++)
			gets(graph[i]);
		gets(dirs);

		tot = 0;
		start();
		printf("%d\n", tot);
	}
}
