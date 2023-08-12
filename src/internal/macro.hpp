#pragma once
#define CAT_IMPL(x, y) x##y
#define CAT(x, y)      CAT_IMPL(x, y)

#define UNUSED [[maybe_unused]]
#define _      CAT(_temp_name_, __COUNTER__)
