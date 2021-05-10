#include<iostream>
#include<vector>
#include<map>
#include<assert.h>
#include<algorithm>
using namespace std;

class Trie {
  map<char, Trie*> m_keys = {}; // what are the next avail chars in trie node
  int m_traversed = 0; // how many words in trie are proper prefix
  bool m_isLeaf = 0; // is this trie node a leaf node i.e a word ends here
  int m_depth = 0; // depth of trie node

public:
  Trie() = default;
  Trie(int depth): m_depth(depth) {}
  int getDepth() { return m_depth; }
  bool isKeyPresent(const char &c) { return m_keys.find(c) != m_keys.end(); }
  bool isLeaf() { return m_isLeaf; }
  void setLeaf() { m_isLeaf = 1; }
  void add(const string &word);
  int matchLength(const string &prefix); // returns the length of max prefix that exists in trie
  vector<string> getAllWords();
  vector<string> autoComplete(const string &prefix);
  bool isPresent(const string &word);
  void addKey(const char &c);
  Trie *to(const char &c);
};

template <typename T>
void assertVectors(const vector<T>& lhs, const vector<T>& rhs) {
  // for(auto e: lhs)
  //   cout << e << " ";
  // cout << endl;
  // for(auto e: rhs)
  //   cout << e << " ";
  // cout << endl;
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

  assertVectors(t.autoComplete(""), words);
  assertVectors(t.autoComplete("Ra"), {"Rachit", "Rachit1", "Ramesh"});
  assertVectors(t.autoComplete("Rachit"), {"Rachit", "Rachit1"});
  assertVectors(t.autoComplete("Rachit1"), {"Rachit1"});
  assertVectors(t.autoComplete("Rachit12"), {});
  
  assert(t.isPresent(""));
  assert(!t.isPresent("Racht"));
  assert(t.isPresent("Rachit"));
  assert(t.isPresent("Rachit1"));
  assert(!t.isPresent("Rachit12"));

  assert(t.matchLength("Ract") == 3);
  assert(t.matchLength("") == 0);

  return 0;
}

// add the given char to current Trie node
void Trie::addKey(const char& c) {
  if(!isKeyPresent(c)) {
    m_keys[c] = new Trie(m_depth + 1);
  }
  m_traversed++;
}

Trie* Trie::to(const char& c) {
  if(!isKeyPresent(c)) {
    return NULL;
  }
  return m_keys[c];
}

// add the word to trie, duplicates are ignored
void Trie::add(const string &word) {
  Trie *cur = this;
  for (char c: word)
  {
    cur->addKey(c);
    cur = cur->to(c);
  }
  cur->setLeaf();
}

// returns the length of max prefix that exists in trie
int Trie::matchLength(const string &prefix) {
  Trie *cur = this;
  int match = 0;
  for (char c: prefix) {
    if (cur->isKeyPresent(c)) {
      match++;
      cur = cur->to(c);
    }
    else {
      return match;
    }
  }
  return match;
}

vector<string> Trie::getAllWords() {
  vector<string> ans = {};
  for (auto it: m_keys) {
    char c = it.first;
    Trie *t = it.second;
    if (t->isLeaf()) {
      ans.push_back(string("") + c);
    }
    for (auto word: t->getAllWords()) {
      ans.push_back(c + word);
    }
  }

  return ans;
}

vector<string> Trie::autoComplete(const string &prefix) {
  if (!isPresent(prefix)) {
    return {};
  }
  vector<string> ans = {};

  Trie *cur = this;
  for (char c: prefix) {
    if (cur->isKeyPresent(c)) {
      cur = cur->to(c);
    }
    else {
      break;
    }
  }

  if (cur->isLeaf()) {
    ans.push_back(prefix);
  }

  for (auto restWord: cur->getAllWords()) {
    ans.push_back(prefix + restWord);
  }
  return ans;
}

bool Trie::isPresent(const string &word) {
  return matchLength(word) == word.size();
}
