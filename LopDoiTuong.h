#ifndef LopDoiTuong_H
#define LopDoiTuong_H

#include <string>
using namespace std;
class BanDoc {
private:
    string _strMaBD;
    string _strHoTen;
    string _strNgayDK;
public:
	/************
    * @Description Constructor mac dinh cua class BanDoc
    *
    * @return       Khong co
    * @attention    Khoi tao cac thuoc tinh chuoi rong
    *********************/
    BanDoc() {
        _strMaBD = "";
        _strHoTen = "";
        _strNgayDK = "";
    }
    /************
    * @Description Constructor co tham so cua class BanDoc
    *
    * @return       Khong co
    * @attention    Gan gia tri truyen vao cho ma ban doc, ho ten va ngay dang ky
    *********************/
    BanDoc(string& strMa, string& strTen, string& strNgay) {
        _strMaBD = strMa;
        _strHoTen = strTen;
        _strNgayDK = strNgay;
    }
    /************
    * @Description Copy constructor cua class BanDoc
    *
    * @return       Khong co
    * @attention    Sao chep du lieu tu doi tuong BanDoc khac
    *********************/
    BanDoc(const BanDoc& p) {
        _strMaBD = p._strMaBD;
        _strHoTen = p._strHoTen;
        _strNgayDK = p._strNgayDK;
    }
    /************
    * @Description Destructor cua class BanDoc
    *
    * @return       Khong co
    * @attention    Huy doi tuong an toan
    *********************/
    ~BanDoc(){};
    /************
    * @Description Lay ma ban doc
    *
    * @return       Chuoi string chua ma ban doc
    * @attention    Ham hang (const) khong lam thay doi trang thai object
    *********************/
    string getMaBD() const { return _strMaBD; }
    /************
    * @Description Lay ho ten ban doc
    *
    * @return       Chuoi string chua ho ten ban doc
    * @attention    Ham hang (const)
    *********************/
    string getHoTen() const { return _strHoTen; }
    /************
    * @Description Lay ngay dang ky tham gia cua ban doc
    *
    * @return       Chuoi string chua ngay dang ky
    * @attention    Ham hang (const)
    *********************/
    string getNgayDK() const { return _strNgayDK; }
    /************
    * @Description Thiet lap ma ban doc moi
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string& de toi uu hieu nang
    *********************/
    void setMaBD(const string& strMa) { _strMaBD = strMa; }
    /************
    * @Description Thiet lap ho ten ban doc moi
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setHoTen(const string& strTen) { _strHoTen = strTen; }
    /************
    * @Description Thiet lap ngay dang ky cho ban doc
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setNgayDK(const string& strNgay) { _strNgayDK = strNgay; }
};

class PhieuMuon {
private:
    int _iSoPhieu;
    string _strMaBD;
    string _strMaSach;
    string _strNgayMuon;
    string _strNgayTra;
    int _iTinhTrang;
public:
	/************
    * @Description Constructor mac dinh cua class PhieuMuon
    *
    * @return       Khong co
    * @attention    Khoi tao so phieu va tinh trang bang 0
    *********************/
    PhieuMuon() {
        _iSoPhieu = 0;
        _iTinhTrang = 0;
    }
    /************
    * @Description Constructor co tham so cua class PhieuMuon
    *
    * @return       Khong co
    * @attention    Khoi tao toan bo thong tin chi tiet cho phieu muon
    *********************/
    PhieuMuon(int iSo, string& strMBD, string& strMSach, string& strNMuon, string& strNTra, int iTt) {
        _iSoPhieu = iSo;
        _strMaBD = strMBD;
        _strMaSach = strMSach;
        _strNgayMuon = strNMuon;
        _strNgayTra = strNTra;
        _iTinhTrang = iTt;
    }
    /************
    * @Description Copy constructor cua class PhieuMuon
    *
    * @return       Khong co
    * @attention    Sao chep du lieu tu phieu muon khac
    *********************/
    PhieuMuon(const PhieuMuon& p) {
        _iSoPhieu = p._iSoPhieu;
        _strMaBD = p._strMaBD;
        _strMaSach = p._strMaSach;
        _strNgayMuon = p._strNgayMuon;
        _strNgayTra = p._strNgayTra;
        _iTinhTrang = p._iTinhTrang;
    }
    /************
    * @Description Destructor cua class PhieuMuon
    *
    * @return       Khong co
    * @attention    Huy doi tuong
    *********************/
    ~PhieuMuon(){};
    /************
    * @Description Lay so thu tu phieu muon
    *
    * @return       So nguyen (int) the hien so phieu
    * @attention    Ham hang (const)
    *********************/
    int getSoPhieu() const { return _iSoPhieu; }
    /************
    * @Description Lay ma ban doc cua phieu muon
    *
    * @return       Chuoi string chua ma ban doc
    * @attention    Ham hang (const)
    *********************/
    string getMaBD() const { return _strMaBD; }
    /************
    * @Description Lay ma sach duoc muon trong phieu
    *
    * @return       Chuoi string chua ma sach
    * @attention    Ham hang (const)
    *********************/
    string getMaSach() const { return _strMaSach; }
    /************
    * @Description Lay ngay muon sach
    *
    * @return       Chuoi string chua ngay muon
    * @attention    Ham hang (const)
    *********************/
    string getNgayMuon() const { return _strNgayMuon; }
    /************
    * @Description Lay ngay phai tra sach
    *
    * @return       Chuoi string chua ngay tra
    * @attention    Ham hang (const)
    *********************/
    string getNgayTra() const { return _strNgayTra; }
    /************
    * @Description Lay tinh trang phieu muon (1: Dang muon, 0: Da tra)
    *
    * @return       So nguyen (int) the hien tinh trang
    * @attention    Ham hang (const)
    *********************/
    int getTinhTrang() const { return _iTinhTrang; }
    /************
    * @Description Thiet lap so phieu muon
    *
    * @return       Void
    * @attention    Tham so truyen vao la const int
    *********************/
    void setSoPhieu(const int iSo) { _iSoPhieu = iSo; }
    /************
    * @Description Thiet lap ma ban doc cho phieu
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setMaBD(const string& strMa) { _strMaBD = strMa; }
    /************
    * @Description Thiet lap ma sach cho phieu
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setMaSach(const string& strMa) { _strMaSach = strMa; }
    /************
    * @Description Thiet lap ngay muon sach
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setNgayMuon(const string& strNgay) { _strNgayMuon = strNgay; }
    /************
    * @Description Thiet lap ngay tra sach
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setNgayTra(const string& strNgay) { _strNgayTra = strNgay; }
    /************
    * @Description Thiet lap tinh trang phieu muon
    *
    * @return       Void
    * @attention    Tham so truyen vao la const int
    *********************/
    void setTinhTrang(const int iTt) { _iTinhTrang = iTt; }
};

class Sach {
private:
    string _strMaSach;
    string _strTenSach;
    string _strTacGia;
    string _strNxb;
    double _dGiaBan;
    int _iNamPhatHanh;
    int _iSoTrang;
    string _strNgayNhapKho;
    int _iTinhTrang;
public:
	/************
    * @Description Constructor mac dinh cua class Sach
    *
    * @return       Khong co
    * @attention    Khoi tao gia ban, nam phat hanh, so trang va tinh trang ve 0
    *********************/
    Sach() {
        _dGiaBan = 0.0;
        _iNamPhatHanh = 0;
        _iSoTrang = 0;
        _iTinhTrang = 0;
    }
    /************
    * @Description Constructor co tham so cua class Sach
    *
    * @return       Khong co
    * @attention    Khoi tao day du thong tin cho sach moi
    *********************/
    Sach(string& strMa, string& strTen, string& strTg, string& strNxb, double dGia, int iNam, int iTrang, string& strNgay, int iTt) {
        _strMaSach = strMa;
        _strTenSach = strTen;
        _strTacGia = strTg;
        _strNxb = strNxb;
        _dGiaBan = dGia;
        _iNamPhatHanh = iNam;
        _iSoTrang = iTrang;
        _strNgayNhapKho = strNgay;
        _iTinhTrang = iTt;
    }
    /************
    * @Description Copy constructor cua class Sach
    *
    * @return       Khong co
    * @attention    Sao chep du lieu tu doi tuong Sach khac
    *********************/
    Sach(const Sach& p) {
        _strMaSach = p._strMaSach;
        _strTenSach = p._strTenSach;
        _strTacGia = p._strTacGia;
        _strNxb = p._strNxb;
        _dGiaBan = p._dGiaBan;
        _iNamPhatHanh = p._iNamPhatHanh;
        _iSoTrang = p._iSoTrang;
        _strNgayNhapKho = p._strNgayNhapKho;
        _iTinhTrang = p._iTinhTrang;
    }
    /************
    * @Description Destructor cua class Sach
    *
    * @return       Khong co
    * @attention    Huy doi tuong an toan
    *********************/
    ~Sach(){};
    /************
    * @Description Lay ma sach
    *
    * @return       Chuoi string chua ma sach
    * @attention    Ham hang (const)
    *********************/
    string getMaSach() const { return _strMaSach; }
    /************
    * @Description Lay ten sach
    *
    * @return       Chuoi string chua ten sach
    * @attention    Ham hang (const)
    *********************/
    string getTenSach() const { return _strTenSach; }
    /************
    * @Description Lay tac gia cua sach
    *
    * @return       Chuoi string chua ten tac gia
    * @attention    Ham hang (const)
    *********************/
    string getTacGia() const { return _strTacGia; }
    /************
    * @Description Lay nha xuat ban cua sach
    *
    * @return       Chuoi string chua ten NXB
    * @attention    Ham hang (const)
    *********************/
    string getNxb() const { return _strNxb; }
    /************
    * @Description Lay gia ban cua sach
    *
    * @return       So thuc (double) the hien gia ban
    * @attention    Ham hang (const)
    *********************/
    double getGiaBan() const { return _dGiaBan; }
    /************
    * @Description Lay nam phat hanh sach
    *
    * @return       So nguyen (int) the hien nam phat hanh
    * @attention    Ham hang (const)
    *********************/
    int getNamPhatHanh() const { return _iNamPhatHanh; }
    /************
    * @Description Lay so trang cua sach
    *
    * @return       So nguyen (int) the hien so trang
    * @attention    Ham hang (const)
    *********************/
    int getSoTrang() const { return _iSoTrang; }
    /************
    * @Description Lay ngay nhap kho cua sach
    *
    * @return       Chuoi string chua ngay nhap kho
    * @attention    Ham hang (const)
    *********************/
    string getNgayNhapKho() const { return _strNgayNhapKho; }
    /************
    * @Description Lay tinh trang sach (0: San sang, >0: Ma phieu dang muon)
    *
    * @return       So nguyen (int) the hien tinh trang
    * @attention    Ham hang (const)
    *********************/
    int getTinhTrang() const { return _iTinhTrang; }
    /************
    * @Description Thiet lap ma sach
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setMaSach(const string& strMa) { _strMaSach = strMa; }
    /************
    * @Description Thiet lap ten sach
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setTenSach(const string& strTen) { _strTenSach = strTen; }
    /************
    * @Description Thiet lap tac gia cua sach
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setTacGia(const string& strTg) { _strTacGia = strTg; }
    /************
    * @Description Thiet lap nha xuat ban
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setNxb(const string& strNxb) { _strNxb = strNxb; }
    /************
    * @Description Thiet lap gia ban cho sach
    *
    * @return       Void
    * @attention    Tham so truyen vao la const double
    *********************/
    void setGiaBan(const double dGia) { _dGiaBan = dGia; }
    /************
    * @Description Thiet lap nam phat hanh
    *
    * @return       Void
    * @attention    Tham so truyen vao la const int
    *********************/
    void setNamPhatHanh(const int iNam) { _iNamPhatHanh = iNam; }
    /************
    * @Description Thiet lap so trang cho sach
    *
    * @return       Void
    * @attention    Tham so truyen vao la const int
    *********************/
    void setSoTrang(const int iTrang) { _iSoTrang = iTrang; }
    /************
    * @Description Thiet lap ngay nhap kho
    *
    * @return       Void
    * @attention    Tham so truyen vao la const string&
    *********************/
    void setNgayNhapKho(const string& strNgay) { _strNgayNhapKho = strNgay; }
    /************
    * @Description Thiet lap tinh trang cho sach
    *
    * @return       Void
    * @attention    Tham so truyen vao la const int
    *********************/
    void setTinhTrang(const int iTt) { _iTinhTrang = iTt; }
};

#endif
