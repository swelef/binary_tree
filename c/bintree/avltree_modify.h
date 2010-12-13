//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_AVLTREE_MODIFY_H_INCLUDED
#define VMARKO_AVLTREE_MODIFY_H_INCLUDED

#include "bintree_base.h"

#include "bintree_impl_begin.h"

// functions to modify an AVL tree
/*
 *  The class template avltree_modify provides functions to modify an AVL tree
 *  described by the BINTREE_* macros. In addition to the basic macros, see
 *  bintree_base, the macro BINTREE_BALANCE_TYPE defines the AVL balance type,
 *  the values are defined by macros BINTREE_LEFT_HEAVY, BINTREE_RIGHT_HEAVY
 *  and BINTREE_BALANCED and the balance of a node is accessed by
 *  BINTREE_BALANCE and manipulated by BINTREE_SET_BALANCE.
 *
 *  The functions provided by this template are avl_insert and avl_erase.
 */

#if defined(BINTREE_POINTER)

// insert a node at specified position
BINTREE_LKG_ void BINTREE_MANGLE_(avl_insert)(
        BINTREE_TRPAR_ BINTREE_POINTER root_,BINTREE_POINTER node_,
        BINTREE_MANGLE_(pos_type) pos_);
// erase a node
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(avl_erase)(
        BINTREE_TRPAR_ BINTREE_POINTER root_,BINTREE_POINTER node_);

#endif // defined(BINTREE_POINTER)

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_AVLTREE_MODIFY_H_INCLUDED
