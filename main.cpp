#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <SFML/Graphics.hpp>

void log_help(std::ostream& os){
  os<<"Provide the size of the square image to be generated\n";
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
  std::cout<<"Normal behaviour\n";
  return 0;
}
