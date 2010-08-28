//        Copyright Vladimir Marko 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BINTREE_CAT_IMPL_(x_,y_) x_##y_
#define BINTREE_CAT_(x_,y_) BINTREE_CAT_IMPL_(x_,y_)

#define BINTREE_MANGLE_(name_) BINTREE_CAT_(BINTREE_PREFIX,name_)
#if defined(BINTREE_LINKAGE)
#    define BINTREE_LKG_ BINTREE_LINKAGE
#else
#    define BINTREE_LKG_
#endif

// helper macros for functions that can be both const and non-const
#define BINTREE_PTRTYPE_IMPL_ BINTREE_POINTER
#define BINTREE_PTRTYPE_CIMPL_ BINTREE_CONST_POINTER
#define BINTREE_PTRTYPE_(c_) BINTREE_PTRTYPE##c_##IMPL_
#define BINTREE_TOPOLOGY_(c_,dir_) BINTREE##c_##dir_
#define BINTREE_FN_IMPL_(fn_) BINTREE_CAT_(BINTREE_PREFIX,fn_)
#define BINTREE_FN_CIMPL_(fn_) BINTREE_CAT_(BINTREE_PREFIX,BINTREE_CAT_(c,fn_))
#define BINTREE_FN_(c_,fn_) BINTREE_FN##c_##IMPL_(fn_)

#if defined(__cplusplus)
extern "C"{
#endif // defined(__cplusplus)
