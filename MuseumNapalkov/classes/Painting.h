#pragma once
#include "Exhibit.h"

// Картина, плоский експонат що розміщується на стіні
class Painting : public Exhibit {
private:
    double paintWidth;   // ширина картини (м)
    double paintHeight;  // висота картини (м)

public:
    Painting(const std::string& title,
             const std::string& author,
             const std::string& country,
             int year,
             double width,
             double height);

    double getPaintWidth()  const;
    double getPaintHeight() const;
    double getArea() const;

    // Картина поміщається, якщо її площа <= корисна площа стін
    bool fitsInRoom(const Room& room) const override;

    std::string getType() const override;
    double getWallArea() const override;
    void printInfo() const override;
};
