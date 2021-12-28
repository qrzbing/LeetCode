#include "global.hpp"

class Solution
{
    class Trie
    {

    public:
        vector<Trie *> child;
        bool isEnd;
        Trie() : child(26, nullptr), isEnd(false) {}
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
    };
    bool dfs(string &word, int index)
    {
        if (index == word.size())
            return true;
        Trie *node = trie;
        for (int i = index; i < word.size(); ++i)
        {
            char ch = word[i];
            int idx = ch - 'a';
            node = node->child[idx];
            if (!node)
                return false;
            if (node->isEnd)
                // 这里处理类似 cat 和 cats 的问题。
                // 假设输入为 catsdogscat
                // 最开始找到 cat，然后从 s 开始 dfs，返回 false
                // 接着继续循环，这时找到 cats，然后 dfs dog。
                if (dfs(word, i + 1))
                    return true;
        }
        return false;
    }
    Trie *trie = new Trie();

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.length() < b.length(); });
        vector<string> ret;
        for (string &word : words)
        {
            if (word.empty())
                continue;
            if (dfs(word, 0))
                ret.emplace_back(word);
            else
                trie->insert(word);
        }
        return ret;
    }
};