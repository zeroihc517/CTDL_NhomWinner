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
void setColor(const int iColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iColor);
}
void chayWinner(const string& strText, const int iColor, const int iDelay = 5) {
    setColor(iColor);
    for (size_t i = 0; i < strText.length(); ++i) {
        cout << strText[i];
        Sleep(iDelay);
    }
}
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
template <typename T>
string toStr(const T tValue) {
    ostringstream os;
    os << tValue;
    return os.str();
}
string getNgayHienTai() {
    time_t tNow = time(0);
    tm* pLtm = localtime(&tNow);
    char szBuf[30];
    sprintf(szBuf, "%02d:%02d %02d/%02d/%04d", pLtm->tm_hour, pLtm->tm_min, pLtm->tm_mday, 1 + pLtm->tm_mon, 1900 + pLtm->tm_year);
    return string(szBuf);
}
string getNgayTra() {
    time_t tNow = time(0) + (7 * 24 * 60 * 60); 
    tm* pLtm = localtime(&tNow);
    char szBuf[20];
    sprintf(szBuf, "%02d/%02d/%04d", pLtm->tm_mday, 1 + pLtm->tm_mon, 1900 + pLtm->tm_year);
    return string(szBuf);
}
string canGiua(const string& str, int width) {
    if ((int)str.length() >= width) return str.substr(0, width);
    int padLeft = (width - (int)str.length()) / 2;
    int padRight = width - (int)str.length() - padLeft;
    return string(padLeft, ' ') + str + string(padRight, ' ');
}
void wrapText(string text, int width, LinkedList<string>& result) {
    result.clear();
    if (width <= 0) width = 1;
    while (text.length() > (size_t)width) {
        size_t pos = text.rfind(' ', width);
        if (pos == string::npos || pos == 0) {
            pos = width;
        }
        result.addTail(text.substr(0, pos));
        if (pos < text.length() && text[pos] == ' ') {
            text = text.substr(pos + 1);
        } else {
            text = text.substr(pos);
        }
    }
    if (text.length() > 0 || result.getSize() == 0) {
        result.addTail(text);
    }
}
LinkedList<string> split(const string& strInput, const char cDelim) {
    LinkedList<string> listTokens;
    stringstream ss(strInput);
    string strToken = "";
    while (getline(ss, strToken, cDelim)) {
        listTokens.addTail(strToken);
    }
    return listTokens;
}
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
void veBangConsole(int numCols, string headers[], int colPercents[], LinkedList<string>& flatData, LinkedList<int>& flatColors) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int W = consoleWidth - 14; 
    if (W < 80) W = 80; 
    int* col = new int[numCols];
    int sumUsed = 0;
    for (int i = 0; i < numCols - 1; i++) {
        col[i] = W * colPercents[i] / 100;
        if (col[i] < 4) col[i] = 4;
        sumUsed += col[i];
    }
    col[numCols - 1] = W - sumUsed;
    if (col[numCols - 1] < 4) col[numCols - 1] = 4;
    setColor(COLOR_VIEN); 
    cout << "\n  " << char(201);
    for (int i = 0; i < numCols; i++) {
        cout << string(col[i], char(205));
        if (i < numCols - 1) cout << char(203);
    }
    cout << char(187) << "\n";
    LinkedList<string>* headerData = new LinkedList<string>[numCols];
    int maxHeaderLines = 1;
    for (int i = 0; i < numCols; i++) {
        wrapText(headers[i], col[i] - 2, headerData[i]); 
        if (headerData[i].getSize() > maxHeaderLines) maxHeaderLines = headerData[i].getSize();
    }
    for (int line = 0; line < maxHeaderLines; ++line) {
        setColor(COLOR_VIEN);
        cout << "  " << char(186); 
        for (int j = 0; j < numCols; ++j) {
            int numLines = headerData[j].getSize();
            int startLine = (maxHeaderLines - numLines) / 2; 
            setColor(COLOR_TIEU_DE);
            if (line >= startLine && line < startLine + numLines) {
                string text = headerData[j][line - startLine];
                size_t first = text.find_first_not_of(' ');
                if (first != string::npos) text = text.substr(first, text.find_last_not_of(' ') - first + 1);
                else text = "";
                cout << canGiua(text, col[j]); 
            } else {
                cout << string(col[j], ' '); 
            }
            setColor(COLOR_VIEN);
            cout << char(186); 
        }
        cout << "\n";
    }
    cout << "  " << char(204);
    for (int i = 0; i < numCols; i++) {
        cout << string(col[i], char(205));
        if (i < numCols - 1) cout << char(206);
    }
    cout << char(185) << "\n";
    int numRows = flatData.getSize() / numCols;
    for (int i = 0; i < numRows; ++i) {
        LinkedList<string>* data = new LinkedList<string>[numCols];
        int maxLines = 1;
        for (int j = 0; j < numCols; ++j) {
            wrapText(flatData[i * numCols + j], col[j] - 2, data[j]);
            if (data[j].getSize() > maxLines) maxLines = data[j].getSize();
        }
        for (int line = 0; line < maxLines; ++line) {
            setColor(COLOR_VIEN); 
            cout << "  " << char(186);
            for (int j = 0; j < numCols; ++j) {
                int numLines = data[j].getSize();
                setColor(flatColors[i * numCols + j]); 
                if (line < numLines) {
                    string text = data[j][line];
                    size_t first = text.find_first_not_of(' ');
                    if (first != string::npos) text = text.substr(first, text.find_last_not_of(' ') - first + 1);
                    else text = "";
                    text = " " + text;
                    if (text.length() > (size_t)col[j]) text = text.substr(0, col[j]);
                    cout << left << setw(col[j]) << text;
                } else {
                    cout << string(col[j], ' '); 
                }
                setColor(COLOR_VIEN); 
                cout << char(186);
            }
            cout << "\n";
        }
        if (i < numRows - 1) {
            cout << "  " << char(204);
            for (int k = 0; k < numCols; k++) {
                cout << string(col[k], char(205));
                if (k < numCols - 1) cout << char(206);
            }
            cout << char(185) << "\n";
        }
        delete[] data;
    }
    setColor(COLOR_VIEN);
    cout << "  " << char(200);
    for (int i = 0; i < numCols; i++) {
        cout << string(col[i], char(205));
        if (i < numCols - 1) cout << char(202);
    }
    cout << char(188) << "\n";
    delete[] headerData;
    delete[] col;
}

#endif
