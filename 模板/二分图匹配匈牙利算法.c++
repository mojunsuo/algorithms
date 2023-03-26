#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 3;
int n = maxn, m = maxn;
int Map[maxn][maxn];//map[i][j]=1表示X部的i和Y部的j存在路径,是否可以匹配
int cx[maxn], cy[maxn];
bool vis[maxn];
//cx[i]表示X部i点匹配的Y部顶点的编号
//cy[i]表示Y部i点匹配的X部顶点的编号
 
bool dfs(int u)//dfs进入的都是X部的点
{
	for (int v = 0; v < n; v++)//枚举Y部的点，判断X部的u和Y部的v是否存在路径
	{
		//如果存在路径并且还没被标记加入增广路
		if (Map[u][v] && !vis[v])//vis数组只标记Y组
		{
			//标记加入增广路
			vis[v] = 1;
 
			//如果Y部的点v还未被匹配
			//或者已经被匹配了，但是可以从v点原来匹配的cy[v]找到一条增广路
			//说明这条路就可是一个正确的匹配
			//因为递归第一次进入dfs时，u是未匹配的
			//如果v还没有匹配对象，即和它相连的所有边都不在，已经选择的匹配边集合M（M\in E）中，这时就找到了u-v增广路径
			//如果v已经有匹配对象了，那么u-v是一条未选择的边，而v-cy[v] \in M 则是一条已经选择的边, dfs(cy[v])从cy[v]开始搜索增广路径
				//如果新的v'没有匹配对象，那么u-v-cy[v]-v'就是一条增广路径，如果v'已经有匹配对象了，那么根据匹配是唯一的，cy[v]-v'一定不在已经选择的边中(和cy[v]-v冲突)，u-v-cy[v]-v'-cy[v']符合增广路径对边顺序的要求，继续利用dfs(cy[v'])搜索u-v-cy[v]-v'-cy[v']-下面的点
				//当搜索到增广链时，如u-v-cy[v]-v',那么经过递归的匹配调整和return 1，进行匹配增广操作，假设dfs0 是main调用的dfs算法，dfs1是dfs0调用的dfs算法
				//在dfs1中进行cy[v]-v'的匹配，因为dfs1返回1，因此在dfs0中进行u-v的匹配，匹配增广操作的结果是{cy[v]-v}->{u-v,cy[v]-v'}
				//如果在一个dfs(k)自调用的dfs(k+1)中，遍历所有的v(k+1),要么已经有匹配点了，要么和输入u(k+1)没有连接可能，这时搜索终止，说明不存在经过u(k+1)的增广链，返回0
				//而在main调用的dfs(0)中，调用的dfs(1)返回的都是0，而且v都是已经有匹配了，那么不存在从该点出发的增广链，那么就该点就不在最大匹配当中
				//为什么找不到增广链就不在最大匹配当中呢？感觉可以用反证法证明，博客中下面内容可能有更新这方面的思考
			if (cy[v] == -1 || dfs(cy[v]))
			{
				cx[u] = v;//可以匹配，进行匹配
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;//不能匹配
}
int maxmatch()//匈牙利算法主函数
{
	int ans = 0;
	//匹配清空，全部置为-1
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	for (int i = 0; i < n; i++)
	{
		if (cx[i] == -1)//如果X部的i还未匹配
		{
			memset(vis, 0, sizeof(vis));//每次找增广路的时候清空vis
			ans += dfs(i);
		}
	}
	return ans;
}
 
int main_test()
{
	//输入匹配的两个点集合的数量
	cin >> n >> m;
	//输入两个点集合成员间的匹配可能
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		Map[x][y] = 1;
	}
	//执行匈牙利算法，输出最大匹配
	cout << maxmatch() << endl;
}