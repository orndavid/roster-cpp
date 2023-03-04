#include "person_process.hpp"
#include "ERRORS.hpp"

#include <cstdlib>

void run_8_values(Person& person){
  for(int i=0; i<8; i++)
    person.generate_shifts();
}


int random_from_selection(std::vector<int>& vector){
  return vector[(rand() % vector.size())];
}
