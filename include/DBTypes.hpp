#include <string>

/**
 * Class for all the types in the project
**/
namespace db {

    struct DBStatus {
        // 0 is SUCCESS, 1 is FAIL
        int statusCode;
        // A string contains fail reason, it will empty/null for success case.
        std::string failMessage;

        DBStatus(int code) : statusCode(code) {};
        DBStatus(int code, std::string message) : statusCode(code), failMessage(message) {};
    };
}
