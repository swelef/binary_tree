//        Copyright Vladimir Marko 2006 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_TREE_VALIDATE_H_INCLUDED
#define VMARKO_TREE_VALIDATE_H_INCLUDED

#include <stdio>

#include "bintree_impl_begin.h"

//
// tree print functions
//

BINTREE_LKG_ void BINTREE_MANGLE_(avl_print)(
        BINTREE_TRPAR_ BINTREE_POINTER root_,FILE* file_);
BINTREE_LKG_ void BINTREE_MANGLE_(rb_print)(
        BINTREE_TRPAR_ BINTREE_POINTER root_,FILE* file_);

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_TREE_VALIDATE_H_INCLUDED
