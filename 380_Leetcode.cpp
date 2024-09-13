#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class RandomizedSet {

    int _sizeRS;
    unordered_map<int, int> _uMapRS;
    vector<int> _elemVectorRS;

    int _absoluteVal(const int val) {

        return (val < 0) ? (-1) * val : val;

    }

    void _swapInt(int& a, int& b) {

        const int temp = a;
        a = b;
        b = temp;

    }

    //

    void _printVector() {

        cout << "VectorRS: ";

        for (const int elem : _elemVectorRS) 
        {
            cout << elem << " ";
        }
        cout << "\n\n";

    }

    void _printU_Map() {

        cout << "uMapRS: ";

        for (auto& x : _uMapRS)
        {
            cout << "( " << x.first << " / " << x.second << " )\t";
        }
        cout << "\n\n";

    }

    //

public:
    RandomizedSet() {

        srand(time(0));
        this->_sizeRS = 0;

    }

    bool insert(int val) { // Amortized O(1) Time Complexity

        if (_uMapRS.find(val) != _uMapRS.end()) // Value found (already inserted)
            return false;
        
        _elemVectorRS.push_back(val);
        _uMapRS[val] = this->_sizeRS;

        (this->_sizeRS)++;

        /*
        cout << "\n";
        _printU_Map();
        _printVector();
        cout << "\n";
        */

        return true;

    }

    bool remove(int val) { // Amortized O(1) Time Complexity

        if (_uMapRS.find(val) == _uMapRS.end()) // Value not found (cannot be removed)
            return false;

        const int indexVal = _uMapRS[val];
        _swapInt(_elemVectorRS[indexVal], _elemVectorRS[(this->_sizeRS) - 1]);
        _uMapRS[_elemVectorRS[indexVal]] = indexVal;

        _uMapRS.erase(val);
        _elemVectorRS.pop_back();

        (this->_sizeRS)--;

        /*
        cout << "\n";
        _printU_Map();
        _printVector();
        cout << "\n";
        */

        return true;

    }

    int getRandom() { // O(1) Time Complexity

        const int randIndex = _absoluteVal(rand() % (this->_sizeRS));
        const int randElem = _elemVectorRS[randIndex];
        
        return randElem;

    }

    int size() { // O(1) Time Complexity

        return this->_sizeRS;

    }

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    // Time Complexity: Average O(1) for all class methods: insert, remove, getRandom - Using a combination between an unordered_map (for inserting and removing elements) and a vector (for generating a random index and access that corresponding element in constant time).
    // 
    // Example 1:
    vector<string> operations = { "RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom" };
    vector<vector<int>> elements = { {}, {1}, {2}, {2}, {}, {1}, {2}, {} };

    RandomizedSet* rs = new RandomizedSet();

    cout << "Solution: ";
    int index = 0;
    for (const string& operation : operations)
    {

        if (operation == "RandomizedSet") {

            cout << "null, ";

        }
        else if (operation == "insert") {

            int elem = elements[index][0];
            bool sol = rs->insert(elem);
            cout << sol << ", ";

        }
        else if (operation == "remove") {

            int elem = elements[index][0];
            bool sol = rs->remove(elem);
            cout << sol << ", ";

        }
        else if (operation == "getRandom") {

            int sol = rs->getRandom();
            cout << sol << ", ";

        }

        index++;

    } // [null, true, false, true, 2, true, false, 2]

    cout << "\n\n";


    return 0;
}
