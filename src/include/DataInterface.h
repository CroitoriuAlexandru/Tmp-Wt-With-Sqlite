#pragma once
#include <string>
#include <chrono>

enum class Enumeration {
    Value1 = 0,
    Value2 = 1,
    Value3 = 2
};

struct ExampleTable_Data {
    int id;
    std::string string_field;
    Enumeration enum_field;
    double double_field;
    bool bool_field;
    std::chrono::system_clock::time_point dateTime_field;
};
