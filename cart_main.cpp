#include<iostream>
#include<vector>
#include "datamodel.h"

using namespace std;

vector<Product> allProducts = {
    Product(1,"Apple",26),
    Product(2,"Guava",36),
    Product(3,"Mango",56),
    Product(4,"strawberry",72),
    Product(5,"banana",26),
    Product(6,"Kiwi",190),
    Product(7,"Pineapple",48),
};

Product* chooseProduct()
{
    string ProductList;
    cout<<"Available Products "<<endl;

    for(auto product : allProducts)
    {
        ProductList.append(product.getDisplayName());
    }
    cout<<ProductList<<endl;

    cout<<"-----------------------------------"<<endl;
    string choice;
    cin>>choice;

    for(int i=0;i<allProducts.size();i++)
    {
        if(allProducts[i].getShortName()==choice)
        {
            return &allProducts[i];
        }
    }
    cout<<"Product Not Found!"<<endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if(cart.isEmpty())
        return false;

    int total=cart.getTotal();
    cout<<"Pay in Cash: ";

    int paid;
    cin>>paid;
    if(paid>=total)
    {
        cout<<"Change "<<paid-total<<endl;
        cout<<"Thank you for shopping with us! ";
        return true;
    }
    else{
        cout<<"Not Enough Cash!";
        return false;
    }
}

int main()
{
    char action;
    Cart cart;
    while(true)
    {
        cout<<" Select an action- (a)dd item, (v)iew cart,  (c)heckout"<<endl;
        cin>>action;

        if(action=='a')
        {
            Product * product = chooseProduct();
            if(product!=NULL)
            {
                cout<<" Added to Cart! "<<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }
        }
        else if(action=='v')
        {
            cout<<"------------------------------------"<<endl;
            cout<<cart.viewCart();
            cout<<"------------------------------------"<<endl;
        }
        else{
            cart.viewCart();
            if(checkout(cart))
            {
                break;
            }
        }
    }

    return 0;
}
