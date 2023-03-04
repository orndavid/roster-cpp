#include <iostream>
#include <stdlib.h> // srand (need to move functionality somewhere else)
#include <time.h> // time
#include <vector>
#include <algorithm>
#include <functional>

#include "person_process.hpp" // Includes Person


int main(int argc, char** argv){
  std::cout << "Select computing";
  // Configure the random generator
  srand(time(NULL));
  constexpr int no_persons = 10;

  // Create a set of class objects that represent 10 persons
  std::vector<Person> persons(no_persons);
  for(int i=0; i<no_persons; i++){
    persons[i] = Person(i);
  }

  std::cout << "Number of persons: " << persons.size() << "\n";
  std::for_each(persons.begin(), persons.end(), run_8_values);
  std::for_each(persons.begin(), persons.end(), std::mem_fn(&Person::stats));
  
  std::cout << "\nFinished\n";
}
