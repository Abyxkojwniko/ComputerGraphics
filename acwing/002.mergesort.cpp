#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000000;
int q[N], temp[N];

void MergeSort(int q[], int left, int right){
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(q, left, mid);
    MergeSort(q, mid + 1, right);
    int k = 0, i = left, j = mid + 1;
    while(i <= mid && j <= right){
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= right) temp[k++] = q[j++];
    for(int i = left, j = 0; i <= right; i++, j++) q[i] = temp[j];
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> q[i];
    }
    MergeSort(q, 0, n - 1);
    for(int i = 0; i < n; ++i){
        cout << q[i] << " ";
    }
    cout << endl;
    return 0;
}