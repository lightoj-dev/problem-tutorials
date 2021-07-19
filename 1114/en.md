# LOJ 1114 - Easily Readable

---

**Problem Statement** : We are given some words in a dictionary and some sentences. The sentences may or may not comprise of words from the dictionary. Our task is to determine how many different sentences can we make from the words in those given sentences which follow the following rule:

- The first and last letters of each word remain unmodified and all the characters in the middle can be reordered freely.

  Let's say, we have a sentence `abcd efg`, then there are two combinations of the word `abcd` possible with first and last character unchanged i.e `abcd`, `acbd` - if both the words are found in the dictionary, we can say, we can form two different sentences - `abcd efg` and `acdb efg`. If, only `acbd` is present in the dictionary, then we can form only one sentence - `acdb efg`.

**Solution Approach**: This one is a straight-forward implementation of Trie except memory allocated with `new` in heap results in TLE due to large dataset. So we follow an array implementation of Trie in C++.

This implementation follows the Trie implementation in [GeeksForGeeks](https://www.geeksforgeeks.org/trie-insert-and-search/)

Our Trie is a collection of the following structure:

```cpp
struct TrieNode {
 public:
  int ch[ALPHABET_SIZE];
  int totalOccurrencesOfFinalCharacter;
};
```

We have to keep in mind the followings for this particular problem:

- As we could guess already, we need to push each word in Trie with the characters except the first and the last one sorted. We would do the same for the words in the given sentences too.

- We declare a global variable `totalNodes` to keep track of the nodes. It starts from `0` for each test case. As we traverse the words character by character, we increase its value by `1`. We store its value in `ch[]`, which works as a pointer to the next node.

- We declare another global variable, `trie`, which is a collection of `TrieNode`, each entry in this collection knows where to look for the next node via `ch[]`.

- `totalOccurrencesOfFinalCharacter` is used to keep track of the number of occurrences of the final character in a word.

Let's take an example string `aceg` and see how we can build a Trie:

Global variables: `trie` and `totalNodes`
We calculate index of a character using `findIndex` function.

- character - `a`: index `0`, `trie[0].ch[0]` = 1
- character - `c`: index `2`, `trie[1].ch[2]` = 2
- character - `e`: index `4`, `trie[2].ch[4]` = 3
- character - `g`: index `6`, `trie[3].ch[6]` = 4

---

## Code :

```cpp
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 52;
const int MAX_TRIE_SIZE = 1e5 + 10;

struct TrieNode {
 public:
  int ch[ALPHABET_SIZE];
  int totalOccurrencesOfFinalCharacter;
};

int totalNodes;
vector<TrieNode> trie;

void initializeTrie() {
  totalNodes = 0;
  trie.resize(MAX_TRIE_SIZE);
}

int findIndex(char character) {
  if (islower(character)) {
    return character - 'a';
  }

  return character - 'A' + 26;
}

void insert(string key) {
  int currentNode = 0;
  for (auto s : key) {
    int index = findIndex(s);

    if (!trie[currentNode].ch[index]) {
      trie[currentNode].ch[index] = ++totalNodes;
    }

    currentNode = trie[currentNode].ch[index];
  }
  trie[currentNode].totalOccurrencesOfFinalCharacter += 1;
}

void sortWordExceptFirstAndLastCharacter(string &word) {
  if (word.size() <= 3) {
    return;
  }

  return sort(word.begin() + 1, word.end() - 1);
}

void buildTrie(vector<string> &words) {
  for (auto word : words) {
    sortWordExceptFirstAndLastCharacter(word);
    insert(word);
  }
}

int findPossibleSentences(string word) {
  int currentNode = 0;
  sortWordExceptFirstAndLastCharacter(word);

  for (auto s : word) {
    int index = findIndex(s);

    if (!trie[currentNode].ch[index]) {
      return 0;
    } else {
      currentNode = trie[currentNode].ch[index];
    }
  }

  return trie[currentNode].totalOccurrencesOfFinalCharacter;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  // ifstream cin("a.txt");

  int cases, totalWords, totalSentences;
  string word, sentence;

  cin >> cases;
  vector<string> words;

  for (int i = 1; i <= cases; i++) {
    initializeTrie();
    cin >> totalWords;

    while (totalWords--) {
      cin >> word;
      words.emplace_back(word);
    }

    buildTrie(words);

    cin >> totalSentences;
    cout << "Case " << i << ":" << endl;
    cin.ignore();

    while (totalSentences--) {
      int possibleSentences = 1;

      getline(cin, sentence);
      stringstream ss(sentence);

      while (ss >> word) {
        possibleSentences *= findPossibleSentences(word);
      }

      cout << possibleSentences << endl;
    }

    words.clear();
    trie.clear();
  }

  return 0;
}
```
