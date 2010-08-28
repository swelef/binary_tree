//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_RBTREE_MODIFY_H_INCLUDED
#define VMARKO_RBTREE_MODIFY_H_INCLUDED

#include "bintree_base.h"

#include "bintree_impl_begin.h"

// functions to modify a red-black tree
/*
 *  The class template rbtree_modify provides functions to modify a red-black
 *  tree described by the BINTREE_* macros. In addition to the basic macros,
 *  see bintree_base, the macro BINTREE_COLOR_TYPE defines the red-black color
 *  type, the values are defined by by macros BINTREE_RED_COLOR and
 *  BINTREE_BLACK_COLOR, the color of a node is accessed by BINTREE_COLOR and
 *  manipulated by BINTREE_SET_COLOR.
 *
 *  The functions provided by this template are rb_insert and rb_erase.
 */

#if defined(BINTREE_POINTER)

// insert a node at specified position
BINTREE_LKG_ void BINTREE_MANGLE_(rb_insert)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_POINTER node_,
        BINTREE_MANGLE_(pos_type) pos_);

// erase a node
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(rb_erase)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_POINTER node_);

#endif // defined(BINTREE_POINTER)

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_RBTREE_MODIFY_H_INCLUDED
