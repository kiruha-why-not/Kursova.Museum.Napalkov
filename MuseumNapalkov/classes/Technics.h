#pragma once
#include "VolumetricExhibit.h"

class Technics : public VolumetricExhibit {
private:
    std::string techType; // тип техніки (автомобіль, літак, верстат тощо)
    bool isWorking;       // чи є діючим

public:
    Technics(const std::string& title,
             const std::string& author,
             const std::string& country,
             int year,
             double width,
             double length,
             double height,
             const std::string& techType,
             bool isWorking = false);

    std::string getTechType()  const;
    bool        getIsWorking() const;

    std::string getType() const override;
    void printInfo() const override;
};
