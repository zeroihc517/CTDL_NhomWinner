#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include "LinkedList.h"

using namespace std;

const int COLOR_VIEN = 11;        
const int COLOR_TIEU_DE = 14;  
const int COLOR_TEXT = 15;  
const int COLOR_CHON = 10;    
const int COLOR_LOI = 12;
const int WIDTH_FRAME = 116;
/************
* @Description Thay doi mau sac cua text tren console
*
* @return       Void
* @attention    Chi ap dung cho he dieu hanh Windows (dung <windows.h>)
*********************/
void setColor(const int iColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iColor);
}
/************
* @Description Hien thi text voi hieu ung danh may (delay)
*
* @return       Void
* @attention    iDelay mac dinh la 5ms de tao hieu ung muot ma
*********************/
void chayWinner(const string& strText, const int iColor, const int iDelay = 5) {
    setColor(iColor);
    for (int i = 0; i < strText.length(); ++i) {
        cout << strText[i];
        Sleep(iDelay);
    }
}
/************
* @Description Nhap chuoi tu ban phim, ho tro bat phim ESC de thoat hoac xoa ky tu
*
* @return       Void
* @attention    Tham chieu strText se luu tru chuoi vua nhap
* @attention    Thoat ngang chuong trinh neu nhan ESC (ma ASCII 27)
*********************/
void nhapChuoi(string& str) {
    str = "";
    char c;
    while (true) {
        c = _getch();
        if (c == 27) {
            chayWinner("\n\n  [!] Ban vua nhan ESC. He thong dang thoat...\n", COLOR_LOI, 10);
            exit(0);
        }
        if (c == 13) {
            cout << endl;
            break;
        }
        if (c == 8) {
            if (str.length() > 0) {
                cout << "\b \b";
                str.erase(str.length() - 1);
            }
        } else if (c >= 32 && c <= 126) {
            str += c;
            cout << c;
        }
    }
}
/************
* @Description Chuyen doi gia tri tu kieu bat ky (T) sang kieu chuoi (string)
*
* @return       Chuoi string tuong ung voi gia tri dau vao
* @attention    Su dung ostringstream de ep kieu an toan
*********************/
template <typename T>
string toStr(const T tValue) {
    ostringstream os;
    os << tValue;
    return os.str();
}
/************
* @Description Lay ngay gio hien tai cua he thong theo format "HH:MM DD/MM/YYYY"
*
* @return       Chuoi string chua ngay gio hien tai
* @attention    Dung thu vien <ctime>
*********************/
string getNgayHienTai() {
    time_t tNow = time(0);
    tm* pLtm = localtime(&tNow);
    char szBuf[30];
    sprintf(szBuf, "%02d:%02d %02d/%02d/%04d", pLtm->tm_hour, pLtm->tm_min, pLtm->tm_mday, 1 + pLtm->tm_mon, 1900 + pLtm->tm_year);
    return string(szBuf);
}
/************
* @Description Lay ngay tra sach (Cong them 7 ngay tu ngay hien tai)
*
* @return       Chuoi string chua ngay tra (format "DD/MM/YYYY")
* @attention    Mac dinh quy dinh muon sach la 7 ngay
*********************/
string getNgayTra() {
    time_t tNow = time(0) + (7 * 24 * 60 * 60); 
    tm* pLtm = localtime(&tNow);
    char szBuf[20];
    sprintf(szBuf, "%02d/%02d/%04d", pLtm->tm_mday, 1 + pLtm->tm_mon, 1900 + pLtm->tm_year);
    return string(szBuf);
}
/************
* @Description Can giua mot chuoi text trong mot khoang chieu rong cho truoc
*
* @return       Chuoi text sau khi da duoc padding khoang trang 2 ben
* @attention    Neu chieu rong nho hon do dai chuoi, chuoi se bi cat but
*********************/
string canGiua(const string& strText, int iWidth) {
    if ((int)strText.length() >= iWidth) return strText.substr(0, iWidth);
    int iPadLeft = (iWidth - (int)strText.length()) / 2;
    int iPadRight = iWidth - (int)strText.length() - iPadLeft;
    return string(iPadLeft, ' ') + strText + string(iPadRight, ' ');
}
/************
* @Description Tu dong ngat dong (word wrap) cho mot doan text dai
*
* @return       Void (ket qua luu vao listResult)
* @attention    Dam bao khong ngat nua chung giua 1 tu neu khong can thiet
*********************/
void wrapText(string strText, int iWidth, LinkedList<string>& listResult) {
    listResult.clear();
    if (iWidth <= 0) iWidth = 1;
    while (strText.length() > (size_t)iWidth) {
        size_t iPos = strText.rfind(' ', iWidth);
        if (iPos == string::npos || iPos == 0) {
            iPos = iWidth;
        }
        listResult.addTail(strText.substr(0, iPos));
        if (iPos < strText.length() && strText[iPos] == ' ') {
            strText = strText.substr(iPos + 1);
        } else {
            strText = strText.substr(iPos);
        }
    }
    if (strText.length() > 0 || listResult.getSize() == 0) {
        listResult.addTail(strText);
    }
}
/************
* @Description Tach mot chuoi thanh nhieu chuoi con dua tren ky tu phan cach
*
* @return       Danh sach lien ket (LinkedList) chua cac chuoi con
* @attention    Su dung stringstream de tach chuoi
*********************/
LinkedList<string> split(const string& strInput, const char cDelim) {
    LinkedList<string> listTokens;
    stringstream ss(strInput);
    string strToken = "";
    while (getline(ss, strToken, cDelim)) {
        listTokens.addTail(strToken);
    }
    return listTokens;
}
/************
* @Description Kiem tra dang nhap tai khoan quan tri admin
*
* @return       True neu dang nhap thanh cong, False neu that bai
* @attention    Tai khoan doc tu file Admin.txt, nhap sai qua 3 lan se thoat
*********************/
bool dangNhap() {
    ifstream fAdmin("Admin.txt");
    string strDbUser = "";
    string strDbPass = "";
    fAdmin >> strDbUser >> strDbPass;
    fAdmin.close();
    int iThu = 0;
    while (iThu < 3) {
        system("cls");
        setColor(COLOR_TIEU_DE);
        cout << "\n\t***********************************";
        cout << "\n\t*       DANG NHAP HE THONG        *";
        cout << "\n\t***********************************\n\n";
        string strUser = "";
        string strPass = "";
        setColor(COLOR_CHON);
        cout << "\tUser:     ";
        setColor(COLOR_TEXT);
        nhapChuoi(strUser);
        setColor(COLOR_CHON);
        cout << "\n\tPassword: ";
        setColor(COLOR_TEXT);
        char cCh = '\0';
        while (true) {
            cCh = _getch();
            if (cCh == 27) {
                chayWinner("\n\n\tDa an ESC. Thoat he thong!\n", COLOR_LOI);
                exit(0);
            }
            if (cCh == 13) {
                break;
            }
            if (cCh == 8) {
                if (strPass.length() > 0) {
                    cout << "\b \b";
                    strPass.erase(strPass.length() - 1);
                }
            } else {
                strPass += cCh;
                cout << "*";
            }
        }
        if (strUser == strDbUser && strPass == strDbPass) {
            chayWinner("\n\n\tDang nhap thanh cong!\n", COLOR_CHON, 15);
            Sleep(500);
            return true;
        } else {
            iThu++;
            chayWinner("\n\n\tSai User hoac Password! (Con " + toStr(3 - iThu) + " lan thu)\n", COLOR_LOI);
            system("pause");
        }
    }
    return false;
}
/************
* @Description Ve menu lua chon chuc nang ra man hinh console
*
* @return       Void
* @attention    Tu dong tinh toan can giua de ve khung vien menu
*********************/
void veMenu(const string& strTitle, LinkedList<string>& vecOptions) {
    system("cls");
    setColor(COLOR_VIEN);
    cout << "\n  " << char(201) << string(44, char(205)) << char(187) << "\n";
    cout << "  " << char(186);
    setColor(COLOR_TIEU_DE);
    int iPadL = (44 - strTitle.length()) / 2;
    int iPadR = 44 - strTitle.length() - iPadL;
    cout << string(iPadL, ' ') << strTitle << string(iPadR, ' ');
    setColor(COLOR_VIEN);
    cout << char(186) << "\n";
    cout << "  " << char(204) << string(44, char(205)) << char(185) << "\n";
    for (int i = 0; i < vecOptions.getSize(); ++i) {
        setColor(COLOR_VIEN);
        cout << "  " << char(186) << " ";
        if (i == vecOptions.getSize() - 1) {
            setColor(COLOR_LOI);
        } else {
            setColor(COLOR_TIEU_DE);
        }
        cout << i + 1 << ". ";
        setColor(COLOR_TEXT);
        cout << left << setw(40) << vecOptions[i];
        setColor(COLOR_VIEN);
        cout << char(186) << "\n";
    }
    cout << "  " << char(200) << string(44, char(205)) << char(188) << "\n\n";
    chayWinner("  >> Nhap lua chon: ", COLOR_TIEU_DE, 0);
    setColor(COLOR_TEXT);
}
/************
* @Description Ve bang console linh hoat ho tro word-wrap tu dong
*
* @return       Void
* @attention    Kich thuoc bang tu thich ung voi do rong cua man hinh console hien tai
*********************/
void veBangConsole(int iNumCols, string arrHeaders[], int arrColPercents[], LinkedList<string>& listFlatData, LinkedList<int>& listFlatColors) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int iConsoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int iWidth = iConsoleWidth - 14; 
    if (iWidth < 80) iWidth = 80; 
    int* pArrCol = new int[iNumCols];
    int iSumUsed = 0;
    for (int i = 0; i < iNumCols - 1; i++) {
        pArrCol[i] = iWidth * arrColPercents[i] / 100;
        if (pArrCol[i] < 4) pArrCol[i] = 4;
        iSumUsed += pArrCol[i];
    }
    pArrCol[iNumCols - 1] = iWidth - iSumUsed;
    if (pArrCol[iNumCols - 1] < 4) pArrCol[iNumCols - 1] = 4;
    setColor(COLOR_VIEN); 
    cout << "\n  " << char(201);
    for (int i = 0; i < iNumCols; i++) {
        cout << string(pArrCol[i], char(205));
        if (i < iNumCols - 1) cout << char(203);
    }
    cout << char(187) << "\n";
    LinkedList<string>* pArrHeaderData = new LinkedList<string>[iNumCols];
    int iMaxHeaderLines = 1;
    for (int i = 0; i < iNumCols; i++) {
        wrapText(arrHeaders[i], pArrCol[i] - 2, pArrHeaderData[i]); 
        if (pArrHeaderData[i].getSize() > iMaxHeaderLines) iMaxHeaderLines = pArrHeaderData[i].getSize();
    }
    for (int iLine = 0; iLine < iMaxHeaderLines; ++iLine) {
        setColor(COLOR_VIEN);
        cout << "  " << char(186); 
        for (int j = 0; j < iNumCols; ++j) {
            int iNumLines = pArrHeaderData[j].getSize();
            int iStartLine = (iMaxHeaderLines - iNumLines) / 2; 
            setColor(COLOR_TIEU_DE);
            if (iLine >= iStartLine && iLine < iStartLine + iNumLines) {
                string strText = pArrHeaderData[j][iLine - iStartLine];
                size_t iFirst = strText.find_first_not_of(' ');
                if (iFirst != string::npos) strText = strText.substr(iFirst, strText.find_last_not_of(' ') - iFirst + 1);
                else strText = "";
                cout << canGiua(strText, pArrCol[j]); 
            } else {
                cout << string(pArrCol[j], ' '); 
            }
            setColor(COLOR_VIEN);
            cout << char(186); 
        }
        cout << "\n";
    }
    cout << "  " << char(204);
    for (int i = 0; i < iNumCols; i++) {
        cout << string(pArrCol[i], char(205));
        if (i < iNumCols - 1) cout << char(206);
    }
    cout << char(185) << "\n";
    int iNumRows = listFlatData.getSize() / iNumCols;
    for (int i = 0; i < iNumRows; ++i) {
        LinkedList<string>* pArrData = new LinkedList<string>[iNumCols];
        int iMaxLines = 1;
        for (int j = 0; j < iNumCols; ++j) {
            wrapText(listFlatData[i * iNumCols + j], pArrCol[j] - 2, pArrData[j]);
            if (pArrData[j].getSize() > iMaxLines) iMaxLines = pArrData[j].getSize();
        }
        for (int iLine = 0; iLine < iMaxLines; ++iLine) {
            setColor(COLOR_VIEN); 
            cout << "  " << char(186);
            for (int j = 0; j < iNumCols; ++j) {
                int iNumLines = pArrData[j].getSize();
                setColor(listFlatColors[i * iNumCols + j]); 
                if (iLine < iNumLines) {
                    string strText = pArrData[j][iLine];
                    size_t iFirst = strText.find_first_not_of(' ');
                    if (iFirst != string::npos) strText = strText.substr(iFirst, strText.find_last_not_of(' ') - iFirst + 1);
                    else strText = "";
                    strText = " " + strText;
                    if (strText.length() > (size_t)pArrCol[j]) strText = strText.substr(0, pArrCol[j]);
                    cout << left << setw(pArrCol[j]) << strText;
                } else {
                    cout << string(pArrCol[j], ' '); 
                }
                setColor(COLOR_VIEN); 
                cout << char(186);
            }
            cout << "\n";
        }
        if (i < iNumRows - 1) {
            cout << "  " << char(204);
            for (int k = 0; k < iNumCols; k++) {
                cout << string(pArrCol[k], char(205));
                if (k < iNumCols - 1) cout << char(206);
            }
            cout << char(185) << "\n";
        }
        delete[] pArrData;
    }
    setColor(COLOR_VIEN);
    cout << "  " << char(200);
    for (int i = 0; i < iNumCols; i++) {
        cout << string(pArrCol[i], char(205));
        if (i < iNumCols - 1) cout << char(202);
    }
    cout << char(188) << "\n";
    delete[] pArrHeaderData;
    delete[] pArrCol;
}

#endif
