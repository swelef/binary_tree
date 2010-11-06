#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "test_node.h"

#include "bintree_base.h"
#include "bintree_traverse.h"
#include "avltree_modify.h"
#include "rbtree_modify.h"
#define BINTREE_LINKAGE static
#include "bintree_root.h"
#include "bintree_balance.h"
#include "bintree_traverse_base.h"
#include "bintree_root.tc"
#include "bintree_balance.tc"
#include "bintree_traverse_base.tc"
#undef BINTREE_LINKAGE
#include "bintree_base.tc"
#include "bintree_traverse.tc"
#include "avltree_modify.tc"
#include "rbtree_modify.tc"

#include "tree_validate.h"
#include "tree_validate.tc"
#include "tree_print.h"
#include "tree_print.tc"
#define STORAGE_ITERATOR test_node*
#define STORAGE_NEXT(i) ((i)+1)
#define STORAGE_PREV(i) ((i)-1)
#define STORAGE_ITER_TO_PTR(i) ((BINTREE_POINTER)(i))
#include "avltree_generate.h"
#include "avltree_generate.tc"
#include "rbtree_generate.h"
#include "rbtree_generate.tc"

#define MAX_AVL_SIZE 24
#define MAX_RB_SIZE 24

void avl_failure_handler(const char* description,BINTREE_POINTER node){
    fprintf(stderr,"AVL tree validation failure at node 0x%08x: %s\n",(unsigned)node,description);
}

void rb_failure_handler(const char* description,BINTREE_POINTER node){
    fprintf(stderr,"red black tree validation failure at node 0x%08x: %s\n",(unsigned)node,description);
}

void deep_print_subtree(BINTREE_POINTER top,int depth){
    if(top){
        deep_print_subtree(BINTREE_LEFT(top),depth+1);
        static const char indent[] = "                                                 ";
        fprintf(stderr, "%sdeep print, root@0x%08x, { 0x%08x, 0x%08x, 0x%08x, %c }\n",
                indent+sizeof(indent)-1-4*depth,
                (unsigned)top, (unsigned)BINTREE_PARENT(top), (unsigned)BINTREE_LEFT(top), (unsigned)BINTREE_RIGHT(top),
                BINTREE_COLOR(top));
        deep_print_subtree(BINTREE_RIGHT(top),depth+1);
    }
}

void deep_print(BINTREE_POINTER root){
    fprintf(stderr, "deep print, root@0x%08x, { 0x%08x, 0x%08x, 0x%08x }\n",
            (unsigned)root, (unsigned)BINTREE_PARENT(root), (unsigned)BINTREE_LEFT(root), (unsigned)BINTREE_RIGHT(root));
    deep_print_subtree(BINTREE_LEFT(root),1);
}

int main(){
    int ret = 0;
    test_node* storage;
    test_node* storage_backup;
    test_node_root root;
    test_node_root root_backup;
    int sz;
    size_t max_nodes = (MAX_AVL_SIZE>MAX_RB_SIZE) ? MAX_AVL_SIZE : MAX_RB_SIZE;
    storage = (test_node*)malloc(2*max_nodes*sizeof(test_node));
    if(storage==NULL){
        fprintf(stderr,"storage allocation failure\n");
        goto error0;
    }
    storage_backup = storage+max_nodes;
    #define BACKUP \
        memcpy(&root_backup,&root,sizeof(root)); \
        memcpy(storage_backup,storage,sz*sizeof(storage[0]));
    #define REVERT \
        memcpy(&root,&root_backup,sizeof(root)); \
        memcpy(storage,storage_backup,sz*sizeof(storage[0]));
    for(sz=1;sz<=MAX_AVL_SIZE;++sz){
        memset(&root,0x5a,sizeof(root));
        memset(storage,0x3c,max_nodes*sizeof(test_node));
        test_tree_init(&root);
        test_tree_avl_generate* avlgen = test_tree_avl_generate_alloc(&root,storage,storage+sz);
        if(avlgen==NULL){
            fprintf(stderr,"AVL tree generator allocation failure\n");
            free(storage);
            return 2;
        }
        do{
            #define VALIDATE(operation) \
                if(!test_tree_avl_validate(&root,avl_failure_handler)){ \
                    ret = 1; \
                    REVERT \
                    fprintf(stderr,"[AVL %d/%d] " operation " failed on this tree:\n",i,sz); \
                    test_tree_avl_print(&root,stderr); \
                }
            int i = 0;
            BACKUP
            VALIDATE("generated") // checking the test framework
            for(i=0;i!=sz;++i){
                BINTREE_POINTER node = STORAGE_ITER_TO_PTR(&storage[i]);
                // test erase
                test_tree_avl_erase(&root,node);
                VALIDATE("erase")
                REVERT
                // test insert
                if(BINTREE_LEFT(node)==NULL){
                    test_node new_node;
                    test_tree_pos_type pos = { node,1 };
                    test_tree_avl_insert(&root,STORAGE_ITER_TO_PTR(&new_node),pos);
                    VALIDATE("insert left")
                    REVERT
                }
                if(BINTREE_RIGHT(node)==0){
                    test_node new_node;
                    test_tree_pos_type pos = { node,0 };
                    test_tree_avl_insert(&root,STORAGE_ITER_TO_PTR(&new_node),pos);
                    VALIDATE("insert right")
                    REVERT
                }
            }
            #undef VALIDATE
        }while(test_tree_avl_generate_next(avlgen));
        fprintf(stdout,"AVL: %d finished at %d\n", sz, (int)time(NULL));
        fflush(stdout);
    }
    for(sz=1;sz<=MAX_RB_SIZE;++sz){
        memset(&root,0x5a,sizeof(root));
        memset(storage,0x3c,max_nodes*sizeof(test_node));
        test_tree_init(&root);
        test_tree_rb_generate* rbgen = test_tree_rb_generate_alloc(&root,storage,storage+sz);
        if(rbgen==NULL){
            fprintf(stderr,"red-black tree generator allocation failure\n");
            goto error1;
        }
        do{
            #define VALIDATE(operation) \
                if(!test_tree_rb_validate(&root,rb_failure_handler)){ \
                    ret = 1; \
                    REVERT \
                    fprintf(stderr,"[RB %d/%d] " operation " failed on this tree:\n",i,sz); \
                    test_tree_rb_print(&root,stderr); \
                }
            int i;
            BACKUP
            VALIDATE("generated")
            for(i=0;i!=sz;++i){
                BINTREE_POINTER node = STORAGE_ITER_TO_PTR(&storage[i]);
                // test erase
                test_tree_rb_erase(&root,node);
                VALIDATE("erase")
                REVERT
                // test insert
                if(BINTREE_LEFT(node)==0){
                    test_node new_node;
                    test_tree_pos_type pos = { node,1 };
                    test_tree_rb_insert(&root,STORAGE_ITER_TO_PTR(&new_node),pos);
                    VALIDATE("left insert")
                    REVERT
                }
                if(BINTREE_RIGHT(node)==0){
                    test_node new_node;
                    test_tree_pos_type pos = { node,0 };
                    test_tree_rb_insert(&root,STORAGE_ITER_TO_PTR(&new_node),pos);
                    VALIDATE("right insert")
                    REVERT
                }
            }
            #undef VALIDATE
        }while(test_tree_rb_generate_next(rbgen));
        fprintf(stdout,"RB: %d finished at %d\n", sz, (int)time(NULL));
        fflush(stdout);
    }
    #undef REVERT
    #undef BACKUP
    free(storage);
    return ret;
error1:
    free(storage);
error0:
    return 2;
}
