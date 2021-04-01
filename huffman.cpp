#include "huffman.h"

Recurrence::iterator min(Recurrence::iterator begin,Recurrence::iterator end)
{
    Recurrence::iterator minimun = begin;
    while(++begin!=end)
        if(begin->second<minimun->second)
            minimun = begin;
    return minimun;
}

int HuffmanTree::translateCode(char code[])
{
    int character = -1;
    Node *node = this->root;
    int index = 0;
    while(node->type!=LEAF)
        node = node->subtree[code[index++]-'0'];
    if(node)
        character = node->letter;
    return character;
}

void HuffmanTree::addLetter(char letter)
{
    Recurrence::iterator it = recurrence.find(letter);
    if(it!=recurrence.end())
        it->second++;
    else
        recurrence.emplace(letter,1);
}

void HuffmanTree::addNode(Recurrence::iterator it)
{
    NodeRecurrency::iterator node = nodes.find(it->second);
    if(node == nodes.end());
}

void HuffmanTree::generateTree()
{
    Recurrence cpy = recurrence;
    while(cpy.size())
    {

    }
}