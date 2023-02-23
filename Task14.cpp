#include <iostream>
#include <fstream>
using namespace std;

void readlines();

int main()
{

  char line;
  int count = 0;
  fstream File;
  File.open("Read Alphabets.txt", ios::in);
  while (!File.eof())
  {
    File >> line;

    if (line == 'T')
    {
      count++;
    }
  }
  File.close();
  cout << count;
}