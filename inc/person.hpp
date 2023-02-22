/** A Person represents a single person object that is created
 * to contain and manipulate the information about the shifts
 * that a single person takes.
 * The shifts are then allocated to a ShiftBoard object for validation
 */ 
#include <iostream>
#include <stdlib.h>
#include <vector>

#ifndef TIMESPAN
#define TIMESPAN 14
#endif

enum ShiftTypes{
  morning, evening, night, stubs, COUNT
};


struct Shifts{
  bool days[TIMESPAN] {0};
};


class Person{
public:
  Person();
  Person(const int person_id);
  /* The following can be introduced to set the available days specifically */
  // Person(const int person_id, const Shifts available_days);
  ~Person(){};
  
  /** Count the number of true values set */
  const int get_id() {return id;}

  /** Add a random value to one of the shifts that
  * isn't already selected 
  * */
  void generate_shifts();
  /** Print stats to stdout */
  void stats();


private:
  int shift_size = TIMESPAN;
  int id {-1};
  Shifts available_days;
  Shifts working_days;
  /* Generic approach so we can increase the number of shifts */
  std::vector<Shifts> shifts;

  // Internally allow for flipping one available workday to a working day
  void make_working_day_invalid(const int& index);
};


int count(const Shifts& shift);
// Given a selection of values return a random value from it
int random_from_selection(std::vector<int>& vector);
// Get a list of indecies that still contain true values
std::vector<int> get_remaining_true(const Shifts& shifts);
