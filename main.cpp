#include "include/file.h"

int main()
{
    File *file = new File;//creating File object
    file->openText("files/text.txt");//openText that we'll be compress
    file->compress("files/compressed.txt");//compressing text and saving in compress.txt
    file->openText("files/compressed.txt");//open text that we'll be decompress
    file->decompress("files/decompressed.txt");//decompressing text and saving in decompress.txt
    return 0;
}
