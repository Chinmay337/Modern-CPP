#include <iostream>
#include <queue>

int main() {
  std::cout << "\n================\nPriority Queues!\n================\n\n";

  std::cout << "1. MAX HEAP using Priority Queue\n\n"
            << "In C++ , by default ->\n\n  std::priority_queue<int> pq is a "
               "Max-Heap\n\n";

  // By Default Priority Queue is a Max Heap in C++
  std::priority_queue<int> maxHeap;

  maxHeap.push(10);
  maxHeap.push(20);
  maxHeap.push(30);
  maxHeap.push(40);

  std::cout << "Size of Priority Queue: " << maxHeap.size() << std::endl;
  std::cout << "Top Element of Priority Queue: " << maxHeap.top() << std::endl;

  maxHeap.pop();
  std::cout << "Top Element of Priority Queue: " << maxHeap.top() << std::endl;
  std::cout << "======================\n======================\n\n";

  std::cout << "2. MIN HEAP using Priority Queue\n"
            << "In C++ to use priority queue to get a MIN HEAP we can reverse "
               "the sign of the elements\n\n";

  std::priority_queue<int> minHeap;
  minHeap.push(-10);
  minHeap.push(-20);
  minHeap.push(-30);
  minHeap.push(-40);

  std::cout << "Top Element of Priority Queue: " << minHeap.top() << std::endl;

  minHeap.pop();
  std::cout << "Top Element of Priority Queue: " << minHeap.top() << std::endl;

  std::cout << "======================\n\n"
            << "Important Methods on Priority Queue\n\n";
  std::cout << "1. push() - Inserts an element into the Priority Queue\n"
            << "2. pop() - Removes the top element from the Priority Queue\n"
            << "3. top() - Returns the top element from the Priority Queue\n"
            << "4. size() - Returns the size of the Priority Queue\n"
            << "5. empty() - Returns true if the Priority Queue is empty\n";

  std::cout << "\n======================\n======================\n\n";
}

//// g++ -std=c++17 priorityQ.cpp  -o pq && ./pq
