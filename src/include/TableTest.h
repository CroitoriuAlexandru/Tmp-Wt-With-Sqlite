#pragma once
#include "DataInterface.h"
#include <Wt/Dbo/Dbo.h>

namespace dbo = Wt::Dbo;
class TableData;
typedef dbo::collection< dbo::ptr<TableData> > TablesData;

class TableData : public ExampleTable_Data {
public:

    template<class Action>
    void persist(Action& a)
    {
        dbo::field(a, string_field, "string_field");
        dbo::field(a, enum_field,  "enum_field");
        dbo::field(a, double_field, "double_field");
        dbo::field(a, bool_field, "bool_field");
        dbo::field(a, dateTime_field, "dateTime_field");
    }


};