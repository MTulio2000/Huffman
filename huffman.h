#include <iostream>
#include <map>

using namespace std;

enum Type
{
    LEAF,
    TRUNK
};

enum Direction
{
    LEFT = 0,
    RIGHT = 1
};

typedef struct Node
{
    Type type = LEAF;
    char letter;
    int recurrency = 0;
    struct Node *subtree[2] = {nullptr,nullptr};
}Node;
typedef map<char,int> Recurrence;
typedef map<int,Node*> NodeRecurrency;
class HuffmanTree
{
private:
    NodeRecurrency nodes;
    Recurrence recurrence;
    Node *root;
    void addNode(Recurrence::iterator it);
public:
    void generateTree();
    int translateCode(char code[]);
    void addLetter(char letter);
};

class Huffman
{
private:
public:
    Huffman();
    

};