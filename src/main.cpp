#include <iostream>
#include "DLinkedlist.h"


int main()
{
    DLinkedlist<int> l;
    l.append(1);
    l.append(2);
    l.append(3);

    DLinkedlist<int>::node* nd = new DLinkedlist<int>::node;
    nd->data = 6;
    // l.append(nd);
    l.append(4);
    l.append(5);
    printLinkedList(l);
    std::cout << std::endl;
    l.prepend(nd);
    l.prepend(7);
    l.prepend(8);
    
    printLinkedList(l);
    std::cout << std::endl;

    std::cout << "l.head->right->data: " << l.head->right->data << std::endl;
    std::cout << l.getNodeAt(5).data << std::endl << std::endl;
    l.getNodeAt(7).data = 467;
    printLinkedList(l);

    std::cout << "\nTest 1\n\n";
    nd->data = 5555;

    DLinkedlist<int>::node* nd2 = new DLinkedlist<int>::node;
    nd2->data = 278;
    nd2->right = l.getNodeAtP(3)->right;
    nd2->left = l.getNodeAtP(3);
    l.getNodeAtP(3)->right->left = nd2;
    l.getNodeAtP(3)->right = nd2;

    printLinkedList(l);
    std::cout << std::endl;
    std::cout << "Detached at index 3\n";
    l.detachNode(l.getNodeAtP(3));
    printLinkedList(l);

    DLinkedlist<int>::node* nd3 = new DLinkedlist<int>::node;
    nd3->data = 2222;
    l.detachNode(l.getNodeAtP(0));
    printLinkedList(l);

    l.detachNode(nd3);

    return 0;
}