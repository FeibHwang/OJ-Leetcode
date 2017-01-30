/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/

/*
construct a trie
*/


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new dict_tree();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert_word(head,word, 0);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_word(head,word,0);
    }


private:

    struct dict_tree
    {
        bool isword;
        vector<dict_tree*> next_letter;
        dict_tree() : isword(false),next_letter(vector<dict_tree*>(26,nullptr)){};
    };
    
    dict_tree* head;
    
    void insert_word(dict_tree* head, string word, int i)
    {
        if(i == word.length())
        {
            head->isword = true;
            return;
        }
        if(!head->next_letter[word[i]-'a'])
        {
            head->next_letter[word[i]-'a'] = new dict_tree();
        }
        insert_word(head->next_letter[word[i]-'a'],word,i+1);
    }
    
    bool search_word(dict_tree* head, string word, int i)
    {
        if(!head) return false;
        if(i == word.size()) return head->isword;
        if(word[i]=='.')
        {
            for(int k = 0; k < 26; ++k)
            {
                if(search_word(head->next_letter[k],word,i+1))
                    return true;
            }
        }else{
            if(head->next_letter[word[i]-'a']!=nullptr)
            {
                return search_word(head->next_letter[word[i]-'a'],word,i+1);
            }else{
                return false;
            }
        }
        return false;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */