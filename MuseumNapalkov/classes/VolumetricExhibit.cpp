#include "VolumetricExhibit.h"
#include "Room.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

VolumetricExhibit::VolumetricExhibit(const std::string& title,
                                     const std::string& author,
                                     const std::string& country,
                                     int year,
                                     double width,
                                     double length,
                                     double height)
    : Exhibit(title, author, country, year),
      objWidth(width), objLength(length), objHeight(height)
{
    if (width <= 0 || length <= 0 || height <= 0)
        throw std::invalid_argument("Розміри об'ємного експонату мають бути додатними.");
}

double VolumetricExhibit::getObjWidth()  const { return objWidth;  }
double VolumetricExhibit::getObjLength() const { return objLength; }
double VolumetricExhibit::getObjHeight() const { return objHeight; }
double VolumetricExhibit::getFootprint() const { return objWidth * objLength; }

bool VolumetricExhibit::fitsInRoom(const Room& room) const {
    // Перевірка: об'єкт поміщається за шириною, довжиною та висотою
    return (objWidth  <= room.getWidth())  &&
           (objLength <= room.getLength()) &&
           (objHeight <= room.getHeight());
}

std::string VolumetricExhibit::getType() const { return "Об'ємний експонат"; }
double VolumetricExhibit::getFootprint() const { return objWidth * objLength; }

void VolumetricExhibit::printInfo() const {
    Exhibit::printInfo();
    std::cout << std::fixed << std::setprecision(2)
              << "     Розмір: " << objWidth << " x " << objLength
              << " x " << objHeight << " м\n";
}
