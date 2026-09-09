#include "../KhaiBao/DuLieu.h"

// Ghi chú: tọa độ (x, y) là tọa độ quy đổi trên hệ trục phẳng (đơn vị km),
// được ước lượng tương đối theo vị trí địa lý thực tế của các khu vực nhằm
// phục vụ mục đích mô phỏng và đo hiệu năng thuật toán trong đề tài.

std::vector<DiemGiao> TaoBoDuLieu1() {
    return {
        {0, "Tiem banh Goc Bep Me Bap (Thuan An)",  0.0,  0.0},
        {1, "Di An",                                 4.5,  1.2},
        {2, "Thu Duc",                                7.0, -2.5},
        {3, "Linh Xuan",                              3.0, -1.0},
        {4, "Lai Thieu",                             -2.0,  3.0},
        {5, "An Phu",                                 6.5, -5.0},
        {6, "Binh Hoa (Thuan An)",                   -1.5,  1.5},
        {7, "Tan Uyen",                               2.0,  6.0},
    };
}

std::vector<DiemGiao> TaoBoDuLieu2() {
    return {
        {0, "Tiem banh Goc Bep Me Bap (Thuan An)",  0.0,  0.0},
        {1, "Di An",                                 4.5,  1.2},
        {2, "Thu Duc",                                7.0, -2.5},
        {3, "Linh Xuan",                              3.0, -1.0},
        {4, "Lai Thieu",                             -2.0,  3.0},
        {5, "An Phu",                                 6.5, -5.0},
        {6, "Binh Hoa (Thuan An)",                   -1.5,  1.5},
        {7, "Tan Uyen",                               2.0,  6.0},
        {8, "Quan 1",                                13.0, -8.0},
        {9, "Binh Thanh",                             9.5, -6.0},
    };
}

std::vector<DiemGiao> TaoBoDuLieu3() {
    return {
        {0,  "Tiem banh Goc Bep Me Bap (Thuan An)", 0.0,   0.0},
        {1,  "Di An",                                4.5,   1.2},
        {2,  "Thu Duc",                               7.0,  -2.5},
        {3,  "Linh Xuan",                             3.0,  -1.0},
        {4,  "Lai Thieu",                            -2.0,   3.0},
        {5,  "An Phu",                                6.5,  -5.0},
        {6,  "Binh Hoa (Thuan An)",                  -1.5,   1.5},
        {7,  "Tan Uyen",                              2.0,   6.0},
        {8,  "Quan 1",                               13.0,  -8.0},
        {9,  "Binh Thanh",                            9.5,  -6.0},
        {10, "Go Vap",                                6.0,  -4.5},
        {11, "Hoc Mon",                               1.0,  -6.5},
    };
}
