#include <stdio.h>
#include <stdlib.h>

typedef struct Heap Heap;

struct Heap {
    int * arr; // Heap Array
    int size; //Current number of elements in heap
    int cap; //capacity o heap
};

//Prototypes
Heap * createHeap();
void swap(Heap * heap, int index1, int index2);
void percolateUp(Heap * heap, int index);
void percolateDown(Heap * heap, int index);
void enqueue(Heap * heap, int value);
void dequeue(Heap * heap);
void front(Heap * heap);
void cleanHeap(Heap * heap);

Heap * createHeap(){
    
}


int main(){
    //first we shall initialize the heap
    Heap * heap = createHeap();
}