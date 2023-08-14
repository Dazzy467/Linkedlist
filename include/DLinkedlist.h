#pragma once
#include <exception>

class NodeNotFoundExcept : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Node not found!";
    }
};


template<typename T>
class DLinkedlist
{
public: // Node structure
    struct node
    {
        T data;
        node* left;
        node* right;
    };

    node* head;
    node* tail;


public: // Constructor
    DLinkedlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~DLinkedlist()
    {
        //Hapus data jika out-of-scope
        node* toDelete = this->head;

        while(toDelete != NULL)
        {
            node* tempDel = toDelete; 
            toDelete = toDelete->right;
            delete tempDel;
        }
    }

public: // Method
    void append(const T& _data)
    {
        node* temp_node = this->head;
        node* new_node = new node;

        new_node->data = _data;

        // Jika head kosong
        if (this->head == NULL)
        {
            new_node->right = NULL;
            new_node->left = NULL;
            this->head = new_node;
            this->tail = new_node;
            return;
        }

        // Jika head berisi

        // Jalan ke kanan
        while(temp_node->right != NULL)
            temp_node = temp_node->right;
        
        new_node->left = this->tail;
        new_node->right = NULL;
        temp_node->right = new_node;
        temp_node = new_node;
        this->tail = temp_node;
        return;
    }

    void append(node* new_node)
    {
        node* temp_node = this->head;
        if (new_node != NULL)
        {
            // Jika head kosong
            if (this->head == NULL)
            {
                new_node->right = NULL;
                new_node->left = NULL;
                this->head = new_node;
                this->tail = new_node;
                return;
            }

            // Jika head berisi

            // Jalan ke kanan
            while(temp_node->right != NULL)
                temp_node = temp_node->right;
            
            new_node->left = this->tail;
            new_node->right = NULL;
            temp_node->right = new_node;
            temp_node = new_node;
            this->tail = temp_node;
        }

        return;
    }

    void prepend(const T& _data)
    {
        node* temp_node = this->head;
        node* new_node = new node;

        new_node->data = _data;

        // Jika head kosong
        if (this->head == NULL)
        {
            new_node->right = NULL;
            new_node->left = NULL;
            this->head = new_node;
            this->tail = new_node;
            return;
        }

        // Jika head berisi
        temp_node->left = new_node;
        new_node->right = temp_node;
        new_node->left = NULL;
        this->head = new_node;
        return;
    }

    void prepend(node* new_node)
    {
        node* temp_node = this->head;
        
        // Jika head kosong
        if (this->head == NULL)
        {
            new_node->right = NULL;
            new_node->left = NULL;
            this->head = new_node;
            this->tail = new_node;
            return;
        }

        // Jika head berisi
        temp_node->left = new_node;
        new_node->right = temp_node;
        new_node->left = NULL;
        this->head = new_node;
        return;
    }

    node& getNodeAt(size_t index)
    {
        node* temp_node = this->head;
        node* toReturn = this->head;
        size_t it = 0;
        while(it < index && temp_node != NULL)
        {
            temp_node = temp_node->right;
            it++;
        }
        if (temp_node != NULL)
            toReturn = temp_node;
        return *toReturn;
    }

    node* getNodeAtP(size_t index)
    {
        node* temp_node = this->head;
        node* toReturn = this->head;
        size_t it = 0;
        while(it < index && temp_node != NULL)
        {
            temp_node = temp_node->right;
            it++;
        }
        if (temp_node != NULL)
            toReturn = temp_node;
        return toReturn;
    }

    const node getNodeAt(size_t index) const
    {
        node* temp_node = this->head;
        node* toReturn = this->head;
        size_t it = 0;
        while(it < index && temp_node != NULL)
        {
            temp_node = temp_node->right;
            it++;
        }
        if (temp_node != NULL)
            toReturn = temp_node;
        return *toReturn;
    }

    void detachNode(node* _node)
    {
        node* temp_node = this->head;
        node* toDetach = this->head;

        while(temp_node != _node && temp_node != NULL)
            temp_node = temp_node->right;

        if (temp_node == _node)
        {
            toDetach = _node;

            if(toDetach != this->head && toDetach != this->tail)
            {
                toDetach->right->left = toDetach->left;
                toDetach->left->right = toDetach->right;
            }
            else if (toDetach == this->head)
            {

                this->head = toDetach->right;
                this->head->left = NULL;
                
            }
            else if (toDetach == this->tail)
            {
                this->tail = toDetach->left;
                this->tail->right = NULL;
            }



            delete toDetach;
            return;
        }
        else {
            throw NodeNotFoundExcept();
            return;
        };
        
        
    }
private:

};

template<typename T>
void printLinkedList(const DLinkedlist<T>& l)
{
    DLinkedlist<int>::node* nd = l.head;


    while(nd != NULL)
    {
        if (nd->left == NULL)
            std::cout << "[NULL]<-[" << nd->data << "]->";
        else if (nd->right != NULL)
            std::cout << "<-[" << nd->data << "]->";
        else std::cout << "<-[" << nd->data << "]->[NULL]";
        nd = nd->right;

        
    }
    std::cout << std::endl;
}