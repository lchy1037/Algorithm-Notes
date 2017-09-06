
// node with a next and element field; element is a pair<const K,E>

#ifndef PAIRNODE_H
#define PAIRNODE_H

#include <utility>
using namespace std;

template <typename K, typename E>
struct pairNode 
{
   typedef pair<const K, E> pairType;
   pairType element;
   pairNode<K,E> *next;

   pairNode(const pairType& thePair):element(thePair){}
   pairNode(const pairType& thePair, pairNode<K,E>* theNext)
            :element(thePair){next = theNext;}
};

#endif
