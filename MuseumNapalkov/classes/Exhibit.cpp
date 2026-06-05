#include <iostream>
#include "Exhibit.h"
#include "Room.h"
#include <stdexcept>

const std::string Exhibit::UNKNOWN_AUTHOR = "Невідомий";

Exhibit::Exhibit(const std::string& title,
                 const std::string& author,
                 const std::string& country,
                 int year)
    : title(title),
      author(author.empty() ? UNKNOWN_AUTHOR : author),
      country(country),
      year(year)
{
    if (title.empty())
        throw std::invalid_argument("Назва експонату не може бути порожньою.");
}

std::string Exhibit::getTitle()   const { return title;   }
std::string Exhibit::getAuthor()  const { return author;  }
std::string Exhibit::getCountry() const { return country; }
int         Exhibit::getYear()    const { return year;    }

bool Exhibit::isAuthorKnown() const {
    return author != UNKNOWN_AUTHOR;
}

void Exhibit::printInfo() const {
    std::cout << "[" << getType() << "] " << title << "\n"
              << "     Автор: "   << author  << "\n"
              << "     Країна: "  << country << "\n"
              << "     Рік: "     << year    << "\n";
}
