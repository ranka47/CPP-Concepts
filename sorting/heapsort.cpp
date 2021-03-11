#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent(int i){
    if (i == 0)
        return 0;
    else if (i%2 == 0)
        return i/2 - 1;
    else if (i%2 == 1)
        return i/2; 
}

int left_child(int i){
    return (2*i + 1);
}

int right_child(int i){
    return (2*i + 2);
}

void insertKey(vector<int>& heap, int value){
    heap.push_back(value);
    int index = heap.size() - 1;
    while (index != 0 && heap[parent(index)] > heap[index]){
        heap[parent(index)] = heap[index] + heap[parent(index)] - (heap[index] = heap[parent(index)]);
        index = parent(index);
    }
}

void heapify(vector<int>& heap){
    int index = 0;
    while (index < heap.size()){
        int smallest_index = index;

        if (left_child(index) < heap.size() && heap[smallest_index] > heap[left_child(index)])
            smallest_index = left_child(index);
        if (right_child(index) < heap.size() && heap[smallest_index] > heap[right_child(index)])
            smallest_index = right_child(index);
        if (index == smallest_index)
            break;
        else{
            heap[index] = heap[smallest_index] + heap[index] - (heap[smallest_index] = heap[index]);
            index = smallest_index;
        }
    }
}

int extractMin(vector<int>& heap){
    int min = heap[0];
    heap[0] = heap[heap.size() - 1] + heap[0] - (heap[heap.size() - 1] = heap[0]);
    heap.pop_back();
    heapify(heap);

    return min;
}


void heapsort(vector<int>& arr){
    vector<int> heap;
    for (vector<int>::iterator itr=arr.begin(); itr!=arr.end(); itr++)
        insertKey(heap, *itr);

    for (int i=0; i < arr.size(); i++)
        arr[i] = extractMin(heap);
}

int main(){
    vector<int> arr({78, 1, 2, 383, -33, 12, 6, -12, -111, 1225, 16, 523, 25});
    // vector<int> arr({1, 2, -1});
    heapsort(arr);

    for (vector<int>::iterator itr=arr.begin(); itr!=arr.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}