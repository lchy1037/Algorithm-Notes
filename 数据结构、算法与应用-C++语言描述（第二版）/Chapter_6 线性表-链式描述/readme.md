# 1. 线性表---链式描述

STL 的容器类 list 使用带有**头结点**的**双向循环链表**来描述实例。

链表用到的词汇表：
- **单向链表（chain or singly linked list）**。令 x 是一个单向链表，当且仅当 x.firstNode=NULL 时，x 为空表。如果 x 非空，则 x.firstNode 指向链表的第一个节点，即首节点。第一个节点指向第二个节点，依次类推。最后一个节点的链指针为 NULL；
- **单向循环链表（singly linked circular list）**。这种链表与单向链表的唯一区别是最后一个节点反过来指向第一个节点。当循环链表 x 为空时，x.firstNode=NULL；
- **头结点（header node）**。头结点是链表的一个附加节点。有了这个节点，空表就不用作为特殊情况来处理了，程序因此变得简单。有了头节点，每个链表（包括空表）都至少包括一个节点（即头节点）。
- **双向链表（doubly linked list）**。双向链表的节点从左至右排序。节点的指针域 next 把节点从左到右链接在一起。在最右边的节点中， next 指针为 NULL。节点的另一个指针域 previous 把节点从右至左链接在一起。在最左边节点中，previous 指针为 NULL。
- **双向循环链表（circular doubly linked list）**。这种链表与双向链表的唯一区别在于，最左边节点的 previous 指针指向最右边的节点，而最右边节点的 next 指针指向最左边的节点。