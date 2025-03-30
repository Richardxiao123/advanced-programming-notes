#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void randAns(int*);
int guess(int*);
int check(string&);

int main() {
    srand(time(NULL));
    cout << "1A2B猜數字遊戲" << endl;
    int ans[4] = {0};
    randAns(ans);
    int times = 0;

    while (true) {
        if (guess(ans)) {
            cout << "您答對了，正確答案是 " << ans[0] << ans[1] << ans[2] << ans[3] << endl;
            cout << "您共猜了 " << ++times << " 次" << endl;
            break;
        }
        ++times;
    }

    cout << "隨機生成的數字是: " << ans[0] << ans[1] << ans[2] << ans[3] << endl;
    system("pause");
    return 0;
}

void randAns(int* ans) {
    int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    for (int i = 9; i > 0; i--) {
        int r = rand() % (i + 1);
        swap(num[i], num[r]);
    }

    for (int i = 0; i < 4; i++) {
        ans[i] = num[i];
        cout << num[i];
    }
    cout << endl;
}

int check(string &str) {
    if (str.length() != 4) return 1; // 確保輸入長度為4
    for (int i = 0; i < 4; i++) {
        if (str[i] < '0' || str[i] > '9') return 1;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (str[i] == str[j]) return 1; // 檢查重複
        }
    }
    return 0;
}

int guess(int *ans) {
    cout << "請輸入猜4個數字: ";
    string inputStr;
    while (cin >> inputStr) {
        if (check(inputStr)) {
            cout << "輸入錯誤，請重新輸入: ";
        } else {
            break;
        }
    }

    int guess[4] = {0};
    for (int i = 0; i < 4; i++) {
        guess[i] = inputStr[i] - '0';
    }

    int a = 0; // A的數量
    int b = 0; // B的數量

    for (int i = 0; i < 4; i++) {
        if (ans[i] == guess[i]) {
            a++; // A的數量
        } else {
            for (int j = 0; j < 4; j++) {
                if (ans[i] == guess[j]) {
                    b++; // B的數量
                    break;
                }
            }
        }
    }

    cout << a << "A" << b << "B" << endl; // 輸出結果
    return a == 4; // 如果猜對返回true
}
