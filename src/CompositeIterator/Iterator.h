//
// Created by yexin on 2020/8/8.
//

#ifndef TEST_ITERATOR_H
#define TEST_ITERATOR_H

#include<stack>

class MenuComponent;
class Menu;

//迭代器抽象基类Iterator
class Iterator{
public:
    virtual ~Iterator()=default;

    virtual bool hasNext()=0;
    virtual MenuComponent* next()=0;
};


//空迭代器NullIterator
class NullIterator:public Iterator{
public:

    bool hasNext() override;
    MenuComponent* next() override;
};


//菜单迭代器，适用于各种菜单
class MenuIterator:public Iterator{
    Menu* pmenu= nullptr;
    int pos=0;

public:
    MenuIterator(Menu*menu);

    bool hasNext() override;
    MenuComponent* next() override;
};


//组合迭代器，适用于任何一个菜单组件，但不打印传入菜单组件类对象本身，而是打印它的孩子们
class CompositeIterator:public Iterator{
    std::stack<Iterator*>* pstack= nullptr;

public:
    CompositeIterator(Iterator*iterator);
    ~CompositeIterator();

    bool hasNext() override;
    MenuComponent* next() override;
};

#endif //TEST_ITERATOR_H