//
// Created by yexin on 2020/8/8.
//

#include<iostream>
#include"MenuComponent.h"
#include"Iterator.h"

class Waitress{
    MenuComponent* allMenus= nullptr;

public:
    Waitress(MenuComponent* menuComponent):
        allMenus(menuComponent){
        //...
    }
    ~Waitress(){
        if(allMenus)delete allMenus;
    }

    void print() const{
        CompositeIterator* compositeIterator=
                new CompositeIterator(allMenus->createIterator());
        while(compositeIterator->hasNext())
            compositeIterator->next()->print();
    }

};

int main(void)
{
    MenuComponent* dinerMenu=new VecMenu("Diner Menu");
    MenuComponent* pancakeHouseMenu=new ArrMenu("Pancake House Menu");
    MenuComponent* cafeMenu=new VecMenu("Cafe Menu");
    MenuComponent* dessertMenu=new ArrMenu("Dessert Menu");

    VecMenu* allMenus=new VecMenu("All Menus");{
        allMenus->add(dinerMenu);
        allMenus->add(pancakeHouseMenu);
        allMenus->add(cafeMenu);
    }

    dinerMenu->add(new MenuItem("Soup",2.99));
    dinerMenu->add(new MenuItem("Rice",1.09));
    dinerMenu->add(new MenuItem("Meat",5.99));
    dessertMenu->add(new MenuItem("dessert cake",2.99));
    dinerMenu->add(dessertMenu);

    pancakeHouseMenu->add(new MenuItem("cake",3.99));
    pancakeHouseMenu->add(new MenuItem("water",0.99));

    cafeMenu->add(new MenuItem("cafe",1.99));
    cafeMenu->add(new MenuItem("orange water",1.19));

    Waitress waitress(allMenus);
    waitress.print();
}