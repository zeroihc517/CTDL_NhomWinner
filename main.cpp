#include <iostream>
#include <string>
#include <conio.h>
#include "QuanLyThuVien.h"
#include "Utils.h"

using namespace std;
int main() {
    SetConsoleOutputCP(437);
    QuanLyThuVien objQl;
    if (!dangNhap()) { return 0;  }
    int iChonChinh = 0;
    string strInput;
    do {
        LinkedList<string> vecMenuChinh;
        vecMenuChinh.addTail("Quan ly sach");
        vecMenuChinh.addTail("Quan ly phieu muon");
        vecMenuChinh.addTail("Thoat chuong trinh");
        veMenu("HE THONG QUAN LY THU VIEN", vecMenuChinh);
        getline(cin, strInput);
        iChonChinh = -1;
        stringstream(strInput) >> iChonChinh;
        if (iChonChinh == 1) { 
            int iChonPhu = 0;
            do {
                LinkedList<string> vecMenuSach;
                vecMenuSach.addTail("Hien thi thong tin sach");
                vecMenuSach.addTail("Them sach moi");
                vecMenuSach.addTail("Xoa sach");
                vecMenuSach.addTail("Quay lai menu chinh");
                veMenu("QUAN LY SACH", vecMenuSach);
                getline(cin, strInput);
                iChonPhu = -1;
                stringstream(strInput) >> iChonPhu;
                switch (iChonPhu) {
                    case 1: objQl.hienThiSach(); break;
                    case 2: objQl.themSach(); break;
                    case 3: objQl.xoaSach(); break;
                    case 4: break;
                    default: 
                        chayWinner("  [!] Lua chon sai hoac khong ton tai!\n", COLOR_LOI);
                        break;
                }
                if (iChonPhu != 4) { cout << "\n  "; system("pause"); }
            } while (iChonPhu != 4);
        } else if (iChonChinh == 2) { 
            int iChonPhu = 0;
            do {
                LinkedList<string> vecMenuPhieu;
                vecMenuPhieu.addTail("Hien thi thong tin phieu muon");
                vecMenuPhieu.addTail("Muon sach (Tao phieu)");
                vecMenuPhieu.addTail("Tra sach");
                vecMenuPhieu.addTail("Quay lai menu chinh");
                veMenu("QUAN LY PHIEU MUON", vecMenuPhieu);
                getline(cin, strInput);
                iChonPhu = -1;
                stringstream(strInput) >> iChonPhu;
                switch (iChonPhu) {
                    case 1: objQl.hienThiPhieuMuon(); break;
                    case 2: objQl.muonSach(); break;
                    case 3: objQl.traSach(); break;
                    case 4: break;
                    default: 
                        chayWinner("  [!] Lua chon sai hoac khong ton tai!\n", COLOR_LOI);
                        break;
                }
                if (iChonPhu != 4) { cout << "\n  "; system("pause"); }
            } while (iChonPhu != 4);
        } else if (iChonChinh == 3) {
            break;
        } else {
            chayWinner("  [!] Lua chon sai hoac khong ton tai!\n", COLOR_LOI);
            cout << "\n  "; system("pause"); 
        }
    } while (iChonChinh != 3);
    chayWinner("\n  DANG THOAT HE THONG...\n  TAM BIET!\n", COLOR_CHON, 20);
    return 0;
}