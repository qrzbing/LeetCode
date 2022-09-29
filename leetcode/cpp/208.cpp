#include "global.hpp"

class Trie
{
    vector<Trie *> child;
    bool isEnd;

public:
    Trie() : child(26), isEnd(false) {}

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (!node->child[ch])
                node->child[ch] = new Trie();
            node = node->child[ch];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->child[ch])
                node = node->child[ch];
            else
                return false;
        }
        if (node->isEnd)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->child[ch])
                node = node->child[ch];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */