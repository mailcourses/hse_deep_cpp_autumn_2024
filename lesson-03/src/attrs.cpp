#include <iostream>
#include <string>

enum class HttpCode
{
    OK,
    NOT_FOUND,
    INTERNAL_SERVER_ERROR
};

[[nodiscard("HttpCode is VERY important!!!")]]
HttpCode
getUrl([[maybe_unused]] const std::string & url) //  ( const std::string & /*url*/ )
{
    // ...
    return HttpCode::OK;
}

int main()
{
    if ( auto code = getUrl("https://vk.com"); code != HttpCode::NOT_FOUND) {
        std::cout << "Not NOT_FOUND" << std::endl;
    }
}
