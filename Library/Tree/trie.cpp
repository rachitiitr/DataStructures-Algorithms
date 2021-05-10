#include<iostream>
#include<vector>
#include<map>
#include<assert.h>
#include<algorithm>
using namespace std;

class Trie {
  map<char, Trie*> keys = {};
  int traversed = 0;
  bool isLeaf = 0;
public:
  void add(const string &word);
  int matchLength(const string &prefix); // returns the length of max prefix that exists in trie
  vector<string> autoComplete(const string &prefix);
  bool isPresent(const string &word);
};

template <typename T>
void assertVectors(const vector<T>& lhs, const vector<T>& rhs) {
  assert(lhs.size() == rhs.size());
  for (int i = 0; i < lhs.size(); i++)
  {
    assert(lhs[i] == rhs[i]);
  }
}

int main() {

  Trie t;

  vector<string> words = {"Rachit", "Ramesh", "Ankit", "Ankita", "Rachit1"};
  sort(words.begin(), words.end());
  for (auto w : words)
  {
    t.add(w);
  }

  assertVectors(t.autoComplete("Ra"), {"Rachit", "Rachit1", "Ramesh"});
  assertVectors(t.autoComplete("Rachit"), {"Rachit", "Rachit1"});
  assertVectors(t.autoComplete("Rachit1"), {"Rachit1"});
  
  assert(t.isPresent(""));
  assert(!t.isPresent("Racht"));
  assert(t.isPresent("Rachit"));
  assert(t.isPresent("Rachit1"));
  assert(!t.isPresent("Rachit12"));

  assert(t.matchLength("Ract") == 3);
  assert(t.matchLength("") == 0);

  return 0;
}


void Trie::add(const string &word) {
  
}

// returns the length of max prefix that exists in trie
int Trie::matchLength(const string &prefix) {

}

vector<string> Trie::autoComplete(const string &prefix) {

}
bool Trie::isPresent(const string &word) {

}
