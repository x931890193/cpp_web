//
// Created by sato on 2021/8/21.
//

#ifndef CPP_WEB_INCLUDE_HPP
#define CPP_WEB_INCLUDE_HPP

#include "ormpp/dbng.hpp"
#include "ormpp/mysql.hpp"
#include "handler/index.hpp"

dbng <mysql> Conn();

auto index();
auto getPerson();
#endif //CPP_WEB_INCLUDE_HPP
