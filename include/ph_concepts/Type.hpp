//#pragma once
//
//#include "common.hpp"
//#include "concepts.hpp"
//
//
//
//template <typename T>
//struct Max{};
//
//
//template <>
//struct Max <char>
//{
//    cexpr char max = CHAR_MAX;
//};
//
//template <>
//struct Max <signed char>
//{
//    cexpr signed char max = SCHAR_MAX;
//};
//
//template <>
//struct Max <wchar_t>
//{
//    cexpr wchar_t max = WCHAR_MAX;
//};
//
//template <>
//struct Max <short>
//{
//    cexpr short max = SHRT_MAX;
//};
//
//template <>
//struct Max <unsigned short>
//{
//    cexpr unsigned short max = USHRT_MAX;
//};
//
//template <>
//struct Max <int>
//{
//    cexpr int max = INT_MAX;
//};
//
//template <>
//struct Max <unsigned int>
//{
//    cexpr unsigned int max = UINT_MAX;
//};
//
//template <>
//struct Max <long>
//{
//    cexpr long max = LONG_MAX;
//};
//
//template <>
//struct Max <unsigned long>
//{
//    cexpr unsigned long max = ULONG_MAX;
//};
//
//template <>
//struct Max <long long>
//{
//    cexpr long long max = LLONG_MAX;
//};
//
//template <>
//struct Max <unsigned long long>
//{
//    cexpr unsigned long long max = ULLONG_MAX;
//};
//
//template <>
//struct Max <float>
//{
//    cexpr float max = __FLT_MAX__;
//};
//
//template <>
//struct Max <double>
//{
//    cexpr double max = __DBL_MAX__;
//};
//
//
//template <typename T>
//struct Min{};
//
//
//template <>
//struct Min <char>
//{
//    cexpr char min = CHAR_MIN;
//};
//
//template <>
//struct Min <signed char>
//{
//    cexpr signed char min = SCHAR_MIN;
//};
//
//template <>
//struct Min <wchar_t>
//{
//    cexpr wchar_t min = WCHAR_MIN;
//};
//
//template <>
//struct Min <short>
//{
//    cexpr short min = SHRT_MIN;
//};
//
//template <>
//struct Min <unsigned short>
//{
//    cexpr unsigned short min = 0;
//};
//
//template <>
//struct Min <int>
//{
//    cexpr int min = INT_MIN;
//};
//
//template <>
//struct Min <unsigned int>
//{
//    cexpr unsigned int min = 0;
//};
//
//template <>
//struct Min <long>
//{
//    cexpr long min = LONG_MIN;
//};
//
//template <>
//struct Min <unsigned long>
//{
//    cexpr unsigned long min = 0;
//};
//
//template <>
//struct Min <long long>
//{
//    cexpr long long min = LLONG_MIN;
//};
//
//template <>
//struct Min <unsigned long long>
//{
//    cexpr unsigned long long min = 0;
//};
//
//template <>
//struct Min <float>
//{
//    cexpr float min = __FLT_MIN__;
//};
//
//template <>
//struct Min <double>
//{
//    cexpr double min = __DBL_MIN__;
//};
//
//
//
//
//
//
//
//
//
//
//
//
//template <typename T, template <typename> typename... TypeImp>
//requires requires(){((TypeImp <T>{}), ...);}
//struct Type : TypeImp <T>...
//{
//
//    
//
//};
//
//
//
//template <typename T>
//requires requires () {Type <T, Max> {};}
//using type = Type <std::decay_t<T>, Max, Min>;




