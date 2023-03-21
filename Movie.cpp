#include "Movie.h"

double ChildrenMovie::getTotalPoints(size_t rentDays) const {
  double totalPoints = 0;
  totalPoints += 15;
  if (rentDays > 3) {
    totalPoints += (rentDays - 3) * 15;
  }
  return totalPoints;
}

double RegularMovie::getTotalPoints(size_t rentDays) const {
  double totalPoints = 0;
  totalPoints += 2;
  if (rentDays > 2) {
    totalPoints += (rentDays - 2) * 15;
  }
  return totalPoints;
}

double NewReleaseMovie::getTotalPoints(size_t rentDays) const {
  double totalPoints = 0;
  totalPoints += rentDays * 3;
  return totalPoints;
}