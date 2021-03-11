// Took 17 minutes
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int start_index, int end_index){
    int ptr = start_index;

    for(int i=start_index; i<end_index; i++){
        if (arr[i] < arr[end_index]){
            arr[i] = arr[ptr] + arr[i] - (arr[ptr] = arr[i]);
            ptr++;
        }
    }
    arr[ptr] = arr[end_index] + arr[ptr] - (arr[end_index] = arr[ptr]);

    return ptr;
}

void quicksort(vector<int>& arr, int start_index, int end_index){
    if (start_index == end_index)
        return;
    
    int index = partition(arr, start_index, end_index);
    if (index != start_index)
        quicksort(arr, start_index, index-1);
    if (index != end_index)
        quicksort(arr, index+1, end_index);
}

int main(){
    vector<int> arr({5, 3, 4, 7, 10, 1, -3, -2, 11, 100, 234});
    quicksort(arr, 0, arr.size()-1);

    for(vector<int>::iterator itr=arr.begin(); itr!=arr.end(); itr++)
        cout << *itr << " ";
    cout << endl;
    return 0;
}