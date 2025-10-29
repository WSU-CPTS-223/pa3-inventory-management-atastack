#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class product
{
private:
    string id;
    string product_name;
    vector<string> categories;
public:
    product();
    product(const string& id, const string& name, vector<string>& cat) : id(id), product_name(name), categories(cat) {}

    const string& get_id() const{return id; }
    const string& get_name() const{return product_name;}
    const vector<string>& get_cat() const {return categories;}

    void print() const
    {
        cout << "ID: " << id << "\n";
        cout << "Product name: " << product_name << "\n";
        cout << "Categories: " ;

        for (size_t i = 0; i < categories.size(); i++)
        {
            cout << categories[i];
            if (i< categories.size()-1)
            {
                cout << "|";
            }
            
        }
        cout << "\n";
    }
};



#endif