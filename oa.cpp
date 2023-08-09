/*
OA Questions

Given - costs = [6,2,1,2,6]

3,2,1,2
3,1,1
3,0

1,1,3
0.5,3 = 0,3

final ans [0,3]

sol'n -

declare variable to store final arr size

removeItems = 0

transform to

[
  <6,4>,
  <6,0>
  <2,3>,
  <2,1>,
  <1,2>
]

1st algo loop -
max 6 at i=0 , next max at i=4
remove <6,0> and increment removeItems++ change <6,4> to <3,4>

removeItems = 1, and pq below

[
  <3,4>
  <2,1>,
  <2,3>,
  <1,2>
]

second algo loop
check top <3,4> - next is <2,1> so not same max - remove <3,4> from pq and save in memory

discarded = [ <3,4>]

2 is max so remove <2,1> and increment removeItems++ change <2,3> to <1,3>

pq is now
[
  <1,3>,
  <1,2>
]

same , remove <1,3> and increment removeItems++ change <1,2> to <0,2>

pq is now [<0,2>]
algo terminates

removeItems = 3
length = 5
finalArray = vector of size (length - removeitems) = vector of size 2

add remaining items in pq [<0,2>] to discarded items [<3,4>]
remaining is [<0,2>, <3,4>]
sorted in ascending order of e[1] = [<0,2>, <3,4>]

return [0,3] final answer


Given - prios = [6,2,1,2,6]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> calcCosts(vector<int> &costs)
{
  const int n = costs.size();

  priority_queue<pair<int, int>> pq; // pq is a max heap by default

  for (int i = 0; i < n; ++i)
  {
    pq.emplace(costs[i], i); // fill the pq with costs and their indices
  }

  auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
  {
    return a.second > b.second; // Using the pq as a min-heap based on index
  };

  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> finalCosts(comp);

  while (!pq.empty())
  {
    // Get item with Max Cost from the top of the heap
    auto currMax = pq.top();
    pq.pop();

    // Check if the next item doesnt have the same Max Cost
    while (!pq.empty() && currMax.first != pq.top().first)
    {
      finalCosts.emplace(currMax);
      currMax = pq.top();
      pq.pop();
    }

    if (pq.empty())
    {
      finalCosts.emplace(currMax);
      break; // Terminate Algo if no 2 items with Max Cost found
    }

    /*

    We have found 2 elems with common Max Cost
        -- delete the 1st element
        -- halve the 2nd element and push it back to the pq

    */

    pq.emplace(pq.top().first / 2, pq.top().second);
    pq.pop();
  }

  // Algo is terminated

  while (!pq.empty())
  {
    finalCosts.emplace(pq.top()); // Push remaining costs to finalCosts
    pq.pop();
  }

  vector<int> final;

  while (!finalCosts.empty()) // Push finalCosts->final which is the answer
  {
    final.push_back(finalCosts.top().first);
    finalCosts.pop();
  }

  return final;
}

int main()
{
  vector<int> costs = {6, 2, 1, 2, 6};
  vector<int> ans = calcCosts(costs);
  for (auto &v : ans)
  {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}

// g++ -std=c++20 -o oa oa.cpp && ./oa

/*
6, 6, 3, 2, 2, 6

3 3 2 2 6

1 2 2 6

1 1 6
0 6

6 2 1 2 6

for arr [6,2,1,2,6]

   1st while [<6,4>,<6,0>,<2,2>,<2,3>,<1,2>]  finalCosts {}
   2nd while [<3,0>,<2,3>,<2,2>,<1,2>]        finalCosts { (3,0) }
   3rd while [<1,2>,<1,1>]                    finalCosts { (3,0) }

   after 3rd while pq only has [ (0,1) ]
   push it to finalCosts { (3,0), (0,1) }

   final answer is [3,0]
*/