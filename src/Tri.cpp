#include "Tri.hpp"

void Tri::Insert(const std::string& word)
{
    TriNode* tmpNode = m_tri.get();
    for (std::string::size_type i = 0; i < word.size(); ++i)
    {
        if (tmpNode->next[word[i]] == nullptr)
        {
            tmpNode->next[word[i]] = std::make_unique<TriNode>(false);
            tmpNode                = tmpNode->next[word[i]].get();
            tmpNode->isWord        = ((i + 1) == word.size()) ? true : false;
        }
        else
        {
            tmpNode         = tmpNode->next[word[i]].get();
            tmpNode->isWord = ((i + 1) == word.size()) ? true : false;
        }

    }
}

bool Tri::Search(const std::string& word)
{
    TriNode* tmpNode = m_tri.get();
    for (std::string::size_type i = 0; i < word.size(); ++i)
    {
        bool shouldBeWord = ((i + 1) == word.size()) ? true : false;

        tmpNode = tmpNode->next[word[i]].get();

        if (tmpNode == nullptr)
        {
            return false;
        }

        if (tmpNode->isWord && shouldBeWord)
        {
            return true;
        }
    }

    return false;
}

void Tri::Traverse(std::vector<std::string>& allWords)
{
    if (m_tri == nullptr)
    {
        return;
    }

    std::vector<char>        word;

    for (auto const& [key, val] : m_tri->next)
    {
        word.push_back(key);
        inorder(val.get(), allWords, word);
        word.pop_back();
    }
}


void Tri::inorder(TriNode* tri, std::vector<std::string>& allWords, std::vector<char>& word)
{
    if (tri == nullptr)
    {
        return;
    }

    if (tri->isWord)
    {
        addWord(allWords, word);
    }

    for (auto const& [key, val] : tri->next)
    {
        word.push_back(key);
        inorder(val.get(), allWords, word);
        word.pop_back();
    }
}

void Tri::addWord(std::vector<std::string>& allWords, std::vector<char>& word)
{
    std::string tmp;
    for (const auto& c : word)
    {
        tmp += c;
    }
    allWords.push_back(tmp);
}
