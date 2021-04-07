#include "../include/huffman.h"

void Huffman::makeNode(int c, int freq)
{
    table.emplace(c,"");
    Node *n = new Node;
    n->frequence = freq;
    n->letter = c;
    nodes.push_back(n);
}

void Huffman::makeBits()
{
    makeBits(nodes[0],"");
}

void Huffman::setText(string txt)
{
    text = txt;
    alphabet = vector<int>(ASCII,0);
    for(int i = 0; i < (int)text.size();i++)
        alphabet[text[i]]++;
}

void Huffman::generateNodes()
{
    int position;
    while(true)
    {
        position = distance(alphabet.begin(),max_element(alphabet.begin(),alphabet.end()));
        if(!alphabet[position])break;
        makeNode(position,alphabet[position]);
        alphabet[position] = 0;
    }
}

string Huffman::decompress(string code)
{
    int index = 0;
    Node *n;
    text = "";
    while(index<(int)code.size())
    {
        n = nodes[0];
        while(index<(int)code.size())
        {
            n = n->child[code[index++]-'0'];
            if(!(n->child[LEFT]||n->child[RIGHT]))
            {
                text+=n->letter;
                break;
            }
        }
    }
    return text;
}

string Huffman::compress(string code)
{
    setText(code);
    generateNodes();
    buildTree();
    makeBits();
    string compressed = "";
    for(int i = 0; i < (int)text.size();i++)
        compressed += table[text[i]];
    return compressed;
}

void Huffman::makeBits(Node *n, string bit)
{
    if(n!=nullptr)
    {
        if(!(n->child[LEFT]||n->child[RIGHT]))
            table[n->letter] = bit;
        else
        {

            makeBits(n->child[RIGHT],bit+"1");
            makeBits(n->child[LEFT],bit+"0");
        }
    }
}

int Huffman::getMin(vector<Node*> tree)
{
    int p = 0,smaller = (int)INFINITY;
    for(int i = 0; i < (int)tree.size();i++)
    {
        if(tree[i]->frequence<smaller)
        {
            smaller = tree[i]->frequence;
            p = i;
        }
    }
    return p;
}

void Huffman::buildTree()
{
    reverse(nodes.begin(),nodes.end());
    vector<Node*> tree;
    while(nodes.size()!=1)
    {
        tree = nodes;
        nodes.clear();
        int p,smaller;
        while(tree.size())
        {
            if(tree.size()>1)
            {
                Node *n = new Node;
                p=0;
                for(int i = 0; i < 2;i++)
                {
                    p = getMin(tree);
                    n->child[i] = tree[p];
                    tree.erase(tree.begin()+p);
                }
                n->frequence = n->child[LEFT]->frequence+n->child[RIGHT]->frequence;
                nodes.push_back(n);
            }
            else
            {
                nodes.push_back(tree[0]);
                tree.erase(tree.begin());
            }
        }
    }
}
