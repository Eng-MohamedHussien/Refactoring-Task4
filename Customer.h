#pragma once

#include "Rental.h"
#include <string>
#include <vector>

class Customer {
private:
  std::string m_name;
  std::vector<Rental *> m_rentals;

public:
  Customer(const std::string &name) : m_name(name) {}
  ~Customer(void) { m_rentals.clear(); }
  void addRental(Rental *rental) { m_rentals.push_back(rental); }
  const std::string &getName(void) const { return m_name; }
  void setName(const std::string &name) { m_name = name; }
  void loadReport(std::string &report);
};
