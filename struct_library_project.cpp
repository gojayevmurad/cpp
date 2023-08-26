#include <iostream>
#include <Windows.h>

using namespace std;

void setColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg < 4));
}

struct Book {
	double price;
	char* title;
	char* author;
	int page;
};

struct BookItem {
	Book book;
	int quantity;
};

struct Library {
	BookItem** items;
	int count = 0;
};

void ShowMenu() {
	cout << "========================================" << endl;
	cout << "Show All Books		[1]" << endl;
	cout << "Add New Book		[2]" << endl;
	cout << "Buy Book			[3]" << endl;
	cout << "Delete Book		[4]" << endl;
}

void ShowBook(const Book book) {
	cout << " - - - BOOK INFO - - - " << endl;
	cout << "Title : " << book.title << endl;
	cout << "Author : " << book.author << endl;
	cout << "Page : " << book.page << endl;
	cout << "Price : " << book.price << "$" << endl;
}

void ShowBookItem(const BookItem& item) {
	ShowBook(item.book);
	setColor(1, 0);
	cout << "\t\tQuantity  : [" << item.quantity << "]" << endl;
	setColor(7, 0);
}

void ShowLibrary(const Library & library) {
	for (size_t i = 0; i < library.count; i++){ 
		cout << "NO : " << i + 1 << endl;
		ShowBookItem(*library.items[i]);
	}
}

BookItem* GetNewBookItem() {
	cin.ignore();
	cin.clear();

	cout << "Enter title : " << endl;
	char* title = new char[100] {};
	cin.getline(title, 100);

	cout << "Enter author : " << endl;
	char* author = new char[100] {};
	cin.getline(author, 100);

	cout << "Enter page : " << endl;
	int page = 0;
	cin >> page;

	cout << "Enter price : " << endl;
	double price = 0;
	cin >> price;

	cout << "Enter quantity : " << endl;
	int quantity = 0;
	cin >> quantity;

	Book* book = new Book{ price, title, author, page };
	BookItem* item = new BookItem{ *book, quantity };

	return item;
}

void AddBookToLibrary(Library& library,  BookItem* newItem) {
	auto newItems = new BookItem * [library.count + 1] {};

	for (size_t i = 0; i < library.count; i++){
		newItems[i] = library.items[i];
	}

	newItems[library.count] = newItem;
	library.items = newItems;
	newItems = nullptr;
	library.count++;
}

void BuyBook(BookItem& item, int quantity) {
	if (quantity <= item.quantity) {
		item.quantity -= quantity;
		setColor(14, 0);
		cout << "You purchased " << item.book.title << " with " << quantity << " counts successfully" << endl;
		setColor(7, 0);
	}
	else {
		cout << "There are not book with this quantity : " << quantity << endl;
	}
}

void DeleteBook(Library& library, int index) {
	auto temp = new BookItem * [library.count - 1] {};

	for (size_t i = 0, k=0; i < library.count; i++, k++){
		if (i != index) {
			temp[k] = library.items[i];
		}
		else {
			k--;
		}
	}

	cout << library.items[index]->book.author << " was deleted" << endl;
	library.items = temp;
	library.count--;

}

void main() {

	Book* b1 = new Book{ 12.5, new char[30] {"Tom Sawyer Adventures"}, new char[20] {"Mark Twen"}, 356 };
	Book* b2 = new Book{ 34.70, new char[30] {"Crime and Punishment"}, new char[20] {"Fyeder Dostoyevsky"}, 750 };
	Book* b3 = new Book{ 12.5, new char[40] {"Data Structure and Algorithms"}, new char[20] {"Grokkin"}, 356 };

	BookItem* item1 = new BookItem{ *b1, 15 };
	BookItem* item2 = new BookItem{ *b2, 30 };
	BookItem* item3 = new BookItem{ *b3, 5 };

	Library* library = new Library;

	library->items = new BookItem * [3] {item1, item2, item3};
	library->count = 3;

	while (true){
		ShowMenu();
		int select = 0;
		cin >> select;
		system("cls");
		if (select == 1) {
			ShowLibrary(*library);
		}
		else if (select == 2) {
			BookItem* newitem = GetNewBookItem();
			AddBookToLibrary(*library, newitem);
			setColor(4, 0);
			cout << newitem->book.title << " added successfully" << endl;
			setColor(7, 0);
		}
		else if (select == 3) {
			ShowLibrary(*library);
			cout << "Enter no of book " << endl;
			int no = 0;
			cin >> no;
			if (no >= 1 && no <= library->count) {
				int index = no - 1;
				BookItem* item = library->items[index];
				cout << "Enter book quantity : " << endl;
				int quantity = 0;
				cin >> quantity;
				BuyBook(*item, quantity);
			}
			else {
				setColor(4, 0);
				cout << "Incorrect NO " << endl;
				setColor(7, 0);
			}
		}
		else if (select == 4) {
			ShowLibrary(*library);
			cout << "Enter NO of book : " << endl;
			int no = 0;
			cin >> no;

			if (no >= 0 && no <= library->count) {
				int index = no - 1;
				DeleteBook(*library, index);
			}
			else {
				setColor(4, 0);
				cout << "Incorrect NO " << endl;
				setColor(7, 0);
			}
		}
		else {
			setColor(4, 0);
			cout << "Wrong !! " << endl;
			setColor(7, 0);
		}
	}

}