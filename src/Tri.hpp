#ifndef TRI_HPP
#define TRI_HPP

#include <string>
#include <map>
#include <memory>
#include <vector>

class Tri
{
	// Tri Node Data Structure
	private:
		struct TriNode 
		{
			TriNode(void) = delete;
			TriNode(bool _isWord) : isWord{_isWord} {}
			~TriNode(void) = default;

			std::map<char, std::unique_ptr<TriNode>> next;
			bool isWord = false;
		};

	public: 
		Tri() = default;
		void Insert(const std::string& word);
		bool Search(const std::string& word);
		void Traverse(std::vector<std::string>& allWords);
		
	private:
		void addWord(std::vector<std::string>& allWords, std::vector<char>& word);
		void inorder(TriNode* tri, std::vector<std::string>& allWords, std::vector<char>& word);

        private:
		std::unique_ptr<TriNode> m_tri = std::make_unique<TriNode>(false);

};
#endif
