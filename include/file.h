#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <streambuf>
#include <bitset>
#include "huffman.h"

class File
{
private:
    Huffman *huffman;
    string text,compressed;
    void checkRecurrence();
    void generateNodes();
    void writeBit(string path);
    void saveText(string path);
    void compress();
    void decompress();
public:
    File();
    void openText(string path);
    void compress(string path);
    void decompress(string path);
};

#endif // FILE_H
