#include <iostream>
#include <array>

int main()
{
  using namespace std;
  // create array using std:array
  array<int, 10> arr = {9, 5, 7, 4, 2, 8, 1, 10, 6, 3};

  for (const auto &num : arr)
    cout << "Num " << num << '\n';

  return 0;
}
/*
g++ -std=c++20 -o quicksort quicksort.cpp && ./quicksort

Approach for [10,5,3,7,1,11]
1. Choosing Random Pivot - 3 - need to make sure elems smaller than arr[3] are on left and elems greater than arr[3] are on right
2.
[10,5,3,7,1,11] - Choose pivot elem 7


quickSort(arr , l , r) {
 if (l < r) {
  p = partition(arr,l,r)
  quickSort(arr,l,p-1)
  quickSort(arr,p+1,r)
 }
}

partition(arr,l,r) {

  randomIndex = random(l,r)
  swapArr(l,randomIndex)
  pivotElem = arr[start] // since we swapped
  swapIdx = start; // index of pivot elem

  for (j=l+1 ; j<r ; l++) {
    if (arr[l] < pivotElem ) {
      swapIdx++;
      swapArr(arr[j],arr[swapIdx])
    }
  }

  swapArr(arr[start],arr[swapIdx]) // to make sure pivot elem is at correct place
  return swapIdx                   // return correct index of pivot Elem

}

quickSort(arr,0,5)

*/
