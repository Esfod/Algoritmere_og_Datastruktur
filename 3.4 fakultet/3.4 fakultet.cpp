#include <iostream>

using namespace std;
int faukultet(int n)
{
    int nfak = 1;
    for (auto i = 1; i <= n; i++)
        nfak = nfak * i;
    return nfak;
}

int fakrek(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fakrek(n - 1);
}
int binom(int n, int r)
{
    return fakrek(n) / (fakrek(r) * fakrek(n - r));
}
int main()
{
    cout << "n: ";
    int n; cin >> n;
    cout << n << "! = " << fakrek(n) << endl;
    int r;
    cout << "n r: ";
    cin >> n >> r;
    cout << "binom(" << n << " " << r << ") = " << binom(n, r) << endl;
}