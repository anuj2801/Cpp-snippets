#include<bits/stdc++.h>
using namespace std;
class Trie
{
    public:
    class Node
    {  public:
        bool end;// true when a word ends there
        Node* next[26];
        Node()
        {
            end=false;
            for(int i=0;i<26;i++)
            next[i]=NULL;
        }
    };
                    //         trie     //trie have pointers to a to z,and those nodes too have pointers to a to z and so on 
                    //     /  / ....\  \
                    //    a  b ..... y  z
                    //      /..\
                    //     a ...z
                                 
    Node *trie;
    Trie()
    { 
        trie=new Node();
    }
    void insert(string word)
    {
        int i=0;
        Node* it=trie; 
        while(i++<word.size())
        {  if(it->next[word[i]-'a']==NULL)
              it->next[word[i]-'a']=new Node();//creating space for that char
           it=it->next[word[i]-'a'];
        }
        it->end=true;
    }
    bool search(string word)
    {   int i=0;
        Node* it=trie; 
        while(i++<word.size())
        {   if(it->next[word[i]-'a']==NULL)
             return false;
            it=it->next[word[i]-'a'];
        }
        return it->end; //if word ends here returns true,else returns false
    }
};
int main()
{  Trie myTrie;
   myTrie.insert("ak");
   cout<<myTrie.search("ak");

   
    return 0;
}