#include "Room.h"
#include <iostream>

Room::Room() : id(0), description("empty room") {}

Room::Room(int id, const std::string& desc)
    : id(id), description(desc) {}

int Room::getId() const {
    return id;
}

std::string Room::getDescription() const {
    return description;
}

void Room::setDescription(const std::string& desc) {
    description = desc;
}

void Room::display() const {
    std::cout << "Room " << id << ": " << description << "\n";
}