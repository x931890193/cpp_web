//
// Created by sato on 2021/8/21.
//

#ifndef CPP_WEB_WRAPPER_HPP
#define CPP_WEB_WRAPPER_HPP

#include "ormpp/dbng.hpp"
#include "ormpp/mysql.hpp"


namespace person {
    void DeletePerson(ormpp::dbng<ormpp::mysql> conn) {
        conn.delete_records<Person>();

    }

    void UpdatePerson() {

    }

    void InsertPerson() {

    }

    std::vector<Person> PersonList(ormpp::dbng<ormpp::mysql> conn) {
        auto result = conn.query<Person>();
        return result;
    }
}

#endif //CPP_WEB_WRAPPER_HPP
