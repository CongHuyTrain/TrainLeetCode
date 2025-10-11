#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//3186. Maximum Total Damage With Spell Casting
//Attempted
//Medium
//A magician has various spells.
//You are given an array power, where each element represents the damage of a spell.Multiple spells can have the same damage value.
//It is a known fact that if a magician decides to cast a spell with a damage of power[i], 
//they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
//Each spell can be cast only once.
//Return the maximum possible total damage that a magician can cast.
//Example 1:
//Input: power = [1, 1, 3, 4]
//Output : 6
//Explanation :
//    The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
//    Example 2 :
//    Input : power = [7, 1, 6, 6]
//    Output : 13
//    Explanation :
//    The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.
//Constraints:
//1 <= power.length <= 10^5
//1 <= power[i] <= 10^9
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> cnt;
        for (long long x : power) {
            cnt[x]++;
        }
        vector<long long> uniq(cnt.size());
        for (auto& p : cnt) {
            uniq.push_back(p.first);
        }
        sort(uniq.begin(), uniq.end());
        int n = uniq.size();
        // nxt[i] = chỉ số đầu tiên j > i sao cho uniq[j] > uniq[i] + 2
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            long long val = uniq[i];
            long long need = val + 2;
            // tìm j > i với uniq[j] > need
            // because upper_bound return iterator so minus begin() to return int
            int j = upper_bound(uniq.begin() + i + 1, uniq.end(), need) - uniq.begin();
            nxt[i] = j;
        }
        vector<long long> dp(n + 1, 0);  // dp[i]: max sát thương từ i đến n-1
        // tính từ cuối về đầu
        for (int i = n - 1; i >= 0; i--) {
            // chọn bỏ uniq[i]
            long long skip = dp[i + 1];
            // chọn lấy uniq[i]
            long long take = uniq[i] * cnt[uniq[i]];
            int j = nxt[i];
            if (j <= n) {
                take += dp[j];
            }
            dp[i] = max(skip, take);
        }
        return dp[0];
    }
};