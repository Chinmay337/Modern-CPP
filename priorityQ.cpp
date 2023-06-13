#include <iostream>
#include <queue>
#include <vector>

int main()
{
  using namespace std;

  cout << "\n================\nPriority Queues!\n================\n\n";

  cout << "1. MAX HEAP using Priority Queue\n\n"
       << "In C++, by default ->\n\n  std::priority_queue<int> pq is a Max-Heap\n\n";

  // By Default, Priority Queue is a Max Heap in C++
  priority_queue<int> maxHeap;

  maxHeap.push(10);
  maxHeap.push(20);
  maxHeap.push(30);
  maxHeap.push(40);

  cout << "Size of Priority Queue: " << maxHeap.size() << endl;
  cout << "Top Element of Priority Queue: " << maxHeap.top() << endl;

  maxHeap.pop();
  cout << "Top Element of Priority Queue after pop: " << maxHeap.top() << endl;
  cout << "======================\n======================\n\n";

  cout << "2. MIN HEAP using Priority Queue\n"
       << "In C++, to use priority queue to get a MIN HEAP we can reverse the sign of the elements\n\n";

  priority_queue<int> minHeap;
  minHeap.push(-10);
  minHeap.push(-20);
  minHeap.push(-30);
  minHeap.push(-40);

  cout << "Top Element of Priority Queue: " << minHeap.top() << endl;

  minHeap.pop();
  cout << "Top Element of Priority Queue after pop: " << minHeap.top() << endl;

  cout << "======================\n\n";

  cout << "3. Priority Queue of Pairs\n\n"
       << "We can use Priority Queue to sort a vector of pairs based on different criteria\n\n";

  vector<pair<int, int>> v = {{3, 6}, {1, 2}, {5, 9}, {7, 0}};

  cout << "If we want to order a Priority Queue of Pairs based on the first element such that the Smallest Element is at the Top (Min Heap)\n"
       << endl;

  cout << "priority_queue<pair<int,int> , vector<pair<int,int> , greater<pair<int,int>>> pqMinHeap(v.begin(), v.end());\n\n";

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
      pqMinHeap(v.begin(), v.end());

  cout << "Priority Queue of Pairs with custom ordering based on first element in ascending order:\n";

  while (!pqMinHeap.empty())
  {
    auto topElem = pqMinHeap.top();
    cout << topElem.first << ", " << topElem.second << endl;
    pqMinHeap.pop();
  }

  // Priority Queue of Pairs with default ordering (max heap based on first element of pair)
  priority_queue<pair<int, int>> pqDefault(v.begin(), v.end());

  cout << "Priority Queue with Default Ordering (Max Heap based on first element):\n";
  while (!pqDefault.empty())
  {
    auto topElem = pqDefault.top();
    cout << topElem.first << ", " << topElem.second << endl;
    pqDefault.pop();
  }

  // Priority Queue of Pairs with custom ordering based on second element in ascending order
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqCustomAsc(v.begin(), v.end());

  // Priority Queue of Pairs with custom ordering based on second element in descending order
  auto compareDesc = [](const pair<int, int> &p1, const pair<int, int> &p2)
  {
    return p1.second < p2.second; // Compare in descending order based on second element
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compareDesc)> pqCustomDesc(compareDesc);

  for (const auto &pair : v)
  {
    pqCustomDesc.push(pair);
  }

  cout << "\nPriority Queue with Custom Ordering (Max Heap based on second element - Descending Order):\n";
  while (!pqCustomDesc.empty())
  {
    auto topElem = pqCustomDesc.top();
    cout << topElem.first << ", " << topElem.second << endl;
    pqCustomDesc.pop();
  }

  cout << "======================\n\n"

       << "Important Methods on Priority Queue\n\n";
  cout << "1. push() - Inserts an element into the Priority Queue\n"
       << "2. pop() - Removes the top element from the Priority Queue\n"
       << "3. top() - Returns the top element from the Priority Queue\n"
       << "4. size() - Returns the size of the Priority Queue\n"
       << "5. empty() - Returns true if the Priority Queue is empty\n";

  cout << "======================\n\n";
  cout << "PQ with top() storing Smallest Element\n";
  cout << "priority_queue<pair<int,int> , vector<pair<int,int> , greater<pair<int,int>>> pqMinHeap(v.begin(), v.end());\n\n";

  cout << "PQ with top() storing Largest Element\n";
  cout << "priority_queue<pair<int,int> , vector<pair<int,int> , less<pair<int,int>>> pqMaxHeap(v.begin(), v.end());\n\n";

  cout << "\n======================\n======================\n\n";
}
