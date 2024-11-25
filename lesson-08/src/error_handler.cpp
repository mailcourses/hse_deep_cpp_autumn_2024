#include <iostream>
#include <cassert>
#include <system_error>


enum class HttpCode
{
    OK = 200,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500
};

class HttpCategory : public std::error_category
{
public:
    const char* name() const noexcept override
    {
        return "http";
    }

    std::string message(int code) const override
    {
        switch(code)
        {
            case 200:
                return "ok";
            case 404:
                return "not_found";
            case 500:
                return "internal_server_error";
        }
        assert(!"no code found");
    }
};

std::error_code make_http_code(HttpCode code)
{
    static const HttpCategory instance;
    return std::error_code(static_cast<int>(code), instance);
}

[[nodiscard]]
std::error_code download(const std::string& url)
{
    if (url == "https://vk.com")
        return make_http_code(HttpCode::OK);
    if (url == "https://google.com")
        return make_http_code(HttpCode::INTERNAL_SERVER_ERROR);
    return make_http_code(HttpCode::NOT_FOUND);
}

int main()
{
    auto vk_code = download("https://vk.com");
    if (vk_code)
    {
        std::cout << vk_code << std::endl;
        std::cout << vk_code.message() << std::endl;
    }

    auto google_code = download("https://google.com");
    if (google_code)
    {
        std::cout << google_code << std::endl;
        std::cout << google_code.message() << std::endl;
    }

    auto error = download("rambler.ru");
    /*
     * if (error) ...
     */
}
