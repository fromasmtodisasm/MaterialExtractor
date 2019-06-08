#ifndef MATERIALEXTRACTOR_H
#define MATERIALEXTRACTOR_H

#include <string>
#include <fstream>

struct Item
{
  char tag[4];
  uint32_t size;
  void *data;
  Item() :
    size(0),
    data(nullptr)
  {}
};

struct FileStruct
{
  Item *item;
  FileStruct *next, *child;
  FileStruct() :
    item(nullptr),
    next(nullptr), child(nullptr)
  {}
};

class MaterialExtractor
{
  std::string m_file;
  std::ifstream fin;
  std::ofstream fout;
  FileStruct *m_fileStruct;
public:
  MaterialExtractor();
  MaterialExtractor(std::string file);
  bool open();
  bool parse();
  bool doCommand(std::string command);
private:
  bool parse_internal(FileStruct *fileStruct);
};

#endif // MATERIALEXTRACTOR_H
