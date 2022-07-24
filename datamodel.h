// Product, Item, Cart (HeaderFile) -> Project Model Structure
#include<string>
#include<unordered_map>
using namespace std;

class Item;

class Product{
    int id;
    string name;
    float price;

public:
    Product()
    {
    }

    Product(int u_id, string name, float price)                 //Assignment to constructor
    {
        id=u_id;
        this->price=price;
        this->name=name;
    }

    string getDisplayName()
    {
        return name + ": " + to_string(price) + "\n";
    }

    string getShortName()
    {
        return name.substr(0,1);
    }

    friend class Item;
    friend class Cart;

};


class Item{

    Product product;
    int quantity;

public:

    Item()
    {

    }
    Item(Product p, int q):product(p), quantity(q){}            //Initialization

    int getItemPrice()
    {
        return quantity * product.price;
    }

    string getItemInfo()
    {
        return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity * product.price) + '\n' ;
    }

    friend class Cart;
};

class Cart{
    unordered_map<int,Item> items;

public:

    void addProduct(Product product)
    {
        if(items.count(product.id)==0)
        {
            Item newItem(product,1);
            items[product.id]=newItem;
        }
        else{
            items[product.id].quantity +=1;
        }
    }

    int getTotal()
    {
        int total=0;
        for(auto itemPair : items)
        {
            auto item = itemPair.second;
            total+= item.getItemPrice();
        }
        return total;
    }

    string viewCart()
    {
        if(items.empty())
        {
            return "Cart is Empty";
        }
        string itemizedList;
        int cart_total= getTotal();

        for(auto itemPair : items)
        {
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());
        }

        return itemizedList + "\n Total Amount : Rs. " + to_string(cart_total) + '\n';
    }

    bool isEmpty()
    {
        return items.empty();
    }
};
