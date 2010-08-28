//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_RBTREE_H_INCLUDED
#define VMARKO_RBTREE_H_INCLUDED

// standard red black tree interface
/*
 *  The class template rbtree provides the standard functions to traverse and
 *  modify a red-black tree described by the BINTREE_* macros, see bintree_base
 *  and rbtree_modify for the requirements. It is a simple aggregation of the
 *  appropriate bintree interfaces.
 *
 *  If BINTREE_LINKAGE is defined, all functions will have that linkage,
 *  otherwise the implementation (rbtree.tc) will use "static" for the helper
 *  functions and default (i.e. extern) linkage for the main functions.
 */

#include "bintree_base.h"
#include "bintree_traverse.h"
#include "bintree_search.h"
#include "rbtree_modify.h"

#endif // #ifndef VMARKO_RBTREE_H_INCLUDED
