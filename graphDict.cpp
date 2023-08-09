// class Solution {
// public:
// string alienOrder(vector<string>& words) {
//     if (!words.size()) return "";

//     unordered_map<char, unordered_set<char>> graph;
//     unordered_map<char, int> indeg;

//    if (!buildGraph(words, graph, indeg))
//        return "";

//     queue<int> q;
//     for (auto& i : indeg)
//         if (!i.second) q.push(i.first);

//     string result = "";

// // Pop char with 0 incoming edges - decrement its' outgoing edges -
// // after decrement if the edges have 0 - add to queue
//     while (!q.empty()) {
//         char v = q.front();
//         q.pop();
//         result += v; // "w"

// // Then decrement it's edge and if it's 0 - this is next
// // --indeg[p] is a prefix operator -
// // If indeg[p] is 1 - it will return true after --indeg[p]
//         for (char p : graph[v])
//             if (--indeg[p] == 0) q.push(p);
//     }

//     for (auto& v : indeg)
//         if (v.second > 0) return "";

//     return result;
// }

// bool buildGraph(vector<string>& words, unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& indeg) {

//     for (auto& w : words)
//         for (char c : w) indeg[c] = 0;

// // loop thru every w.i and w.i+1
//     for (int i = 0; i < words.size() - 1;++i) {
//         string w1 = words[i], w2 = words[i+1];

// // this below means the dictionary is not Possible
// // w1,w2 -"dictgo" and "dict" then "dict should be before dictgo.
// // Hence , we return false because this is a violation of the inputs
//         if (w1.size() > w2.size() && w1.rfind(w2, 0) == 0)
//             return false;

//         int sz = min(w1.size(), w2.size());

// // Graph is Adc List of char->set of nextchars
// // Indeg is a Map of Char->incoming edges
//         for (int j = 0;j < sz;++j) {

//             if (w1[j] != w2[j]) {

//                 auto& adj = graph[w1[j]];

//                 if (adj.count(w2[j]) == 0) {
//                     graph[w1[j]].insert(w2[j]);
//                     indeg[w2[j]]++;
//                 }
// // Once first char mismatch - remaining order doesnt tell us anything
// // So we break loop for iteating over chars of w.i and w.i+1 (J LOOP)
//                 break;
//             }
//         }
//     }

//     return true;
// }
// };
