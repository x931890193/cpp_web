//
// Created by sato on 2021/8/21.
//

#ifndef CPP_WEB_CONN_CPP
#define CPP_WEB_CONN_CPP

#include "ormpp/dbng.hpp"
#include "ormpp/mysql.hpp"
#include "ormpp/entity.hpp"



const char *ip = "127.0.0.1";
const char *user = "root";
const char *passsword = "";
const char *db = "cpp_db";

namespace conn {
    using namespace ormpp;
    dbng<mysql> Conn() {
        dbng<mysql> conn;
        conn.connect(ip, user, passsword, db);
        conn.create_datatable<Person>();
        return conn;
    }
}

#endif //CPP_WEB_CONN_CPP
