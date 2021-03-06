// util.h - utilites
#pragma once

// e.g., pick(L(n, 2*n + 1), factorial{}, ) => (2n+1)!
// lambda macro
#ifndef L_
#define L_(x,...) [](auto x) { return (__VA_ARGS__) ; }
#endif
// expressions using n
#ifndef N_
#define N_(...) [](auto n) { return (__VA_ARGS__) ; }
#endif
// enumerator over n
#ifndef E_
#define E_(...) apply([](auto n) { return (__VA_ARGS__) ; })
#endif

namespace iter {

	template<class I>
	inline bool all(I i)
	{
		while (i) {
			if (0 == *i) 
				return false;
			++i;
		}

		return true;
	}

	template<class I>
	inline bool any(I i)
	{
		while (i) {
			if (0 != *i) 
				return true;
			++i;
		}

		return false;
	}

} // iter
#ifdef _DEBUG
#include "include/ensure.h"
#include "enumerator/counted.h"

inline void test_util()
{
	int a[] = {1,2,3};
	auto b = iter::ce(a);
	ensure (all(b));
	ensure (any(b));

	auto c = L_(x, x*x);
	ensure (c(1.2) == 1.2*1.2);

	auto d = N_(n*n);
	ensure (d(2) == 4);
}

#endif // _DEBUG