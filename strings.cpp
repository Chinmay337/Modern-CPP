#include <iostream>
using namespace std;

int main()
{
  cout << "Strings in C++!\n\n";

  string s1 = "hello@email.com";

  string domain = s1.substr(s1.find('@') + 1);

  cout << domain << "\n"
       << endl;

  cout << "To split a string at a particular character we can use the substr() function\n\n";

  cout << "To get the substring from index i to j, we can use s.substr(i, j - i + 1)\n\n";

  cout << "For string s = \"Hello@Memes\"\n"
       << "To get @Memes we can do\n\n s.substr(s.find('@'))\n\n";

  return 0;
}

// g++ -std=c++17 strings.cpp  -o s && ./s