#include "HouseholdItem.h"
#include <iostream>

HouseholdItem::HouseholdItem(const std::string& title,
                             const std::string& author,
                             const std::string& country,
                             int year,
                             double width,
                             double length,
                             double height,
                             const std::string& itemCategory,
                             const std::string& era)
    : VolumetricExhibit(title, author, country, year, width, length, height),
      itemCategory(itemCategory),
      era(era)
{}

std::string HouseholdItem::getItemCategory() const { return itemCategory; }
std::string HouseholdItem::getEra()          const { return era; }

std::string HouseholdItem::getType() const { return "Предмет побуту"; }

void HouseholdItem::printInfo() const {
    VolumetricExhibit::printInfo();
    std::cout << "     Категорія: " << itemCategory << "\n"
              << "     Епоха:     " << era          << "\n";
}
