class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26];
        int maxi = 0;
        int maxcnt = 0;
        for (char task : tasks) {
            cnt[task - 'A']++;
            if (cnt[task - 'A'] == maxi) {
                maxcnt++;
            } else if (cnt[task - 'A'] > maxi) {
                maxi = cnt[task - 'A'];
                maxcnt = 1;
            }
        }
        int partcnt = maxi - 1;
        int partln = n - (maxcnt - 1);
        int emptyslots = partcnt * partln;
        int ava = tasks.size() - maxi * maxcnt;
        int idles = max(0, emptyslots - ava);
        return tasks.size() + idles;
    }
};