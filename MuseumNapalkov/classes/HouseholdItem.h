#pragma once
#include "VolumetricExhibit.h"

class HouseholdItem : public VolumetricExhibit {
private:
    std::string itemCategory; // категорія: меблі, посуд, одяг тощо
    std::string era;          // епоха або культура

public:
    HouseholdItem(const std::string& title,
                  const std::string& author,
                  const std::string& country,
                  int year,
                  double width,
                  double length,
                  double height,
                  const std::string& itemCategory,
                  const std::string& era);

    std::string getItemCategory() const;
    std::string getEra()          const;

    std::string getType() const override;
    void printInfo() const override;
};
