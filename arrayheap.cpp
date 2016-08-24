// Implementation of a Heap using an array.
// Status: Incomplete
// TODO: Fix bubbleDown
#include <cstdio>

class Heap {
  public:
    Heap();
    int min();
    bool insert(int val);
  private:
    int* root;
    int size;
    int nodeCount;

    bool bubbleUp(int index);
    bool bubbleDown(int index);

    void resize();
};

Heap::Heap() {
  size = 256;
  root = new int[size];
  nodeCount = 0;
}

bool Heap::bubbleUp(int index){
  // Bubble up the value at the location given in 'index'.
  int parent = index / 2;
  int tmp;
  while (root[parent] > root[index]) {
    printf("Swapping %i up with %i\n", root[index], root[parent]);
    tmp = root[parent];
    root[parent] = root[index];
    root[index] = tmp;
    index = parent;
    if(parent == 0)
      return true;
    parent = index / 2;
  }
  return true;
}

bool Heap::bubbleDown(int index){
  // Bubble down the value at the location given in 'index'.
  printf("down %i\n", root[index]);
  int child = index;
  if(index == 0)
    child = 1;
  int tmp;
  while (child < nodeCount) {
    // left child is less than current node.
    // Swap with the current node and continue.
    if(root[child] < root[index]){
      printf("Swapping %i down with %i\n", root[index], root[child]);
      tmp = root[child];
      root[child] = root[index];
      root[index] = tmp;
      index = child;
    }

    if(child + 1 >= nodeCount)
      break;
    // Right child is less than current node.
    // Swap with the current node and then continue.
    else if(root[child + 1] < root[index]){
      child = child + 1;
      printf("Swapping %i down with %i\n", root[index], root[child]);
      tmp = root[child];
      root[child] = root[index];
      root[index] = tmp;
      index = child;
    }
    child = index * 2;
  }
  return true;
}

// Insertion done using a bubble up method.
bool Heap::insert(int val) {
  if (nodeCount == size)
    resize();
  root[nodeCount] = val;
  nodeCount = nodeCount + 1;
  bubbleUp(nodeCount);
  return true;
}

int Heap::min(){
  if(nodeCount == 0)
    return -1;
  // min value is at the root(first element of the array)
  int min = root[0];
  nodeCount = nodeCount - 1;
  root[0] = root[nodeCount];
  bubbleDown(0);
  return min;
}

void Heap::resize() {
  int* tmp = new int[size * 2];
  for(int i = 0; i < nodeCount; i++)
    tmp[i] = root[i];
  size = size * 2;
  root = tmp;
}

int main(){
  Heap tmp;
  tmp.insert(12);
  tmp.insert(13);
  tmp.insert(1);
  tmp.min();
  tmp.min();
  tmp.min();
  return 0;
}
