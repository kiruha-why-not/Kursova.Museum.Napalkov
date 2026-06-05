#include "Painting.h"
#include "Room.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

Painting::Painting(const std::string& title,
                   const std::string& author,
                   const std::string& country,
                   int year,
                   double width,
                   double height)
    : Exhibit(title, author, country, year),
      paintWidth(width),
      paintHeight(height)
{
    if (width <= 0 || height <= 0)
        throw std::invalid_argument("Розміри картини мають бути додатними.");
}

double Painting::getPaintWidth()  const { return paintWidth;  }
double Painting::getPaintHeight() const { return paintHeight; }
double Painting::getArea()        const { return paintWidth * paintHeight; }

bool Painting::fitsInRoom(const Room& room) const {
    // Картина вміщується, якщо вона вузька за ширину кімнати,
    // не вища за стіну, і площа <= корисна площа стін
    return (paintWidth  <= room.getWidth())  &&
           (paintHeight <= room.getHeight()) &&
           (getArea()   <= room.getUsableWallArea());
}

std::string Painting::getType() const { return "Картина"; }
double Painting::getWallArea() const { return getArea(); }

void Painting::printInfo() const {
    Exhibit::printInfo();
    std::cout << std::fixed << std::setprecision(2)
              << "     Розмір: " << paintWidth << " x " << paintHeight
              << " м  (площа: " << getArea() << " м²)\n";
}
