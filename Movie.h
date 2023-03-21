#pragma once
#include <string>

enum class PriceCodeType { CHILDREN, REGULAR, NEW_RELEASE };

class Movie {
private:
  std::string m_title;
  PriceCodeType m_priceCode;

public:
  Movie(const std::string &title, PriceCodeType priceCode)
      : m_title(title), m_priceCode(priceCode) {}

  PriceCodeType getPriceCode() const { return m_priceCode; }

  void setPriceCode(PriceCodeType priceCode) { m_priceCode = priceCode; }
  const std::string &getTitle() const { return m_title; }
};
