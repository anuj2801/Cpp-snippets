#include<bits/stdc++.h>
using namespace std;

//Building with total m characters,n vertices,and k(k=26) distinct characters
// Total Complexity for Building entire tree with failure link(suffix links) : O(n log k)
// Access Time for Go() : O( log k )
class Aho_corasik{
 
    class Node {
        public:
        map<char, long long> to,go;  // use count function to check. as it will not create any node no.[not consume space]
        // to -> for direct link [Node no. to which it is directly connected to, using ch]
        // go -> includes to link and also contains failure link  [this go will be in actual use]
        long long link=-1; //will contain failure link Node no. if calculated, otherwise -1
        long long parent=0;     // parent of current node
        char edge=0;         // using which character parent node comes to the current node [ie, edge character]
        long long leaf=-1;    // contains i if ith string ends at this node, otherwise -1
    };
 
    vector<Node> trie;
 public:
    Aho_corasik()
    {
        trie.emplace_back();// pushing an empty/default Node
    }
   
    void bulid(vector<string> &s,long long n)
    {
        for(int i=0;i<n;i++)
         add(s[i],i);
    }
    long long add(string &s, long long i) 
    {
        long long v=0;  // root node
        for(auto&c:s) 
        {
            if(!trie[v].to.count(c)) 
            {
                trie[v].to[c]=trie.size(); // new node no will be at last
                trie.emplace_back();   // adding new node
                trie.back().parent=v;      // set parent to v
                trie.back().edge=c;    // set edge as c
            }
            v=trie[v].to[c];          // move to the next node
        }
        trie[v].leaf=i;     // ith string ends at this leaf node
        return v;
    }
 
    void build_suf_links() 
    {
        // Using BFS
        queue<long long> q;
        q.push(0);
        while(!q.empty()) 
        {
            long long v=q.front();
            q.pop();
            link(v);    // creating failure link for Current Node v
            for(auto&child:trie[v].to)
                q.push(child.second);      // adding next nodes   
        }
    }
 
    long long link(long long v) 
    {
        if(trie[v].link!=-1) 
         return trie[v].link;      // if link has already calculated

        if(v==0 || trie[v].parent==0) 
         return trie[v].link=0;       // root node and its childs failure link will connect to root node only.[base condition]

        trie[v].link=go( link(trie[v].parent) , trie[v].edge ); // aho-corasick suff_link logic

        return trie[v].link;
    }




// go function will be mainly used. and using leaf we can check if some string ends at current character
    long long go(long long v, char c)    // returns which node v shall go if it read char c
    {
        if(trie[v].go.count(c)) 
          return trie[v].go[c];    

        if(trie[v].to.count(c)) 
         return trie[v].go[c]=trie[v].to[c];   //as go includes to

        if(v==0)                  // if root node
         return trie[v].go[c]=0; // failure link connects to root node
        return trie[v].go[c]=go( link(v), c); // if this node v doesn't have anything to go using char c, then recursively find where it will go by its link and c.[Memoization]
       
    }
    long long leaf(long long v)
    {
        return trie[v].leaf;
    }
};
int main()
{
    
    return 0;
}