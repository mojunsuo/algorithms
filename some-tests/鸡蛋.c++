class Solution {
public:
    int calcF(int K, int T)
    {
        if (T == 1 || K == 1) return T + 1;
        return calcF(K - 1, T - 1) + calcF(K, T - 1);
    }

    int superEggDrop(int K, int N)
    {
        int T = 1;
        while (calcF(K, T) < N + 1) T++;
        return T;
    }
};