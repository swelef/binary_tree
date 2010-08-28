//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_BINTREE_SEARCH_H_INCLUDED
#define VMARKO_BINTREE_SEARCH_H_INCLUDED

#include "bintree_base.h"

#include "bintree_impl_begin.h"

// functions for serching in a binary tree
/*
 *  The class template bintree_search provides functions for searching in a
 *  binary tree described by the BINTREE_* macros. In addition to the basic
 *  macros, see bintree_base, the macro BINTREE_KEY_TYPE defines the key type,
 *  the key is extracted by BINTREE_KEY and the comparison is performed by the
 *  total order BINTREE_COMPARE. Similar to the BINTREE_TRAITS_PARAM and
 *  BINTREE_TRAITS_ARG, stateful comparison object can be supplied by the
 *  BINTREE_COMPARE_PARAM and BINTREE_COMPARE_ARG macros except that the
 *  comma must be at the beginning as the comparator may be the last argument.
 *
 *  The basic search functions provided by the template are lower_bound(.),
 *  upper_bound(.) and find(.), prefixed with 'c' for const versions.
 *
 *  Additionaly, there are functions search for insertion positions in trees
 *  with both unique and equal keys, called insert_pos_unique(.) and
 *  insert_pos_equal(.), respectively, with suffix "_hint" for hinted versions.
 */

#if defined(BINTREE_POINTER)

BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(find)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(lower_bound)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(upper_bound)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM);

BINTREE_LKG_ BINTREE_MANGLE_(pos_type) BINTREE_MANGLE_(insert_pos_equal)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM);
BINTREE_LKG_ BINTREE_MANGLE_(pos_type) BINTREE_MANGLE_(insert_pos_unique)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM);
BINTREE_LKG_ BINTREE_MANGLE_(pos_type) BINTREE_MANGLE_(insert_pos_equal_hint)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM,
        BINTREE_POINTER hint_);
BINTREE_LKG_ BINTREE_MANGLE_(pos_type) BINTREE_MANGLE_(insert_pos_unique_hint)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM,
        BINTREE_POINTER hint_);

#endif // defined(BINTREE_POINTER)

#if defined(BINTREE_CONST_POINTER)

BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cfind)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(clower_bound)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cupper_bound)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER root_,BINTREE_KEY_TYPE key_ BINTREE_COMPARE_PARAM);

#endif // defined(BINTREE_CONST_POINTER)

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_BINTREE_SEARCH_H_INCLUDED
