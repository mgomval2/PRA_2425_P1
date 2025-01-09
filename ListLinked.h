#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

    Node<T>* getNode(int pos) {
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux;
    }

public:
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("Posición fuera de rango");

        if (n == 0) {
            first = new Node<T>(e);
        } else if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* prev = getNode(pos - 1);
            prev->next = new Node<T>(e, prev->next);
        }
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

        Node<T>* nodeToRemove = getNode(pos);
        if (pos == 0) {
            first = nodeToRemove->next;
        } else {
            Node<T>* prev = getNode(pos - 1);
            prev->next = nodeToRemove->next;
        }

        T data = nodeToRemove->data;
        delete nodeToRemove;
        n--;
        return data;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición fuera de rango");
        return getNode(pos)->data;
    }

    int search(T e) override {
        Node<T>* aux = first;
        int i = 0;
        while (aux != nullptr) {
            if (aux->data == e) return i;
            aux = aux->next;
            i++;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    T operator[](int pos) {
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "List => [";
        Node<T>* aux = list.first;
        while (aux != nullptr) {
            out << aux->data;
            if (aux->next != nullptr) out << ", ";
            aux = aux->next;
        }
        out << "]";
        return out;
    }
};

#endif
