//        Copyright Vladimir Marko 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BINTREE_CAT_IMPL_(x_,y_) x_##y_
#define BINTREE_CAT_(x_,y_) BINTREE_CAT_IMPL_(x_,y_)

#define BINTREE_MANGLE_(name_) BINTREE_CAT_(BINTREE_PREFIX,name_)

// helper macro for optional linkage
#if defined(BINTREE_LINKAGE)
#    define BINTREE_LKG_ BINTREE_LINKAGE
#else
#    define BINTREE_LKG_
#endif

// helper macro for optional traits param and arg
#if defined(BINTREE_TRAITS_PARAM) && defined(BINTREE_TRAITS_ARG)
#    define BINTREE_TRPAR_ BINTREE_TRAITS_PARAM
#    define BINTREE_TRARG_ BINTREE_TRAITS_ARG
#elif !defined(BINTREE_TRAITS_PARAM) && !defined(BINTREE_TRAITS_ARG)
#    define BINTREE_TRPAR_
#    define BINTREE_TRARG_
#else
#    error "Either both BINTREE_TRAITS_PARAM and BINTREE_TRAITS_ARG must be defined or none of them."
#endif

// helper macro for optional compare param and arg
#if defined(BINTREE_COMPARE_PARAM) && defined(BINTREE_COMPARE_ARG)
#    define BINTREE_CPPAR_ BINTREE_COMPARE_PARAM
#    define BINTREE_CPARG_ BINTREE_COMPARE_ARG
#elif !defined(BINTREE_COMPARE_PARAM) && !defined(BINTREE_COMPARE_ARG)
#    define BINTREE_CPPAR_
#    define BINTREE_CPARG_
#else
#    error "Either both BINTREE_COMPARE_PARAM and BINTREE_COMPARE_ARG must be defined or none of them."
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
