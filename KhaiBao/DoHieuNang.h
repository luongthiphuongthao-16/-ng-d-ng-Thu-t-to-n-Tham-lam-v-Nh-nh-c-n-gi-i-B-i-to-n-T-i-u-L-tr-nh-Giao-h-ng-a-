#ifndef DOHIEUNANG_H
#define DOHIEUNANG_H

#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <utility>

// Cấu trúc lưu một dòng kết quả đo hiệu năng, dùng để xuất báo cáo so sánh
struct KetQuaDo {
    std::string tenBoDuLieu;     // Ví dụ: "Bộ dữ liệu 1"
    std::string tenThuatToan;    // "Tham lam" hoặc "Nhánh cận"
    int soDiemGiao;              // Số điểm giao hàng (không tính điểm xuất phát)
    double quangDuong_km;        // Tổng quãng đường của lộ trình tìm được
    double thoiGian_micro;       // Thời gian thực thi, đơn vị micro giây (µs)
};

class DoHieuNang {
public:
    // Đo thời gian thực thi (µs) của một hàm bất kỳ (dùng std::chrono::high_resolution_clock)
    // Trả về cặp (kết quả hàm trả về, thời gian thực thi tính bằng micro giây)
    template <typename Ham, typename... ThamSo>
    static auto Do(Ham&& ham, ThamSo&&... thamSo)
        -> std::pair<decltype(ham(thamSo...)), double>
    {
        auto batDau = std::chrono::high_resolution_clock::now();
        auto ketQua = ham(std::forward<ThamSo>(thamSo)...);
        auto ketThuc = std::chrono::high_resolution_clock::now();
        double thoiGianMicro = std::chrono::duration<double, std::micro>(ketThuc - batDau).count();
        return { ketQua, thoiGianMicro };
    }

    // Xuất toàn bộ kết quả đo được ra file CSV để phục vụ lập Bảng 5.1
    static void XuatBaoCaoCSV(const std::vector<KetQuaDo>& danhSachKetQua, const std::string& duongDanFile);
};

#endif
