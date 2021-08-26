//
// Created by qiyu on 10/20/17.
//
#ifndef ORM_ENTITY_HPP
#define ORM_ENTITY_HPP

#include <set>
#include <string>
#include "reflection.hpp"

struct ormpp_not_null {
    std::set<std::string> fields;
};

struct ormpp_key {
    std::string fields;
};

struct ormpp_auto_key {
    std::string fields;
};

struct ormpp_unique {
    std::string fields;
};

struct Person {
    int id;
    std::string name;
    int age;
};
REFLECTION(Person, id, name, age);

#endif //ORM_ENTITY_HPP
