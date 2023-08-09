#include <iostream>
#include <vector>
#include <string>

/*
Suppose you have two strings, find all the palindromes that can be made using letters of these strings.

From these palindromes, select one from each set that when combined and rearranged, produces the largest palindrome possible.

If there are multiple palindromes of that length, choose the alphabetically smallest of them.

Example 1: input: s1 = 'adaab', s2 = 'cac' output: 'aaccaa'.

Explanation:
Characters ['a', 'a', 'a'] can be picked from the first string to form the palindrome 'aaa'.
Characters ['c', 'c', 'a'] can be picked from the second string to form the palindrome 'cac' and merged with 'aaa' to form 'aaccaa'.

1. Get Freq Counter of s1 and s2
2. For shorter string - check if palindrome can be formed using all chars from shorter string

vector<string> canPalindromeBeFormed(string shorter , int windowSize) logic -
3. If s2 is 'cca' - in s1 check for even charCounts (c:2) - is there a char with freq 2 in s1?
4. Check if there are enough chars in s1 to match even chars in s2
5. Once we check even frequencies in s2 and there is a matching even char in s1
6. If no odd strings in s2 - createPalindrome() from s2 chars and return it
7. If there are chars in s2 with an odd count remaining - see if there is the same char in s1 to make it even
8. If not - see if there is the char count is 1 = if so we can form a palindrome.
9. If more than 1 char with odd count or 1 char has odd count > 1 - cannot form palindrome

canPalindromeBeFormed("aca",2) returns ['a','a'] after checking if there is a freq of count 2 in s2 and corresponding in s1

createPalindrome(['a','a']) returns ['a','a','a','a'] - which is the answer


vector<string> longestCommonPalindrome(string s1 , string s2) {

  string& shorter;
  if (s1.size() > s2.size()) shorter=s2;
  else shorter = s1;

  int n = min(s1.size(),s2.size());

  for (int i=n;i>=0;--i) {
    vector<char> chars = canPalindromeBeFormed(shorter,i);
    return createPalindrome(chars);
  }
  // return empty vector if no palindrome can be formed
}

*/
using namespace std;

class Solution
{
public:
  vector<string> longestCommonPalindrome(string s1, string s2)
  {
  }
  bool isPalindrome(string s1)
  {
    int l = 0;
    int r = s1.size() - 1;
    while (l < r)
    {
      if (s1[l] != s1[r])
        return false;
      l++;
      r--;
    }
    return true;
  }

  bool canPalindromeBeFormed(string s)
  {
    /*
    create Character Counter

    int n = size(s);

    If n is even - every character must have an even count

    If n is odd - every character must have an even count except one character

    if (n % 2)  -> every charCount not modded by 2 ? return false : return true

    else -> every charCount modded by 2 && (num charCounts <= 1)  ? return true : return false


    */
  }
};

int main()
{

  cout << "Strings in C++!\n\n";
  string s1 = "aaa";
  string s2 = "abbba";
  Solution sol = Solution();

  if (sol.isPalindrome(s2))
  {
    cout << "Is Palindrome\n";
  }
  else
  {
    cout << "Not Palindrome\n";
  }

  return 0;
}

// g++ -std=c++20 -o legoat legoat.cpp && ./legoat
