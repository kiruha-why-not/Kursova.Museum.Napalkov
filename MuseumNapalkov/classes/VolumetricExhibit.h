#pragma once
#include "Exhibit.h"

// Об'ємний експонат який займає місце на підлозі
class VolumetricExhibit : public Exhibit {
protected:
    double objWidth;   // ширина (м)
    double objLength;  // довжина (м)
    double objHeight;  // висота (м)

public:
    VolumetricExhibit(const std::string& title,
                      const std::string& author,
                      const std::string& country,
                      int year,
                      double width,
                      double length,
                      double height);

    double getObjWidth()  const;
    double getObjLength() const;
    double getObjHeight() const;

    // Поміщається, якщо: розміри <= розміри кімнати
    bool fitsInRoom(const Room& room) const override;

    std::string getType() const override;
    double getFootprint() const override;
    void printInfo() const override;
};
