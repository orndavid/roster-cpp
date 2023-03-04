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

void print_array(const Shifts& shifts){
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


void Person::stats(){
  std::cout << "Person id: " << id << "\n";
  std::cout << "Remaining Workdays: " << count(available_days) << "\n";
  std::cout << "available_days / working_days" << "\n";
  print_array(available_days);
  print_array(working_days);
}

int random_available_day(const Shifts& shifts){
  /** Pick a randomly available day from the shift */
  // TODO Optimization : use a created base object and the boolean as a mask
  std::vector<int> counts;
  int selected_index = -1;
  for(int i=0; i<TIMESPAN; i++){
    if(shifts.days[i]){
      counts.push_back(i);
    }
  }
  if(counts.size() > 0){
    selected_index = counts[(rand() % counts.size())];
  }
  return selected_index;
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
  std::vector<int> temp = {0, 1, 2};
  int random_shift_value = random_from_selection(temp);
  int work_day = random_available_day(available_days);

   /** A person can't work the day after nightshift, unless that
      * previous shift is a nightshift */
  if (work_day == -1){
    std::cerr << "Unable to add shift" << std::endl;
    exit(UNABLE_TO_ADD_SHIFT);
  }
  available_days.days[work_day] = false;
  working_days.days[work_day] = true;

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
