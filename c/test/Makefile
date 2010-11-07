#        Copyright Vladimir Marko 2010 - 2010.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

BINTREE_HEADERS = bintree_base.h bintree_traverse.h avltree_modify.h rbtree_modify.h bintree_root.h bintree_balance.h bintree_traverse_base.h \
      bintree_impl_begin.h bintree_impl_end.h
BINTREE_TEMPLATES = bintree_base.tc bintree_traverse.tc avltree_modify.tc rbtree_modify.tc bintree_root.tc bintree_balance.tc bintree_traverse_base.tc
TEST_HEADERS = avltree_generate.h rbtree_generate.h tree_validate.h tree_print.h test_node.h
TEST_TEMPLATES = avltree_generate.tc rbtree_generate.tc tree_validate.tc tree_print.tc
TEST_SOURCES = bintree_test.c
DEPENDS = $(BINTREE_HEADERS:%=../bintree/%) $(BINTREE_TEMPLATES:%=../bintree/%) $(TEST_HEADERS) $(TEST_TEMPLATES) $(TEST_SOURCES)

all: bintree_test

bintree_test: $(DEPENDS)
	cc -I ../bintree/ bintree_test.c -o bintree_test
