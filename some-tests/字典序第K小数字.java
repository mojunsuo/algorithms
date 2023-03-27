class Solution {
    public int findKthNumber(int n, int k) {
        int ans = 1;
        while (k > 1) {
            int cnt = getCnt(ans, n);
            if (cnt < k) {
                k -= cnt; ans++;
            } else {
                k--; ans *= 10;
            }
        }
        return ans;
    }
    int getCnt(int x, int limit) {
        String a = String.valueOf(x), b = String.valueOf(limit);
        int n = a.length(), m = b.length(), k = m - n;
        int ans = 0, u = Integer.parseInt(b.substring(0, n));
        for (int i = 0; i < k; i++) ans += Math.pow(10, i);
        if (u > x) ans += Math.pow(10, k);
        else if (u == x) ans += limit - x * Math.pow(10, k) + 1;
        return ans;
    }
}

class Solution {
    public int findKthNumber(int n, int k) {
        int curr = 1;//��1��ʼ��1���ֵ�����С��
        k--;//���k=1���򲻽��������ѭ����ֱ�ӷ���1������˵��1����Ŀ�꣬�ҵ�k-1��С����
        while (k > 0) {
            int steps = count(curr, n);//steps=��ǰ�ڵ�curr���ж��ٱ�nС���ӽڵ�(����n)
            if (steps <= k) {//��������Ҫȥ�ڽ��ڵ���
                curr++;//+1��ζ�ŵ������ڽ��ֵܽڵ�
                k = k - steps;
                //��ζ��ǰ���steps������������curr�ڵ��£������������ֵܽڵ��ҵ�k-stepsС����
            } else {//������curr��
                k--;//��ȥ��ǰ�ڵ�
                curr = curr * 10;//������࿪ʼ��Ѱ
            }
        }
        return curr;
    }

        public static int count(int curr, int n) {//����ڵ�curr���ж��ٱ�nС���ӽڵ�
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {//��ǰ���з���Ҫ��Ľڵ�
            steps += Math.min(last, n) - first + 1;//����
            first = first * 10;//���뵽��һ��
            last = last * 10 + 9;//���뵽��һ��
        }
        return steps;
    }
}