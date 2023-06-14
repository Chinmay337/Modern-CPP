#include <iostream>
#include <sstream>

int main()
{
     using namespace std;

     cout << "Strings in C++!\n\n";

     string s1 = "hello@email.com";

     string domain = s1.substr(s1.find('@') + 1);

     cout << domain << "\n"
          << endl;

     cout << "To split a string at a particular character we can use the substr() function\n\n";

     cout << "To get the substring from index i to j, we can use s.substr(i, j - i + 1)\n\n";

     cout << "For string s = \"Hello@Memes\"\n\n"
          << "To get @Memes we can do\n\n s.substr(s.find('@'))\n\n";

     cout << "========================\n\n";

     cout << "Splitting a String into a Vector\n\n";

     string longStr = "Splitting By  Spaces!";

     std::istringstream splitStr(longStr);
     std::string word;

     while (splitStr >> word)
     {
          cout << "Word: " << word << endl;
     }

     cout << "Splitting a String based on a Character\n\n";

     string leadingStr = "abc-123444-xxxx!->>>  ";
     std::istringstream ss(leadingStr);

     std::string word2;

     while (std::getline(ss, word2, '-'))
     {
          cout << "Word: " << word2 << endl;
     }

     cout << "To split a String into a Vector of Strings\n\n";

     cout << "std::istringstream can be used\n\n";

     cout << "string s = \"aa bqw c12 dz e \"\n\n"
          << "To get [aa,bqw,c12,e] we can do\n\n";

     cout << "std::istringstream ss(s);\n\n"
          << "std::vector<std::string> result;\n\n"
          << "for (std::string s; ss >> s;)\n\n"
          << "result.push_back(s);\n\n"
          << "========================\n\n"
          << "for(std::string s ; ss >> s;)\n\n"
          << "Creates a Temporary Variable s and this loop runs until a string can \nsuccessfully be "
          << "inserted into s from the input stream\n\n";

     cout << "========================\n\n";

     return 0;
}

// g++ -std=c++17 strings.cpp  -o s && ./s