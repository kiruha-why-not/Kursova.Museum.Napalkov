#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "classes/Room.h"
#include "classes/Painting.h"
#include "classes/Sculpture.h"
#include "classes/Technics.h"
#include "classes/HouseholdItem.h"

//      Допоміжні методи 

void clearInput() {
    std::cin.clear();
    std::cin.ignore(100, '\n');
}

int readInt(const std::string& prompt) {
    int val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val) { clearInput(); return val; }
        std::cout << "  [!] Введіть ціле число.\n";
        clearInput();
    }
}

double readDouble(const std::string& prompt) {
    double val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val && val > 0) { clearInput(); return val; }
        std::cout << "  [!] Введіть додатнє число.\n";
        clearInput();
    }
}

std::string readString(const std::string& prompt) {
    std::string val;
    std::cout << prompt;
    std::getline(std::cin, val);
    return val;
}

bool readBool(const std::string& prompt) {
    while (true) {
        std::cout << prompt << " (1 - Так / 0 - Ні): ";
        int v; std::cin >> v; clearInput();
        if (v == 0 || v == 1) return v == 1;
        std::cout << "  [!] Введіть 1 або 0.\n";
    }
}

void printSeparator() {
    std::cout << "----------------------------------------\n";
}

//      Вивід списку кімнат

void listRooms(const std::vector<std::shared_ptr<Room>>& rooms) {
    if (rooms.empty()) {
        std::cout << "  (кімнат поки немає)\n";
        return;
    }
    for (size_t i = 0; i < rooms.size(); ++i)
        std::cout << "  " << (i + 1) << ". " << rooms[i]->getName()
                  << "  [" << rooms[i]->getWidth() << "x"
                  << rooms[i]->getLength() << "x"
                  << rooms[i]->getHeight() << " м]\n";
}

int chooseRoom(const std::vector<std::shared_ptr<Room>>& rooms) {
    if (rooms.empty()) { std::cout << "  [!] Спочатку додайте кімнату.\n"; return -1; }
    listRooms(rooms);
    int idx = readInt("  Виберіть номер кімнати: ") - 1;
    if (idx < 0 || idx >= (int)rooms.size()) {
        std::cout << "  [!] Невірний номер.\n"; return -1;
    }
    return idx;
}

//      Додавання кімнати 

void addRoom(std::vector<std::shared_ptr<Room>>& rooms) {
    printSeparator();
    std::cout << "== ДОДАТИ КІМНАТУ ==\n";
    std::string name = readString("  Назва кімнати: ");
    double w = readDouble("  Ширина  (м): ");
    double l = readDouble("  Довжина (м): ");
    double h = readDouble("  Висота  (м): ");
    double maxWall = 2.0 * (w + l) * h;
    std::cout << "  Загальна площа стін: " << maxWall << " м²\n";
    double wall = readDouble("  Корисна площа стін (м²): ");
    try {
        rooms.push_back(std::make_shared<Room>(name, w, l, h, wall));
        std::cout << "  [+] Кімнату \"" << name << "\" додано!\n";
    } catch (const std::exception& e) {
        std::cout << "  [!] Помилка: " << e.what() << "\n";
    }
}

//      Створення експонату

std::shared_ptr<Exhibit> createExhibit() {
    printSeparator();
    std::cout << "== ТИП ЕКСПОНАТУ ==\n"
              << "  1. Картина\n"
              << "  2. Скульптура\n"
              << "  3. Техніка\n"
              << "  4. Предмет побуту\n";
    int type = readInt("  Виберіть тип: ");
    if (type < 1 || type > 4) { std::cout << "  [!] Невірний тип.\n"; return nullptr; }

    printSeparator();
    std::string title   = readString("  Назва: ");
    std::string author  = readString("  Автор (Enter = невідомий): ");
    std::string country = readString("  Країна: ");
    int year            = readInt("  Рік: ");

    try {
        if (type == 1) {
            // Картина
            double w = readDouble("  Ширина картини  (м): ");
            double h = readDouble("  Висота картини  (м): ");
            return std::make_shared<Painting>(title, author, country, year, w, h);
        }

        // Об'ємні — спільні розміри
        double w = readDouble("  Ширина  (м): ");
        double l = readDouble("  Довжина (м): ");
        double h = readDouble("  Висота  (м): ");

        if (type == 2) {
            std::string mat = readString("  Матеріал: ");
            return std::make_shared<Sculpture>(title, author, country, year, w, l, h, mat);
        }
        if (type == 3) {
            std::string tt = readString("  Тип техніки: ");
            bool working   = readBool("  Діючий?");
            return std::make_shared<Technics>(title, author, country, year, w, l, h, tt, working);
        }
        if (type == 4) {
            std::string cat = readString("  Категорія (меблі/посуд/...): ");
            std::string era = readString("  Епоха: ");
            return std::make_shared<HouseholdItem>(title, author, country, year, w, l, h, cat, era);
        }
    } catch (const std::exception& e) {
        std::cout << "  [!] Помилка: " << e.what() << "\n";
    }
    return nullptr;
}

//      Додавання експонату в кімнату

void addExhibitToRoom(std::vector<std::shared_ptr<Room>>& rooms,
                      std::vector<std::shared_ptr<Exhibit>>& exhibits) {
    if (exhibits.empty()) { std::cout << "  [!] Спочатку створіть експонат.\n"; return; }
    if (rooms.empty())    { std::cout << "  [!] Спочатку додайте кімнату.\n";   return; }

    printSeparator();
    std::cout << "== ВИБІР ЕКСПОНАТУ ==\n";
    for (size_t i = 0; i < exhibits.size(); ++i)
        std::cout << "  " << (i + 1) << ". [" << exhibits[i]->getType()
                  << "] " << exhibits[i]->getTitle() << "\n";
    int ei = readInt("  Номер експонату: ") - 1;
    if (ei < 0 || ei >= (int)exhibits.size()) { std::cout << "  [!] Невірний номер.\n"; return; }

    printSeparator();
    std::cout << "== ВИБІР КІМНАТИ ==\n";
    int ri = chooseRoom(rooms);
    if (ri < 0) return;

    rooms[ri]->addExhibit(exhibits[ei]);
}

//      Перегляд всіх кімнат 

void viewAllRooms(const std::vector<std::shared_ptr<Room>>& rooms) {
    printSeparator();
    std::cout << "== УСІ КІМНАТИ ==\n";
    if (rooms.empty()) { std::cout << "  (порожньо)\n"; return; }
    for (auto& r : rooms) {
        r->printInfo();
        r->printExhibits();
        std::cout << "\n";
    }
}

//      Перегляд всіх експонатів 

void viewAllExhibits(const std::vector<std::shared_ptr<Exhibit>>& exhibits) {
    printSeparator();
    std::cout << "== УСІ ЕКСПОНАТИ ==\n";
    if (exhibits.empty()) { std::cout << "  (порожньо)\n"; return; }
    for (size_t i = 0; i < exhibits.size(); ++i) {
        std::cout << (i + 1) << ". ";
        exhibits[i]->printInfo();
        std::cout << "\n";
    }
}

//      Головне меню

void printMenu() {
    std::cout << "\n========================================\n";
    std::cout << "              МУЗЕЙ\n";
    std::cout << "========================================\n";
    std::cout << "  1. Додати кімнату\n";
    std::cout << "  2. Створити експонат\n";
    std::cout << "  3. Розмістити експонат у кімнаті\n";
    std::cout << "  4. Переглянути всі кімнати\n";
    std::cout << "  5. Переглянути всі експонати\n";
    std::cout << "  0. Вийти\n";
    std::cout << "========================================\n";
}

//      Main

int main() {
    std::vector<std::shared_ptr<Room>>    rooms;
    std::vector<std::shared_ptr<Exhibit>> exhibits;

    std::cout << "Ласкаво просимо до системи управління музеєм!\n";

    while (true) {
        printMenu();
        int choice = readInt("Ваш вибір: ");

        switch (choice) {
            case 1: addRoom(rooms);                             break;
            case 2: {
                auto ex = createExhibit();
                if (ex) {
                    exhibits.push_back(ex);
                    std::cout << "  [+] Експонат \"" << ex->getTitle() << "\" створено!\n";
                }
                break;
            }
            case 3: addExhibitToRoom(rooms, exhibits);          break;
            case 4: viewAllRooms(rooms);                        break;
            case 5: viewAllExhibits(exhibits);                  break;
            case 0:
                std::cout << "До побачення!\n";
                return 0;
            default:
                std::cout << "  [!] Невірний вибір.\n";
        }
    }
}
