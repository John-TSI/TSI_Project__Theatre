#include"../include/excInvalidInput.hpp"

const char* InvalidInput::excInvalidInput::what() const noexcept
{
    return "Invalid input.";
}

const char* InvalidInput::excInvalidChoice::what() const noexcept
{
    return "Invalid input, please review the input options and try again.";
}