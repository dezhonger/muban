struct Node {
    // isWord表示这个结点是否为一个单词的结尾
    // next[]表示这个结点的下一个26个字母结点
    bool isWord;
    Node *next[26];
    Node() : isWord(false) {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        } 
    }
};

class Trie {
public:
    Node * root;
    
    Trie() {
        root = new Node();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        Node *now = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            // 依次寻找每个字符
            // 如果所有下一个结点中没有当前字符，则增加新结点到下一个next[pos]
            int pos = word[i] - 'a';
            if (!now->next[pos]) {
                now->next[pos] = new Node();
            } 
            now = now->next[pos];
        }
        now->isWord = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // 查找单词
        Node *now = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            // 如果有下一个对应字符的结点，那么继续查找下一个结点
            // 如果没有下一个对应字符的结点，那么说明查找单词失败
            int ch = word[i] - 'a';
            if (now->next[ch]) {
                now = now->next[ch];
            }
            else {
                return false;
            }
        }
        // 如果每个字符都有且是完整单词，才说明查找单词成功
        return now->isWord;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // 查找前缀
        Node *now = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++) {
            // 如果有下一个对应字符的结点，那么继续查找下一个结点
            // 如果没有下一个对应字符的结点，那么说明查找前缀失败
            int ch = prefix[i] - 'a';
            if (now->next[ch]) {
                now = now->next[ch];
            }
            else {
                return false;
            }
        }
        return true;
    }
};
