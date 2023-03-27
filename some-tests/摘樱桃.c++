class Solution {
private:
    int rows;
    int cols;
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // �������NΪ��Ч��������յ�Ҳ��Ч���������Ե���
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<vector<int>>> d(rows, vector<vector<int>>(cols, vector<int>(rows, INT_MIN)));
        return max(0, helper(grid, d, 0, 0, 0));
    }

    int helper(vector<vector<int>>& grid, vector<vector<vector<int>>>& d, int x1, int y1, int x2)
    {
        // ��������һ��·����y����
        int y2 = x1 + y1 - x2;
        // ������Ч��λ�û��߲��ɴ��·��
        if (x1 == rows || y1 == cols || x2 == rows || y2 == cols || grid[x1][y1] == -1 || grid[x2][y2] == -1)
        {
            return -1;
        }
        else if (d[x1][y1][x2] != INT_MIN)
        {
            // ֱ�ӷ����Ѿ�������Ľ��
            return d[x1][y1][x2];
        }
        else if (x1 == rows-1 && y1 == cols -1)
        {
            // �����յ㣬ֻ����һ�ν��
            return grid[x1][y1];
        }
        else
        {
            // �������
            // 1. �ۼӽ����ֵ���жϱ����ظ�����һ���Ľ��
            // 2. �����ĸ���������ֵ
            int res = max(max(helper(grid, d, x1, y1+1, x2), helper(grid, d, x1, y1+1, x2+1)),
                          max(helper(grid, d, x1+1, y1, x2), helper(grid, d, x1+1, y1, x2+1)));
            res = res < 0 ? res : (res + grid[x1][y1] + ((x2 != x1 && y1 != y2) ? grid[x2][y2] : 0));
            d[x1][y1][x2] = res;
            return res;
        }
    }
};

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<int>>dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n][n];
        memset(dp,-1,sizeof dp);
        int ans=0;
        dp[0][0][n-1]=grid[0][0]+grid[0][n-1];
        for(int r=1;r<m;r++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    
                    if(i==j)
                    {
                        int mx=-1;
                        for(auto x:dir)
                        {
                            int dx=x[0]+i;
                            int dy=x[1]+j;
                            if(dx<0||dy<0||dx==n||dy==n)
                            {
                                continue;
                            }
                            mx=max(mx,dp[r-1][dx][dy]);
                        }
                        if(mx==-1)
                        {
                            dp[r][i][j]=-1;
                        }
                        else{
                            dp[r][i][j]=mx+grid[r][i];
                        }
                        
                    }
                    else{
                        
                        int mx=-1;
                        for(auto x:dir)
                        {
                            int dx=x[0]+i;
                            int dy=x[1]+j;
                            if(dx<0||dy<0||dx==n||dy==n)
                            {
                                continue;
                            }
                            mx=max(mx,dp[r-1][dx][dy]);
                        }
                        if(mx==-1)
                        {
                            dp[r][i][j]=-1;
                        }
                        else dp[r][i][j]=mx+grid[r][i]+grid[r][j];
                    }
                    if(r==m-1)
                    {
                        //cout<<dp[r][i][j]<<endl;
                        ans=max(ans,dp[r][i][j]);
                    }
                }
            }
            
        }
        return ans;
    }
};