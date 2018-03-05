#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int initPixel();

int main()
{
  int pixels1[1024][786];
  int pixels2[1024][786];
  srand(time(NULL));
  clock_t time;
  time = clock();
  for(int row=0; row < 768; row++)
    for(int col=0; col <1024; col++)
      pixels1[col][row] = initPixel();
  time = clock() - time;
  cout << ((float)time/CLOCKS_PER_SEC) << " seconds for unefficient caching" << endl;

  time = clock();
  for(int col=0; col < 1024; col++)
    for(int row=0; row < 768; row++)
      pixels1[col][row] = initPixel();
  time = clock() - time;
  cout << ((float)time/CLOCKS_PER_SEC) << " seconds for efficient caching" << endl;
  
  return 0;
}

int initPixel()
{
  return rand() % 100 + 1;
}
