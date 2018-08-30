/*
    Create a class with data members book no, book name and member function getdata() and putdata(). Create a class second with data members author name, publisher and members function getdata() and showdata(). Derive a class third from first and second with data member no of pages and year of publication. DIsplay all these information using array of objects of their class..

*/
#include <bits/stdc++.h>
using namespace std;
class first{
private:
    int book_no;
    string book_name;
public:
    void getdata(int n, string name){
        book_no = n, book_name = name;
    }
    void putdata(){
        cout << "Book number : " << book_no << endl << "Book name : " << book_name << endl;
    }
};
class second{
private:
    string author_name, publisher;
public:
    void getdata(string name, string pub){
        author_name = name, publisher = pub;
    }
    void showdata(){
        cout << "Author name : " << author_name << endl << "Publisher name : " << publisher << endl;
    }
};
class third : public first, public second {
protected:
    int no_of_pages, year_of_publication;
public:
    void getdata(int n, int year){
        no_of_pages = n, year_of_publication = year;
    }
    void display(){
        cout << "Number of pages : " << no_of_pages << endl << "Year of publication : " << year_of_publication << endl;
    }

};
int main(){
    third pub[10];
    pub[0].first::getdata(1, "OOP with C++");
    pub[0].second::getdata("E. Balagurushamy", "6e");
    pub[0].getdata(250, 1999);
    pub[0].first::putdata();
    pub[0].second::showdata();
    pub[0].display();
    return 0;
}
