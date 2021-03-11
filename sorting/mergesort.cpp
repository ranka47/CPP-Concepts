#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int start_index, int end_index, int mid_index){
    int left_index = start_index;
    int right_index = mid_index+1;
    vector<int> temp;

    while (left_index < mid_index+1 && right_index < end_index+1){
        if (arr[left_index] > arr[right_index])
            temp.push_back(arr[right_index++]);
        else if (arr[left_index] < arr[right_index])
            temp.push_back(arr[left_index++]);
        else
            temp.push_back(arr[left_index++]);
    }

    while (left_index < mid_index+1)
        temp.push_back(arr[left_index++]);

    while (right_index < end_index+1)
        temp.push_back(arr[right_index++]);
    
    left_index=start_index;
    for (vector<int>::iterator itr=temp.begin(); itr!=temp.end(); itr++)
        arr[start_index++] = (*itr);
}

void mergesort(vector<int>& arr, int start_index, int end_index){
    if (start_index == end_index)
        return;
    if (start_index == end_index-1){
        if (arr[start_index] > arr[end_index])
            arr[start_index] = arr[end_index] + arr[start_index] - (arr[end_index] = arr[start_index]);
        return;
    }
    int mid = (start_index+end_index)/2;

    mergesort(arr, start_index, mid);
    mergesort(arr, mid+1, end_index);
    merge(arr, start_index, end_index, mid);
}

int main(){
    vector<int> arr({7, 10, 1, -3, -2, 11, 100, 234, 8, 1, 23, 12, 6, -12, -111, 1225, 16, 523, 25});
    mergesort(arr, 0, arr.size()-1);

    for (vector<int>::iterator itr=arr.begin(); itr!=arr.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}