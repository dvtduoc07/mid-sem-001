#include <iostream>
#include <cmath>
using namespace std;

int dequy(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 2;
    } else {
        return 5 * dequy(n - 1) - 6 * dequy(n - 2);
    }
}

int vonglap(int n) {
    int a0 = 0;
    int a1 = 2;
    int an;

    if (n == 0) {
        return a0;
    } else if (n == 1) {
        return a1;
    } else {
        for (int i = 2; i <= n; i++) {
            an = 5 * a1 - 6 * a0;
            a0 = a1;
            a1 = an;
        }
        return an;
    }
}

int mang(int n) {
    int a[100];
    a[0] = 0;
    a[1] = 2;

    for (int i = 2; i <= n; i++) {
        a[i] = 5 * a[i - 1] - 6 * a[i - 2];
    }

    return a[n];
}

void nhanmatran(int a[][2], int b[][2], int c[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int matran(int n) {
    int result[2][2] = {{2}, {0}};
    int cmp[2][2] = {{5, -6}, {1, 0}};

    if (n == 0) {
        return result[1][0];
    }

    for (int i = 2; i <= n; i++) {
        int temp[2][2];
        nhanmatran(cmp, result, temp);
        result[0][0] = temp[0][0];
        result[1][0] = temp[1][0];
    }

    return result[0][0];
}

int truyhoi(int n) {
    int da=-2*pow(2, n);
    int db=2*pow(3, n);
    return da+db;
}

void printMenu() {
    cout << "=============== MENU ===============" << endl;
    cout << "1. Tinh gia tri cua a(n) su dung de quy" << endl;
    cout << "2. Tinh gia tri cua a(n) su dung vong lap" << endl;
    cout << "3. Tinh gia tri cua a(n) su dung mang 1 chieu" << endl;
    cout << "4. Tinh gia tri cua a(n) su dung mang 2 chieu" << endl;
    cout << "5. Tinh gia tri cua a(n) su dung cong thuc truy hoi" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "=====================================" << endl;
}

int main() {
    int choice;
    int n;
    do {
        printMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cout << "Nhap gia tri n: ";
        cin >> n;
        switch (choice) {
            case 0:
                cout << "Thoat chuong trinh. Cam on!" << endl;
                break;
            case 1:
                cout << "Gia tri cua a(" << n << ") la: " << dequy(n) << endl;
                break;
            case 2:
                cout << "Gia tri cua a(" << n << ") la: " << vonglap(n) << endl;
                break;
            case 3:
                cout << "Gia tri cua a(" << n << ") la: " << mang(n) << endl;
                break;
            case 4:
                cout << "Gia tri cua a(" << n << ") la: " << matran(n) << endl;
                break;
            case 5:
                cout << "Gia tri cua a(" << n << ") la: " << truyhoi(n) << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Moi chon lai!" << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
