#include "Sculpture.h"
#include <iostream>

Sculpture::Sculpture(const std::string& title,
                     const std::string& author,
                     const std::string& country,
                     int year,
                     double width,
                     double length,
                     double height,
                     const std::string& material)
    : VolumetricExhibit(title, author, country, year, width, length, height),
      material(material)
{}

std::string Sculpture::getMaterial() const { return material; }

std::string Sculpture::getType() const { return "Скульптура"; }

void Sculpture::printInfo() const {
    VolumetricExhibit::printInfo();
    std::cout << "     Матеріал: " << material << "\n";
}
