https://www.acwing.com/solution/content/105579/

/*
 * @Author: 爱学习的图灵机
 * @Date: 2022-03-28 12:07:21
 * @LastEditTime: 2022-03-28 12:31:24
 * Bilibili:https://space.bilibili.com/7469540
 * 题目地址:https://www.acwing.com/problem/content/4384/
 * @keywords: 树形dp 换根dp
令反向边边权为1，正向边权为0，从某点出发遍历所有点所过的权重就是需要翻转边的数量。
down[u]表示u向下走的权值，up[u]表示u节点向上走需要的权值
down[u]随便选一个根dfs就可以求出。down[u] = Σdown[j] + w
up[u] = up[fa] + (down[fa] - down[u]) - w + w' 图见笔记
解释：父节点向上走的权 + 父节点向下走但扣除down[u]的权,再扣fa到u的权 + u走到fa的权
down[u]先算， up[u]算时先算父节点再算子结点

最后答案就是最小的那些down[i] + up[i]
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx;
int down[N], up[N];
int n;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dfs_down(int u,int from) // from是来的边
{
    for(int i = h[u]; ~ i; i = ne[i]){
        if(i == (from ^ 1)) continue; // 搜到反向边
        // from ^ 1 偶数和下一位奇数, 奇数和上一位偶数 01,23,45
        int j = e[i];
        dfs_down(j, i);
        down[u] += down[j] + w[i];
    }
}

void dfs_up(int u,int from){
    if(from != -1){
        int fa = e[from ^ 1];
        up[u] = up[fa] + down[fa] - down[u] - w[from] + w[from ^ 1];
    }
    for(int i = h[u]; ~ i; i = ne[i]){
        if(i == (from ^ 1)) continue;
        int j = e[i];
        dfs_up(j, i);
    }
}

int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; ++ i){
        int a, b;scanf("%d%d", &a, &b);
        add(a, b, 0), add(b, a, 1);
    }
    dfs_down(1, -1);
    dfs_up(1, -1); // 先统计父节点
    int res = N;
    for(int i = 1; i <= n; ++ i){
        res = min(res, down[i] + up[i]);
    }
    printf("%d\n", res);
    for(int i = 1; i <= n; ++ i){
        if(down[i] + up[i] == res){
            printf("%d ", i); 
        }
    }



    return 0;
}
