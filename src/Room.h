#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
    int id;
    std::string description;

public:
    Room();
    Room(int id, const std::string& desc);

    int getId() const;
    std::string getDescription() const;

    void setDescription(const std::string& desc);
    void display() const;
};

#endif