#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <ctime>
#include <iomanip>
#include <map>
#include <memory.h>
using namespace std;
inline int Max(int a, int b) { if (a < b) a = b; return a; }
inline int Min(int a, int b) { if (a > b) a = b; return a; }

const int maxn = 500005;
const double EPS = 1e-6;

struct node
{
	int a, b, c;
};

struct LiSanNode
{
	int value; // 离散化后的值.
	int Index; // 在原来数组中的下标.
};

struct ITree
{
	int l, r;
	int maxnum; // 最大值.
	int bj;
	int lchild, rchild;
};

int n, m, nn;
node a[maxn];
int ans;
LiSanNode arr[maxn]; // 离散化的排序的数组，每条边有两个x值，所以这里还要再开大两倍.
int Map[maxn]; // 离散化后的值对应原来的值.

int vertex;
ITree tree[maxn << 1];

void Init(void)
{
	int i, j;
	vertex = 1;
	// 注意我们这里不判断是否存在左右孩子，而是直接使用tree[0]，所以要给tree[0]赋初值.
	tree[0].maxnum = 0;
	ans = 0;
}

bool cmp(const node & a, const node & b)
{
	if (a.a != b.a) return a.a > b.a;
	if (a.b != b.b) return a.b > b.b;
	return a.c > b.c;
}

bool cmpArr(const LiSanNode & a, const LiSanNode & b)
{
	return a.value < b.value;
}

void LiSanHua(void)
{ // 离散化.
	int i, j;
	nn = 0; m = 0;
	for (i = 0; i < n; i++)
	{
		arr[nn].value = a[i].b, arr[nn++].Index = i;
	}
	sort(arr, arr + nn, cmpArr);
	for (i = 0; i < nn; i++)
	{
		if (i == 0 || arr[i].value != arr[i - 1].value)
		{
			Map[++m] = arr[i].value; // m从1开始.
		}
		a[arr[i].Index].b = m; // 改变原数组的值为映射后的值.
	}
}

void CreateTree(int a, int b)
{
	int now = vertex;
	tree[now].l = a, tree[now].r = b;
	tree[now].maxnum = -1; tree[now].bj = -1;
	tree[now].lchild = tree[now].rchild = 0;
	if (b > a)
	{
		int mid = (a + b) >> 1;
		tree[now].lchild = ++vertex;
		CreateTree(a, mid);
		tree[now].rchild = ++vertex;
		CreateTree(mid + 1, b);
	}
}

inline void Clear(int now)
{
	tree[now].maxnum = max(tree[now].maxnum, tree[now].bj);
	tree[tree[now].lchild].bj = tree[tree[now].rchild].bj = tree[now].maxnum;
	tree[now].bj = -1;
}

void InsertTree(int now, int a, int b, int c)
{
	if (a > b) return ;
	if (now == 0) return ;
	if (tree[now].bj >= 0) Clear(now);
	if (a <= tree[now].l && tree[now].r <= b)
	{
		//        cout << now << " " << tree[now].l << " " << tree[now].r << " " << tree[now].maxnum << endl;
		if (c > tree[now].maxnum)
		{
			tree[now].maxnum = c;
			tree[tree[now].lchild].bj = tree[tree[now].rchild].bj = c;
		}
		//        cout << tree[now].maxnum << endl;
	}
	else
	{
		int mid = (tree[now].l + tree[now].r) >> 1;
		if (a <= mid) InsertTree(tree[now].lchild, a, b, c);
		else Clear(tree[now].lchild);
		if (b > mid) InsertTree(tree[now].rchild, a, b, c);
		else Clear(tree[now].rchild);
		tree[now].maxnum = max(tree[tree[now].lchild].maxnum, tree[tree[now].rchild].maxnum);
	}
}

int QueryMaxTree(int now, int a, int b)
{
	//    cout << now << " " << tree[now].l << " " << tree[now].r << " " << tree[now].maxnum << endl;
	if (a > b) return -1;
	if (now == 0) return 0;
	if (tree[now].bj >= 0) Clear(now);
	if (a <= tree[now].l && tree[now].r <= b)
	{
		//        cout << tree[now].maxnum << endl;
		return tree[now].maxnum;
	}
	else
	{
		int mid = (tree[now].l + tree[now].r) >> 1;
		int na, nb;
		na = nb = -1;
		if (a <= mid) na = QueryMaxTree(tree[now].lchild, a, b);
		if (b > mid) nb = QueryMaxTree(tree[now].rchild, a, b);
		//        cout << na << " " << nb << endl;
		return max(na, nb);
	}
}

int main(void)
{
	//    freopen("in.txt", "r", stdin);
	int i, j;
	int start;
	scanf("%d", &n);
	Init();
	for (i = 0; i < n; ++i) scanf("%d", &a[i].a);
	for (i = 0; i < n; ++i) scanf("%d", &a[i].b);
	for (i = 0; i < n; ++i) scanf("%d", &a[i].c);
	sort(a, a + n, cmp);
	LiSanHua();
	CreateTree(1, m);

	start = -1;
	for (i = 0; i < n; ++i)
	{
		j = QueryMaxTree(1, a[i].b + 1, m);
		//        cout << a[i].a << " " << a[i].b << " " << a[i].c << " " << j << " " << m << endl;
		if (a[i].c < j) ans++;
		if (i < n - 1 && a[i].a == a[i + 1].a)
		{
			if (start == -1) start = i;
		}
		else
		{
			if (start == -1) start = i;
			for (j = start; j <= i; ++j)
			{
				InsertTree(1, 1, a[j].b, a[j].c);
				//                cout << a[j].b - 1 << " " << a[j].c << endl;
			}
			start = -1;
		}
	}
	printf("%d\n", ans);
	return 0;
}