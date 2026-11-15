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
/************
* @Description Khoi tao node moi voi du lieu chuyen vao
*
* @return       Con tro Node
* @attention    Con tro _pNext mac dinh duoc gan bang NULL
*********************/
template <class DataType>
Node<DataType>::Node(DataType data){
    _data = data;
    _pNext = NULL;
}
/************
* @Description In ra man hinh gia tri _data cua Node hien tai
*
* @return       Void
* @attention    Can nap chong (overload) toan tu << cho DataType neu do la class/struct
*********************/
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
/************
* @Description Constructor khoi tao danh sach lien ket rong
*
* @return       Khong co
* @attention    Thiet lap _pHead, _pTail ve NULL va _iSize bang 0
*********************/
template <class DataType>
LinkedList<DataType>::LinkedList(){
    _pHead = NULL;
    _pTail = NULL;
    _iSize = 0;
}
/************
* @Description Destructor don dep vung nho khi huy danh sach lien ket
*
* @return       Khong co
* @attention    Tu dong goi ham clear() de tranh memory leak (Quy tac 17)
*********************/
template <class DataType>
LinkedList<DataType>::~LinkedList(){
    clear();
}
/************
* @Description Them mot phan tu moi vao cuoi danh sach lien ket
*
* @return       Void
* @attention    Can cap nhat lai con tro _pTail va tang bien _iSize them 1
*********************/
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
/************
* @Description Lay so luong phan tu hien co trong danh sach lien ket
*
* @return       So nguyen (int) the hien kich thuoc danh sach (_iSize)
* @attention    Tra ve 0 neu danh sach rong
*********************/
template <class DataType>
int LinkedList<DataType>::getSize(){
    return _iSize;
}
/************
* @Description Lay thong tin phan tu o vi tri cuoi cung (Tail)
*
* @return       Tham chieu den Data cua phan tu cuoi
* @attention    Can chac chan danh sach khong empty truoc khi goi
*********************/
template <class DataType>
DataType& LinkedList<DataType>::getBack(){
    return _pTail->_data;
}
/************
* @Description Lay thong tin phan tu theo index mong muon (tuong tu nhu Mang)
*
* @return       Tham chieu den Data cua phan tu tai index
* @attention    Khong nen dung vong lap the nay doi voi ds lien ket qua lon
*********************/
template <class DataType>
DataType& LinkedList<DataType>::operator[](int index){
    Node<DataType>* pCurrent = _pHead;
    for(int i = 0; i < index; i++){
        pCurrent = pCurrent->_pNext;
    }
    return pCurrent->_data;
}
/************
* @Description Xoa mot phan tu tai vi tri index chi dinh
*
* @return       Void
* @attention    Can delete vung nho de tranh memory leak (Quy tac 17)
*********************/
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
/************
* @Description Kiem tra danh sach lien ket hien tai co rong hay khong
*
* @return       True neu danh sach rong, False neu co it nhat 1 phan tu
* @attention    Kiem tra dua tren bien _iSize thay vi _pHead de toi uu toc do
*********************/
template <class DataType>
bool LinkedList<DataType>::empty(){
    return _iSize == 0;
}
/************
* @Description Xoa va giai phong vung nho cho toan bo danh sach lien ket
*
* @return       Void
* @attention    Khoi phuc lai _pHead, _pTail = NULL va _iSize = 0
*********************/
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
