//
// Created by sato on 2021/8/21.
//
#include "../wrapper.hpp"
#include "../conn.hpp"

auto index() {
    return "Hello world!";
}

auto getPerson(){
    return "person list!";
//    return person::PersonList(conn::Conn());
}