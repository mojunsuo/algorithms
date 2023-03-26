https://www.acwing.com/solution/content/105579/

/*
 * @Author: ��ѧϰ��ͼ���
 * @Date: 2022-03-28 12:07:21
 * @LastEditTime: 2022-03-28 12:31:24
 * Bilibili:https://space.bilibili.com/7469540
 * ��Ŀ��ַ:https://www.acwing.com/problem/content/4384/
 * @keywords: ����dp ����dp
���߱�ȨΪ1�������ȨΪ0����ĳ������������е�������Ȩ�ؾ�����Ҫ��ת�ߵ�������
down[u]��ʾu�����ߵ�Ȩֵ��up[u]��ʾu�ڵ���������Ҫ��Ȩֵ
down[u]���ѡһ����dfs�Ϳ��������down[u] = ��down[j] + w
up[u] = up[fa] + (down[fa] - down[u]) - w + w' ͼ���ʼ�
���ͣ����ڵ������ߵ�Ȩ + ���ڵ������ߵ��۳�down[u]��Ȩ,�ٿ�fa��u��Ȩ + u�ߵ�fa��Ȩ
down[u]���㣬 up[u]��ʱ���㸸�ڵ������ӽ��

���𰸾�����С����Щdown[i] + up[i]
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

void dfs_down(int u,int from) // from�����ı�
{
    for(int i = h[u]; ~ i; i = ne[i]){
        if(i == (from ^ 1)) continue; // �ѵ������
        // from ^ 1 ż������һλ����, ��������һλż�� 01,23,45
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
    dfs_up(1, -1); // ��ͳ�Ƹ��ڵ�
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
