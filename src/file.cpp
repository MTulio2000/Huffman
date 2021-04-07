#include "../include/file.h"

int current_bit = 7;
unsigned char bit_buffer = 0;

File::File()
{
    huffman = new Huffman;
}

void File::writeBit(string path)
{
    auto write = [this](int bit)
    {
        bit_buffer |= (bit<<current_bit);
        if (!current_bit)
        {
            text+=bit_buffer;
            bit_buffer = 0,current_bit = 8;
        }
        current_bit--;
    };
    text = "";
    for(int i = 0; i < (int)compressed.size();i++)
        write(compressed[i]-'0');
    for(int i = 0; i < (int)compressed.size()%8;i++)
        write(0);
    saveText(path);
}

void File::saveText(string path)
{
    std::ofstream out(path);
    out << text;
    out.close();
}

void File::openText(string path)
{
    ifstream t(path);
    text = string((istreambuf_iterator<char>(t)),istreambuf_iterator<char>());
}

void File::compress(string path)
{
    compressed = huffman->compress(text);
    writeBit(path);
}

void File::decompress(string path)
{
    string bits = "";
    for(int i = 0; i < (int)text.size();i++)
        bits+=bitset<8>(text.c_str()[i]).to_string();
    text = huffman->decompress(bits);
    saveText(path);
}
