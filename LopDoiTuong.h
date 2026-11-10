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
    BanDoc() {
        _strMaBD = "";
        _strHoTen = "";
        _strNgayDK = "";
    }
    BanDoc(string& strMa, string& strTen, string& strNgay) {
        _strMaBD = strMa;
        _strHoTen = strTen;
        _strNgayDK = strNgay;
    }
    BanDoc(const BanDoc& p) {
        _strMaBD = p._strMaBD;
        _strHoTen = p._strHoTen;
        _strNgayDK = p._strNgayDK;
    }
    ~BanDoc(){};
    string getMaBD() const { return _strMaBD; }
    string getHoTen() const { return _strHoTen; }
    string getNgayDK() const { return _strNgayDK; }
    void setMaBD(const string& strMa) { _strMaBD = strMa; }
    void setHoTen(const string& strTen) { _strHoTen = strTen; }
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
    PhieuMuon() {
        _iSoPhieu = 0;
        _iTinhTrang = 0;
    }
    PhieuMuon(int iSo, string& strMBD, string& strMSach, string& strNMuon, string& strNTra, int iTt) {
        _iSoPhieu = iSo;
        _strMaBD = strMBD;
        _strMaSach = strMSach;
        _strNgayMuon = strNMuon;
        _strNgayTra = strNTra;
        _iTinhTrang = iTt;
    }
    PhieuMuon(const PhieuMuon& p) {
        _iSoPhieu = p._iSoPhieu;
        _strMaBD = p._strMaBD;
        _strMaSach = p._strMaSach;
        _strNgayMuon = p._strNgayMuon;
        _strNgayTra = p._strNgayTra;
        _iTinhTrang = p._iTinhTrang;
    }
    ~PhieuMuon(){};
    int getSoPhieu() const { return _iSoPhieu; }
    string getMaBD() const { return _strMaBD; }
    string getMaSach() const { return _strMaSach; }
    string getNgayMuon() const { return _strNgayMuon; }
    string getNgayTra() const { return _strNgayTra; }
    int getTinhTrang() const { return _iTinhTrang; }
    void setSoPhieu(const int iSo) { _iSoPhieu = iSo; }
    void setMaBD(const string& strMa) { _strMaBD = strMa; }
    void setMaSach(const string& strMa) { _strMaSach = strMa; }
    void setNgayMuon(const string& strNgay) { _strNgayMuon = strNgay; }
    void setNgayTra(const string& strNgay) { _strNgayTra = strNgay; }
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
    Sach() {
        _dGiaBan = 0.0;
        _iNamPhatHanh = 0;
        _iSoTrang = 0;
        _iTinhTrang = 0;
    }
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
    ~Sach(){};
    string getMaSach() const { return _strMaSach; }
    string getTenSach() const { return _strTenSach; }
    string getTacGia() const { return _strTacGia; }
    string getNxb() const { return _strNxb; }
    double getGiaBan() const { return _dGiaBan; }
    int getNamPhatHanh() const { return _iNamPhatHanh; }
    int getSoTrang() const { return _iSoTrang; }
    string getNgayNhapKho() const { return _strNgayNhapKho; }
    int getTinhTrang() const { return _iTinhTrang; }
    void setMaSach(const string& strMa) { _strMaSach = strMa; }
    void setTenSach(const string& strTen) { _strTenSach = strTen; }
    void setTacGia(const string& strTg) { _strTacGia = strTg; }
    void setNxb(const string& strNxb) { _strNxb = strNxb; }
    void setGiaBan(const double dGia) { _dGiaBan = dGia; }
    void setNamPhatHanh(const int iNam) { _iNamPhatHanh = iNam; }
    void setSoTrang(const int iTrang) { _iSoTrang = iTrang; }
    void setNgayNhapKho(const string& strNgay) { _strNgayNhapKho = strNgay; }
    void setTinhTrang(const int iTt) { _iTinhTrang = iTt; }
};

#endif
