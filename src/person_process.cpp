#include "person_process.hpp"
#include "ERRORS.hpp"

void run_8_values(Person& person){
  for(int i=0; i<8; i++)
    person.generate_shifts();
}


int random_from_selection(std::vector<int>& vector){
  return 0;
}
