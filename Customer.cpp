#include "Customer.h"

double getBonusPoints(const Rental *r) {
  double bonusAmount = 0;
  switch (r->getMovie()->getPriceCode()) {
  case PriceCodeType::REGULAR:
    bonusAmount += 2;
    if (r->getDaysRented() > 2) {
      bonusAmount += (r->getDaysRented() - 2) * 15;
    }
    break;
  case PriceCodeType::NEW_RELEASE:
    bonusAmount += r->getDaysRented() * 3;
    break;
  case PriceCodeType::CHILDREN:
    bonusAmount += 15;
    if (r->getDaysRented() > 3) {
      bonusAmount += (r->getDaysRented() - 3) * 15;
    }
    break;
  default:
    break;
  }

  return bonusAmount;
}
void Customer::loadReport(std::string &report) {
  report = "";
  report += "Report for " + getName() + "\n";
  double totalBonus = 0;
  int frequentRenterPoints = 0;

  for (auto it = m_rentals.begin(); it != m_rentals.end(); ++it) {
    double movieBonus = getBonusPoints(*it);
    frequentRenterPoints++;
    if ((*it)->isPremiumCustomer()) {
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
