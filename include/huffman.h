#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#define ASCII 127

using namespace std;
typedef map<char,string> Table;

enum Side:int
{
    LEFT = 0,
    RIGHT = 1
};

typedef struct Node
{
    char letter;
    int frequence;
    struct Node *child[2]={nullptr,nullptr};
}Node;

class Huffman
{
private:
    Table table;
    vector<Node*> nodes;
    void makeBits(Node *n,string bit = "");
    vector<int> alphabet;
    string text;
    void makeNode(int c,int freq);
    void makeBits();
    void buildTree();
    void setText(string txt);
    void generateNodes();
    int getMin(vector<Node*> tree);
public:
    string decompress(string code);
    string compress(string code);
};

#endif // HUFFMAN_H
