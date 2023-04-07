#include "include/Session.h"
#include <Wt/Dbo/backend/Sqlite3.h>
#include "include/TableTest.h"

Session::Session()
{
    setConnection(std::make_unique<Wt::Dbo::backend::Sqlite3>("test.db"));
    try {

        mapClass<TableData>("example_table");
        createTables();

    }catch(Wt::Dbo::Exception& e) {
        std::cout << e.what() << std::endl;
    }
}

Session::~Session()
{
}

void Session::addRecord(ExampleTable_Data exampleTable_Data)
{
    Wt::Dbo::Transaction transaction(*this);

    auto tableData = std::make_unique<TableData>(); 
    tableData->string_field = exampleTable_Data.string_field;
    tableData->enum_field = exampleTable_Data.enum_field;
    tableData->double_field = exampleTable_Data.double_field;
    tableData->bool_field = exampleTable_Data.bool_field;
    tableData->dateTime_field = exampleTable_Data.dateTime_field;

    add(std::move(tableData));
    transaction.commit();
}

std::vector<ExampleTable_Data> Session::getTableData()
{
    Wt::Dbo::Transaction transaction(*this);
    std::vector<ExampleTable_Data> tableData;
    TablesData tablesData = find<TableData>();
    for (auto& row : tablesData) {
        ExampleTable_Data rowData;
        rowData.id = row.id();
        rowData.string_field = row->string_field;
        rowData.enum_field = row->enum_field;
        rowData.double_field = row->double_field;
        rowData.bool_field = row->bool_field;
        rowData.dateTime_field = row->dateTime_field;

        tableData.push_back(rowData);
    }
    return tableData;
}

void Session::deleteRecord(int id)
{
    Wt::Dbo::Transaction transaction(*this);
    dbo::ptr<TableData> tableTest_row = find<TableData>().where("id = ?").bind(id);
    tableTest_row.remove();

    transaction.commit();
}

void Session::modifyStringColumn(int id, std::string data)
{
    Wt::Dbo::Transaction transaction(*this);
    dbo::ptr<TableData> tableTest_row = find<TableData>().where("id = ?").bind(id);
    tableTest_row.modify()->string_field = data;
    transaction.commit();
}

void Session::modifyEnumColumn(int id, Enumeration data)
{
    Wt::Dbo::Transaction transaction(*this);
    dbo::ptr<TableData> tableTest_row = find<TableData>().where("id = ?").bind(id);
    tableTest_row.modify()->enum_field = data;
    transaction.commit();
}

void Session::modifyDoubleColumn(int id, double data)
{
    Wt::Dbo::Transaction transaction(*this);
    dbo::ptr<TableData> tableTest_row = find<TableData>().where("id = ?").bind(id);
    tableTest_row.modify()->double_field = data;
    transaction.commit();
}

void Session::modifyBoolColumn(int id, bool data)
{
    Wt::Dbo::Transaction transaction(*this);
    dbo::ptr<TableData> tableTest_row = find<TableData>().where("id = ?").bind(id);
    tableTest_row.modify()->bool_field = data;
    transaction.commit();
}

void Session::modifyDateTimeColumn(int id, std::chrono::system_clock::time_point data)
{
    Wt::Dbo::Transaction transaction(*this);
    dbo::ptr<TableData> tableTest_row = find<TableData>().where("id = ?").bind(id);
    tableTest_row.modify()->dateTime_field = data;
    transaction.commit();
}

