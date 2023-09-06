/*
Description:
This C++ code provides a template-based implementation of a Hash Map data structure with support for three different probing strategies:
1. Linear Probing (HashMap)
2. Quadratic Probing (QHashMap)
3. Double Hashing (DHashMap)

The code includes the following classes:
- HashItem: Represents individual key-value pairs and includes a status to track if the entry is empty, occupied, or deleted.
- HashMap: The base class for the hash map, which provides basic hash map functionality and supports linear probing.
- QHashMap: A subclass of HashMap that implements quadratic probing for collision resolution.
- DHashMap: A subclass of HashMap that implements double hashing for collision resolution.

The code also includes functions for inserting, deleting, and retrieving key-value pairs. It handles load factor-based resizing and ensures efficient collision resolution for all probing strategies.

Usage:
1. Create an instance of the desired hash map class (HashMap, QHashMap, or DHashMap) with an optional initial capacity.
2. Use the insert() method to add key-value pairs to the map.
3. Use the get() method to retrieve the value associated with a specific key.
4. Use the deleteKey() method to remove a key-value pair.
5. The display() method prints the internal state of the hash map for debugging purposes.

Example:
HashMap<string> *map = new HashMap<string>;
populateHash("students.txt", map); // Populate the hash map from a file.
map->display();
cout << *map->get(9) << endl;
map->deleteKey(9);

This code demonstrates the use of different probing strategies for collision resolution in hash maps and includes a sample population of student data into the hash map.

Note:
- This code provides a basic implementation of hash maps for educational purposes. In practice, C++ standard library containers like std::unordered_map are often used for efficient and reliable hash map functionality.
- The code expects data to be populated from an input file (students.txt).
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

template <class v>
class HashItem
{
    template <class h>
    friend class HashMap;

    enum class Status
    {
        EMPTY,
        DELETED,
        OCCUPIED
    };

    int key;
    v value;
    Status status;

    HashItem(int k = 0, v val = v(), Status stats = Status::EMPTY)
        : key(k), value(val), status(stats) {}
};

template <class v>
class HashMap
{
protected:
    HashItem<v> *hashArray;
    int capacity;
    int currentElements;

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    virtual int getNextCandidateIndex(int key, int i) const
    {
        return (key + i) % capacity;
    }

    int getNextPrime(int num)
    {
        if (num <= 1)
            return 2;
        int prime = num;
        bool found = false;
        while (!found)
        {
            prime++;
            if (isPrime(prime))
                found = true;
        }
        return prime;
    }

    float loadFactor()
    {
        return static_cast<float>(currentElements) / static_cast<float>(capacity);
    }

    float nextLoadFactor()
    {
        return static_cast<float>(currentElements + 1) / static_cast<float>(capacity);
    }

    void doubleCapacity()
    {
        int oldC = capacity;
        capacity = getNextPrime(2 * capacity);
        HashItem<v> *tempHashArray = new HashItem<v>[capacity]();

        for (int i = 0; i < oldC; i++)
        {
            if (hashArray[i].status == HashItem<v>::Status::OCCUPIED)
            {
                int j = 0;
                int index = getNextCandidateIndex(hashArray[i].key, j);
                while (tempHashArray[index].status == HashItem<v>::Status::OCCUPIED && j < capacity)
                {
                    index = getNextCandidateIndex(hashArray[i].key, ++j);
                }
                if (j >= capacity)
                {
                    continue;
                }
                tempHashArray[index] = hashArray[i];
            }
        }
        delete[] hashArray;
        this->hashArray = tempHashArray;
    }

public:
    HashMap()
    {
        capacity = getNextPrime(10);
        hashArray = new HashItem<v>[capacity]();
        currentElements = 0;
    }

    HashMap(int cap)
    {
        assert(cap > 0);
        capacity = getNextPrime(cap);
        hashArray = new HashItem<v>[capacity]();
        currentElements = 0;
    }

    void insert(int key, v value)
    {
        if (nextLoadFactor() >= 0.75)
        {
            doubleCapacity();
        }
        int i = 0;
        int index = getNextCandidateIndex(key, i);

        while (hashArray[index].status == HashItem<v>::Status::OCCUPIED && i < capacity)
        {
            index = getNextCandidateIndex(key, ++i);
        }
        if (i >= capacity)
        {
            return;
        }
        hashArray[index] = HashItem<v>(key, value, HashItem<v>::Status::OCCUPIED);
        currentElements++;
    }

    void display()
    {
        cout << "Index    | Key    Value\n";
        for (int i = 0; i < capacity; i++)
        {
            cout << i << "\t| ";
            if (hashArray[i].status == HashItem<v>::Status::EMPTY)
            {
                cout << 'E';
            }
            else if (hashArray[i].status == HashItem<v>::Status::OCCUPIED)
            {
                cout << hashArray[i].key << '\t' << hashArray[i].value;
            }
            else if (hashArray[i].status == HashItem<v>::Status::DELETED)
            {
                cout << 'D';
            }
            cout << endl;
        }
    }

    bool deleteKey(int key)
    {
        int i = 0;
        int index = getNextCandidateIndex(key, i);

        while (hashArray[index].key != key && hashArray[index].status != HashItem<v>::Status::EMPTY && i < capacity)
        {
            index = getNextCandidateIndex(key, ++i);
        }
        if (hashArray[index].key == key)
        {
            hashArray[index].status = HashItem<v>::Status::EMPTY;
            return true;
        }
        return false;
    }

    v *get(int key)
    {
        int i = 0;
        int index = getNextCandidateIndex(key, i);
        while (hashArray[index].key != key && hashArray[index].status != HashItem<v>::Status::EMPTY && i < capacity)
        {
            index = getNextCandidateIndex(key, ++i);
        }
        if (hashArray[index].key == key)
        {
            return &(hashArray[index].value);
        }
        return nullptr;
    }

    ~HashMap()
    {
        delete[] hashArray;
    }
};

template <class v>
class QHashMap : public HashMap<v>
{
    int getNextCandidateIndex(int key, int i) const override
    {
        return (key + i * i) % this->capacity; // Use 'this->capacity' to access the base class member
    }

public:
    QHashMap() : HashMap<v>()
    {
    }
    QHashMap(int cap) : HashMap<v>(cap)
    {
    }
};

template <class v>
class DHashMap : public HashMap<v>
{
    int getNextCandidateIndex(int key, int i) const override
    {
        int first = key % this->capacity; // Use 'this->capacity' to access the base class member
        int primenumber = 13;
        int second = primenumber - (key % primenumber);

        return (first + i * second) % this->capacity;
    }

public:
    DHashMap() : HashMap<v>()
    {
    }
    DHashMap(int cap) : HashMap<v>(cap)
    {
    }
};

void populateHash(string filename, HashMap<string> *hash)
{
    ifstream fin(filename);
    int capacity_file, id;
    string name;
    fin >> capacity_file;
    for (int i = 0; i < capacity_file; i++)
    {
        fin >> id;
        fin >> name;
        hash->insert(id, name);
    }
    fin.close();
}

int main()
{
    HashMap<string> *map;
    map = new HashMap<string>;
    populateHash("students.txt", map);
    map->display();
    cout << *map->get(9) << endl;
    map->deleteKey(9);
    assert(map->get(9) == nullptr);
    delete map;

    map = new QHashMap<string>;
    populateHash("students.txt", map);
    map->display();
    cout << *map->get(98) << endl;
    map->deleteKey(98);
    assert(map->get(98) == nullptr);
    delete map;

    map = new DHashMap<string>;
    populateHash("students.txt", map);
    map->display();
    cout << *map->get(101) << endl;
    map->deleteKey(101);
    assert(map->get(101) == nullptr);
    delete map;

    return 0;
}
