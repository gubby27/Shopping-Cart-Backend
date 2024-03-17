#include<iostream>
#include<vector>
#include<string>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(2, "mango", 16),
    Product(3, "guava", 36),
    Product(4, "banana", 56),
    Product(5, "strawberry", 29),
    Product(6, "pineapple", 20),
};

Product *chooseProduct(){
    // Display list of products
    string productList;
    cout<<"Available Products "<<endl;

    for(auto product : allProducts){
        productList.append(product.getDisplayName());
    }
    cout<<productList<<endl;
    cout<<"---------------------------------"<<endl;

    string choice;
    cin>>choice;

    for(int i =0; i < allProducts.size(); i++){
        if(allProducts[i].getShortName() == choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not found!"<<endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout<<"Pay in cash";

    int paid;
    cin>>paid;

    if(paid>= total){
        cout<< "Change "<<paid - total << endl;
        cout<<"Thank you for shopping!";
        return true;
    }
    else{
        cout<<"Not enough cash!";
        return false;
    }
}

int main(){

    char action;
    Cart cart;
    while(true){
        cout<<"Select an action -  (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin >> action;
        if(action == 'a'){
            // Todo: Add to cart
            // View all Products + choose Product + add to the cart
            Product * product = chooseProduct();
            if(product != NULL){
                cout<<"Added to the cart " <<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }
        }
        else if(action == 'v'){
            // View the cart
            cout<<"----------------------------------" <<endl;
            cout<<cart.viewCart();
            cout<<"----------------------------------" <<endl;
        }
        else{
            // Checkout
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }


    return 0;
}