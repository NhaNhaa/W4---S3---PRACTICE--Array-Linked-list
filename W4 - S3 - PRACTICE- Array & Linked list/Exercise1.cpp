#include <iostream>
#include <string>
using namespace std;

class Array {
private:
    int* data;
    int size;
    int length;

    void resize() {
        size *= 2;
        int* newData = new int[size];
        for (int i = 0; i < length; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Array(int size) {
        this->size = size;
        this->length = 0;
        data = new int[size];
    }

    ~Array() {
        delete[] data;
    }

    int getLength() const {
        return length;
    }

    int get(int index) const {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void push(int value) {
        if (length == size) {
            resize();
        }
        data[length++] = value;
    }

    void insertAt(int index, int value) {
        if (index < 0 || index > length) {
            throw out_of_range("Index out of bounds");
        }
        if (length == size) {
            resize();
        }
        for (int i = length; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        length++;
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of bounds");
        }
        for (int i = index; i < length - 1; ++i) {
            data[i] = data[i + 1];
        }
        length--;
    }

    string print() const {
        string result = "[";
        for (int i = 0; i < length; ++i) {
            result += to_string(data[i]);
            if (i < length - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }
};

int main() {
    Array arr(4);
    arr.push(10);
    arr.push(11);
    arr.push(12);
    arr.push(13);
    cout << "Array after pushes: " << arr.print() << endl;

    arr.insertAt(2, 99);
    cout << "Array after insertAt(2, 99): " << arr.print() << endl;

    arr.removeAt(1);
    cout << "Array after removeAt(1): " << arr.print() << endl;

    cout << "Element at index 2: " << arr.get(2) << endl;
    cout << "Array length: " << arr.getLength() << endl;

    return 0;
}
