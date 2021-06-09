    // #define _System @_System@
#pragma once
namespace ph
{
        // #define _Darwin 0
        // #define _Linux 1
        // #define _Windows 2
        //
        //
        // #define _x86_64 0
        // #define _arm64 1
        // #define _Processor @_Processor@
    
    template <typename T>
    concept Darwin = @_Darwin@;
    
    template <typename T>
    concept Linux = @_Linux@;
    
    template <typename T>
    concept Windows = @_Windows@;
    
    template <typename T>
    concept X86_64 = @_x86_64@;
    
    template <typename T>
    concept Arm64 = @_arm64@;
}
