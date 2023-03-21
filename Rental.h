#pragma once

#include "Movie.h"

class Rental {
private:
  Movie *m_movie;
  std::size_t m_daysRented;

public:
  Rental(Movie *movie, std::size_t daysRented)
      : m_movie(movie), m_daysRented(daysRented) {}
  ~Rental() {}

  std::size_t getDaysRented() const { return m_daysRented; }
  const Movie *getMovie() const { return m_movie; }
};
