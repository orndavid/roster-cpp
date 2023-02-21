/**
* Individual implementation. An individual is a wrapper for
* a fortnight cofiguration. The Fornite is filled with different
* types
*/
#include <iostream>
#include <stdlib.h>
#define FORTNIGHT 14

struct shifts{
  bool days[FORTNIGHT];
};


class Person{
public:
  Person(){};
  
  /** Count the number of true values set */
  const int count_days();
  const int count_nights();
  const int count_middles();

  const int overall_count();

  bool* const get_day() { return day;}
  bool* const get_night() { return night;}
  bool* const get_middle() { return middle;}

  /** Add a random value to one of the shifts that
  * isn't already selected 
  * */
  void generate_shifts();
  /** Print stats to stdout */
  void stats();


private:
  bool day[FORTNIGHT] {0};
  bool night[FORTNIGHT] {0};
  bool middle[FORTNIGHT] {0};
};
