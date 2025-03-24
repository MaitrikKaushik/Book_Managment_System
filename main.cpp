#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Book{
    public:
    int id;
    string title;
    string author;

    Book(int ids, string titles, string authors){
        id = ids;
        title = titles;
        author = authors;
    }
};

class Library{
    public:
    vector<Book> books;

    void addBook(int id , string title , string author){
        books.push_back(Book(id,title,author));
        cout<<"Book added successfully"<<endl;
    }

    void displayBooks(){
        if(books.empty()){
            cout<<"No books found!"<<endl;
            return;
        }
        for(const auto& book : books){
            cout<<"Book ID: "<<book.id<<", Title: "<<book.title<<", Author: "<<book.author<<endl;
        }
    }

    void searchBook(int id){
        for(const auto& book: books){
            if(book.id == id){
                cout<<"Book ID: "<<book.id<<", Title: "<<book.title<<", Author: "<<book.author<<endl;
                return;
            }
        }
        cout<<"Book not found"<<endl;
    }
};

int main()
{
    Library libA;
    int choice;
    while(true){
        cout<<"1. Add Book\n2. Display Books\n3. Search Book\n4. Exit"<<endl;        
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore(); // Fix infinite loop issue

        if(choice == 1){
            int id;
            string title;
            string author;

            cout<<"Enter Book ID: ";
            cin>>id;
            cin.ignore(); // Ignore newline left in buffer
            cout<<"Enter Book Title: ";
            getline(cin, title);
            cout<<"Enter Book Author: ";
            getline(cin, author);
            
            libA.addBook(id, title, author);
        }
        else if(choice == 2){
            libA.displayBooks();
        }
        else if (choice == 3){
            int id;
            cout<<"Enter Book ID to search: ";
            cin>>id;
            libA.searchBook(id);
        }
        else if (choice == 4){
            break;
        }
        else{
            cout<<"Invalid choice! Please enter a valid option."<<endl;
        }
    }
    return 0;
}
