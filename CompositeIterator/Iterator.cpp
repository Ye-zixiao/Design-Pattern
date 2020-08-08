//
// Created by yexin on 2020/8/8.
//

#include<stdexcept>
#include"Iterator.h"
#include"MenuComponent.h"

//空迭代器类NullIterator成员函数定义：
bool NullIterator::hasNext() {
    return false;
}

MenuComponent* NullIterator::next() {
    throw std::runtime_error("");
}


//带单迭代器类MenuIterator成员函数定义：
MenuIterator::MenuIterator(Menu *menu):
    pmenu(menu){
    //...
}

bool MenuIterator::hasNext() {
    return pos<pmenu->size();
}

MenuComponent* MenuIterator::next() {
    return pmenu->getChild(pos++);
}


//组合迭代器类CompositeIterator成员函数定义：
CompositeIterator::CompositeIterator(Iterator *iterator):
    pstack(new std::stack<Iterator*>()){
    pstack->push(iterator);
}

CompositeIterator::~CompositeIterator() {
    if(pstack)
        delete pstack;
}

bool CompositeIterator::hasNext() {
    if(pstack->empty())
        return false;
    else{
        auto& pIterator=pstack->top();
        if(!pIterator->hasNext()){
            delete pstack->top();
            pstack->pop();
            return hasNext();
        }
        return true;
    }
}

MenuComponent* CompositeIterator::next() {
    if(hasNext()){
        MenuComponent* retp=pstack->top()->next();
        pstack->push(retp->createIterator());
        return retp;
    }
    throw std::runtime_error("");
}