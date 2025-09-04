#pragma once
#include <cmath>
//3516. Tìm người gần nhất
//Đã giải quyết
//Dễ
//Chủ đề
//biểu tượng khóa cao cấp
//Các công ty
//Gợi ý
//Bạn được cho ba số nguyên x, y, và z, biểu diễn vị trí của ba người trên một trục số :
//xlà vị trí của Người 1.
//ylà vị trí của Người 2.
//zlà vị trí của Người thứ 3, người không di chuyển.
//Cả Người 1 và Người 2 đều di chuyển về phía Người 3 với cùng tốc độ.
//Xác định xem người nào đến được Người thứ 3 trước :
//Trả về 1 nếu Người 1 đến trước.
//Trả về 2 nếu Người 2 đến trước.
//Trả về 0 nếu cả hai đến cùng một lúc.
//Trả lại kết quả tương ứng.
//Ví dụ 1:
//Đầu vào : x = 2, y = 7, z = 4
//Đầu ra : 1
//Giải thích :
//Người 1 ở vị trí 2 và có thể tiếp cận Người 3 (ở vị trí 4) trong 2 bước.
//Người thứ 2 ở vị trí thứ 7 và có thể tiếp cận Người thứ 3 trong 3 bước.
//Vì Người 1 đến Người 3 trước nên kết quả là 1.
//Ví dụ 2:
//Đầu vào : x = 2, y = 5, z = 6
//Đầu ra : 2
//Giải thích :
//Người 1 ở vị trí 2 và có thể tiếp cận Người 3 (ở vị trí 6) trong 4 bước.
//Người 2 ở vị trí 5 và có thể tiếp cận Người 3 chỉ trong 1 bước.
//Vì Người 2 đến Người 3 trước nên kết quả là 2.
//Ví dụ 3:
//Đầu vào : x = 1, y = 5, z = 3
//Đầu ra : 0
//Giải thích :
//Người 1 ở vị trí 1 và có thể tiếp cận Người 3 (ở vị trí 3) trong 2 bước.
//Người thứ 2 ở vị trí thứ 5 và có thể tiếp cận Người thứ 3 trong 2 bước.
//Vì cả Người 1 và Người 2 đều đến Người 3 cùng lúc nên kết quả đầu ra là 0.
//Hạn chế :
//1 <= x, y, z <= 100
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs(z - x) == abs(z - y))    return 0;
        else if (abs(z - x) < abs(z - y))    return 1;
        else    return 2;
    }
};