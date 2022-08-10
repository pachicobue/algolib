#pragma once
#define CAT(x, y) x##y
#define CAT2(x, y) CAT(x, y)

#define UNUSED [[maybe_unused]]
#define _ CAT2(_temp_name_, __COUNTER__)
#define ALL(vs) std::begin(vs), std::end(vs)
