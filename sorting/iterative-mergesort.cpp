#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int start_index, int end_index, int mid_index){
    int left_index = start_index;
    int right_index = mid_index+1;
    vector<int> temp;

    while (left_index < mid_index+1 && right_index < end_index+1){
        if (arr[left_index] <= arr[right_index])
            temp.push_back(arr[left_index++]);
        else if (arr[left_index] > arr[right_index])
            temp.push_back(arr[right_index++]);
    }

    while (left_index < mid_index+1)
        temp.push_back(arr[left_index++]);
    while (right_index < end_index+1)
        temp.push_back(arr[right_index++]);
    
    left_index=start_index;
    for(vector<int>::iterator itr=temp.begin(); itr!=temp.end(); itr++)
        arr[start_index++] = (*itr);
}

void iterative_mergesort(vector<int>& arr){
    for (int window_size=1; window_size < arr.size(); window_size*=2){
        cout << "Window size: " << window_size << endl;
        for (int start_index=0; start_index < arr.size(); start_index+=(2*window_size)){
            int end_index = start_index+(2*window_size)-1;
            
            // Important
            if (end_index >= arr.size())
                end_index = arr.size()-1;

            // Important especially -1 bcz mid_index
            // represents the last index of the left
            // part of the subarray passed to merge fn 
            int mid_index = start_index+window_size-1;
            cout << start_index << " " << mid_index << " " << end_index << endl;
            merge(arr, start_index, end_index, mid_index);
        }
    }
}

int main(){
    vector<int> arr({7, 10, -3, -2, 11, 100, 8, 1, 2, 2, 2, 2, 383, -33, 12, 6, -12, -111, 1225, 16, 523, 25});
    // vector<int> arr({1, 2, -1});
    iterative_mergesort(arr);

    for (vector<int>::iterator itr=arr.begin(); itr!=arr.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}