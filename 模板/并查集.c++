#include<bits/stdc++.h>
using namespace std;
int main(){
    Solution();
}
class Djset {
public:
    vector<int> parent;  // ��¼�ڵ�ĸ�
    vector<int> rank;  // ��¼���ڵ����ȣ������Ż���
    Djset(int n): parent(vector<int>(n)), rank(vector<int>(n)) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // ѹ����ʽ��ֱ��ָ����ڵ�
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        vector<vector<string> > res;
        // ���ã��洢ÿ�����������ĸ��˻� ��ͬʱ �ڱ�������ʱ���ж������Ƿ���ֹ�
        // ��ʽ��<���䣬�˻�id>
        unordered_map<string, int> um;
        int n = acc.size();
        Djset ds(n);
        for (int i = 0; i < n; i++) {
            int m = acc[i].size();
            for (int j = 1; j < m; j++) {
                string s = acc[i][j];
                if (um.find(s) == um.end()) {
                    um[s] = i;
                } else {
                    ds.merge(i, um[s]);
                }
            }
        }
        
        // ���ã� �洢ÿ���˻��µ�����
        // ��ʽ�� <�˻�id, �����б�> >
        // ע�⣺�����key�������˻�id���������˻����ƣ����ƿ�����ͬ������ɸ���
        unordered_map<int, vector<string> > umv;
        for (auto&[k, v]:um) umv[ds.find(v)].emplace_back(k);
        for (auto&[k, v]:umv){
            sort(v.begin(), v.end());
            vector<string> tmp(1, acc[k][0]);
            tmp.insert(tmp.end(), v.begin(), v.end());
            res.emplace_back(tmp);
        } 


        return res;
    }
};