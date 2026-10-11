#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> semua;
    long long normal = 0;
    for (int i = 0; i < n; i++) {
        long long maks = 0;
        for (int j = 0; j < m; j++) {
            long long x;
            cin >> x;
            semua.push_back(x);
            maks = max(maks, x);
        }
        normal += maks;
    }
    
    sort(semua.begin(), semua.end(), greater<long long>());
    long long rev = 0;
    for (int i = 0; i < n; i++) rev += semua[i];

    cout << normal << " " << rev << endl;
    return 0;
}
