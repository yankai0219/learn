#include "json/json.h"

#include <iostream>
#include <string>

using namespace std;
int main()
{
    string strValue ="[{\"name\":\"TOM\",\"id\":4},{\"name\":\"JACK\",\"id\":5}]";
    Json::Reader reader;
    Json::Value value;
    if (reader.parse(strValue, value)) {  
        if (value.type() != Json::arrayValue) {
            std::cout << "Json type is not arrayValue "<< std::endl;
            return 0;
        }  
        for(unsigned int i = 0;i < value.size(); i++) {  
            if (value[i].type() != Json::objectValue) {
                cout << "Json type is not objectValue "<< "\n";
                continue;
            }          
            if (! value[i].isMember("name")) {
                continue;
            }

            string name = value[i]["name"].asString(); 
            cout << "got name " << name <<endl;
            if(!value[i].isMember("id")) {
                continue;
            }
     
            int id = value[i]["id"].asInt();
            std::cout << "got id" << id << std::endl;
            Json::Value::Members member = value[i].getMemberNames();
            for(Json::Value::Members::iterator iter = member.begin(); iter !=member.end(); ++iter) {
                std::cout << "gotmember " << (*iter) << std::endl;
            }

        }
    }
    return 0;
}
