#pragma once
#include "VolumetricExhibit.h"

class Sculpture : public VolumetricExhibit {
private:
    std::string material; // матеріал (мармур, бронза тощо)

public:
    Sculpture(const std::string& title,
              const std::string& author,
              const std::string& country,
              int year,
              double width,
              double length,
              double height,
              const std::string& material);

    std::string getMaterial() const;

    std::string getType() const override;
    void printInfo() const override;
};
