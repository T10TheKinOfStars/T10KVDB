#include <iostream>
#include "DBOperation.hpp"

using namespace db;

int main(int argc, char* argv[]) {
    DBOperation *op = new DBOperation();
    
    std::cout<<"Please choose your option: i->insert, g->get, d->delete, e->exit"<<std::endl;
    char option;

    do {
        std::cin>>option;
        
        switch (option) {
            case 'i' : {
                std::string key, value;
                std::cin>>key>>value;
                db::DBStatus status = op->putRecord(key, value);
                if (status.statusCode != 0) {
                    std::cout<<status.failMessage<<std::endl;
                }
            }
            break;
            case 'd' : {
                std::string key;
                std::cin>>key;
                db::DBStatus status = op->deleteRecord(key);
                if (status.statusCode != 0) {
                    std::cout<<status.failMessage<<std::endl;
                }
            }
            break;
            case 'g' : {
                std::string key, value;
                std::cin>>key;
                db::DBStatus status = op->getRecord(key,value);
                if (status.statusCode != 0) {
                    std::cout<<status.failMessage<<std::endl;
                } else {
                    std::cout<<"Get value "<<value<<std::endl;
                }
            }
            break;
	    case 'e': {
		std::cout<<"exit"<<std::endl;
		exit(1);
	    };
	    break;
            default : {
                std::cout<<"Unsupported operation."<<std::endl;
            }
        }
	std::cout<<"Choose your option..."<<std::endl;
    } while (std::cin); 

    return 0;
}
