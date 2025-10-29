#ifndef LINK_LIST_H
#define LINK_LIST_H

template<typename Obj>
struct Link_list
{
    Obj data;
    Link_list* nxt;

    Link_list(const Obj val) : data(val), nxt(nullptr) {}
};

template<typename Obj>
class Link_list
{
private:
    Link_list<Obj>* head;
    Link_list<Obj>* tail;

public:
    Link_list() : head(nullptr), tail(nullptr) {}
    ~Link_list(){clear();}

    void insert(const Obj& val)
    {
        Link_list<Obj>* new_node = new Link_list<Obj>(val);
        if (tail == nullptr)
        {
            head = tail = new_node;
        }
        else
        {
            tail->nxt = new_node;
            tail = new_node;
        }
    }

    void prepend(const Obj& val)
    {
        Link_list<Obj>* new_node = new Link_list<Obj>(val);
        if (head == nullptr)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->nxt = head;
            head = new_node;
        }
        
    }

    bool rm(const Obj& val)
    {
        if (head == nullptr) return false;
        
        if (head->data == val) 
        {
            List_list<Obj>* temp = head;
            head = head->nxt;
            if (head == nullptr) tail = nullptr;
            delete temp;
           
            return true;
        }
        
        List_list<Obj>* curr = head;
        while (curr->nxt != nullptr && curr->nxt->data != val) 
        {
            curr = curr->nxt;
        }
        
        if (curr->nxt != nullptr) {
            List_list<Obj>* temp = curr->nxt;
            curr->nxt = temp->nxt;
            if (temp == tail) tail = curr;
            delete temp;
            
            return true;
        }
        return false;
    
    }

    void clear()
    {
        Link_list<Obj>* curr = head;
        while (curr != nullptr)
        {
            Link_list<Obj>* temp = curr;
            curr = curr->nxt;
            delete temp;
        }
        head = tail = nullptr;
    }


};






#endif