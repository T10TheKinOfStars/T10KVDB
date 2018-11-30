#include <DBTypes.hpp>
#include <string>
#include <unordered_map>

namespace db {
    class DBOperation {
        public:
	    DBOperation();
            db::DBStatus putRecord(const std::string& key, const std::string& value);
            db::DBStatus getRecord(const std::string& key, std::string& value);
            db::DBStatus deleteRecord(const std::string& key);

        private:
            std::unordered_map<std::string, std::string> database;
    };
};
