
//  Copyright (c) 2012 Julian Hornich
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <oclm/oclm.hpp>

const char src[] =
    "__kernel "
    "void vecadd(__global int* A, __global int* B, __global int* C)"
    "{"
    "  int tid = get_global_id(0);"
    "  C[tid] = A[tid] + B[tid];"
    "}";

TEST_CASE( "programm", "Create a program")
{
	// default constructor with source code only
    REQUIRE_NOTHROW( oclm::program p(src) );

	// default constructor with source code and build arguments
    REQUIRE_NOTHROW( oclm::program p(src, "-Werror") );
}
