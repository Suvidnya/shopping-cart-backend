#include <string>
#include<unordered_map>
using namespace std;

class Item; // Forward declaration
class Cart;

class Product
{
    int id;
    string name;
    int price;

public:

    Product(){

    }

    Product(int u_id, string name, int price)
    {
        this->name = name;
        this->price = price;
        id = u_id;
    }

    string displayProduct()
    {
        return name + " : ₹" + to_string(price) + "\n";
    }

    string getshortname()
    {
        return name.substr(0, 1);
    }

    friend class Item;
    friend class Cart;
};

class Item
{
    Product product;
    int quantity;

public:
    Item(){};
    Item(Product p, int q) : product(p), quantity(q) {}

    int getItemPrice()
    {
        return quantity * product.price;
    }

    string getitemInfo()
    {
        return to_string(quantity) + " x " + product.name + "(₹" + to_string(product.price) + ")"+ "\n";
    }
    friend class Cart;
};

class Cart
{
    unordered_map<int, Item> items;

public:
  
    void addProduct(Product product){
        if(items.count(product.id)==0){
            Item newItem(product,1);
            items[product.id]=newItem;
        }
        else{
            items[product.id].quantity+=1;
        }
    }

    int getTotal(){
        int total = 0;
        for(auto itemPair : items){
            auto item = itemPair.second;
            total = total + item.getItemPrice(); 
        }
        return total;
    }


    string viewCart(){
        if(items.empty()){
            return "Cart is empty !";
        }
        string itemizedlist;
        int cart_total = getTotal();

        for(auto itemPair : items){
            auto item = itemPair.second;
            itemizedlist.append(item.getitemInfo());
        }

        return itemizedlist + "\n Total Amount : ₹" + to_string(cart_total) + "\n";
    }
 
    bool isEmpty(){
        return items.empty();
    }
};
