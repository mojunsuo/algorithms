https://www.cnblogs.com/wzxbeliever/p/16184744.html
#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
#define ll long long
const int maxn=1e5+5;
ll val[maxn];
int fa[maxn];
int n,m,Q;
int find(int x){
	if(x==fa[x])return x;
	int oldfa=fa[x];
	fa[x]=find(fa[x]);
	val[x]+=val[oldfa];
	return fa[x];
}
int main(){
	cin>>n>>m>>Q;
	for(int i=0;i<=n;i++)fa[i]=i; 
    for(int i=1;i<=m;i++){
    	ll L,R,S;
    	cin>>L>>R>>S;
    	L--;
    	int fx=find(L),fy=find(R);
    		fa[fy]=fx;
    		val[fy]=val[L]-val[R]-S;
	}
	while(Q--){
		int L,R;
		cin>>L>>R;
		L--;
		int fx=find(L),fy=find(R);
		if(fx!=fy)
		cout<<"UNKNOWN"<<endl;
		else cout<<val[L]-val[R]<<endl;
	}
	return 0;
}
 
 https://www.cnblogs.com/gribouillage/p/11311548.html
  1 #include <cstdio>
  2 #include <cstring>
  3 #include <cmath>
  4 #include <cstdlib>
  5 #include <ctime>
  6 #include <cctype>
  7 #include <cstring>
  8 #include <cmath>
  9 #include <iostream>
 10 #include <sstream>
 11 #include <string>
 12 #include <list>
 13 #include <vector>
 14 #include <set>
 15 #include <map>
 16 #include <queue>
 17 #include <stack>
 18 #include <algorithm>
 19 #include <functional>
 20 #define pr pair<int,LL>
 21 #define lowbit(x) (x&(-x))
 22 #define rep(i,a,n) for (int i=a;i<=n;i++)
 23 #define per(i,a,n) for (int i=a;i>=n;i--)
 24 #define mem(ar,num) memset(ar,num,sizeof(ar))
 25 #define debug(x) cout << #x << ": " << x << endl
 26 using namespace std;
 27 typedef long long LL;
 28 typedef unsigned long long ULL;
 29 const int    prime = 999983;
 30 const int    INF = 0x7FFFFFFF;
 31 const LL     INFF =0x7FFFFFFFFFFFFFFF;
 32 const double pi = acos(-1.0);
 33 const double inf = 1e18;
 34 const double eps = 1e-6;
 35 const LL     mod = 1e9 + 7;
 36 const int    maxn = 5e5 + 7;
 37 const int    maxm = 4e6 + 7;
 38 
 39 
 40 inline int read () {   //�����Ż�
 41     int X = 0, w = 1; char ch = 0;
 42     while(ch < '-') { if(ch == '-') w = -1; ch = getchar(); }
 43     while(ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
 44     return X * w;
 45 }
 46 
 47 int pre[maxn],rela[maxn];
 48 int n, k, ans;
 49 
 50 void init() // ��ʼ��
 51 {
 52     for(int i = 1; i <= n; i++){
 53         pre[i] = i; // ͷ�ڵ�����Լ�����
 54         rela[i] = 0; // �Լ����Լ��϶���ͬ��
 55     }
 56     ans = 0; //��¼�ٻ�����
 57 }
 58 
 59 int Find(int x){   // ���ҵ�ǰ���ĸ��ڵ�
 60     if(x == pre[x]) return x;
 61     else{       // ѹ��·��
 62         int temp = pre[x];
 63         pre[x] = Find(pre[x]); // �ݹ�Ѱ�Ҹ��ڵ�,ѹ��·���ڵ�
 64         rela[x] = (rela[x] + rela[temp]) % 3; // ѹ��·����ϵ
 65     }
 66     return pre[x];
 67 }
 68 
 69 void Merge(int x, int y, int r){ // �ϲ������ڵ��ϵ
 70     int fx = Find(x);  // ���� x,y�ĸ��ڵ�
 71     int fy = Find(y);
 72 
 73     if(fx != fy){  //����ڵ㲻ͬ���кϲ�
 74         pre[fx] = fy;   //��x�ڵ㼯�Ϻϲ���y
 75         rela[fx] = (rela[y] - rela[x] + r + 3) % 3; //����xͷ�ڵ���yͷ�ڵ�Ĺ�ϵ
 76     }
 77 
 78 }
 79 
 80 bool solve(int x,int y,int r){ // �ж��滰�ٻ�
 81     int relation;
 82     if(x > n||y > n||(r == 1&&x == y)){ // ��������ֱ���жϵļٻ�
 83             return false;
 84     }
 85     if(Find(x) == Find(y)){ // ����������ڵ���ͬ
 86         relation = (rela[x] - rela[y] + 3) % 3; // �Ƴ��������ڵ�֮��Ĺ�ϵ
 87         return relation == r; // �жϸ�����ϵ�Ƿ����Ѿ����ڵĹ�ϵì��
 88     }
 89     else
 90         return true; //����Ϊ��
 91 }
 92 /// 0 ��ʾ����ڵ���ͬ��
 93 /// 1 ��ʾ����ڵ��ǲ�ʳ��ϵ
 94 /// 2 ��ʾ����ڵ��Ǳ���ʳ��ϵ
 95 int main()
 96 {
 97     n = read();
 98     k = read();
 99     init();
100     int c, x, y;
101     while(k--){
102         c = read();
103         x = read();
104         y = read();
105         c --;
106         if(solve(x,y,c)){
107             Merge(x,y,c); //�滰�ϲ������ڵ��ϵ
108         }else{
109             ans++; //�ٻ�������
110         }
111     }
112     printf("%d\n",ans);
113     return 0;
114 }