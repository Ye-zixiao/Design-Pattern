//
// Created by yexin on 2020/8/8.
//

#ifndef TEST_MENUCOMPONENT_H
#define TEST_MENUCOMPONENT_H

#include<string>
#include<vector>
class Iterator;


//菜单组件抽象基类MenuComponent
class MenuComponent{
public:
    virtual ~MenuComponent()=default;

    virtual void add(MenuComponent*menuComponent);
    virtual void remove(MenuComponent*menuComponent);
    virtual MenuComponent* getChild(int i);
    virtual Iterator* createIterator();

    virtual std::string getName() const;
    virtual double getPrice() const;

    virtual void print() const=0;
};


//菜单项类MenuItem
class MenuItem:public MenuComponent{
    std::string name;
    double price;

public:
    MenuItem(const std::string&str,double p);

    std::string getName() const override;
    double getPrice() const override;
    Iterator* createIterator() override;

    void print() const override;
};


//菜单抽象基类Menu
class Menu:public MenuComponent{
    std::string name;

public:
    Menu(const std::string&str);

    virtual int size() const=0;
    std::string getName() const override;
    void print() const override final;
};


//向量实现的菜单类VecMenu
class VecMenu:public Menu{
    std::vector<MenuComponent*> *pMenuComVec=nullptr;

public:
    VecMenu(const std::string&str);
    ~VecMenu();

    int size() const override;
    void add(MenuComponent*menuComponent) override;
    MenuComponent* getChild(int i) override;
    Iterator* createIterator() override;
};


//数组实现的菜单类ArrMenu，容量有限
class ArrMenu: public Menu{
    MenuComponent* menuComponentArr[5];
    int pos=0;

public:
    ArrMenu(const std::string&str);
    ~ArrMenu();

    int size() const override;
    void add(MenuComponent*menuComponent) override;
    MenuComponent* getChild(int i) override;
    Iterator* createIterator() override;
};

#endif //TEST_MENUCOMPONENT_H