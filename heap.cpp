// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
    for (auto it = start; it != end; ++it)
        vdata.push_back(*it);
 
    int n = (int)vdata.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        bubbleDown(i);
}	


// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value);
    bubbleUp((int)vdata.size() - 1);
}
 

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    if (vdata.empty()) return;

    vdata[0] = vdata.back();
    vdata.pop_back();

    if (!vdata.empty())
        bubbleDown(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}
 
// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    
//Helper Funtions
void Heap::bubbleUp(int i){
    while (i > 0) {
        int p = (i - 1) / 2;
        if (vdata[i] < vdata[p]) {
            std::swap(vdata[i], vdata[p]);
            i = p;
        } else break;
    }
}
 
void Heap::bubbleDown(int i){
    int n = (int)vdata.size();
    while (true) {
        int left = 2*i+1, right = 2*i+2, smallest = i;
        if (left  < n && vdata[left]  < vdata[smallest]) smallest = left;
        if (right < n && vdata[right] < vdata[smallest]) smallest = right;
        if (smallest != i) {
            std::swap(vdata[i], vdata[smallest]);
            i = smallest;
        } else break;
    }
}
 

