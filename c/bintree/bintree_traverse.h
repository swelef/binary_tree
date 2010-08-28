//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_BINTREE_TRAVERSE_H_INCLUDED
#define VMARKO_BINTREE_TRAVERSE_H_INCLUDED

#include "bintree_impl_begin.h"

// functions to traverse a binary tree
/*
 *  The class template bintree_traverse provides functions for traversing a
 *  binary tree whose links are described by the BINTREE_* macros, see the
 *  description in bintree_base.
 *
 *  The functions provided by the template are begin(.), end(.), next(.) and
 *  prev(.) for non-const pointers and cbegin(.), cend(.), cnext(.) and
 *  cprev(.) for const pointers.
 */

// ----------------------------------------------------------------------------
// non-const functions
//

#if defined(BINTREE_POINTER)

BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(begin)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(end)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(next)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER node_);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(prev)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER node_);

#endif // defined(BINTREE_POINTER)

// ----------------------------------------------------------------------------
// const functions
//

#if defined(BINTREE_CONST_POINTER)

BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cbegin)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER root_);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cend)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER root_);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cnext)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER node_);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cprev)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER node_);

#endif // defined(BINTREE_CONST_POINTER)

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_BINTREE_TRAVERSE_H_INCLUDED
