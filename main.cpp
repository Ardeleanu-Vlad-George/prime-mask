#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <SFML/Graphics.hpp>

void log_help(std::ostream& os){
  os<<"Provide the size of the square image to be generated\n";
}

int is_prime(int nr){
  for(int i=2; i < nr/2; i++)
    if(nr % i == 0)
      return 0;
  return 1;
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
  sf::Image img;
  img.create(sz, sz);
  for(int i=0; i < sz*sz; i++)
    if(is_prime(i))
      img.setPixel(i%sz, i/sz, sf::Color(150, 150, 150));
  char file[311];
  sprintf(file, "data/%d.png", sz);
  img.saveToFile(file);
  return 0;
}
