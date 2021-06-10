#include "data_structure.hpp"


namespace ph::data_structures
{
    
    
    
#define Concept Linked_list
    
#define Self linked_list
    template <typename T>
    struct Self
    {
        using element_type = T;
        using rest_type = Self <T>;
//        Self () {}
//        Self (Self &&) = delete;
        element_type _element;
        rest_type* _rest {nullptr};
        
        
        
        
        inline static auto empty_list () -> Self*
        {
            return nullptr;
        }
        inline static auto make_list (element_type&& e, Self* s) -> Self*
        {
            return new Self {std::move (e), s};
        }
        inline static auto first (Self& s) -> element_type&
        {
            return s._element;
        }
        
        inline static auto rest (Self& s) -> rest_type*
        {
            return s._rest;
        }
        
    };
//    static_assert (Concept <Self <int>>, "");
#undef Self
#undef Concept
    
}
