class TrieNode {
public:
    TrieNode* children[10]; // Assuming digits 0-9
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int number) {
        TrieNode* current = root;
        std::string strNumber = std::to_string(number);

        for (int i = 0; i < strNumber.length(); ++i) {
            int digit = strNumber[i] - '0';
            if (current->children[digit] == nullptr) {
                current->children[digit] = new TrieNode();
            }
            current = current->children[digit];
        }
        current->isEnd = true;
    }

    int longestCommonPrefixLength(int number) {
        TrieNode* current = root;
        std::string strNumber = std::to_string(number);
        int lenNumber = 0;

        for (int i = 0; i < strNumber.length(); ++i) {
            int digit = strNumber[i] - '0';
            if (current->children[digit] == nullptr) {
                return lenNumber;
            }
            current = current->children[digit];
            lenNumber++;
        }

        return lenNumber;
    }
};

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& array1, std::vector<int>& array2) {
        Trie trie;
        int maxLength = 0;

        for (int number : array1) {
            trie.insert(number);
        }

        for (int number : array2) {
            maxLength = std::max(maxLength, trie.longestCommonPrefixLength(number));
        }

        return maxLength;
    }
};