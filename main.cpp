#include <iostream>
#include "MaterialExtractor.h"

using namespace std;

int main()
{
  int status = EXIT_FAILURE;
  std::string file;
  cin >> file;
  MaterialExtractor extractor(file);
  if (extractor.open())
  {
    if (extractor.parse())
    {
      status = EXIT_SUCCESS;
      cout << "File parsed" << endl;

    }
    else {
      cout << "Can't parse file" << endl;
    }
  }
  else {
    cout << "Can't open file" << endl;
  }



  return status;
}
