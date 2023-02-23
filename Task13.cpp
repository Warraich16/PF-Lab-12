#include <iostream>

#include <fstream>

using namespace std;

int count =0;

void readlines();
int main()
{
    
    readlines();
}

void readlines()
{   
    string line;
  fstream file1;
  file1.open("newFile.txt",ios::in);
  
 while(getline(file1,line))
 {
     if(line.length() < 4)
 {
      cout << line;
 }

 }
 file1.close();
 
  }







