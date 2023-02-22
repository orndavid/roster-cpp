#include "person.hpp"
#include "ERRORS.hpp"

/* Initializer */

Person::Person(){
  /* Set the default value to 1, cause we can work all days */
  for(int i=0; i < TIMESPAN; i++){
    (&available_days)->days[i] = 1;
  }
}

Person::Person(const int person_id): Person(){
  id = person_id;
}


void Person::stats(){
  std::cout << "Person id: " << id << "\n";
  std::cout << "Remaining Workdays: " << count(available_days) << "\n";
}


void Person::generate_shifts(){
  /** Ensure we can add more shifts to worker */
  int total_available_days = count(available_days);

  if(total_available_days < 1){
    std::cerr << "To few days available to add a shift\n";
    exit(NOT_ENOUGH_AVAILABLE_DAYS);
  }


  //std::vector<int> remaining = get_remaining_true(available_days());
  //
  // Here it comes -> We need to connect the remaining board to an 
  // existing board so we can select what type of shift to select
  // from
  // Temporary solution
  std::vector<int> temp = {0, 1, 2};
  int random_shift_value = random_from_selection(temp);
  
   /** A person can't work the day after nightshift, unless that
      * previous shift is a nightshift */
  std::cerr << "Unable to add shift" << std::endl;
  exit(UNABLE_TO_ADD_SHIFT);

}

// Private function
void Person::make_working_day_invalid(const int& index){
  available_days.days[index] = 0;
}


int count(const Shifts& shift){
  int count = 0;
  for(const auto& shift: shift.days){
    if(shift)
      count++;
  }
  return count;
}


std::vector<int> get_remaining_true(const Shifts& shifts){
  std::vector<int> return_value;
  int count = 0;
  for(const auto& x : shifts.days){
    if(x)
      return_value.push_back(count);
    count++;
  }
  return return_value;
}
