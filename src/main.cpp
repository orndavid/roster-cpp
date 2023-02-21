#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "individual.hpp"


int main(int argc, char** argv){
  std::cout << "Default build system works\n";
  // Configure the random generator
  srand(time(NULL));
  int no_persons = 10;

  // Create a set of class objects that represent 10 persons
  Person object;

  std::cout << object.count_days() << "\n";
  
  auto bool_day = object.get_day();
  for(int i=0; i<7; i++){
    object.generate_shifts();
  }

  object.stats();
  
  std::cout << "Finished\n";
}
