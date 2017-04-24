//将无根树转为有根树，方便 Graph 软件（http://blog.csdn.net/iamzky/article/details/38844917）绘图
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e5;

int n;
int degree[maxn];

int head[maxn];
struct Edge { int to, next; } edge[maxn];
int cnt = 0;

void addEdge(int u, int v) {
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

void dfs(int root, int pre) {
	for (int i = head[root]; i; i = edge[i].next)
		if (edge[i].to != pre) {
			printf("%d %d\n", root, edge[i].to);
			dfs(edge[i].to, root);
		}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	memset(head, 0, sizeof head);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		addEdge(a, b); addEdge(b, a);
		++degree[a]; ++degree[b];
	}
	
	int root = 0;
	for (int i = 1; i <= n; i++) if (degree[i] > degree[root]) root = i;
	
	dfs(root, 0);
	return 0;
}
