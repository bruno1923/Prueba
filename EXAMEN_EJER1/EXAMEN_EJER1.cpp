// EXAMEN_EJER1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
using namespace std;

template<class T>
struct Node {
    T data;
    Node* next;
};

template<class T>
class Stack {
private:
    Node<T>* top;
    int size;

public:
    Stack() {
        this->size = 0;
        this->top = NULL;
    }

    bool insert(T data) {

        Node<T>* newNode = new Node<T>();
        newNode->data = data;
        newNode->next = NULL;

        if (this->top == NULL) {
            this->top = newNode;
            this->size++;
        }
        else {
            newNode->next = top;
            this->top = newNode;
            this->size++;
        }
        return true;
    }

    bool pop() {
        if (this->size == 0)
            return false;

        Node<T>* aux = top;
        this->top = this->top->next;
        aux->next = NULL;
        this->size--;
        return true;
    }

    int getSize() {
        return this->size;
    }

    T getTop() {
        return this->top->data;
    }
};


int main() {

    string input = "<ul></ul>";
    bool correct = true;
    cin >> input;

    Stack<string> s = Stack<string>();



    for (int i = 0; i < input.size(); i++) {
        bool abrir = true;

        if (input[i] == '<') {
            string tag = "";
            for (int j = i; j < input.size(); j++) {

                if (input[j] == '/') {
                    //desapilar
                    abrir = false;
                    tag += input[j];
                }
                else if (input[j] == '>') {
                    tag += input[j];
                    break;
                }
                else if (input[j] != ' ')
                    tag += input[j];

            }
            if (abrir)
                s.insert(tag);
            else {
                s.pop();
            }

        }
        else if (input[i] == '{' || input[i] == '(' || input[i] == '[') {
            string aux = "";
            aux.push_back(input[i]);
            s.insert(aux);
        }
        else if (input[i] == '}' || input[i] == ')' || input[i] == ')') {
            string aux = "";
            if ((s.getTop() == "{" && input[i] == '}') || (s.getTop() == "(" && input[i] == ')') || (s.getTop() == "[" && input[i] == ']'))
            {
                s.pop();
            }
            else {
                correct = false;
                break;
            }
        }
    }

    if (correct)
        cout << "Correcto";
    else
        cout << "Incorrecto";
}