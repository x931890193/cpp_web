//
// Created by sato on 2021/8/21.
//

#include "include/crow_all.h"
#include "include/handler/index.hpp"
#include "include/conn.hpp"

int main() {
    conn::Conn();
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([]() {
        return index();
    });
    CROW_ROUTE(app, "/p")([]() {
        return getPerson();
    });

    CROW_ROUTE(app, "/json")
            ([] {
                crow::json::wvalue x;
                x["message"] = "Hello, World!";
                return x;
            });
    CROW_ROUTE(app, "/about")
            ([]() {
                return "About Cpp_web.";
            });
    app.port(9090).multithreaded().run();
    return 0;
}