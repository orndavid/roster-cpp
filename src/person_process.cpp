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

void print_array(const ShiftsToCover& shifts){
  // Print an array object
  std::cout << "\t";
  for(int i=0; i<TIMESPAN; i++){
    if(i == TIMESPAN - 1){
      std::cout << shifts.days[i] << "\n";
    }else{
      std::cout << shifts.days[i] << ", ";
    }
  }
}



void set_info(std::vector<Person>& persons){
  // Problematic because it assumes incremental structure
  for(int shift=morning; shift!= COUNT; shift++){
    ShiftsToCover results;
    for(auto& person: persons)  {
      for(int i=0; i<TIMESPAN; i++){
        if(person.all_shifts(ShiftTypes(shift)).days[i]){
          results.days[i]++;
        }
      }
    }
    // Print shift type
    std::cout << "Shift type: " << shift << "\n";
    print_array(results);
  }
}
