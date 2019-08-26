#include <bits/stdc++.h>

using namespace std;

/*
 * 10 进制数转 N 进制数
 * */

int main()
{
    string s = "";
    string table = "0123456789ABCDEF";
    int M, N;
    while (cin >> M >> N) {
        while(M) {
            if (M < 0) {
                M = -M;
                cout << "-";
            }
            s = table[M%N] + s;
            M /= N;
        }
        cout << s << endl;
    }
    return 0;
}
