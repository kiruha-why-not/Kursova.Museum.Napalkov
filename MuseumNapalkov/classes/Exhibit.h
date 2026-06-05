#pragma once
#include <string>

class Room;

class Exhibit {
protected:
    std::string title;   // назва
    std::string author;  // автор (може бути "Невідомий")
    std::string country; // країна
    int year;            // рік

public:
    static const std::string UNKNOWN_AUTHOR;

    Exhibit(const std::string& title,
            const std::string& author,
            const std::string& country,
            int year);

    virtual ~Exhibit() = default;

    // Геттери
    std::string getTitle()   const;
    std::string getAuthor()  const;
    std::string getCountry() const;
    int         getYear()    const;
    bool        isAuthorKnown() const;

    // Перевірка, чи поміщається в кімнату (реалізується у нащадках)
    virtual bool fitsInRoom(const Room& room) const = 0;

    // Тип експонату (для виводу)
    virtual std::string getType() const = 0;

    virtual double getFootprint() const { return 0; }
    virtual double getWallArea()  const { return 0; } 

    virtual void printInfo() const;
};
