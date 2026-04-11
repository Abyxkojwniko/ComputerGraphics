#include <iostream>

using namespace std;

const int N = 100010;

int val[N], pointer[N], head, index;

void init(){
    head = -1;
    index = 0;
}

void insert_head(int x){
    val[index] = x;
    pointer[index] = head;
    head = index;
    ++index;
}

void insert_k(int k, int x){
    val[index] = x;
    pointer[index] = pointer[k];
    pointer[k] = index;
    ++index;
}

void delete_k(int k){
    pointer[k] = pointer[pointer[k]];
}

int main(){
    int m;
    cin >> m;
    init();
    while(m--){
        int k, x;
        char op;
        cin >> op;
        if(op == 'H'){
            cin >> x;
            insert_head(x);
        }
        else if(op == 'D'){
            cin >> k;
            if(k == 0) head = pointer[head];
            delete_k(k - 1);
        }
        else{
            cin >> k >> x;
            insert_k(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = pointer[i]){
        cout << val[i] << " ";
    }
    return 0;
}