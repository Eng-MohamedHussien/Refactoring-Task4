cmake_minimum_required(VERSION 3.16)
project(
  RentSystem
  VERSION 0.0.1
  LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG ae7a13539fb71f270b87eb2e874fbac80bc8dda2 # v2.4.11
)

FetchContent_MakeAvailable(doctest)

add_library(${CMAKE_PROJECT_NAME} SHARED Customer.cpp Movie.cpp Rental.cpp)
