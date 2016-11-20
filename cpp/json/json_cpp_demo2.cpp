#include "json/json.h"

#include <iostream>
#include <string>

int main()
{
    //std::string strValue ="{\"1\":{\"addr\":\"beijing\",\"age\":12,\"name\":\"Tome\"},\"2\":{\"addr\":\"beijing2\",\"age\":13,\"name\":\"Tome2\"}}";
    std::string strValue ="{1:{\"addr\":\"beijing\",\"age\":12,\"name\":\"Tome\"},2:{\"addr\":\"beijing2\",\"age\":13,\"name\":\"Tome2\"}}";
    Json::Reader reader;
    Json::Value value;
    if (! reader.parse(strValue, value)) {
        std::cout << "Json parse error"<< std::endl;
        return -1;
    }
    if (value.type() != Json::objectValue) {
        std::cout << "Json type is not objectValue"<< std::endl;
        return -2;
    } 
    for (Json::Value::iterator itr = value.begin(); itr != value.end(); itr++) {
        if ((*itr).type() != Json::objectValue) {
            std::cout << "Json type is not objectValue "<< std::endl;
            continue;
        } 
        if (! itr->isMember("name")) {
            continue;
        }
        std::string name = (*itr)["name"].asString();
        std::cout << "got name:"<< name << std::endl;

        if (! itr->isMember("age")) {
            continue;
        }
        int age = (*itr)["age"].asInt();
        std::cout << "got age:"<< age<< std::endl;

        Json::Value::Members member = itr->getMemberNames();
        for(Json::Value::Members::iterator iter = member.begin(); iter !=member.end(); ++iter) {
            std::cout << "gotmember " << (*iter) << std::endl;
        }
    }
    return 0;
}
