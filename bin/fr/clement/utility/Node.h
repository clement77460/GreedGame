#include "Leaf.h"
#include<iostream>

template<class T,class F> 
class Node
{
public:
	void add(T key, F value);
	T getKey();
	Node<T, F>* getNext();
	void addNewKey();
	void toString();


private:
	Node<T, F>* next=NULL;
	Leaf<F>* firstLeaf=NULL;
	T keyValue;

	int buildingFirstLeaf(T key, F value);


};

template<class T, class F>
void Node<T, F>::add(T key, F value)
{
	int attributed = 0;

	int hasBuildFirstLeaf=this->buildingFirstLeaf(key, value);

	if(hasBuildFirstLeaf==0){
		Leaf<F>* nextLeaf = firstLeaf;
		while (attributed == 0) {

			if (nextLeaf->getValue() == value) {
				std::cout << "[Node] value already exist \n";
				attributed = 1;
			}
			else {
				if (nextLeaf->getNextLeaf() == NULL) {

					nextLeaf->addNewLeaf();
					nextLeaf->getNextLeaf()->add(value);
					attributed = 1;
				}
			}
			nextLeaf = nextLeaf->getNextLeaf();
		}


	}

	
}

template<class T, class F>
inline T Node<T, F>::getKey()
{
	return this->keyValue;
}

template<class T, class F>
inline Node<T, F>* Node<T, F>::getNext()
{
	return this->next;
}

template<class T, class F>
inline void Node<T, F>::addNewKey()
{
	this->next = new Node<T, F>;
}

template<class T, class F>
int Node<T, F>::buildingFirstLeaf(T key, F value)
{
	if (firstLeaf == NULL) {
		this->keyValue = key;
		this->firstLeaf = new Leaf<F>;
		firstLeaf->add(value);
		return 1;
	}
	return 0;
}





template<class T, class F>
inline void Node<T, F>::toString()
{
	std::cout << "** " << this->keyValue << "\n";

	//parcours de ces valeurs
	std::cout << "-> " << this->firstLeaf->getValue() << "\n";
	//std::cout << "-> " << this->firstLeaf->getNextLeaf()->getValue() << "\n";
}

