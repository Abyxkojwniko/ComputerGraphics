#include <iostream>
#include <vector>

const int N = 100000;
using namespace std;

vector<int> add(vector<int>& a, vector<int>& b){
    int temp =  0;
    vector<int> c;
    for(int i = 0; i < a.size() || i < b.size(); ++i){
        if(i < a.size()) temp += a[i];
        if(i < b.size()) temp += b[i];
        c.push_back(temp % 10);
        temp /= 10;
    }
    if(temp) c.push_back(temp % 10);
    return c;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a, b;
    for(int i = s1.size() - 1; i >= 0; --i) a.push_back(s1[i] - '0');
    for(int i = s2.size() - 1; i >= 0; --i) b.push_back(s2[i] - '0');
    vector<int> c = add(a, b);
    for(int i = c.size() - 1; i >= 0; --i){
        cout << c[i];
    }
    return 0;
}