#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    int year;
};

void insertionSort(Book b[], int n) {
    for(int i = 1; i < n; i++) {
        Book key = b[i];
        int j = i - 1;

        while(j >= 0 && b[j].title > key.title) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}

void selectionSort(Book b[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;

        for(int j = i + 1; j < n; j++) {
            if(b[j].year < b[min].year)
                min = j;
        }

        Book temp = b[i];
        b[i] = b[min];
        b[min] = temp;
    }
}

void display(Book b[], int n) {
    cout << "\nBook List:\n";
    for(int i = 0; i < n; i++) {
        cout << b[i].id << " "
             << b[i].title << " "
             << b[i].year << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book b[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter BookID Title Year: ";
        cin >> b[i].id >> b[i].title >> b[i].year;
    }

    insertionSort(b, n);
    selectionSort(b, n);

    display(b, n);

    return 0;
}
