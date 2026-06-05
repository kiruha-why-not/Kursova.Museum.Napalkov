#include "Room.h"
#include "Exhibit.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>


double Room::totalWallArea() const {
    return 2.0 * (width + length) * height;
}

Room::Room(const std::string& name, double width, double length, double height, double usableWallArea)
    : name(name), width(width), length(length), height(height), usableWallArea(usableWallArea)
{
    if (width <= 0 || length <= 0 || height <= 0)
        throw std::invalid_argument("Розміри кімнати мають бути додатними.");

    double total = totalWallArea();
    if (usableWallArea < 0 || usableWallArea > total) {
        throw std::invalid_argument(
            "Корисна площа стін (" + std::to_string(usableWallArea) +
            " м²) не може перевищувати загальну площу стін (" +
            std::to_string(total) + " м²)."
        );
    }
}

std::string Room::getName() const { return name; }
double Room::getWidth() const { return width; }
double Room::getLength() const { return length; }
double Room::getHeight() const { return height; }
double Room::getUsableWallArea() const { return usableWallArea; }
double Room::getTotalWallArea() const { return totalWallArea(); }
double Room::getFloorArea() const { return width * length; }

double Room::getUsedFloorArea() const {
    double used = 0;
    for (const auto& ex : exhibits)
        used += ex->getFootprint();
    return used;
}

double Room::getUsedWallArea() const {
    double used = 0;
    for (const auto& ex : exhibits)
        used += ex->getWallArea();
    return used;
}

bool Room::addExhibit(const std::shared_ptr<Exhibit>& exhibit) {
    if (!exhibit->fitsInRoom(*this)) {
        std::cout << "[!] Експонат \"" << exhibit->getTitle()
            << "\" не поміщається за розмірами.\n";
        return false;
    }

    double freeFloor = getFloorArea() - getUsedFloorArea();
    double freeWall = getUsableWallArea() - getUsedWallArea();

    if (exhibit->getFootprint() > 0 && exhibit->getFootprint() > freeFloor) {
        std::cout << "[!] Недостатньо місця на підлозі. "
            << "Вільно: " << freeFloor
            << " м², потрібно: " << exhibit->getFootprint() << " м²\n";
        return false;
    }

    if (exhibit->getWallArea() > 0 && exhibit->getWallArea() > freeWall) {
        std::cout << "[!] Недостатньо місця на стінах. "
            << "Вільно: " << freeWall
            << " м², потрібно: " << exhibit->getWallArea() << " м²\n";
        return false;
    }

    exhibits.push_back(exhibit);    
}
void Room::removeExhibit(int index) {
    if (index < 0 || index >= (int)exhibits.size())
        throw std::out_of_range("Невірний індекс експонату.");
    exhibits.erase(exhibits.begin() + index);
}

const std::vector<std::shared_ptr<Exhibit>>& Room::getExhibits() const {
    return exhibits;
}

void Room::printInfo() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=== Кімната: " << name << " ===\n"
              << "  Ширина:  " << width  << " м\n"
              << "  Довжина: " << length << " м\n"
              << "  Висота:  " << height << " м\n"
              << "  Площа підлоги:          " << getFloorArea()     << " м²\n"
              << "  Загальна площа стін:    " << getTotalWallArea()  << " м²\n"
              << "  Корисна площа стін:     " << usableWallArea      << " м²\n"
              << "  Кількість експонатів:   " << exhibits.size()     << "\n";
}

void Room::printExhibits() const {
    std::cout << "--- Експонати кімнати \"" << name << "\" ---\n";
    if (exhibits.empty()) {
        std::cout << "  (порожньо)\n";
        return;
    }
    for (size_t i = 0; i < exhibits.size(); ++i) {
        std::cout << "  " << (i + 1) << ". ";
        exhibits[i]->printInfo();
    }
}
