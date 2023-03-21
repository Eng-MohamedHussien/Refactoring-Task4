#include <Customer.h>
#include <Movie.h>
#include <Rental.h>

#include <iostream>

int main() {
  Movie **movies = new Movie *[3];
  movies[0] = new ChildrenMovie("Finding Nemo");
  movies[1] = new RegularMovie("Troy");
  movies[2] = new NewReleaseMovie("Havoc");

  Customer *c1 = new Customer("Muhammed");

  Rental **rents = new Rental *[3];
  rents[0] = new Rental(movies[0], 2);
  rents[1] = new Rental(movies[1], 4);
  rents[2] = new Rental(movies[2], 5);

  c1->addRental(rents[0]);
  c1->addRental(rents[1]);
  c1->addRental(rents[2]);

  std::string report;
  c1->loadReport(report);

  std::cout << report << std::endl;

  delete c1;
  delete[] rents;
  delete[] movies;
  return 0;
}