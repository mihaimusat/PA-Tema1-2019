#include <bits/stdc++.h>

using namespace std;

int n, k, v, i, y, m;
long long nr, z, t;

long long inv_mod(int x) {
    z = (1LL) * x;
    t = 1LL;
    y = 1000000005;
    while(y != 0) {
        if((y % 2) == 1) {
            t = (1LL) * t * z % 1000000007;
	}
        z = (1LL) * z * z % 1000000007;
        y /= 2;
    }
    return t;
}

int main()
{
    ifstream fin("p4.in");
    ofstream fout("p4.out");

    fin >> n >> k >> v;

    nr = 1LL;
    if((n % 2) == 1) {
        m = (n / 2) + 1;
        if(((n + k - m) <= v) && (k >= m)) {
            for(i = 1; i <= (k - 1); i++)
                nr = (1LL) * nr * i % 1000000007;
            for(i = 1; i <= (v - k); i++)
                nr = (1LL) * nr * i % 1000000007;
            for(i = 1; i <= (m - 1); i++)
                nr = (1LL) * nr * inv_mod(i) % 1000000007;
            for(i = 1; i <= (m - 1); i++)
                nr = (1LL) * nr * inv_mod(i) % 1000000007;
            for(i = 1; i <= (v - k - m + 1); i++)
                nr = (1LL) * nr * inv_mod(i) % 1000000007;
            for(i = 1; i <= (k - m); i++)
                nr = (1LL) * nr * inv_mod(i) % 1000000007;
            for(i = 1; i <= n ;i++)
                nr = (1LL) * nr * i % 1000000007;
            fout << nr << endl;
        }
        else {
            fout << 0 << endl;
	}
    }
    else {
        m = n / 2;
        if(((n + k - m) <= v) && (k >= m)) {
            for(i = 1; i <= (k - 1); i++)
                nr = (1LL) * nr * i % 1000000007;
            for(i = 1; i <= (v - k); i++)
                nr = (1LL) * nr * i % 1000000007;
            for(i = 1; i <= m; i++)
                nr = (1LL) * nr * inv_mod(i) % 1000000007;
            for(i = 1; i <= (m - 1); i++)
                nr = (1LL) * nr * inv_mod(i) % 1000000007;
            for(i = 1; i <= (v - k - m); i++)
                nr = (1LL) * nr * inv_mod(i) % 1000000007;
            for(i = 1; i <= (k - m); i++)
                nr = (1LL) * nr * inv_mod(i) % 1000000007;
            for(i = 1; i <= n; i++)
                nr = (1LL) * nr * i % 1000000007;
            fout << nr << endl;
        }
        else {
            fout << 0 << endl;
	}
    }

    return 0;
}
