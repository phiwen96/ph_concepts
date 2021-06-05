// #define _System @_System@
#pragma once
// #define _Darwin 0
// #define _Linux 1
// #define _Windows 2
//
//
// #define _x86_64 0
// #define _arm64 1
// #define _Processor @_Processor@

template <typename T>
concept Darwin = 1 == @_Darwin@;
template <typename T>
concept Linux = 1 == @_Linux@;
template <typename T>
concept Windows = 1 == @_Windows@;
template <typename T>
concept X86_64 = 1 == @_x86_64@;
template <typename T>
concept Arm64 = 1 == @_arm64@;
