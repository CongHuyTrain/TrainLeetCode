#pragma once
#include<vector>
#include<iostream>
using namespace std;
//26. Xóa các phần tử trùng lặp khỏi mảng đã sắp xếp
//Đã giải quyết
//Dễ
//Chủ đề
//Các công ty
//Gợi ý
//Cho một mảng số nguyên numsđược sắp xếp theo thứ tự không giảm, hãy xóa các phần tử trùng lặp tại chỗ sao cho mỗi phần tử duy nhất chỉ xuất hiện một lần.Thứ tự tương đối của các phần tử phải được giữ nguyên.Sau đó trả về số phần tử duy nhất trongnums .
//
//Hãy xem xét số lượng phần tử duy nhất của numsto be k, để được chấp nhận, bạn cần thực hiện những điều sau :
//
//Thay đổi mảng numssao cho kcác phần tử đầu tiên của numschứa các phần tử duy nhất theo thứ tự numsban đầu.Các phần tử còn lại của numskhông quan trọng cũng như kích thước của nums.
//Trở lại k.
//Ví dụ 1:
//
//Đầu vào : nums = [1, 1, 2]
//Đầu ra : 2, nums = [1, 2, _]
//Giải thích : Hàm của bạn phải trả về k = 2, với hai phần tử đầu tiên của nums lần lượt là 1 và 2.
//Không quan trọng bạn để lại gì ngoài k trả về(do đó chúng là dấu gạch dưới).
//Ví dụ 2 :
//
//    Đầu vào : nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//    Đầu ra : 5, nums = [0, 1, 2, 3, 4, _, _, _, _, _]
//    Giải thích : Hàm của bạn sẽ trả về k = 5, với năm phần tử đầu tiên của nums lần lượt là 0, 1, 2, 3 và 4.
//    Không quan trọng bạn để lại gì ngoài k trả về(do đó chúng là dấu gạch dưới).
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1; // we will try 1
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // if true then 
                nums[k] = nums[i];
                k++;
            }
        }
        return k; // we need to return nums if does exits same number.
    }
};