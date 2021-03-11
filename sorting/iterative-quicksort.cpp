#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int partition(vector<int>& arr, int l, int r){
    int ptr=l;

    for(int i=l; i<r; i++){
        if (arr[i] < arr[r]){
            arr[i] = arr[ptr] + arr[i] - (arr[ptr]=arr[i]);
            ptr++;
        }
    }
    arr[ptr] = arr[r] + arr[ptr] - (arr[r] = arr[ptr]);

    return ptr;
}

void iterative_quicksort(vector<int>& arr){
    int l=0;
    int r=arr.size()-1;
    stack<int> range;

    range.push(l);
    range.push(r);

    while(!range.empty()){
        r = range.top(); range.pop();
        l = range.top(); range.pop();
        int index = partition(arr, l, r);

        if (index-1 > l){
            range.push(l);
            range.push(index-1);
        }
        if (index+1 < r){
            range.push(index+1);
            range.push(r);
        }
    }
}

int main(){
    vector<int> arr({5, 3, 4, 7, 10, 1, -3, -2, 11, 100, 234});
    iterative_quicksort(arr);

    for (vector<int>::iterator itr=arr.begin(); itr!=arr.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}