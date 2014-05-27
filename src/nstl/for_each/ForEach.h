#ifndef FOR_EACH_H
#define FOR_EACH_H 

#include <algorithm>
#include <typeinfo>

// name the flag complex to be hard to declared or used by user in other context

#define FOR_EACH(ref_name, container) for (typeof((container).begin()) ref_name ## _iter = (container).begin(); (ref_name ## _iter) != (container).end(); ++(ref_name ## _iter)) for (bool ref_name ## _flag_helper_for_iteration_1337 = true; ref_name ## _flag_helper_for_iteration_1337; ref_name ## _flag_helper_for_iteration_1337 = false) for (typeof(*(container).begin())& ref_name = *(ref_name ## _iter); ref_name ## _flag_helper_for_iteration_1337; ref_name ## _flag_helper_for_iteration_1337 = false)

#define CONST_FOR_EACH(ref_name, container) for (typeof((container).begin()) ref_name ## _iter = (container).begin(); (ref_name ## _iter) != (container).end(); ++(ref_name ## _iter)) for (bool ref_name ## _flag_helper_for_iteration_1337 = true; ref_name ## _flag_helper_for_iteration_1337; ref_name ## _flag_helper_for_iteration_1337 = false) for (const typeof(*(container).begin())& ref_name = *(ref_name ## _iter); ref_name ## _flag_helper_for_iteration_1337; ref_name ## _flag_helper_for_iteration_1337 = false)

template <bool> struct StaticAssert;
template <> struct StaticAssert<true> {};

#define STATIC_ASSERT_FORCE_ERROR(cond) do { StaticAssert<(cond)> (); } while(0)

#define STRING_CONCAT1(X, Y) X##Y
#define STRING_CONCAT(X, Y) STRING_CONCAT1(X, Y)


#define STATIC_ASSERT(cond) struct STRING_CONCAT(StaticAssertFail_at_, __LINE__) { STRING_CONCAT(StaticAssertFail_at_, __LINE__)() { STATIC_ASSERT_FORCE_ERROR((cond)); }  }; 

#define STATIC_ASSERT_WITH_MSG(cond, msg) STATIC_ASSERT((cond))

#endif // FOR_EACH_H 
