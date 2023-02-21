#include "individual.hpp"


int randInt(const unsigned int maxInt){
  /** Get a random integer in range 0-maxInt*/
  return rand() % maxInt; 
}

void print_shifts(bool* array){
  /** Helper print function */
  for(int i=0; i < FORTNIGHT; i++)
    std::cout << array[i] << " ";
  std::cout << std::endl;

}

void Person::stats(){
  std::cout << "Day shifts: " << count_days() << "\n";
  print_shifts(get_day());
  std::cout << "Middle shifts: " << count_middles() << "\n";
  print_shifts(get_middle());
  std::cout << "Night shifts: " << count_nights() << "\n";
  print_shifts(get_night());
}


void Person::generate_shifts(){
  int random_shift = randInt(3);
  int index = randInt(14);
  if(random_shift == 0){
    day[index] = true;
  }else if(random_shift == 1){
    middle[index] = true;
  }else if(random_shift == 2){
    night[index] = true;
  }else{
    std::cerr << "Shift value incorrect (" << random_shift << ")" << std::endl;
  }
}

const int Person::count_days(){
  int count = 0;
  for(auto working: day){
    if(working){
      count++;
    }
  }
  return count;
}

const int Person::count_middles(){
  int count = 0;
  for(auto working: middle){
    if(working){
      count++;
    }
  }
  return count;
}

const int Person::count_nights(){
  int count = 0;
  for(auto working: night){
    if(working){
      count++;
    }
  }
  return count;
}

const int Person::overall_count(){
  return count_days() + count_nights() + count_middles();
}
