#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <SFML/Graphics.hpp>

void log_help(std::ostream& os){
  os<<"Provide an odd number as the size of the square image to be generated\n";
}

//temporary part, just to check the function works properly
//the faulty logic will then be replaced
int ulam_index(int x, int y, int s){
  return x+y*s ;
}

sf::Color paint(int hand){
  sf::Color brushes[] = {
    sf::Color::Yellow, sf::Color::Magenta
  };

  if(hand >= 2)
    return sf::Color::White;
  else
    return brushes[hand];//because factor count starts from 2
}

unsigned int factor_count(unsigned int nr){
  if(1 == nr)
    return -1;//give a large factor count because it is not a prime
  int result=2;
  for(int i=2; i < nr/2; i++)
    if(nr % i == 0){
      result++;
      for(;nr%i==0;nr/=i); //extract all of the factors
      i=2;
    }
  return result;
}

int main(int argc, char *argv[]){
  if(2 == argc && 0 == strcmp(argv[1], "help")){
    log_help(std::cout);
    return 1;
  }
  if(2 != argc){
    std::cerr<<"Incorrect argument count\n";
    log_help(std::cerr);
    return -1;
  }
  //Program waits for first argument to be a number, but doesn't check it
  int sz = atoi(argv[1]);
  if(sz % 2 == 0){
    std::cerr<<"Wrong parity\n";
    log_help(std::cerr);
    return -2;
  }
  sf::Image img;
  img.create(sz, sz, sf::Color::White);
  for(int x=0; x < sz; x++)
    for(int y=0; y < sz; y++)
      img.setPixel(x, y, paint(factor_count(ulam_index(x, y, sz)) - 2));
  char file[311];
  sprintf(file, "data/%d.png", sz);
  img.saveToFile(file);
  return 0;
}
