
#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

#include "Test.h"

void initialize_string_bug_module(godot::ModuleInitializationLevel p_level) {
  if (p_level != godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }

  godot::ClassDB::register_class<godot::Test>();

}

void uninitialize_string_bug_module(godot::ModuleInitializationLevel p_level) {
  if (p_level != godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
  // DO NOTHING
}

extern "C" {

GDExtensionBool GDE_EXPORT string_bug_library_init(const GDExtensionInterface *p_interface, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
  godot::GDExtensionBinding::InitObject init_object(p_interface, p_library, r_initialization);

  init_object.register_initializer(initialize_string_bug_module);
  init_object.register_terminator(uninitialize_string_bug_module);
  init_object.set_minimum_library_initialization_level(godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_object.init();
}

}
