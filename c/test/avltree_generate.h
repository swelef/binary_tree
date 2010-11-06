//        Copyright Vladimir Marko 2006 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_AVLTREE_GENERATE_H_INCLUDED
#define VMARKO_AVLTREE_GENERATE_H_INCLUDED

#include "bintree_impl_begin.h"

/// AVL-tree generate
/**
 * The class template avltree_generate provides means to generate all AVL trees
 * with a given number of nodes. It is parametrised by the BINTREE_* macros
 * describing the nodes of the AVL tree and additional STORAGE_* macros that
 * describe the storage of the nodes. STORAGE_ITERATOR defines the iterator
 * type, STORAGE_NEXT(.) and STORAGE_PREV(.) define the traversal and
 * STORAGE_ITER_TO_PTR(.) translates a storage iterator to BINTREE_POINTER.
 * The constructor takes pointer to the root and storage range with
 * pre-allocated nodes where the tree will be manipulated in-place.
 *
 * The ordering of the generated trees is as follows. The tree with higher
 * depth is earlier, if the depths are equal the tree with less nodes in the
 * left branch is earlier. If that comparison doesn't yield a decissive result,
 * recursively compare left subtrees, if they are equal recursively compare
 * right subtrees.
 */

typedef struct BINTREE_MANGLE_(avl_generate) BINTREE_MANGLE_(avl_generate);

BINTREE_LKG_ BINTREE_MANGLE_(avl_generate)* BINTREE_MANGLE_(avl_generate_alloc)(
        BINTREE_TRAITS_PARAM BINTREE_POINTER root_,STORAGE_ITERATOR storage_begin_,STORAGE_ITERATOR storage_end_);
BINTREE_LKG_ void BINTREE_MANGLE_(avl_generate_free)(
        BINTREE_TRAITS_PARAM BINTREE_MANGLE_(avl_generate)* generate_);

BINTREE_LKG_ void BINTREE_MANGLE_(avl_generate_first)(
        BINTREE_TRAITS_PARAM BINTREE_MANGLE_(avl_generate)* generate_);
BINTREE_LKG_ int BINTREE_MANGLE_(avl_generate_next)(
        BINTREE_TRAITS_PARAM BINTREE_MANGLE_(avl_generate)* generate_);

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_AVLTREE_GENERATE_H_INCLUDED
