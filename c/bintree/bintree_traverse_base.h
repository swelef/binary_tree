//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_BINTREE_TRAVERSE_BASE_H_INCLUDED
#define VMARKO_BINTREE_TRAVERSE_BASE_H_INCLUDED

#include "bintree_impl_begin.h"

// helper functions to traverse a binary tree
/*
 *  The class template bintree_traverse_base provides helper functions for
 *  traversing a binary tree whose links are described by the BINTREE_* macros,
 *  see the description in bintree_base.
 *
 *  The functions provided by the template are first_left_parent_(.),
 *  first_right_parent_(.), leftmost_child(.) and rightmost_child_(.). Const
 *  versions are prefixed by 'c'.
 *
 *  Note that the functions provided by this template are for low level tree
 *  manipulation and usually don't need external linkage, see the description
 *  of the BINTREE_LINKAGE macro in bintree_base.
 */

// ----------------------------------------------------------------------------
// non-const functions
//

#if defined(BINTREE_POINTER)

BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(first_right_parent)(
        BINTREE_TRPAR_ BINTREE_POINTER node_);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(first_left_parent)(
        BINTREE_TRPAR_ BINTREE_POINTER node_);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(leftmost_child)(
        BINTREE_TRPAR_ BINTREE_POINTER node_);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(rightmost_child)(
        BINTREE_TRPAR_ BINTREE_POINTER node_);

#endif // defined(BINTREE_POINTER)

// ----------------------------------------------------------------------------
// const functions
//

#if defined(BINTREE_CONST_POINTER)

BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cfirst_right_parent)(
        BINTREE_TRPAR_ BINTREE_CONST_POINTER node_);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cfirst_left_parent)(
        BINTREE_TRPAR_ BINTREE_CONST_POINTER node_);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cleftmost_child)(
        BINTREE_TRPAR_ BINTREE_CONST_POINTER node_);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(crightmost_child)(
        BINTREE_TRPAR_ BINTREE_CONST_POINTER node_);

#endif // defined(BINTREE_CONST_POINTER)

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_BINTREE_TRAVERSE_BASE_H_INCLUDED
