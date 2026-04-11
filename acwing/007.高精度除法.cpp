#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r)
{
    r = 0;
    vector<int> C;
    for (int i = 0; i < A.size(); i ++)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }

    reverse (C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    reverse (C.begin(), C.end());

    return C;
}

int main()
{
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;

    for (int i = 0; i < a.size(); i ++) A.push_back(a[i] - '0');

    int r;
    vector<int> C = div(A, b, r);

    for (int  i = 0; i < C.size(); i ++) cout << C[i];
    cout << endl << r << endl;

    return 0;
}