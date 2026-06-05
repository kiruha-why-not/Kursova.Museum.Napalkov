#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Painting.h"
#include "VolumetricExhibit.h"

class Exhibit;

class Room {
private:
    std::string name;
    double width;    // ширина (м)
    double length;   // довжина (м)
    double height;   // висота (м)
    double usableWallArea; // корисна площа стін (м²)

    std::vector<std::shared_ptr<Exhibit>> exhibits;

    double totalWallArea() const;

public:
    Room(const std::string& name, double width, double length, double height, double usableWallArea);

    // Геттери
    std::string getName() const;
    double getWidth() const;
    double getLength() const;
    double getHeight() const;
    double getUsableWallArea() const;
    double getTotalWallArea() const;
    double getFloorArea() const;
    double getUsedFloorArea() const;   
    double getUsedWallArea()  const;   


    // Розміщення експонатів
    bool addExhibit(const std::shared_ptr<Exhibit>& exhibit);
    void removeExhibit(int index);
    const std::vector<std::shared_ptr<Exhibit>>& getExhibits() const;

    void printInfo() const;
    void printExhibits() const;
};
