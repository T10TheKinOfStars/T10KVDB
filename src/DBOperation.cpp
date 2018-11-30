#include "DBOperation.hpp"

namespace db {

DBOperation::DBOperation() {
    
}

db::DBStatus DBOperation::putRecord(const std::string& key, const std::string& value) {
    int dbSize = database.size();
    std::pair<std::string, std::string> record(key, value);
    database.insert(record);

    if (dbSize + 1 != database.size()) {
        return db::DBStatus(1, "failed to insert record to database");
    } else {
        return db::DBStatus(0);
    }
}

db::DBStatus DBOperation::getRecord(const std::string& key, std::string& value) {
    if (database.find(key) == database.end()) {
        return db::DBStatus(1, "Record is not existing in the database.");
    }

    value = database[key];

    return db::DBStatus(0);
}

db::DBStatus DBOperation::deleteRecord(const std::string& key) {
    int dbSize = database.size();
    database.erase(key);

    if (dbSize - 1 != database.size()) {
        return db::DBStatus(1, "failed to delete record from database");
    } else {
        return db::DBStatus(0);
    }
}

}
