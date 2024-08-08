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

    //return new heap
    return newHeap;

}

void swap(Heap * heap, int index1, int index2){
    //store the first index in a temp value
    int tmp = heap->arr[index1];
    //swap index1 for index 2
    heap->arr[index1] = heap->arr[index2];
    //index 2 now gets value of index 1
    heap->arr[index2] = tmp;
}

//recursive
void percolateUp(Heap * heap, int index){
    //reached top of heap
    if(index == 0){
        return;
    }
    //calculate parent using this formulate
    int parent = (index - 1) / 2;
    //compare values in max heap and swap if necessary
    if(heap->arr[index] > parent){
        swap(heap, parent, index);
        //pass parent value as new index
        percolateUp(heap, parent); //only perculate if swap occurs, otherwise do nothing.
    }
    
}

void percolateDown(Heap * heap, int index){
    
}


void enqueue(Heap * heap, int value){
    if(heap->size == heap->cap){
        heap->cap *= 2;
        heap->arr = (int *) realloc(heap->arr, sizeof(int) * heap->cap);
    }

    heap->arr[heap->size] = value;
    heap->size++;
    percolateUp(heap, heap->size - 1);
}

void dequeue(Heap * heap){
    if(heap->size == 0){
        return;
    }

    swap(heap, 0, heap->size - 1);
    heap->size--;
    percolateDown(heap, 0);

}


//iteratively Perculate
// void percolateUp(Heap * heap, int index){
//     while(index > 0){
//         int parent = (index - 1) / 2;
//         if(heap->arr[index] > heap->arr[parent]){
//             swap(heap, parent, index);
//             index = parent;
//         }
//         else{
//             break;
//         }
        
//     }
    
// }


int main(){
    //first we shall initialize the heap
    Heap * heap = createHeap();
    enqueue(heap, 0);
    enqueue(heap, 1);
    enqueue(heap, 2);
    enqueue(heap, 3);
    enqueue(heap, 4);
    enqueue(heap, 5);
    enqueue(heap, 6);

    for(int i = 0; i <= heap->size - 1; i++){
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}