//
// Created by sato on 2021/8/21.
//
#define CROW_MAIN  //

#include "ext/resp.hpp"
#include "ext/json.hpp"

#include "ext/crow_all_new.hpp"
#include "include/handler/index.hpp"
#include "include/conn.hpp"
#include "include/method.hpp"
#include <fstream>
#include <regex>


int main() {
    bool use_ssl = false;
    conn::Conn();
    crow::SimpleApp app;
    CROW_LOG_INFO << "message";
    compare();
    // get domian url based on the request
    auto get_domain = [&use_ssl](crow::request const &req) {
        return (use_ssl ? "https://" : "http://")
               + req.get_header_value("Host");
    };
    CROW_ROUTE(app, "/")([]() {
        std::string msg = index();
        nlohmann::json data;
        data["msg"] = msg;
        base::jsonresponse r{base::BaseResp(0, "ok", data)};
        return r;
    });
    CROW_ROUTE(app, "/create_person").methods("POST"_method)
        ([](const crow::request &req) {
            auto x = crow::json::load(req.body);
            if (!x) {
                return base::jsonresponse{base::BaseResp(1, "参数错误", NULL)};
            }

            for (auto &re : x) {
               std::cout << re << std::endl;
            };

            base::jsonresponse r{base::BaseResp(0, "ok", NULL)};
            return r;
        });
    CROW_ROUTE(app, "/p")([]() {
        auto res = getPerson(); // vector
        //  for (auto i=res.begin(); i != res.end(); i++) {
        for (auto &re : res) {
            std::cout << re.name;
        }
        return "getPerson()";
    });
    CROW_ROUTE(app, "/s/<int>")
        ([](int count) {
            if (count > 100)
                return crow::response(400);
            std::ostringstream os;
            os << count << " bottles of beer!";
            return crow::response(os.str());
        });
    // URL PATH 参数
    CROW_ROUTE(app, "/add/<int>/<int>")
        ([](int a, int b) {
            std::ostringstream os;
            std::cerr<< "this is error\n";
            os << a + b;
            return crow::response(os.str());
        });
    // POST 请求
    CROW_ROUTE(app, "/post_json").methods("POST"_method)
        ([](const crow::request &req) {
            // 反序列化参数
            auto x = crow::json::load(req.body);
            nlohmann::json data;
            if (!x) {
                return base::jsonresponse{base::BaseResp(1, "参数错误", NULL)};
            }
            data["a"] = x["a"].i();
            data["b"] = x["b"].i();
            return base::jsonresponse{base::BaseResp(0, "", data)};

        });

    CROW_ROUTE(app, "/orgin_json").methods("POST"_method)
        ([](const crow::request &req) {
            // 反序列化参数
            auto x = crow::json::load(req.body);
            nlohmann::json data;
            if (!x) {
                base::jsonresponse r{base::BaseResp(1, "参数错误", NULL)};
                return r;
            }
            data["a"] = x["a"].i();
            data["b"] = x["b"].i();
            return base::jsonresponse{base::BaseResp(0, "", data)};

        });
    // URl 参数 获取
    CROW_ROUTE(app, "/url_param")
        ([] {
            crow::json::wvalue x;
            x["message"] = "Hello, World!";
            return x;
        });
    // URl 参数 获取
    CROW_ROUTE(app, "/api/url_param").methods("GET"_method)
        ([&](const crow::request &req) {
            // 1.req.url_params.get  2.通过正则获取url参数  三元表达式
            std::string p1 = regex_search(req.raw_url, std::regex{"p1=\\d+"}) ?
                             req.url_params.get("p1") : "0";

            std::string p2 = regex_search(req.raw_url, std::regex{"p2=\\d+"}) ?
                             req.url_params.get("p2") : "25";
            nlohmann::json data;
            data["p1"] = p1;
            data["p2"] = p2;
            base::jsonresponse r{base::BaseResp(0, "", data)};
            r.set_header("Set-Cookie", "key=1111;");
            return r;
        });
    CROW_ROUTE(app, "/about")
        ([]() {
            return "About Cpp_web.";
        });
    CROW_ROUTE(app, "/robots.txt")
        ([&]() {
            std::string text = "User-agent: *\n"
                               "Disallow: ";
            return text;
        });
    CROW_ROUTE(app, "/set_cookies")
        ([&](crow::response &res) {
            crow::CookieParser::context context;
            context.set_cookie("test", "1111");
            context.set_cookie("test2", "333");
            std::string text = "set_cookie\n";
            res.set_header("Set-Cookie", "key=value;key2=rrrr");
            res.write(text);
            res.end();
//                return text;
        });
    app.port(9090).multithreaded().run();
    return 0;
}