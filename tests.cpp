#include "catch2/catch_all.hpp"
#include "Class.h"
#include "priorityQ.cpp"
#include "sorting.cpp"

TEST_CASE("Testing World class") {
  World Planet(5);
  REQUIRE_NOTHROW(Planet.greet());
}

TEST_CASE("Testing Priority Queue - Max Heap") {
  std::priority_queue<int> maxHeap;

  maxHeap.push(10);
  maxHeap.push(20);
  maxHeap.push(30);
  maxHeap.push(40);

  REQUIRE(maxHeap.size() == 4);
  REQUIRE(maxHeap.top() == 40);

  maxHeap.pop();
  REQUIRE(maxHeap.top() == 30);
}

TEST_CASE("Testing Priority Queue - Min Heap") {
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  minHeap.push(10);
  minHeap.push(20);
  minHeap.push(30);
  minHeap.push(40);

  REQUIRE(minHeap.size() == 4);
  REQUIRE(minHeap.top() == 10);

  minHeap.pop();
  REQUIRE(minHeap.top() == 20);
}

TEST_CASE("Testing Sorting - Ascending Order") {
  std::vector<int> vec = {5, 2, 8, 1, 6};
  std::sort(vec.begin(), vec.end());

  REQUIRE(vec == std::vector<int>({1, 2, 5, 6, 8}));
}

TEST_CASE("Testing Sorting - Descending Order") {
  std::vector<int> vec = {5, 2, 8, 1, 6};
  std::sort(vec.rbegin(), vec.rend());

  REQUIRE(vec == std::vector<int>({8, 6, 5, 2, 1}));
}

TEST_CASE("Testing Sorting - Custom Comparator") {
  std::vector<std::pair<int, int>> pairs = {{1, 3}, {2, 1}, {3, 2}};
  std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
    return a.second < b.second;
  });

  REQUIRE(pairs == std::vector<std::pair<int, int>>({{2, 1}, {3, 2}, {1, 3}}));
}

int main() {
  // Run Catch2 test cases
  Catch::Session().run();
}


//g++ tests.cpp memes.cpp priorityQ.cpp sorting.cpp -o test -std=c++17 -I /usr/local/include -L /usr/local/lib -lCatch2

