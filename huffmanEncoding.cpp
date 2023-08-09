#include <iostream>
#include <queue>
#include <unordered_map>
#include <bitset>

class Node
{
public:
  char data;
  int freq;
  Node *left;
  Node *right;

  Node(char data, int freq, Node *left = nullptr, Node *right = nullptr)
  {
    this->data = data;
    this->freq = freq;
    this->left = left;
    this->right = right;
  }
};

struct Compare
{
  bool operator()(Node *l, Node *r)
  {
    return l->freq > r->freq;
  }
};

void Encode(Node *root, std::string str, std::unordered_map<char, std::string> &huffmanCode)
{
  if (root == nullptr)
    return;

  if (root->left == nullptr && root->right == nullptr)
  {
    huffmanCode[root->data] = str;
  }

  Encode(root->left, str + "0", huffmanCode);
  Encode(root->right, str + "1", huffmanCode);
}

void Decode(Node *root, int &index, std::string str)
{
  if (root == nullptr)
    return;

  if (root->left == nullptr && root->right == nullptr)
  {
    std::cout << root->data;
    return;
  }

  index++;

  if (str[index] == '0')
    Decode(root->left, index, str);
  else
    Decode(root->right, index, str);
}

void BuildHuffmanTree(std::string text)
{
  std::unordered_map<char, int> freq;
  for (char ch : text)
  {
    freq[ch]++;
  }

  std::priority_queue<Node *, std::vector<Node *>, Compare> pq;

  for (auto pair : freq)
  {
    pq.push(new Node(pair.first, pair.second));
  }

  while (pq.size() != 1)
  {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    int sum = left->freq + right->freq;
    pq.push(new Node('\0', sum, left, right));
  }

  Node *root = pq.top();

  std::unordered_map<char, std::string> huffmanCode;
  Encode(root, "", huffmanCode);

  std::cout << "Huffman Codes:\n";
  for (auto pair : huffmanCode)
  {
    std::cout << pair.first << " " << pair.second << '\n';
  }

  std::cout << "\nOriginal string:\n"
            << text << '\n';

  std::string str = "";
  for (char ch : text)
  {
    str += huffmanCode[ch];
  }

  std::cout << "\nEncoded string:\n"
            << str << '\n';

  std::cout << "\nDecoded string:\n";
  if (str.length() && root)
  {
    int index = -1;
    while (index < (int)str.size() - 1)
    {
      Decode(root, index, str);
    }
  }
}

int main()
{
  std::string url = "https://www.example.com";
  BuildHuffmanTree(url);
  return 0;
}

/*
g++ -std=c++20 -o huffmanEncoding huffmanEncoding.cpp && ./huffmanEncoding

Huffman Codes:
x 11111
l 11110
p 000
c 10100
/ 1101
m 010
o 0110
t 001
: 0111
a 10111
w 100
s 10101
. 1110
h 10110
e 1100

Original string:
https://www.example.com

Encoded string:
10110001001000101010111110111011001001001110110011111101110100001111011001110101000110010

Decoded string:
https://www.example.com

str = "example"

Decode("example")

'e': '0'
'x': '10'
'a': '110'
'm': '1110'
'p': '11110'
'l': '11111'




*/