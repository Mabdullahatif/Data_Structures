/*
Description:
This C++ code demonstrates the implementation of a generic Hash Table using templates. A Hash Table is a data structure that allows efficient insertion and retrieval of key-value pairs.

In this code:
- The Hash class is implemented as a template class, allowing it to store key-value pairs of any data type.
- The HashItem class, which represents an individual item in the Hash Table, is also a template class. It holds a key, a value, and a status indicating whether it's occupied.
- The Hash Table is implemented as an array of HashItem objects.
- The getIndex() function calculates the index in the array based on the key using a simple modulo operation.
- The insert() function inserts a key-value pair into the Hash Table, handling collisions by linear probing.
- The printKeyValue() function retrieves and prints the value associated with a given key.

Usage:
1. Create an instance of the Hash class, specifying the maximum size of the Hash Table.
2. Use the insert() method to add key-value pairs to the table.
3. Use the printKeyValue() method to retrieve and print the value associated with a specific key.

Example:
Hash<int> hash;  // Create a Hash Table for integers.
hash.insert(5, 10);  // Insert a key-value pair (5, 10) into the table.
hash.insert(15, 11);  // Insert a key-value pair (15, 11) into the table.
hash.printKeyValue(15);  // Retrieve and print the value associated with the key 15.

Note:
This code provides a basic implementation of a Hash Table and uses linear probing to handle collisions. In practice, more advanced techniques, such as separate chaining or open addressing, may be employed for better collision resolution.
*/
#include <iostream>

using namespace std;

template<class var>
class Hash;

template <class var>
class HashItem{
	int key;
	var value;
	bool status;
	friend class Hash<var>;
	HashItem(){
		status = false;
	}
};

template<class var>
class Hash{
	HashItem<var>* arr;
	int maxSize, currSize;
	
	int getIndex(int key){
		return key % maxSize;
	}
	
public:
	Hash(int max = 10): maxSize(max), currSize(0){
		arr = new HashItem<var>[maxSize];
	}
	
	void insert(int key, var val){
		int index = getIndex(key);
		
		for(int i=1; arr[index].status == true; i++)
			index = getIndex(key + i);
		
		arr[index].value = val;
		arr[index].key = key;
		arr[index].status = true;
	}
	
	void printKeyValue(int key){
		int index = getIndex(key);
		
		for(int i=1; arr[index].key != key && i<maxSize; i++)
			index = getIndex(key + i);
		
		if(arr[index].key == key)
			cout << arr[index].value << " ";
	}
};

int main(){
	
	Hash<int> hash;
	
	hash.insert(5, 10);
	hash.insert(15, 11);
	
	hash.printKeyValue(15);
	
	return 0;
}