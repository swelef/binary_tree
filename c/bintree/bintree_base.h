//        Copyright Vladimir Marko 2005 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef VMARKO_BINTREE_BASE_H_INCLUDED
#define VMARKO_BINTREE_BASE_H_INCLUDED

#include "bintree_impl_begin.h"

/*
 *  The following are the shared macros used for all bintree templates.
 *
 *  All template functions are prefixed with BINTREE_PREFIX and by default they
 *  have external linkage. The linkage can be changed by defining the macro
 *  BINTREE_LINKAGE. This can be for example "static" (or also "static inline")
 *  to make functions local to the translation unit. BINTREE_LINKAGE can be
 *  defined differently for different bintree units if done with care.
 *
 *  The tree node link types are defined by macros BINTREE_{,CONST_}POINTER and
 *  the singular value BINTREE_NULL is used to indicate no node in various
 *  contexts. If any of the BINTREE_{,CONST_}POINTER macros is not defined,
 *  associated functions (non-const or const) will not be defined.
 *
 *  The macros BINTREE_{,C}{LEFT,RIGHT,PARENT}, where the 'C' denotes const
 *  versions, are used to retrieve adjacent nodes and the topology of the tree
 *  is modified by macros BINTREE_SET_{LEFT,RIGHT,PARENT}
 *
 *  The macro BINTREE_TRAITS_PARAM can be defined either to expand to an empty
 *  string or to a parameter definition followed by a comma to allow the use of
 *  stateful traits in node-related macros. The macro BINTREE_TRAITS_ARG will
 *  be used to pass that parameter to other functions and must be defined
 *  appropriately, i.e. either empty or the name of the argument followed by a
 *  comma.
 *
 *  Identifiers matching the pattern BINTREE_[_A-Z]+_ are reserved for macro
 *  names in the bintree library implementation. Identifiers matching the
 *  pattern [a-z][_a-z]*_ are reserved for use as local viariable names, thus
 *  they must not be used for macro names while including any of the bintree
 *  header or source files, but may otherwise be used freely. Any other names
 *  used by bintree units will be mentioned by the units using them. This does
 *  not apply to identifiers containing two consecutive underscores as these
 *  are already reserved for the C/C++ language/library implementation.
 */

// bintree base definitions
/*
 *  The class template bintree_base provides the definition of the type
 *  pos_type and the function init for a binary tree described by the BINTREE_*
 *  macros, see above. Both are provided only for modifiable trees, i.e. when
 *  the BINTREE_POINTER macro is defined.
 *
 *  The type pos_type specifies the insertion position in a binary tree, see
 *  its description for details.
 *
 *  The function init initializes the root of an empty tree.
 *
 *  The names pt_node and pt_left are used as struct members and must not be
 *  used in any conflicting way.
 */

#if defined(BINTREE_POINTER)

// insertion position type
/*
 *  The name of this struct is the concatenation of the BINTREE_PREFIX macro
 *  expansion and pos_type.
 *
 *  The insertion position is a pair of a pointer to the node under which the
 *  new node should be inserted and a flag specifying whether it should be
 *  inserted as the left (1) or right (0) child. During the insertion the tree
 *  may be rebalanced, thus the position doesn't guarantee the final relation
 *  of the nodes.
 */
typedef struct BINTREE_MANGLE_(pos_type){
    BINTREE_POINTER pt_node;
    int pt_left;
} BINTREE_MANGLE_(pos_type);

// initialize the links in root
BINTREE_LKG_ void BINTREE_MANGLE_(init)(
        BINTREE_TRPAR_ BINTREE_POINTER root_);

#endif // defined(BINTREE_POINTER)

#include "bintree_impl_end.h"

#endif // #ifndef VMARKO_BINTREE_BASE_H_INCLUDED
