#ifndef QUANLYTHUVIEN_H
#define QUANLYTHUVIEN_H

#include <fstream>
#include <iomanip>
#include "LinkedList.h"
#include "LopDoiTuong.h"
#include "Utils.h"

using namespace std;
class QuanLyThuVien {
private:
    LinkedList<Sach> _vecSach;
    LinkedList<BanDoc> _vecBD;
    LinkedList<PhieuMuon> _vecPhieu;
public:
    QuanLyThuVien();
    void khoiTaoDuLieuMau();
    void docFileSach();
    void ghiFileSach();
    void docFileBanDoc();
    void ghiFileBanDoc();
    void docFilePhieuMuon();
    void ghiFilePhieuMuon();
    void hienThiSach();
    void themSach();
    void xoaSach();
    void hienThiPhieuMuon();
    void muonSach();
    void themBanDoc();
    void traSach();
};
QuanLyThuVien::QuanLyThuVien() {
    this->khoiTaoDuLieuMau();
    this->docFileSach();
    this->docFileBanDoc();
    this->docFilePhieuMuon();
}
void QuanLyThuVien::khoiTaoDuLieuMau() {
    ifstream kiemTraAdmin("Admin.txt");
    if (!kiemTraAdmin) {
        ofstream fileAdmin("Admin.txt");
        if (fileAdmin) {
            fileAdmin << "admin 123" << endl;
            fileAdmin.close();
        }
    }
    kiemTraAdmin.close();
    ifstream kiemTraBanDoc("BanDoc.txt");
    if (!kiemTraBanDoc) {
        ofstream fileBanDoc("BanDoc.txt");
        if (fileBanDoc) { fileBanDoc.close(); }
    }
    kiemTraBanDoc.close();
    ifstream kiemTraSach("Sach.txt");
    if (!kiemTraSach) {
        ofstream fileSach("Sach.txt");
        if (fileSach) { fileSach.close(); }
    }
    kiemTraSach.close();
    ifstream kiemTraPhieu("PhieuMuon.txt");
    if (!kiemTraPhieu) {
        ofstream filePhieu("PhieuMuon.txt");
        if (filePhieu) { filePhieu.close(); }
    }
    kiemTraPhieu.close();
}
void QuanLyThuVien::docFileSach() {
    _vecSach.clear();
    ifstream fileSach("Sach.txt");
    if (!fileSach) return;
    string strLine = "";
    while (getline(fileSach, strLine)) {
        if (strLine.empty()) continue;
        LinkedList<string> parts = split(strLine, '|');
        if (parts.getSize() >= 9) {
            Sach objSach;
            objSach.setMaSach(parts[0]); 
            objSach.setTenSach(parts[1]); 
            objSach.setTacGia(parts[2]); 
            objSach.setNxb(parts[3]);
            double dGia = 0.0; 
            stringstream(parts[4]) >> dGia; 
            objSach.setGiaBan(dGia);
            int iNam = 0; 
            stringstream(parts[5]) >> iNam; 
            objSach.setNamPhatHanh(iNam);
            int iTrang = 0; 
            stringstream(parts[6]) >> iTrang; 
            objSach.setSoTrang(iTrang);
            objSach.setNgayNhapKho(parts[7]);
            int iTt = 0; 
            stringstream(parts[8]) >> iTt; 
            objSach.setTinhTrang(iTt);
            _vecSach.addTail(objSach);
        }
    }
    fileSach.close();
}
void QuanLyThuVien::ghiFileSach() {
    ofstream fileSach("Sach.txt");
    if (!fileSach) return;
     for (int i = 0; i < _vecSach.getSize(); i++) {
        fileSach << _vecSach[i].getMaSach() << "|"
             << _vecSach[i].getTenSach() << "|"
             << _vecSach[i].getTacGia() << "|"
             << _vecSach[i].getNxb() << "|"
             << _vecSach[i].getGiaBan() << "|"
             << _vecSach[i].getNamPhatHanh() << "|"
             << _vecSach[i].getSoTrang() << "|"
             << _vecSach[i].getNgayNhapKho() << "|"
             << _vecSach[i].getTinhTrang() << endl;
    }
    fileSach.close();
}
void QuanLyThuVien::docFileBanDoc() {
    _vecBD.clear();
    ifstream fileBanDoc("BanDoc.txt");
    if (!fileBanDoc) return;
    string strLine = "";
    while (getline(fileBanDoc, strLine)) {
        if (strLine.empty()) continue;
        LinkedList<string> parts = split(strLine, '|');
        if (parts.getSize() >= 3) {
            BanDoc objBd;
            objBd.setMaBD(parts[0]); 
            objBd.setHoTen(parts[1]); 
            objBd.setNgayDK(parts[2]);
            _vecBD.addTail(objBd);
        }
    }
    fileBanDoc.close();
}
void QuanLyThuVien::docFilePhieuMuon() {
    _vecPhieu.clear();
    ifstream filePhieuMuon("PhieuMuon.txt");
    if (!filePhieuMuon) return;
    string strLine = "";
    while (getline(filePhieuMuon, strLine)) {
        if (strLine.empty()) continue;
        LinkedList<string> parts = split(strLine, '|');
        if (parts.getSize() >= 6) {
            PhieuMuon objPhieu;
            int iSo = 0; 
            stringstream(parts[0]) >> iSo; 
            objPhieu.setSoPhieu(iSo);
            objPhieu.setMaBD(parts[1]); 
            objPhieu.setMaSach(parts[2]); 
            objPhieu.setNgayMuon(parts[3]); 
            objPhieu.setNgayTra(parts[4]);
            int iTt = 0; 
            stringstream(parts[5]) >> iTt; 
            objPhieu.setTinhTrang(iTt);
            this->_vecPhieu.addTail(objPhieu);
        }
    }
    filePhieuMuon.close();
}
void QuanLyThuVien::ghiFilePhieuMuon() {
    ofstream filePhieuMuon("PhieuMuon.txt");
    for (int i = 0; i < _vecPhieu.getSize(); ++i) {
        PhieuMuon objPhieu = _vecPhieu[i];
        filePhieuMuon <<_vecPhieu[i].getSoPhieu() << "|"
             <<_vecPhieu[i].getMaBD() << "|"
             <<_vecPhieu[i].getMaSach() << "|"
             <<_vecPhieu[i].getNgayMuon() << "|"
             <<_vecPhieu[i].getNgayTra() << "|"
             <<_vecPhieu[i].getTinhTrang() << endl;
    }
    filePhieuMuon.close();
}
void QuanLyThuVien::hienThiSach() {
    if (this->_vecSach.empty()) { 
        chayWinner("\n [!] Kho sach hien dang trong! \n", COLOR_LOI);
        return; 
    }
    string headers[9] = {"Ma Sach", "Ten Sach", "Tac Gia", "Nha Xuat Ban", "Gia Ban", "Phat Hanh", "So Trang", "Ngay Nhap Kho", "Tinh Trang"};
    int colPercents[9] = {7, 18, 15, 15, 8, 8, 7, 12, 0}; // S? 0 ? cu?i d? hàm t? bù kho?ng tr?ng
    LinkedList<string> flatData;
    LinkedList<int> flatColors;
    for (int i = 0; i < this->_vecSach.getSize(); ++i) {
        Sach objSach = this->_vecSach[i];
        string strTinhTrang = (objSach.getTinhTrang() == 0) ? "San sang" : "Muon (Phieu " + toStr(objSach.getTinhTrang()) + ")";
        flatData.addTail(objSach.getMaSach());        flatColors.addTail(COLOR_TEXT);
        flatData.addTail(objSach.getTenSach());       flatColors.addTail(COLOR_TEXT);
        flatData.addTail(objSach.getTacGia());        flatColors.addTail(COLOR_TEXT);
        flatData.addTail(objSach.getNxb());           flatColors.addTail(COLOR_TEXT);
        flatData.addTail(toStr(objSach.getGiaBan())); flatColors.addTail(COLOR_TEXT);
        flatData.addTail(toStr(objSach.getNamPhatHanh())); flatColors.addTail(COLOR_TEXT);
        flatData.addTail(toStr(objSach.getSoTrang()));flatColors.addTail(COLOR_TEXT);
        flatData.addTail(objSach.getNgayNhapKho());   flatColors.addTail(COLOR_TEXT);
        flatData.addTail(strTinhTrang);
        if (objSach.getTinhTrang() == 0) flatColors.addTail(COLOR_CHON);
        else flatColors.addTail(COLOR_LOI);
    }
    veBangConsole(9, headers, colPercents, flatData, flatColors);
}
void QuanLyThuVien::themSach() {
    string strTemp = ""; 
    double dTemp = 0.0; 
    int iTemp = 0;
    setColor(COLOR_VIEN); 
    cout << "\n  " << char(175) << " Nhap Ma sach: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strTemp);
    for (int i = 0; i < this->_vecSach.getSize(); ++i) {
        if (this->_vecSach[i].getMaSach() == strTemp) {
            chayWinner("  [!] Ma sach da ton tai. Khong the them!\n", COLOR_LOI);
            return;
        }
    }
    Sach objSach;
    objSach.setMaSach(strTemp);
    setColor(COLOR_VIEN); 
    cout << "  " << char(175) << " Nhap Ten sach: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strTemp); 
    objSach.setTenSach(strTemp);
    setColor(COLOR_VIEN); 
    cout << "  " << char(175) << " Nhap Tac gia: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strTemp); 
    objSach.setTacGia(strTemp);
    setColor(COLOR_VIEN); 
    cout << "  " << char(175) << " Nhap NXB: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strTemp); 
    objSach.setNxb(strTemp);
    setColor(COLOR_VIEN); 
    cout << "  " << char(175) << " Nhap Gia ban: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strTemp);
    stringstream(strTemp) >> dTemp; 
    objSach.setGiaBan(dTemp);
    setColor(COLOR_VIEN); 
    cout << "  " << char(175) << " Nhap Nam phat hanh: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strTemp);
    stringstream(strTemp) >> iTemp;
    objSach.setNamPhatHanh(iTemp);
    setColor(COLOR_VIEN); 
    cout << "  " << char(175) << " Nhap So trang: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strTemp);
    iTemp = 0;
    stringstream(strTemp) >> iTemp;
    objSach.setSoTrang(iTemp);
    objSach.setNgayNhapKho(getNgayHienTai());
    objSach.setTinhTrang(0); 
    this->_vecSach.addTail(objSach);
    this->ghiFileSach(); 
    chayWinner("\n  => Them sach vao he thong thanh cong!\n", COLOR_CHON);
    setColor(COLOR_VIEN);
    cout << "  " << char(201) << string(52, char(205)) << char(187) << "\n";
    cout << "  " << char(186);
    setColor(COLOR_TIEU_DE);
    cout << canGiua("THONG TIN SACH VUA NHAP", 52);
    setColor(COLOR_VIEN);
    cout << char(186) << "\n";
    cout << "  " << char(204) << string(15, char(205)) << char(203) << string(36, char(205)) << char(185) << "\n";
    string props[7] = {"Ma sach", "Ten sach", "Tac gia", "Nha xuat ban", "Gia ban", "Nam Phat Hanh", "So trang"};
    string vals[7] = {objSach.getMaSach(), objSach.getTenSach(), objSach.getTacGia(), objSach.getNxb(), toStr(objSach.getGiaBan()), toStr(objSach.getNamPhatHanh()), toStr(objSach.getSoTrang())};
    for (int i = 0; i < 7; i++) {
        cout << "  " << char(186);
        setColor(COLOR_TEXT);
        cout << " " << left << setw(14) << props[i];
        setColor(COLOR_VIEN);
        cout << char(186);
        setColor(COLOR_CHON);
        cout << " " << left << setw(35) << (vals[i].length() > 35 ? vals[i].substr(0,35) : vals[i]);
        setColor(COLOR_VIEN);
        cout << char(186) << "\n";
    }
    cout << "  " << char(200) << string(15, char(205)) << char(202) << string(36, char(205)) << char(188) << "\n";
}
void QuanLyThuVien::xoaSach() {
    string strMaXoa = "";
    setColor(COLOR_VIEN); 
    cout << "\n  " << char(175) << " Nhap Ma sach can xoa: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strMaXoa);
    for (int i = 0; i < this->_vecSach.getSize(); ++i) {
        if (this->_vecSach[i].getMaSach() == strMaXoa) {
            if (this->_vecSach[i].getTinhTrang() != 0) {
            	setColor(COLOR_LOI);
                chayWinner("  [!] Khong the xoa! Sach nay dang duoc muon.\n", COLOR_LOI);
                return;
            }
            this->_vecSach.erase(i);
            this->ghiFileSach();
            chayWinner("  => Da xoa sach thanh cong!\n", COLOR_CHON);
            return;
        }
    }
    chayWinner("  [!] Khong tim thay Ma sach trong he thong!\n", COLOR_LOI);
}
void QuanLyThuVien::hienThiPhieuMuon() {
    if (this->_vecPhieu.empty()) {
        chayWinner("\n  [!] Chua co phieu muon nao trong he thong!\n", COLOR_LOI);
        return;
    }
    string headers[6] = {"So Phieu", "Ban Doc", "Ma Sach", "Ngay Muon", "Ngay Tra", "Tinh Trang"};
    int colPercents[6] = {10, 15, 25, 12, 16, 0};
    LinkedList<string> flatData;
    LinkedList<int> flatColors;
    for (int i = 0; i < this->_vecPhieu.getSize(); i++) {
        PhieuMuon objPhieu = this->_vecPhieu[i];
        string strTinhTrang = (objPhieu.getTinhTrang() == 1) ? "Dang muon" : "Da tra";
        string strMaBD = objPhieu.getMaBD();
        string strTenBD = "";
        for (int k = 0; k < this->_vecBD.getSize(); k++) {
            if (this->_vecBD[k].getMaBD() == strMaBD) {
                strTenBD = this->_vecBD[k].getHoTen();
                break;
            }
        }
        string strHienThiBD = strMaBD + (strTenBD != "" ? " - " + strTenBD : "");
        flatData.addTail(toStr(objPhieu.getSoPhieu())); flatColors.addTail(COLOR_TEXT);
        flatData.addTail(strHienThiBD);                 flatColors.addTail(COLOR_TEXT);
        flatData.addTail(objPhieu.getMaSach());         flatColors.addTail(COLOR_TEXT);
        flatData.addTail(objPhieu.getNgayMuon());       flatColors.addTail(COLOR_TEXT);
        flatData.addTail(objPhieu.getNgayTra());        flatColors.addTail(COLOR_TEXT);
        flatData.addTail(strTinhTrang);
        if (objPhieu.getTinhTrang() == 1) flatColors.addTail(COLOR_LOI);
        else flatColors.addTail(COLOR_CHON);
    }
    veBangConsole(6, headers, colPercents, flatData, flatColors);
}
void QuanLyThuVien::muonSach(){
    string strMaSach;
    string strMaBD;
    setColor(COLOR_VIEN);
    cout << "\n " << char(175) << " Nhap Ma sach: ";
    setColor(COLOR_TEXT);
    getline(cin, strMaSach);
	int iSach = -1;
    for (int i = 0; i < this->_vecSach.getSize(); i++) {
		if (this->_vecSach[i].getMaSach() == strMaSach) {
			iSach = i;
			break;
		}
    }
    if (iSach == -1) {
		chayWinner("[!] Khong tim thay Ma sach trong he thong!\n", COLOR_LOI);
		return;
    }
    if (this->_vecSach[iSach].getTinhTrang() != 0) {
		chayWinner("[!] Sach nay dang duoc muon!\n", COLOR_LOI);
		return;
    }
    setColor(COLOR_VIEN);
    cout << " " << char(175) << " Nhap Ma ban doc: ";
    setColor(COLOR_TEXT);
    getline(cin, strMaBD);
    int iBanDoc = -1;
    for (int i = 0; i < this->_vecBD.getSize(); i++){
		if (this->_vecBD[i].getMaBD() == strMaBD) {
			iBanDoc=i;
			break;
		}
    }
    if (iBanDoc == -1) {
        chayWinner("  [!] Khong tim thay Ma ban doc trong he thong!\n", COLOR_LOI);
        chayWinner("  => Dang tien hanh them Ban doc moi (Nhap '0' de huy)...\n", COLOR_TIEU_DE);
        string strTen;
        setColor(COLOR_VIEN); 
        cout << "  " << char(175) << " Nhap Ho ten ban doc moi: "; 
        setColor(COLOR_TEXT); 
        getline(cin, strTen); 
        if (strTen == "0") {
            chayWinner("  [!] Da huy chuc nang muon sach va them ban doc.\n", COLOR_LOI);
            return;
        }
        BanDoc objBd;
        objBd.setMaBD(strMaBD);
        objBd.setHoTen(strTen);
        objBd.setNgayDK(getNgayHienTai()); 
        this->_vecBD.addTail(objBd);
        this->ghiFileBanDoc(); 
        chayWinner("  => Da them ban doc vao he thong thanh cong!\n\n", COLOR_CHON);
    }
    int iSoPhieu = 1;
    if (!this->_vecPhieu.empty()) {
		iSoPhieu = this->_vecPhieu.getBack().getSoPhieu() + 1;
	}
    for (int i = 0; i < this->_vecPhieu.getSize(); i++) {
		if (this->_vecPhieu[i].getSoPhieu() == iSoPhieu) {
			iSoPhieu++;
			i=-1;
		}
    }
    PhieuMuon objPhieu;
    objPhieu.setSoPhieu(iSoPhieu);
    objPhieu.setMaBD(strMaBD);
    objPhieu.setMaSach(strMaSach);
    objPhieu.setNgayMuon(getNgayHienTai());
    objPhieu.setNgayTra(getNgayTra());
    objPhieu.setTinhTrang(1);
    this->_vecPhieu.addTail(objPhieu);
	this->_vecSach[iSach].setTinhTrang(iSoPhieu);
    this->ghiFileSach();
    this->ghiFilePhieuMuon();
    chayWinner("\n  => Muon sach thanh cong!\n",COLOR_CHON);
    setColor(COLOR_VIEN);
    cout << "  " << char(201) << string(52, char(205)) << char(187) << "\n";
    cout << "  " << char(186);
    setColor(COLOR_TIEU_DE);
    cout << canGiua("THONG TIN PHIEU MUON VUA TAO", 52);
    setColor(COLOR_VIEN);
    cout << char(186) << "\n";
    cout << "  " << char(204) << string(15, char(205)) << char(203) << string(36, char(205)) << char(185) << "\n";
    string strTenBanDoc = "";
    for (int k = 0; k < this->_vecBD.getSize(); k++) {
        if (this->_vecBD[k].getMaBD() == strMaBD) {
            strTenBanDoc = this->_vecBD[k].getHoTen();
            break;
        }
    }
    string propsPM[5] = {"So phieu", "Ban doc", "Ma sach", "Ngay muon", "Ngay tra"};
    string valsPM[5] = {toStr(objPhieu.getSoPhieu()), strMaBD + " - " + strTenBanDoc, objPhieu.getMaSach(), objPhieu.getNgayMuon(), objPhieu.getNgayTra()};
    for (int i = 0; i < 5; i++) {
        cout << "  " << char(186);
        setColor(COLOR_TEXT);
        cout << " " << left << setw(14) << propsPM[i];
        setColor(COLOR_VIEN);
        cout << char(186);
        setColor(COLOR_CHON);
        cout << " " << left << setw(35) << (valsPM[i].length() > 35 ? valsPM[i].substr(0,35) : valsPM[i]);
        setColor(COLOR_VIEN);
        cout << char(186) << "\n";
    }
    cout << "  " << char(200) << string(15, char(205)) << char(202) << string(36, char(205)) << char(188) << "\n";
}
void QuanLyThuVien::traSach(){
    string strSoPhieu;
    int iSoPhieu;
    setColor(COLOR_VIEN);
    cout << " " << char(175) << " Nhap So phieu: ";
    setColor(COLOR_TEXT);
    getline(cin, strSoPhieu);
    stringstream(strSoPhieu) >> iSoPhieu;
    if (iSoPhieu <= 0) {
		chayWinner("  [!] So phieu khong hop le!\n", COLOR_LOI);
		return;
    }
    int iPhieu = -1;
    for (int i = 0; i < this->_vecPhieu.getSize(); i++){
		if(this->_vecPhieu[i].getSoPhieu() == iSoPhieu) {
			iPhieu=i;
			break;
		}
    }
    if (iPhieu == -1) { 
		chayWinner("  [!] Khong tim thay phieu muon!\n", COLOR_LOI);
		return;
    }
    if (this->_vecPhieu[iPhieu].getTinhTrang() == 0) {
		chayWinner("  [!] Phieu nay da duoc tra truoc do!\n", COLOR_LOI);
		return;
    }
    string strMaSach = this->_vecPhieu[iPhieu].getMaSach();
    int iSach = -1;
    for (int i = 0; i < this->_vecSach.getSize(); i++) {
		if (this->_vecSach[i].getMaSach() == strMaSach) {
			iSach=i;
			break;
		}
    }
    if (iSach == -1) {
		chayWinner("  [!] Du lieu khong dong bo: ""Khong tim thay sach cua phieu!\n", COLOR_LOI);
		return;
    }
    if (this->_vecSach[iSach].getTinhTrang() != iSoPhieu) {
		chayWinner("  [!] Du lieu Sach va PhieuMuon khong dong bo!\n", COLOR_LOI);
		return;
    }
    this->_vecSach[iSach].setTinhTrang(0);
    this->_vecPhieu[iPhieu].setTinhTrang(0);
    this->_vecPhieu[iPhieu].setNgayTra(getNgayHienTai());
    this->ghiFileSach();
    this->ghiFilePhieuMuon();
    chayWinner("\n  => Tra sach thanh cong!\n", COLOR_CHON);
}
void QuanLyThuVien::ghiFileBanDoc() {
    ofstream fileBanDoc("BanDoc.txt");
    if (!fileBanDoc) return;
    for (int i = 0; i < _vecBD.getSize(); ++i) {
        fileBanDoc << _vecBD[i].getMaBD() << "|"
                   << _vecBD[i].getHoTen() << "|"
                   << _vecBD[i].getNgayDK() << endl;
    }
    fileBanDoc.close();
}
void QuanLyThuVien::themBanDoc() {
    string strMa, strTen;
    setColor(COLOR_VIEN); 
    cout << "\n  " << char(204) << char(205) << " Nhap Ma ban doc: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strMa);
    for (int i = 0; i < this->_vecBD.getSize(); ++i) {
        if (this->_vecBD[i].getMaBD() == strMa) {
            setColor(COLOR_LOI);
            cout << " [!] Ma ban doc da ton tai. Khong the them! \n";
            return;
        }
    }
    setColor(COLOR_VIEN); 
    cout << "  " << char(204) << char(205) << " Nhap Ho ten: "; 
    setColor(COLOR_TEXT); 
    getline(cin, strTen); 
    BanDoc objBd;
    objBd.setMaBD(strMa);
    objBd.setHoTen(strTen);
    objBd.setNgayDK(getNgayHienTai()); 
    this->_vecBD.addTail(objBd);
    this->ghiFileBanDoc(); 
    setColor(COLOR_CHON);
    cout << "\n  => Them ban doc vao he thong thanh cong!\n";
}
#endif
