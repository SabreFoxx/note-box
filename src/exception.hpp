#pragma once
#include <exception>
#include <string>

struct Exception : public std::exception {
  Exception(std::string message) : message{"Exception: " + message} {}
  const char *what() const noexcept override { return message.c_str(); }

private:
  const std::string message;
};

struct RareException : public Exception {
  RareException(std::string message) : Exception{message} {}
};