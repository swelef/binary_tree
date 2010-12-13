//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_BINTREE_BALANCE_H_INCLUDED
#define VMARKO_BINTREE_BALANCE_H_INCLUDED

#include "bintree_impl_begin.h"

// functions to manipulate a balanced binary tree
/*
 *  The class template bintree_balance provides functions for manipulating
 *  a balanced binary tree described by the BINTREE_* macros, see the
 *  description in bintree_base.h; note that this template contains only
 *  non-const functions.
 *
 *  The template provides functions commonly used by tree rebalancing
 *  algorithms, namely rotate_left_(.) and rotate_right_(.). It is expected
 *  that the pointer types are light-weight while the access to the objects
 *  may be slow. Therefore the interfaces take not only the pointer to the
 *  node_ but also the pointer to the child_ which should be already known
 *  anyway.
 *
 *  The rotations take advantage of more fundamental functions, namely child
 *  replacement. These are also provided for their usefullness in the
 *  rebalancing algorithms. See functions with prefix "replace_" for details.
 *
 *  It is worth mention that when the function's name establishes
 *  certain relation between two of its arguments this relation is never
 *  checked and the links for the relation need not be set if the relation
 *  is to be changed by the function anyway. For example in the sequence
 *  "replace_left_(node,left); rotate_right_(node,left)" the first call is
 *  a useless pessimization since the function rotate_right_ never reads
 *  the links between node and left but replaces them by new values anyway.
 *
 *  Note that the functions provided by this template are for low level tree
 *  manipulation and usually don't need external linkage, see the description
 *  of the BINTREE_LINKAGE macro in bintree_base.
 */

#if defined(BINTREE_POINTER)

// replace left child, new child exists -- set its parent
BINTREE_LKG_ void BINTREE_MANGLE_(replace_left)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER left_);
// replace right child, new child exists -- set its parent
BINTREE_LKG_ void BINTREE_MANGLE_(replace_right)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER right_);
// replace left child, set child's parent if child exists
BINTREE_LKG_ void BINTREE_MANGLE_(replace_left_test)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER left_);
// replace right child, set child's parent if child exists
BINTREE_LKG_ void BINTREE_MANGLE_(replace_right_test)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER right_);
// replace left child, move the old child to new left's right if exists
BINTREE_LKG_ void BINTREE_MANGLE_(replace_left_move_child_test)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER left_);
// replace right child, move the old child to new right's left if exists
BINTREE_LKG_ void BINTREE_MANGLE_(replace_right_move_child_test)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER right_);
// clear children
BINTREE_LKG_ void BINTREE_MANGLE_(clear_children)(
        BINTREE_TRPAR_ BINTREE_POINTER node_);
// make left leaf, i.e. replace left child and set its children to BINTREE_NULL
BINTREE_LKG_ void BINTREE_MANGLE_(make_left_leaf)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER leaf_);
// make right leaf, i.e. replace right child and set its children to BINTREE_NULL
BINTREE_LKG_ void BINTREE_MANGLE_(make_right_leaf)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER leaf_);
// remove leaf, update front and back if necessary, return parent
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(remove_leaf_update_ends)(
        BINTREE_TRPAR_ BINTREE_POINTER root_,BINTREE_POINTER leaf_);
// replace both left and right moving node's old children to new positions
BINTREE_LKG_ void BINTREE_MANGLE_(replace_both_move_children_test)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,
        BINTREE_POINTER left_,BINTREE_POINTER right_);
// replace child by a new one, return parent
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(replace_child)(
        BINTREE_TRPAR_ BINTREE_POINTER old_,BINTREE_POINTER new_);
// rotate left, middle is known not to exist
BINTREE_LKG_ void BINTREE_MANGLE_(rotate_left)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER right_);
// rotate right, middle is known not to exist
BINTREE_LKG_ void BINTREE_MANGLE_(rotate_right)(
        BINTREE_TRPAR_ BINTREE_POINTER node_,BINTREE_POINTER left_);

#endif // defined(BINTREE_POINTER)

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_BINTREE_BALANCE_H_INCLUDED
