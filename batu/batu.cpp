#include <bits/stdc++.h>
using namespace std;

int a[100005], pre[100005], suf[100005];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    pre[0] = 0;
    for (int i = 1; i <= n; i++) pre[i] = __gcd(pre[i - 1], a[i]);
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) suf[i] = __gcd(suf[i + 1], a[i]);
    int idxBest = 1;
    int gcdBest = -1;

    for (int i = 1; i + k - 1 <= n; i++) {
        int g = __gcd(pre[i - 1], suf[i + k]);
        if ( g > gcdBest) {
            gcdBest = g;
            idxBest = i;
        }
    }

    cout << idxBest << " " << gcdBest << endl;
    return 0;
}
