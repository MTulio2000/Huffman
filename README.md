# Huffman

Huffman's code is an optimal algorithm for compressing files.

The File class gives us 3 options:
  * openText -> to open the text that will be compress or decompress
  * compress -> to compress the opened text
  * decompress -> to decompress the opened text 

Its use is easy, you can use as the example below:
```c++
//creating new instance 
File *file = new File;
//opening text file in "files/text.txt"
file->openText("files/text.txt");
//compressing the opened text and saving in "files/compressed.txt"
file->compress("files/compressed.txt");
//opening text file in "files/compressed.txt"
file->openText("files/compressed.txt");
//decompressing the opened text and saving in "files/decompressed.txt"
file->decompress("files/decompressed.txt");
```
