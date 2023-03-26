#include<bits/stdc++.h>

using namespace std;

const int maxn=100010;

int a[maxn+2];

struct tree{
    int l,r;
    long long pre,add;
}t[4*maxn+2];

void bulid(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        t[p].pre=a[l];
        return;
    }
    int mid=l+r>>1;
    bulid(p*2,l,mid);
    bulid(p*2+1,mid+1,r);
    t[p].pre=t[p*2].pre+t[p*2+1].pre;
} 

void spread(int p){
    if(t[p].add){
        t[p*2].pre+=t[p].add*(t[p*2].r-t[p*2].l+1);
        t[p*2+1].pre+=t[p].add*(t[p*2+1].r-t[p*2+1].l+1);
        t[p*2].add+=t[p].add;
        t[p*2+1].add+=t[p].add;
        t[p].add=0;
    }
}

void change(int p,int x,int y,int z){
    if(x<=t[p].l && y>=t[p].r){
        t[p].pre+=(long long)z*(t[p].r-t[p].l+1);
        t[p].add+=z;
        return;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid) change(p*2,x,y,z);
    if(y>mid) change(p*2+1,x,y,z);
    t[p].pre=t[p*2].pre+t[p*2+1].pre;   
}

long long ask(int p,int x,int y){
    if(x<=t[p].l && y>=t[p].r) return t[p].pre;
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    long long ans=0;
    if(x<=mid) ans+=ask(p*2,x,y);
    if(y>mid) ans+=ask(p*2+1,x,y);
    return ans;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    bulid(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int q,x,y,z;
        scanf("%d",&q);
        if(q==1){
            scanf("%d%d%d",&x,&y,&z);
            change(1,x,y,z);
        }
        else {
            scanf("%d%d",&x,&y);
            cout<<ask(1,x,y)<<endl;
        }
    }
    return 0;
}


#include<cstdio>
using namespace std;
int n,m,a[100010];
struct llk
{
	long long l,r,lazy,sum;
}tree[500010];
void build(int id,int l,int r)
{
	tree[id].l=l;
	tree[id].r=r;
	if(l==r)
	{
		tree[id].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
void down(int id)
{
	tree[id*2].lazy+=tree[id].lazy;
	tree[id*2].sum+=(tree[id*2].r-tree[id*2].l+1)*tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;
	tree[id*2+1].sum+=(tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].lazy;
	tree[id].lazy=0;
}
void update(int id,int l,int r,int v)
{
	if(tree[id].l>r || tree[id].r<l) return;
	if(tree[id].l>=l && tree[id].r<=r)
	{
		tree[id].lazy+=v;
		tree[id].sum+=(tree[id].r-tree[id].l+1)*v;
		return;
	}
	if(tree[id].lazy>0) down(id);
	update(id*2,l,r,v);
	update(id*2+1,l,r,v);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
long long query(int id,int l,int r)
{
	if(tree[id].l>r || tree[id].r<l) return 0;
	if(tree[id].l>=l && tree[id].r<=r) return tree[id].sum;
	if(tree[id].lazy>0) down(id);
	return query(id*2,l,r)+query(id*2+1,l,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int o,x,y;
		scanf("%d",&o);
		if(o==1)
		{
			int k;
			scanf("%d%d%d",&x,&y,&k);
			update(1,x,y,k);
		}
		else 
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,x,y));
		}
	}
}