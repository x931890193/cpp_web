//
// Created by sato on 2021/8/22.
//

#ifndef CPP_WEB_RESP_HPP
#define CPP_WEB_RESP_HPP

#include "crow_all.h"
#include "../ext/json.hpp"

namespace base {
    struct htmlresponse : public crow::response {
        htmlresponse(std::string &&_body)
                : crow::response{std::move(_body)} {
            add_header("Content-Type", "text/html; charset=utf-8");
        }
    };

    struct jsonresponse : public crow::response {
        jsonresponse(const nlohmann::json &_body)
                : crow::response{_body.dump()} {
            add_header("Access-Control-Allow-Origin", "*");
            add_header("Access-Control-Allow-Headers", "*");
            add_header("Content-Type", "application/json");
        }
    };

    nlohmann::json BaseResp(int code, std::string msg, const nlohmann::json &_data) {
        nlohmann::json j_response{
                {"data", _data},
                {"code", code},
                {"msg",  msg}
        };
        return j_response;
    }
}

#endif //CPP_WEB_RESP_HPP
