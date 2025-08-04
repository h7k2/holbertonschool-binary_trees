# 0x1D. C - Binary Trees

## 📚 Description

Ce projet a pour objectif de comprendre et manipuler les **arbres binaires** en langage C.  
Tu vas construire, parcourir, analyser et modifier des arbres binaires simples, ainsi que certains types spécifiques comme les **AVL**, **BST**, ou **Max Binary Heap**.

---

## 🎯 Objectifs pédagogiques

À la fin du projet, tu seras capable d'expliquer :

- Ce qu’est un **arbre binaire**
- La **différence entre un arbre binaire simple et un Binary Search Tree (BST)**
- Les **gains en complexité** par rapport aux listes chaînées
- Ce que sont la **profondeur**, la **hauteur**, la **taille** d’un arbre
- Les différents **parcours** (préfixe, infixe, postfixe)
- Ce qu’est un arbre **complet**, **plein**, **parfait**, **équilibré**

---

## 📁 Structure des données utilisée

```c
/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;