#include"Node.h"

template <class T,class F> 
class PersonnalMap
{
public:
	void add(T key, F value);
	void toString();


private:
	Node<T, F>* firstNode=NULL;
	int buildingFirstNode(T key, F value);
	int buildingNewNode(Node<T, F>* temp,T key, F value);
	int checkIfKeyExistsInNode(Node<T, F>* temp, T key, F value);

};


template<class T, class F>
 void PersonnalMap<T, F>::add(T key, F value)
{
	 
	 int attributed = 0;
	 
	 //verification du premierNoeud
	 int hasBuildFirstNode = this->buildingFirstNode(key, value);

	 
	 if(hasBuildFirstNode==0){
		 Node<T, F>* temp = firstNode;
		 while (attributed == 0) {
			 
			 attributed = this->checkIfKeyExistsInNode(temp, key, value);
			 
			 if(attributed==0) {
				 attributed=this->buildingNewNode(temp, key, value);
				 
			 }
			 temp = temp->getNext();
		 }
	 }
	 
}


 template<class T, class F>
 int PersonnalMap<T, F>::buildingFirstNode(T key, F value)
 {
	 if (firstNode == NULL) {
		 firstNode = new Node<T, F>;
		 firstNode->add(key, value);

		 return 1;
	 }
	 return 0;
 }

 template<class T, class F>
 int PersonnalMap<T, F>::buildingNewNode(Node<T, F>* temp, T key, F value)
 {
	 if (temp->getNext() == NULL) {

		 temp->addNewKey();
		 temp->getNext()->add(key, value);
		 
		 return 1;
	 }

	 return 0;
 }

 template<class T, class F>
 int PersonnalMap<T, F>::checkIfKeyExistsInNode(Node<T, F>* temp, T key, F value)
 {
	 if (temp->getKey() == key) {
		 temp->add(key, value);

		 return 1;
	 }

	 return 0;
 }



 template<class T, class F>
 inline void PersonnalMap<T, F>::toString()
 {

	 firstNode->toString();
	 firstNode->getNext()->toString();
	 firstNode->getNext()->getNext()->toString();
 }