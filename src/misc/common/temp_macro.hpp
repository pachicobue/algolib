#pragma once
#define CONCAT_IMPL_(x, y) x##y
#define CONCAT_(x, y) CONCAT_IMPL_(x, y)

#define UNUSED [[maybe_unused]]
#define _ CONCAT_(_temp_name_, __COUNTER__)
