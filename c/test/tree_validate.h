//        Copyright Vladimir Marko 2006 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_TREE_VALIDATE_H_INCLUDED
#define VMARKO_TREE_VALIDATE_H_INCLUDED

#include "bintree_impl_begin.h"

typedef void (*BINTREE_MANGLE_(failure_handler))(const char* description_,BINTREE_POINTER node_);

//
// tree validation functions
//

BINTREE_LKG_ int BINTREE_MANGLE_(avl_validate)(
        BINTREE_TRPAR_ BINTREE_POINTER root_,BINTREE_MANGLE_(failure_handler) handler_);
BINTREE_LKG_ int BINTREE_MANGLE_(rb_validate)(
        BINTREE_TRPAR_ BINTREE_POINTER root_,BINTREE_MANGLE_(failure_handler) handler_);

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_TREE_VALIDATE_H_INCLUDED
