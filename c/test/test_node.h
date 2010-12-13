//        Copyright Vladimir Marko 2006 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_TEST_NODE_H_INCLUDED
#define VMARKO_TEST_NODE_H_INCLUDED

#include <stddef.h>

#define BINTREE_PREFIX test_tree_

//
// test node base
//

typedef struct test_node_base test_node_base;
struct test_node_base{
  test_node_base* left;
  test_node_base* right;
  test_node_base* parent;
};
typedef test_node_base test_node_root;

#define BINTREE_NULL NULL
#define BINTREE_POINTER test_node_base*
#define BINTREE_LEFT(n) ((n)->left)
#define BINTREE_RIGHT(n) ((n)->right)
#define BINTREE_PARENT(n) ((n)->parent)
#define BINTREE_SET_LEFT(n,x) ((n)->left=(x))
#define BINTREE_SET_RIGHT(n,x) ((n)->right=(x))
#define BINTREE_SET_PARENT(n,x) ((n)->parent=(x))
#define BINTREE_CONST_POINTER const test_node_base*
#define BINTREE_CLEFT(n) ((n)->left)
#define BINTREE_CRIGHT(n) ((n)->right)
#define BINTREE_CPARENT(n) ((n)->parent)

//
// test node with color, balance and key
//

typedef struct test_node test_node;
struct test_node {
    test_node_base node_;
    char color;
    char balance;
    short key;
};

#define BINTREE_COLOR_TYPE char
#define BINTREE_RED_COLOR 'R'
#define BINTREE_BLACK_COLOR 'B'
#define BINTREE_COLOR(n) (((test_node*)(n))->color)
#define BINTREE_SET_COLOR(n,x) (((test_node*)(n))->color=(x))

#define BINTREE_BALANCE_TYPE int
#define BINTREE_LEFT_HEAVY 'l'
#define BINTREE_RIGHT_HEAVY 'r'
#define BINTREE_BALANCED 'b'
#define BINTREE_BALANCE(n) (((test_node*)(n))->balance)
#define BINTREE_SET_BALANCE(n,x) (((test_node*)(n))->balance=(x))

#define BINTREE_KEY_TYPE short
#define BINTREE_CONST_KEY_TYPE const short
#define BINTREE_KEY(n) (((test_node*)(n))->key)
#define BINTREE_COMPARE(k1,k2) ((k1)<(k2))
#define BINTREE_COMPARE_PARAM
#define BINTREE_COMPARE_ARG

#endif // #ifndef VMARKO_TEST_NODE_H_INCLUDED
