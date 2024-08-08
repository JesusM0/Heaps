#include <stdio.h>
#include <stdlib.h>


#define CAP 3
// #define MAXSIZE 20

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
    //Allocate memory for heap
    Heap * newHeap = (Heap *) malloc(sizeof(Heap));

    //Initialize heap beginner values
    newHeap->size = 0;
    newHeap->cap = CAP;

    //Initialize Heap Array
    newHeap->arr = (int *) malloc(sizeof(int) * newHeap->cap);

    return newHeap;

}


int main(){
    //first we shall initialize the heap
    Heap * heap = createHeap();
}