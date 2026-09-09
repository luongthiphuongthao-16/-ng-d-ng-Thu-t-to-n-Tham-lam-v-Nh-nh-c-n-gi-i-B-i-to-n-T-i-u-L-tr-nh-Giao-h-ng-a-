#include "../KhaiBao/ThamLam.h"
#include <limits>

KetQuaLoTrinh GiaiThamLam(const std::vector<DiemGiao>& diem) {
    int n = (int)diem.size();
    std::vector<bool> daTham(n, false);
    std::vector<int> loTrinh;
    loTrinh.reserve(n);

    int hienTai = 0; // Điểm 0 = tiệm bánh (điểm xuất phát)
    daTham[hienTai] = true;
    loTrinh.push_back(hienTai);
    double tongQuangDuong = 0.0;

    // Vòng lặp chính: tại mỗi bước, tham lam chọn điểm giao hàng CHƯA thăm
    // và có khoảng cách GẦN NHẤT với vị trí hiện tại
    for (int buoc = 1; buoc < n; buoc++) {
        int diemGanNhat = -1;
        double khoangCachNhoNhat = std::numeric_limits<double>::max();

        for (int j = 0; j < n; j++) {
            if (!daTham[j]) {
                double kc = TinhKhoangCach(diem[hienTai], diem[j]);
                if (kc < khoangCachNhoNhat) {
                    khoangCachNhoNhat = kc;
                    diemGanNhat = j;
                }
            }
        }

        daTham[diemGanNhat] = true;
        loTrinh.push_back(diemGanNhat);
        tongQuangDuong += khoangCachNhoNhat;
        hienTai = diemGanNhat;
    }

    // Khép kín chu trình: quay về tiệm bánh sau khi giao hết các điểm
    tongQuangDuong += TinhKhoangCach(diem[hienTai], diem[0]);
    loTrinh.push_back(0);

    return { loTrinh, tongQuangDuong };
}
