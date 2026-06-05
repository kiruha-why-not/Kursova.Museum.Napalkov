#include "Technics.h"
#include <iostream>

Technics::Technics(const std::string& title,
                   const std::string& author,
                   const std::string& country,
                   int year,
                   double width,
                   double length,
                   double height,
                   const std::string& techType,
                   bool isWorking)
    : VolumetricExhibit(title, author, country, year, width, length, height),
      techType(techType),
      isWorking(isWorking)
{}

std::string Technics::getTechType()  const { return techType;  }
bool        Technics::getIsWorking() const { return isWorking; }

std::string Technics::getType() const { return "Техніка"; }

void Technics::printInfo() const {
    VolumetricExhibit::printInfo();
    std::cout << "     Тип техніки: " << techType << "\n"
              << "     Діючий:      " << (isWorking ? "Так" : "Ні") << "\n";
}
