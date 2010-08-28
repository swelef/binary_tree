//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_AVLTREE_H_INCLUDED
#define VMARKO_AVLTREE_H_INCLUDED

// standard red black tree interface
/*
 *  The class template avltree provides the standard functions to traverse and
 *  modify an AVL tree described by the BINTREE_* macros, see bintree_base and
 *  avltree_modify for the requirements. It is a simple aggregation of the
 *  appropriate bintree interfaces.
 *
 *  If BINTREE_LINKAGE is defined, all functions will have that linkage,
 *  otherwise the implementation (avltree.tc) will use "static" for the helper
 *  functions and default (i.e. extern) linkage for the main functions.
 */

#include "bintree_base.h"
#include "bintree_traverse.h"
#include "bintree_search.h"
#include "avltree_modify.h"

#endif // #ifndef VMARKO_AVLTREE_H_INCLUDED
