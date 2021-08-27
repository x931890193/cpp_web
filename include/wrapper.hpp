//
// Created by sato on 2021/8/21.
//

#ifndef CPP_WEB_WRAPPER_HPP
#define CPP_WEB_WRAPPER_HPP

#include "ormpp/dbng.hpp"
#include "ormpp/mysql.hpp"


namespace person {
    void DeletePersonById(ormpp::dbng<ormpp::mysql> conn, int id) {
        std::ostringstream stream;
        stream << "id = " << id;
        std::string new_string = stream.str();
        conn.delete_records<Person>(new_string);

    }

    void UpdatePerson(ormpp::dbng<ormpp::mysql> conn) {
    }

    void InsertPerson(ormpp::dbng<ormpp::mysql> conn) {
    }

    std::vector<Person> PersonList(ormpp::dbng<ormpp::mysql> conn) {
        auto result = conn.query<Person>();
        return result;
    }
}

#endif //CPP_WEB_WRAPPER_HPP
