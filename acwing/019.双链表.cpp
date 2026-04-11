#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

// 使用原生数组在算法竞赛中更稳，idx 避开关键字
int v[N], l[N], r[N], idx;

void init(){
    // 0 是左端点(Head)，1 是右端点(Tail)
    r[0] = 1, l[1] = 0;
    idx = 2; // 真正的数据从 2 开始存
}

// 在下标为 k 的点右侧插入 x
void add(int k, int x){
    v[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx; // 让原来 k 的右邻居指向新点
    r[k] = idx;    // 让 k 指向新点
    idx++;
}

// 删除下标为 k 的点
void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    init();

    while(m--){
        string op;
        int k, x;
        cin >> op;
        if(op == "L"){ // 最左端插入 (即在 0 的右边插)
            cin >> x;
            add(0, x);
        }
        else if(op == "R"){ // 最右端插入 (即在 1 的左边点的右边插)
            cin >> x;
            add(l[1], x);
        }
        else if(op == "D"){ // 删除第 k 个插入的数
            cin >> k;
            remove(k + 1);
        }
        else if(op == "IL"){ // 在第 k 个插入的数左边插
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else{ // "IR": 在第 k 个插入的数右边插
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    // 🌟 修正：从 r[0] 开始，避开虚拟头结点
    for(int i = r[0]; i != 1; i = r[i]){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}