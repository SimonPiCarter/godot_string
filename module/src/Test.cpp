#include "Test.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/input.hpp>

namespace godot {

Test::~Test()
{}

void Test::_process(double delta)
{
    Node::_process(delta);
}

TypedArray<String> Test::get_test() const
{
    return TypedArray<String>();
}
void Test::set_test(TypedArray<String> const &) const
{

}

void test(String const &str)
{
    UtilityFunctions::print(str);
}

void Test::_bind_methods()
{
    UtilityFunctions::print("Binding Test methods...");

    {
        godot::String str_l("String");
        godot::String str2_l(str_l.utf8().get_data());
        UtilityFunctions::print(str_l);
        UtilityFunctions::print(str2_l);
        test(str_l.utf8().get_data());
    }

    ClassDB::bind_method(D_METHOD("get_test"), &Test::get_test);
    ClassDB::bind_method(D_METHOD("set_test", "test"), &Test::set_test);

    UtilityFunctions::print("done");
}

}
