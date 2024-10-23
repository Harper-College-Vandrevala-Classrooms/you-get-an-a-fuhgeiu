#include <iostream>

namespace user_input {

struct class_room_id {
    
    size_t id;
    core_data::Class::class_data *classroom_data;
    
    class_room_id (const char* class_name) {
        
        
    }
    
    class_room_id (const char* class_name, size_t class_size) {
        
        
        
    }
    
};


void create_classroom (const char* class_name) {
    
//    class_room_id class_room(class_name);
    auto *classroom = new core_data::Class::class_data();   // create new classroom
    core_data::classroom classroom1(classroom);    // store the classroom
}


void create_classroom (const char* class_name, size_t number_of_students) {
    
    class_room_id(class_name,number_of_students);
    
}

void add_student () {
    
    
    
    
    
}

void add_grade () {
    
    
    
    
    
}

};

