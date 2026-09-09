#include "../KhaiBao/NhanhCan.h"
#include <limits>
#include <algorithm>

namespace {

const double VO_CUC = std::numeric_limits<double>::max();

// Hàm tính cận dưới (lower bound) cho một trạng thái bộ phận của lộ trình.
// Ý tưởng: với đỉnh hiện tại, cộng thêm cạnh ra rẻ nhất tới một đỉnh còn lại
// (đỉnh chưa thăm hoặc điểm xuất phát để khép chu trình); với mỗi đỉnh CHƯA
// thăm còn lại, cộng thêm cạnh ra rẻ nhất của chính đỉnh đó. Cận dưới này
// không bao giờ vượt quá chi phí thật của phần đường đi còn lại, do đó đảm
// bảo tính hợp lệ (admissible) để cắt nhánh an toàn.
double TinhCanDuoi(const std::vector<std::vector<double>>& C, int n,
                    const std::vector<bool>& daTham, int diemHienTai,
                    double chiPhiHienTai) {
    double canDuoi = chiPhiHienTai;

    double minTuHienTai = VO_CUC;
    for (int j = 0; j < n; j++) {
        if (j == diemHienTai) continue;
        if (!daTham[j] || j == 0)
            minTuHienTai = std::min(minTuHienTai, C[diemHienTai][j]);
    }
    if (minTuHienTai < VO_CUC) canDuoi += minTuHienTai;

    for (int i = 0; i < n; i++) {
        if (!daTham[i] && i != diemHienTai) {
            double minCanhRa = VO_CUC;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (!daTham[j] || j == 0)
                    minCanhRa = std::min(minCanhRa, C[i][j]);
            }
            if (minCanhRa < VO_CUC) canDuoi += minCanhRa;
        }
    }
    return canDuoi;
}

struct BoGiaiNhanhCan {
    const std::vector<std::vector<double>>& C;
    int n;
    double canTren;
    std::vector<int> loTrinhTotNhat;

    void ThuNghiem(std::vector<int>& duongDiHienTai, std::vector<bool>& daTham,
                    double chiPhiHienTai) {
        int diemHienTai = duongDiHienTai.back();

        // Trường hợp cơ sở: đã ghé thăm hết các điểm giao hàng
        if ((int)duongDiHienTai.size() == n) {
            double tongCuoi = chiPhiHienTai + C[diemHienTai][0];
            if (tongCuoi < canTren) {
                canTren = tongCuoi;
                loTrinhTotNhat = duongDiHienTai;
                loTrinhTotNhat.push_back(0);
            }
            return;
        }

        // Sắp xếp các nhánh con theo khoảng cách tăng dần để ưu tiên khám phá
        // nhánh "hứa hẹn" trước, giúp tìm được cận trên tốt sớm và cắt tỉa hiệu quả hơn
        std::vector<int> ungVien;
        for (int j = 0; j < n; j++) if (!daTham[j]) ungVien.push_back(j);
        std::sort(ungVien.begin(), ungVien.end(), [&](int a, int b) {
            return C[diemHienTai][a] < C[diemHienTai][b];
        });

        for (int diemKe : ungVien) {
            double chiPhiMoi = chiPhiHienTai + C[diemHienTai][diemKe];
            if (chiPhiMoi >= canTren) continue; // cắt nhánh: đã vượt cận trên

            daTham[diemKe] = true;
            duongDiHienTai.push_back(diemKe);

            double canDuoi = TinhCanDuoi(C, n, daTham, diemKe, chiPhiMoi);
            if (canDuoi < canTren) {
                // Nhánh còn "hứa hẹn" (cận dưới nhỏ hơn cận trên hiện có) -> tiếp tục khám phá
                ThuNghiem(duongDiHienTai, daTham, chiPhiMoi);
            }
            // Ngược lại: cắt nhánh (bound), không khám phá tiếp nhánh con này

            duongDiHienTai.pop_back();
            daTham[diemKe] = false;
        }
    }
};

} // namespace

KetQuaLoTrinh GiaiNhanhCan(const std::vector<DiemGiao>& diem, double canTrenBanDau) {
    int n = (int)diem.size();
    auto C = XayDungMaTranKhoangCach(diem);

    BoGiaiNhanhCan boGiai{ C, n, canTrenBanDau, {} };

    std::vector<int> duongDiHienTai = { 0 };
    std::vector<bool> daTham(n, false);
    daTham[0] = true;

    boGiai.ThuNghiem(duongDiHienTai, daTham, 0.0);

    // Nếu vì lý do nào đó nhánh cận không tìm được lời giải tốt hơn cận trên ban đầu
    // (trường hợp hiếm, ví dụ n quá nhỏ), trả về một lộ trình mặc định an toàn
    if (boGiai.loTrinhTotNhat.empty()) {
        std::vector<int> mac_dinh;
        for (int i = 0; i < n; i++) mac_dinh.push_back(i);
        mac_dinh.push_back(0);
        return { mac_dinh, canTrenBanDau };
    }

    return { boGiai.loTrinhTotNhat, boGiai.canTren };
}
