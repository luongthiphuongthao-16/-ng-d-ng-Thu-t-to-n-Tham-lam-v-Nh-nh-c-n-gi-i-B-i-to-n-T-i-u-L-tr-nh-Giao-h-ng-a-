#ifndef DULIEU_H
#define DULIEU_H

#include "Chung/DiemGiao.h"
#include <vector>

// Ba bộ dữ liệu thực nghiệm mô phỏng các đơn hàng thực tế của tiệm bánh
// "Góc Bếp Mẹ Bắp" tại khu vực TP.HCM và vùng lân cận (Thuận An, Bình Dương).
// Điểm 0 trong mỗi bộ dữ liệu luôn là vị trí tiệm bánh (điểm xuất phát).
std::vector<DiemGiao> TaoBoDuLieu1(); // 8 điểm giao hàng - khu vực gần
std::vector<DiemGiao> TaoBoDuLieu2(); // 10 điểm giao hàng - khu vực mở rộng
std::vector<DiemGiao> TaoBoDuLieu3(); // 12 điểm giao hàng - toàn khu vực

#endif
