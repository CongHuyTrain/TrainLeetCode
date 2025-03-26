#pragma once
#include<vector>
#include <algorithm>
using namespace std;
//2033. Các phép toán tối thiểu để tạo lưới giá trị đơn nhất
//Đã giải quyết
//Trung bình
//Chủ đề
//Các công ty
//Gợi ý
//Bạn được cung cấp một số nguyên 2D gridcó kích thước m x nvà một số nguyên x.Trong một phép toán, bạn có thể thêm x vào hoặc trừ đi x bất kỳ phần tử nào trong grid.
//
//Lưới đơn giá trị là lưới mà tất cả các phần tử đều bằng nhau.
//
//Trả về số lượng thao tác tối thiểu để làm cho lưới có giá trị đơn nhất.Nếu không thể, hãy trả về - 1.
//
//
//
//Ví dụ 1:
//
//
//Đầu vào : lưới = [[2, 4], [6, 8]], x = 2
//Đầu ra : 4
//Giải thích : Chúng ta có thể làm cho mọi phần tử bằng 4 bằng cách thực hiện như sau :
//-Thêm x vào 2 một lần.
//- Trừ x khỏi 6 một lần.
//- Trừ x khỏi 8 hai lần.
//Tổng cộng có 4 phép toán được sử dụng.
//Ví dụ 2 :
//
//
//    Đầu vào : lưới = [[1, 5], [2, 3]], x = 1
//    Đầu ra : 5
//    Giải thích : Chúng ta có thể làm cho mọi phần tử bằng 3.
//    Ví dụ 3 :
//
//
//    Đầu vào : lưới = [[1, 2], [3, 4]], x = 2
//    Đầu ra : -1
//    Giải thích : Không thể làm cho mọi phần tử bằng nhau.
//
//
//    Hạn chế :
//
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 105
//1 <= m * n <= 105
//1 <= x, grid[i][j] <= 104
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> count;
        int result = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                count.push_back(grid[row][col]);
            }
        }
        sort(count.begin(), count.end());
        for (int c : count) {
            if (abs(c - count[0]) % x != 0) {
                return -1;
            }
        }
        int median = count[count.size() / 2];
        for (int c : count) {
            result += abs(c - median) / x;
        }
        return result;
    }
};