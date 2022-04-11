#include <iostream>
#include "datamodels.h"
#include <vector>
using namespace std;

vector<Product> allProducts{
    Product(1, "apple", 10),
    Product(2, "mango", 20),
    Product(3, "banana", 5),
    Product(4, "custardapple", 25),
    Product(5, "pineapple", 40),
    Product(6, "watermelon", 50),
    Product(7, "grapes", 80),
    Product(8, "pomogranate", 100),

};

Product *choooseProduct()
{
    // display all the products
    string productList;
    cout << "Available products" << endl;

    for (auto product : allProducts)
    {
        productList.append(product.displayProduct());
    }
    cout << productList << endl;

    cout << "-------------------" << endl;
    cout << "Enter the first character of the product to add to your cart - ";

    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getshortname() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Product not found !" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if (cart.isEmpty())
    {
        return false;
    }

    int total = cart.getTotal();
    cout<<"Total amount to be paid is ₹"<<total<<endl;
    cout<<"Do you have any coupons? You can apply any of these coupons(Enter the coupoun code) 'SAVE30%' |  FLAT50OFF"<<endl;
    string c;
    cin>>c;
    if(c=="SAVE30%"){
        total = total - (total *30)/100;
    }
    else if(c=="FLAT50OFF"){
        total = total - 50;
    }
    cout<<"Yayy! Coupon is applied succesfully. Your total is now ₹"<<total<<endl;
    cout << "Pay in Cash ₹ ";             

    int paid;
    cin >> paid;

    if (paid >= total)
    {
        cout << "Change = " << paid - total << endl;
        cout << "Thank you for shopping with us !" << endl;
        return true;
    }
    else
    {
        cout << "Not enough cash" << endl;
        return false;
    }
}

int main()
{

    char action;
    Cart cart;
    while (true)
    {
        cout << "Select an action and enter the character : a - add item | v - view cart | c - checkout (to EXIT press 'e)'" << endl;
        cin >> action;
        if (action == 'a')
        {
            // todo : add the product
            // view all products then choose the product and then add to cart 
            Product *product = choooseProduct();
            if (product != NULL)
            {
                cout << "Added to the cart " + product->displayProduct();
                cart.addProduct(*product);
            }
        }
        else if (action == 'v')
        {
            // view the cart
            cout << "-----------------" << endl;
            cout << cart.viewCart();
            cout << "-----------------" << endl;
        }
        else if (action == 'c')
        {
            // checkout
            cart.viewCart();            
            if (checkout(cart))
            {
                break;
            }
        }
        else if(action =='e'){
            exit(0);
        }
        else
        {
            cout << "PLZ ENTER A VALID CHARACTER" << endl;
        }
    }
}





