#include <iostream>

using namespace std;
int a[100];
int main() {
    int q, l, r, t, val, n = 10;

    cin >> q;
    while (q --) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r;
            int ans = 1 << 30;
            for (int i = l ; i <= r ; i ++)
                if (ans > a[i])
                    ans = a[i];
            cout << ans << endl;
        } else {
            cin >> l >> r >> val;
            for (int i = l ; i <= r ; i ++)
                a[i] += val;
        }
    }
    return 0;
}