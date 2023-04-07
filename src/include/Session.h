#pragma once
#include "DataInterface.h"
#include <Wt/Dbo/Session.h>

class Session : public Wt::Dbo::Session 
{
public:
    Session();
    ~Session();

    void addRecord(ExampleTable_Data exampleTable_Data);
    void deleteRecord(int id);
    std::vector<ExampleTable_Data> getTableData();
    
    void modifyStringColumn(int id, std::string data);
    void modifyEnumColumn(int id, Enumeration data);
    void modifyDoubleColumn(int id, double data);
    void modifyBoolColumn(int id, bool data);
    void modifyDateTimeColumn(int id, std::chrono::system_clock::time_point data);

private:

};
