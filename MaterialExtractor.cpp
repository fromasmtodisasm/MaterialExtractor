#include "MaterialExtractor.h"

using namespace std;

MaterialExtractor::MaterialExtractor()
{

}

MaterialExtractor::MaterialExtractor(std::string file)
  : m_file(file)
{

}

bool MaterialExtractor::open()
{
  fin.open(m_file.c_str(), ios_base::binary);
  return fin.is_open();
}

bool MaterialExtractor::parse()
{
  Item *item;
  m_fileStruct = new FileStruct();
  item = new Item();
  fin.read(reinterpret_cast<char*>(item->tag), sizeof(Item::tag));
  fin.read(reinterpret_cast<char*>(&item->size), sizeof(Item::size));

  item->data = new void *[item->size]();
  fin.read(reinterpret_cast<char*>(&item->data), item->size);

  m_fileStruct->item = item;
  return false;
}

bool MaterialExtractor::doCommand(std::string command)
{
  if (command == "quit")
    return false;
  return true;
}

bool MaterialExtractor::parse_internal(FileStruct *fileStruct)
{

}
