#pragma once
#include <vector>
using namespace std;
//2787. Các cách biểu diễn số nguyên dưới dạng tổng các lũy thừa
//Đã giải quyết
//Trung bình
//Chủ đề
//biểu tượng khóa cao cấp
//Các công ty
//Gợi ý
//Cho hai số nguyên dươngn và x.
//
//Trả về số cách ncó thể biểu diễn dưới dạng tổng lũy thừa của các số nguyên dương duy nhất, hay nói cách khác, là số tập hợp các số nguyên duy nhất trong đó.xth[n1, n2, ..., nk]n = n1x + n2x + ... + nkx
//
//Vì kết quả có thể rất lớn nên hãy trả về theo modulo .109 + 7
//
//Ví dụ, nếu n = 160và x = 3, một cách để biểu thị nlà.n = 23 + 33 + 53
//
//
//
//Ví dụ 1:
//
//Đầu vào : n = 10, x = 2
//Đầu ra : 1
//Giải thích : Ta có thể biểu thị n như sau : n = 3 2 + 1 2 = 10.
//Có thể chứng minh rằng đây là cách duy nhất để biểu thị 10 dưới dạng tổng lũy thừa bậc 2 của các số nguyên duy nhất.
//Ví dụ 2 :
//
//    Đầu vào : n = 4, x = 1
//    Đầu ra : 2
//    Giải thích : Chúng ta có thể biểu thị n theo những cách sau :
//-n = 4 1 = 4.
//- n = 3 1 + 1 1 = 4.
//
//
//Hạn chế :
//
//1 <= n <= 300
//1 <= x <= 5
class Solution {
public:
	static const int MOD = 1'000'000'007; // ' is used to avoid confusion, it is not a part of the number.
    //when reading the code, it is easier to read
    int numberOfWays(int n, int x) {
        vector<int>powers;
		for (int i = 1; ; ++i) { // From 1 because we caculate 1-> a number that ^ <= n
            long long p = 1;
            for (int k = 0; k < x; ++k) p *= i;
            if (p > n) break;
            powers.push_back((int)p);
        }
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // start
        for (int p : powers) {
            for (int s = n; s >= p; --s) dp[s] = (dp[s] + dp[s - p]) % MOD; // backward looping ensures each power is used at most once
        }
        return (int)dp[n];
    }
};