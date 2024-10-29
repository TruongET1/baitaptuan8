#include <iostream>
using namespace std;

struct Node {
    int coefficient; // hệ số
    int exponent;    // bậc của biến
    Node* next;      // con trỏ tới phần tử tiếp theo
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}

    // Thêm một hạng tử vào đa thức
    void addTerm(int coefficient, int exponent) {
        if (coefficient == 0) return; // Bỏ qua nếu hệ số là 0

        Node* newNode = new Node;
        newNode->coefficient = coefficient;
        newNode->exponent = exponent;
        newNode->next = nullptr;

        if (!head || head->exponent < exponent) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->exponent > exponent) {
                temp = temp->next;
            }
            if (temp->exponent == exponent) {
                temp->coefficient += coefficient;
                delete newNode;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // In đa thức
    void print() {
        if (!head) {
            cout << "0" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << (temp->coefficient > 0 && temp != head ? "+" : "") << temp->coefficient;
            if (temp->exponent != 0) cout << "x^" << temp->exponent;
            temp = temp->next;
        }
        cout << endl;
    }

    ~Polynomial() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Polynomial poly;
    int n, coeff, exp;

    cout << "Nhap so luong hang tu cua da thuc: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap he so va bac cua hang tu thu " << i + 1 << ": ";
        cin >> coeff >> exp;
        poly.addTerm(coeff, exp);
    }

    cout << "Da thuc la: ";
    poly.print();

    return 0;
}