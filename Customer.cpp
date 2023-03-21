#include "Customer.h"

void Customer::loadReport(std::string &report) {
  report = "";
  report += "Report for " + getName() + "\n";
  double totalBonus = 0;
  int frequentRenterPoints = 0;

  for (auto it = m_rentals.begin(); it != m_rentals.end(); ++it) {
    size_t rentDays = (*it)->getDaysRented();
    double movieBonus = (*it)->getMovie()->getTotalPoints(rentDays);
    frequentRenterPoints++;
    if ((*it)->getMovie()->checkFrequentRentPoints(rentDays)) {
      frequentRenterPoints++;
    }
    auto movieTitle = (*it)->getMovie()->getTitle();
    report += "\t" + movieTitle + "\t" + std::to_string(movieBonus) + "\n";
    totalBonus += movieBonus;
  }

  report += "The amount owed is " + std::to_string(totalBonus) +
            "\nYou've earned " + std::to_string(frequentRenterPoints) +
            " activity points";
}
