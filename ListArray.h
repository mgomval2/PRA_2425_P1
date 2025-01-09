#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;              // Puntero al array dinámico
    int max;             // Capacidad máxima actual del array
    int n;               // Número de elementos en la lista
    static const int MINSIZE = 2;  // Tamaño mínimo del array

    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < std::min(max, new_size); i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    ~ListArray() {
        delete[] arr;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("Posición fuera de rango");
        if (n >= max) resize(max * 2);
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición fuera de rango");
        T temp = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        return temp;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición fuera de rango");
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) return i;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) {
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "Array [";
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i];
            if (i != list.n - 1) out << ", ";
        }
        out << "]";
        return out;
    }

    friend ListArray<T> operator+(const ListArray<T>& a, const ListArray<T>& b) {
        ListArray<T> result;
        result.resize(a.size() + b.size());
        for (int i = 0; i < a.size(); i++) {
            result.append(a.get(i));
        }
        for (int i = 0; i < b.size(); i++) {
            result.append(b.get(i));
        }
        return result;
    }

    ListArray<T>& operator+=(const ListArray<T>& other) {
        for (int i = 0; i < other.size(); i++) {
            this->append(other.get(i));
        }
        return *this;
    }

    friend bool operator==(const ListArray<T>& a, const ListArray<T>& b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i) != b.get(i)) return false;
        }
        return true;
    }

    friend ListArray<T> operator-(const ListArray<T>& a, const ListArray<T>& b) {
        ListArray<T> result;
        for (int i = 0; i < a.size(); i++) {
            if (b.search(a.get(i)) == -1) {
                result.append(a.get(i));
            }
        }
        return result;
    }
};

#endif
