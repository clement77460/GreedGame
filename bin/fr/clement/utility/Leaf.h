#include<iostream>
template <class T>
class Leaf
{
public:
	void add(T value);
	void addNewLeaf();
	T getValue();
	T* getPTRValue();
	Leaf<T>* getNextLeaf();
	
	~Leaf();
private:
	T value;
	Leaf<T>* nextLeaf =NULL;


};

template<class T>
void Leaf<T>::add(T value)
{
	this->value = value;
	
}

template<class T>
inline void Leaf<T>::addNewLeaf()
{
	this->nextLeaf = new Leaf<T>;
}

template<class T>
T Leaf<T>::getValue()
{
	return this->value;
}

template<class T>
inline T * Leaf<T>::getPTRValue()
{
	return &value;
}

template<class T>
inline Leaf<T> * Leaf<T>::getNextLeaf()
{
	return nextLeaf;
}

template<class T>
inline Leaf<T>::~Leaf()
{
	printf("deleting next Leaf \n");
	delete[] nextLeaf;
}
