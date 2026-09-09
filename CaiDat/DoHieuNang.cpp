#include "../KhaiBao/DoHieuNang.h"
#include <iostream>

void DoHieuNang::XuatBaoCaoCSV(const std::vector<KetQuaDo>& danhSachKetQua,
                                const std::string& duongDanFile) {
    std::ofstream tep(duongDanFile);
    if (!tep.is_open()) {
        std::cerr << "Khong the mo file de ghi: " << duongDanFile << std::endl;
        return;
    }

    tep << "BoDuLieu,ThuatToan,SoDiemGiao,QuangDuong_km,ThoiGianThucThi_micro_giay\n";
    for (const auto& kq : danhSachKetQua) {
        tep << kq.tenBoDuLieu << ","
            << kq.tenThuatToan << ","
            << kq.soDiemGiao << ","
            << kq.quangDuong_km << ","
            << kq.thoiGian_micro << "\n";
    }
    tep.close();
}
