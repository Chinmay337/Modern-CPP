#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
int main()
{
  std::cout << "========\nSorting in C++!\n========\n";

  std::cout << "By default: \nstd::sort(vec.begin(),vec.end()) sorts in "
               "Ascending Order\n\n";

  std::cout << "To sort in Descending Order -> \nstd::sort(vec.rbegin(), "
               "vec.rend())\n\n";

  // To Sort using Custom Comparator Function
  std::cout << "Sorting using CUSTOM COMPARATOR\n\nTo sort using Custom "
               "Comparator Function -> \n"
               "std::sort(vec.begin(), vec.end(), compare)\n\n";

  std::cout << "Example using Custom Comparator Function\n\n"
            << "std::vector<std::pair<int,int>> v = "
               "{{1,2},{2,3},{3,4},{4,5},{5,6}};\n\n"
            << "std::sort(v.begin(), v.end() , [](const auto a& ,const auto "
               "b&){\n\treturn "
               "b.second-a.second;};\n\n";

  // std::vector<std::pair<int, int>> vp = {
  //     {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
  // std::sort(vp.begin(), vp.end(),
  //           [](const auto &a, const auto &b) { return b.second - a.second;
  //           });

  // for (auto &i : vp) {
  //   std::cout << i.first << " " << i.second << std::endl;
  // }

  // Sorting Ascending and Descending
  std::vector<int> v = {19, 2, 1, 6, 22, 4, 2, 16};

  std::sort(v.begin(), v.end());
  std::cout << "Sorted Ascending: \n";
  for (const auto &i : v)
  {
    std::cout << i << " ";
  };

  std::sort(v.rbegin(), v.rend());
  std::cout << "\nSorted Descending: \n";
  for (auto i : v)
  {
    std::cout << i << " ";
  };

  // Sorting Pair - Default Behavior is to Sort by FIRST ELEMENT of Pair.
  std::vector<std::pair<int, std::string>> p = {
      {3, "A"}, {1, "B"}, {5, "C"}, {0, "D"}, {4, "E"}};
  std::cout << "\nInitial Vector of Pairs \n";
  for (auto i : p)
  {
    std::cout << i.first << " " << i.second << std::endl;
  }

  std::sort(p.begin(), p.end());
  std::cout << "\nSorted Pair Ascending: \n";
  for (const auto &i : p)
  {
    std::cout << i.first << " " << i.second << std::endl;
  };

  std::sort(p.rbegin(), p.rend());
  std::cout << "\nSorted Pair Descending: \n";
  for (const auto &i : p)
  {
    std::cout << i.first << " " << i.second << std::endl;
  };

  /*

      Sorting Pair using CUSTOM COMPARATOR FUNCTION

      vector<pair<int,int>> pair_vec = {{1,20},{3,4},{5,12},{7,7},{9,2}};

      bool compareSecond(const pair<int,int>& a , const pair<int,int>& b) {
        return a.second < b.second;
      }

      std::sort(pair_vec.begin(), pair_vec.end(), compareSecond);

      Vector is now Sorted by the second element.

      The Logic of the Comparator function is that state should be achieved.
      So if it is :
      a < b

      Then it checks that for any consecutive element (a,b) a<b should hold
     true.

  */

  std::vector<std::pair<int, std::string>> customPairSort = {
      {3, "A"}, {1, "Q"}, {5, "X"}, {0, "Z"}, {4, "A"}};
  std::cout
      << "\nInitial Vector of Pairs std::vector<std::pair<int,std::string>>\n";

  for (auto i : customPairSort)
  {
    std::cout << i.first << " " << i.second << std::endl;
  }
  std::sort(customPairSort.begin(), customPairSort.end(),
            [&customPairSort](const std::pair<int, std::string> &a,
                              const std::pair<int, std::string> &b)
            {
              return a.second < b.second;
            });

  std::cout << "\nSorted std::vector<std::pair<int,std::string>> using Custom "
               "Operator (Ascending): \n";
  for (const auto &i : customPairSort)
  {
    std::cout << i.first << " " << i.second << std::endl;
  };

  // SORTING a Custom Struct using Custom Comparator Function
  struct Elem
  {
    int id;
    int cost;
    int duration;
    Elem(int id, int cost, int duration) : id(id), cost(cost), duration(duration) {}
  };
  struct Compare
  {
    bool operator()(const Elem &Elem1, const Elem &Elem2) const
    {
      if (Elem1.id != Elem2.id)
        return Elem1.id < Elem2.id;
      if (Elem1.cost != Elem2.cost)
        return Elem1.cost < Elem2.cost;

      return Elem1.duration < Elem2.duration;
    }
  };
  std::vector<Elem> elems;
  elems.emplace_back(2, 2, 3);
  elems.emplace_back(1, 2, 3);
  elems.emplace_back(6, 2, 3);
  elems.emplace_back(10, 2, 3);
  elems.emplace_back(10, 2, 1);

  std::sort(elems.begin(), elems.end(), Compare());

  // print the sorted vector
  for (auto &elem : elems)
  {
    std::cout << elem.id << " " << elem.cost << " " << elem.duration << std::endl;
  }

  // For a Priority Queue - we pass the actual Type not the func itself
  std::priority_queue<Elem, std::vector<Elem>, Compare> pq;
  pq.emplace(2, 2, 3);
  pq.emplace(1, 0, 0);

  std::cout << pq.top().id << " " << pq.top().cost << " " << pq.top().duration << std::endl;

  return 0;
}