/*
    This is a basic implementation of a hash table (hashmap) in C++ using classes.

    Hash tables are data structures that allow efficient storage and retrieval of
    key-value pairs. In this implementation, we create a hash table class called
    HashMap that uses a vector of lists for storage. Each list represents a "bucket"
    in the hash table, and each bucket can contain multiple HashEntry objects
    (key-value pairs).

    The HashEntry class is a simple container for key-value pairs.

    The hash function calculates the index in the vector (bucket) where a key
    should be placed using a hash function. We use the std::hash function to hash
    the key and then take the modulo of the capacity to ensure it falls within the
    valid range of indices.

    The insert method inserts a key-value pair into the hash table. It calculates
    the index for the key, checks if the key already exists in the bucket, and
    updates the value if it does or adds a new HashEntry if it doesn't.

    The get method retrieves the value associated with a given key. It calculates
    the index, searches through the list in that bucket, and returns the value if
    the key is found.

    The remove method removes a key-value pair from the hash table. It calculates
    the index, and then removes the HashEntry from the list in that bucket if the
    key matches.

    In the main function, it demonstrate how to use the HashMap class by inserting,
    retrieving, and removing key-value pairs.

*/
#include <iostream>
#include <vector>
#include <list>

// HashEntry represents a key-value pair in the hash table
template <typename K, typename V>
class HashEntry {
public:
    K key;
    V value;

    HashEntry(const K& k, const V& v) : key(k), value(v) {}
};

// HashMap represents the hash table
template <typename K, typename V>
class HashMap {
private:
    std::vector<std::list<HashEntry<K, V>>> table;
    int capacity;

    // Hash function to calculate the index of a key
    int hash(const K& key) {
        std::hash<K> hashFunc;
        return hashFunc(key) % capacity;
    }

public:
    HashMap(int initialCapacity = 10) : capacity(initialCapacity) {
        table.resize(capacity);
    }

    // Insert a key-value pair into the hash table
    void insert(const K& key, const V& value) {
        int index = hash(key);
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                entry.value = value; // Update value if key exists
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    // Get the value associated with a key
    bool get(const K& key, V& result) {
        int index = hash(key);
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                result = entry.value;
                return true;
            }
        }
        return false; // Key not found
    }

    // Remove a key-value pair from the hash table
    void remove(const K& key) {
        int index = hash(key);
        table[index].remove_if([&key](const HashEntry<K, V>& entry) {
            return entry.key == key;
        });
    }
};

int main() {
    HashMap<std::string, int> hashMap;

    hashMap.insert("one", 1);
    hashMap.insert("two", 2);
    hashMap.insert("three", 3);

    int value;
    if (hashMap.get("two", value)) {
        std::cout << "Value associated with 'two' is: " << value << std::endl;
    } else {
        std::cout << "'two' not found in the hashmap." << std::endl;
    }

    hashMap.remove("three");

    if (hashMap.get("three", value)) {
        std::cout << "Value associated with 'three' is: " << value << std::endl;
    } else {
        std::cout << "'three' not found in the hashmap." << std::endl;
    }

    return 0;
}
