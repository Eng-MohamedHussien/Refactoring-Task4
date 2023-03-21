#pragma once
#include <string>

// enum class PriceCodeType { CHILDREN, REGULAR, NEW_RELEASE };

class Movie {
protected:
  std::string m_title;

public:
  Movie(const std::string &title) : m_title(title) {}
  const std::string &getTitle() const { return m_title; }
  virtual double getTotalPoints(size_t rentDays) const = 0;
  virtual bool checkFrequentRentPoints(size_t rentDays) const { return false; }
};

class ChildrenMovie : public Movie {
public:
  ChildrenMovie(const std::string &title) : Movie(title) {}
  double getTotalPoints(size_t rentDays) const override;
};

class RegularMovie : public Movie {
public:
  RegularMovie(const std::string &title) : Movie(title) {}
  double getTotalPoints(size_t rentDays) const override;
};

class NewReleaseMovie : public Movie {
public:
  NewReleaseMovie(const std::string &title) : Movie(title) {}
  double getTotalPoints(size_t rentDays) const override;
  bool checkFrequentRentPoints(size_t rentDays) const override {
    return rentDays > 1;
  }
};