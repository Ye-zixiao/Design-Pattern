//
// Created by yexin on 2020/8/8.
//

#include<stdexcept>
#include<iostream>
#include<algorithm>
#include"Iterator.h"
#include"MenuComponent.h"

//抽象基类MenuComponent成员函数定义：
void MenuComponent::add(MenuComponent*menuComponent){
    throw std::runtime_error("");
}

void MenuComponent::remove(MenuComponent *menuComponent) {
    throw std::runtime_error("");
}

MenuComponent* MenuComponent::getChild(int i) {
    throw std::runtime_error("");
}

Iterator* MenuComponent::createIterator() {
    throw std::runtime_error("");
}

std::string MenuComponent::getName() const {
    throw std::runtime_error("");
}

double MenuComponent::getPrice() const {
    throw std::runtime_error("");
}


//菜单项类MenuItem成员函数定义：
MenuItem::MenuItem(const std::string &str, double p):
    name(str),price(p){
   //...
}

std::string MenuItem::getName() const {
    return name;
}

double MenuItem::getPrice() const {
    return price;
}

Iterator* MenuItem::createIterator() {
    return new NullIterator();
}

void MenuItem::print() const {
    std::cout<<"Name: "<<getName()<<", Price: "
        <<getPrice()<<std::endl;
}


//菜单抽象类Menu成员函数定义：
Menu::Menu(const std::string &str):
    name(str){
    //...
}

std::string Menu::getName() const {
    return name;
}

void Menu::print() const {
    std::cout<<"\nMENU("<<getName()<<"): "<<std::endl;
}


//向量菜单类VecMenu成员函数定义：
VecMenu::VecMenu(const std::string &str):
    Menu(str),pMenuComVec(new std::vector<MenuComponent*>()){
    //...
}

VecMenu::~VecMenu() {
    if(pMenuComVec){
        std::for_each(pMenuComVec->begin(),pMenuComVec->end(),
                      [](MenuComponent*p){if(p)delete p;});
        delete pMenuComVec;
    }
}

int VecMenu::size() const {
    return pMenuComVec->size();
}

void VecMenu::add(MenuComponent *menuComponent) {
    if(!pMenuComVec)
        throw std::runtime_error("");
    pMenuComVec->push_back(menuComponent);
}

MenuComponent* VecMenu::getChild(int i){
    if(i>=0&&i<size())
        return (*pMenuComVec)[i];
    throw std::runtime_error("");
}

Iterator* VecMenu::createIterator() {
    return new MenuIterator(this);
}


//数组菜单类ArrMenu成员函数定义：
ArrMenu::ArrMenu(const std::string &str):
    Menu(str){
    //...
}

ArrMenu::~ArrMenu() {
    if(size()>0){
        while(pos--)
            delete menuComponentArr[pos];
    }
}

int ArrMenu::size() const{
    return pos;
}

void ArrMenu::add(MenuComponent *menuComponent) {
    if(size()<5){
        menuComponentArr[pos++]=menuComponent;
    }
    else throw std::runtime_error("");
}

MenuComponent* ArrMenu::getChild(int i) {
    if(i>=0&&i<size())
        return menuComponentArr[i];
    throw std::runtime_error("");
}

Iterator* ArrMenu::createIterator() {
    return new MenuIterator(this);
}