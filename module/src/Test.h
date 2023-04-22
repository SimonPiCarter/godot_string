#ifndef __Test_Test__
#define __Test_Test__

#include <cstdint>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/node2d.hpp>

namespace godot {

class Test : public Node {
    GDCLASS(Test, Node)

public:
    ~Test();

    void _process(double delta);

    TypedArray<String> get_test() const;
    void set_test(TypedArray<String> const &) const;

    // Will be called by Godot when the class is registered
    // Use this to add properties to your class
    static void _bind_methods();
};

}

#endif //__Test_Test__
