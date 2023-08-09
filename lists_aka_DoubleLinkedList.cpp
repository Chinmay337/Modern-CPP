#include <iostream>
#include <list>
#include <vector>

int main()
{
  using namespace std;

  cout << "========================\n";
  cout << "Lists aka Double Linked Lists\n";
  cout << "========================\n\n";

  cout << "std::list<type> is a Doubly Linked List in C++.\n\n";

  cout << "list<int> myList = {10, 20, 30, 40, 50}\n\n";

  cout << "We can insert at the front and at any position in this list.\n\n";

  cout << "To delete from the List use\n list.erase(iterator)\n\n";

  cout << "To delete specific item from the List use\n list.remove(item)\n\n";

  cout << "To delete a range of items from the List use\n list.erase(start, end) where start,end are iterators.\n\n";

  cout << "To get the last element of the List use\n list.rbegin() -> returns iterator\n*list.rbegin() to get actual value.\n\n";

  cout << "We use the * operator because <container>.begin() or <container>.end() returns an iterator which is a Pointer to the container.\n\n";

  cout << "========================\n";
  cout << "========================\n\n";

  list<int> myList = {10, 20, 30, 40, 50};

  // Insert an element at a specific index
  list<int>::iterator it = myList.begin();
  advance(it, 2);        // Move iterator to the desired index
  myList.insert(it, 25); // Inserts at Index 2

  // Print the list elements -> 10 20 25 30 40 50
  for (const auto &element : myList)
  {
    cout << element << " ";
  }

  cout << endl;

  // Remove an element at a specific index
  list<int>::iterator it2 = myList.begin();
  advance(it2, 3); // Move iterator to the desired index
  myList.erase(it2);

  list<int> secList = {10, 20, 30, 40, 50};

  // print last element of secList
  cout << "Last Element " << *secList.rbegin() << endl;

  // Removing a range of elements (e.g., from the 2nd element to the 4th element)
  auto start = std::next(secList.begin(), 1); // Iterator pointing to the 2nd element
  auto end = std::next(secList.begin(), 4);   // Iterator pointing to the 4th element
  secList.erase(start, end);

  // Print the list elements -> 10 40 50
  for (const auto &element : secList)
  {
    cout << element << "\n";
  }

  // Deleting particular element from the list
  // (e.g., deleting all elements with value 10)
  secList.remove(10);

  // Removing all elements from the list
  secList.clear();

  list<pair<int, int>> lru{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  cout << "Last Element " << lru.rbegin()->second << "\n\n";

  vector<int> tt = {1};
  cout << tt.begin().size() << "\n\n";

  return 0;
}

// class LRUCache {
// public:
//     int capacity;
//     // Map is used to point a Key to it's position in the List using an iterator
//     unordered_map<int, list<pair<int, int>>::iterator> dic;
//     list<pair<int, int>> lru;

//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }

//     // 1. check if the key exists,if doesn't return -1.
//     // 2. Once we get the value from key - we want to :
//     // 3. Put it at the start of List because it's the latest used
//     //This way , the least recently used key is at the end , and
//     // whenever we use the keys - they go to the start
//     // Then, the map still points key to old iterator. So delete that
//     // and make sure we update map with key pointing to start of List

//     int get(int key) {
//         auto it = dic.find(key); // it is iterator

//         if (it == dic.end()) {
//             return -1;
//         }
//         // it is an iterator over the unord_map<int,list<t>::iterator>
//         // it->second is List Iterator
//         // it->second->second is List Iterator's second value - so 2nd val of pair

//         int value = it->second->second;
//         lru.erase(it->second); // erase deletes item associated with iterator frm List

//         // pushes Key from get(key) and existing Value to List Beginning
//         lru.push_front({key, value});

//         // Delete existing Key -> iterator in List from Map
//         dic.erase(it);
//         // Then add the correct one
//         dic[key] = lru.begin();
//         return value;
//     }

//     void put(int key, int value) {
//         auto it = dic.find(key);

//         // If map HAS the key already
//         // delete from List (it->second is the iterator pointing to current val of key)
//         // Delete the k-v from our map

//         if (dic.find(key) != dic.end()) {
//             // if the key is found , we need to remove it from the map and list
//             lru.erase(it->second);
//             dic.erase(it);
//         }

//         // Push new k/v in front of List
//         lru.push_front({key, value});
//         // Set k-v on map of key -> iterator(k,v) by lru.begin()
//         dic[key] = lru.begin();

//         // If the Capacity was exceeded, make sure to delete latest used Item
//         if (dic.size() > capacity) {
//             // Gets last pair from List and Finds in map
//             auto it = dic.find(lru.rbegin()->first);
//             // uses iterator to delete last used from map
//             dic.erase(it);
//             // gets rid of last used key
//             lru.pop_back();
//         }
//     }

// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */