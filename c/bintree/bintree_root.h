//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_BINTREE_ROOT_H_INCLUDED
#define VMARKO_BINTREE_ROOT_H_INCLUDED

#include "bintree_impl_begin.h"

// functions to query and modify the root of a binary tree
/*
 *  The class template bintree_root provides functions for querying and
 *  modifying a binary tree whose links are described by the BINTREE_* macros,
 *  see the description in bintree_base.
 *
 *  The functions provided by the template are the getters front(.), back(.)
 *  and top(.), with const versions prefixed by 'c', and setters set_front(.,.)
 *  set_back(.,.) and set_top(.,.).
 *
 *  Note that the functions provided by this template are for low level tree
 *  manipulation and usually don't need external linkage, see the description
 *  of the BINTREE_LINKAGE macro in bintree_base.
 */

// ----------------------------------------------------------------------------
// non-const functions
//

#if defined(BINTREE_POINTER)

BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(front)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(back)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_);
BINTREE_LKG_ BINTREE_POINTER BINTREE_MANGLE_(top)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_);
BINTREE_LKG_ void BINTREE_MANGLE_(set_front)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_POINTER new_);
BINTREE_LKG_ void BINTREE_MANGLE_(set_back)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_POINTER new_);
BINTREE_LKG_ void BINTREE_MANGLE_(set_top)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,BINTREE_POINTER new_);

#endif // defined(BINTREE_POINTER)

// ----------------------------------------------------------------------------
// const functions
//

#if defined(BINTREE_CONST_POINTER)

BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cfront)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER root_);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(cback)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER root_);
BINTREE_LKG_ BINTREE_CONST_POINTER BINTREE_MANGLE_(ctop)(
        BINTREE_TRAITS_PARAM BINTREE_CONST_POINTER root_);

#endif // defined(BINTREE_CONST_POINTER)

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_BINTREE_ROOT_H_INCLUDED
