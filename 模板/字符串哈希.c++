class Solution {
    static final int P = 131;
    long[] h, p;
    int n;
    int sl, sr;
    public String longestDupSubstring(String s) {
        n = s.length();
        h = new long[n + 10];
        p = new long[n + 10];
        p[0] = 1;
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] * P;
            h[i + 1] = h[i] * P + s.charAt(i);
        }
        int l = 1, r = n - 1;
        while (l <= r) {
            int mid = (r + l) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l == 1 ? "" : s.substring(sl, sr);
    }

    private boolean check(int mid) {
        Map<Long, int[]> map = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            if (i + mid - 1 > n) {
                continue;
            }
            int j = i + mid - 1;
            long cur = h[j] - h[i - 1] * p[j - i + 1];
            if (map.containsKey(cur)) {
               sl = map.get(cur)[0];
               sr = map.get(cur)[1];
               return true;
            }
            map.put(cur, new int[] {i - 1, j});
        }
        return false;
    }
}