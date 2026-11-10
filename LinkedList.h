#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
template <class DataType>
class LinkedList;
template <class DataType>
class Node{
    friend class LinkedList<DataType>;
private:
    DataType _data;
    Node* _pNext;
public:
    Node(DataType data);
    void display();
};
template <class DataType>
Node<DataType>::Node(DataType data){
    _data = data;
    _pNext = NULL;
}
template <class DataType>
void Node<DataType>::display(){
    cout << _data << endl;
}
template <class DataType>
class LinkedList{
private:
    Node<DataType>* _pHead;
    Node<DataType>* _pTail;
    int _iSize;
public:
    LinkedList();
    ~LinkedList();
    void addTail(DataType data);
    int getSize();
    DataType& getBack();
    DataType& operator[](int index);
    void erase(int index);
    bool empty();
    void clear();
};
template <class DataType>
LinkedList<DataType>::LinkedList(){
    _pHead = NULL;
    _pTail = NULL;
    _iSize = 0;
}
template <class DataType>
LinkedList<DataType>::~LinkedList(){
    clear();
}
template <class DataType>
void LinkedList<DataType>::addTail(DataType data){
    Node<DataType>* pAdd = new Node<DataType>(data);
    if(_pHead == NULL){
        _pHead = _pTail = pAdd;
    }
    else{
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    _iSize++;
}
template <class DataType>
int LinkedList<DataType>::getSize(){
    return _iSize;
}
template <class DataType>
DataType& LinkedList<DataType>::getBack(){
    return _pTail->_data;
}
template <class DataType>
DataType& LinkedList<DataType>::operator[](int index){
    Node<DataType>* pCurrent = _pHead;
    for(int i = 0; i < index; i++){
        pCurrent = pCurrent->_pNext;
    }
    return pCurrent->_data;
}
template <class DataType>
void LinkedList<DataType>::erase(int index){
    if(index < 0 || index >= _iSize){return;}
    if(index == 0){
        Node<DataType>* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if(_pHead == NULL){
            _pTail = NULL;
        }
    }
    else{
        Node<DataType>* pTemp = _pHead;
        for(int i = 0; i < index - 1; i++){
            pTemp = pTemp->_pNext;
        }
        Node<DataType>* pTemp2 = pTemp->_pNext;
        pTemp->_pNext = pTemp2->_pNext;
        if(pTemp2 == _pTail){
            _pTail = pTemp;
        }
        delete pTemp2;
    }
    _iSize--;
}
template <class DataType>
bool LinkedList<DataType>::empty(){
    return _iSize == 0;
}
template <class DataType>
void LinkedList<DataType>::clear(){
    while(_pHead != NULL){
        Node<DataType>* pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
    }
    _pTail = NULL;
    _iSize = 0;
}

#endif
