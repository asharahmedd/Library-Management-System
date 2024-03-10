#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;
struct Date {
	int day;
	int month;
	int year;
};
struct Book {
	int id;
	double price;
	Date date;

};
struct Library {
	int num;
	Book books[N];
};


void add(Library* lib) {

	struct Book x;

	if (lib->num >= N) {
		cout << "Library is full" << endl;
		return;
	}
	cout << "Input Book ID:" << endl;
	cin >> x.id;
	cout << "Input Price:" << endl;
	cin >> x.price;
	cout << "Input Date (dd mm yyyy):" << endl;
	cin >> x.date.day;
	cin >> x.date.month;
	cin >> x.date.year;

	if (lib->num <= N) {
		lib->books[lib->num].id = x.id;
		lib->books[lib->num].price = x.price;
		lib->books[lib->num].date.day = x.date.day;
		lib->books[lib->num].date.month = x.date.month;
		lib->books[lib->num].date.year = x.date.year;
		lib->num++;
	}
}
void show(Library* lib) {

	for (int i = 0; i < lib->num; i++) {
		cout << setw(3) << setfill('0') << lib->books[i].id << "     ";
		cout << fixed << setprecision(2) << lib->books[i].price << "   ";
		cout << lib->books[i].date.day << "-" << lib->books[i].date.month << "-" << lib->books[i].date.year;
		cout << endl;
	}

}
void sort_date(Library& lib) {
	int id_temp;
	double price_temp;
	int day_temp;
	int month_temp;
	int year_temp;

	for (int i = 0; i < lib.num - 1; i++) {
		for (int j = 0; j < lib.num - i - 1; j++) {
			if (lib.books[j].date.year > lib.books[j + 1].date.year ||
				(lib.books[j].date.year == lib.books[j + 1].date.year &&
					lib.books[j].date.month > lib.books[j + 1].date.month) ||
				(lib.books[j].date.year == lib.books[j + 1].date.year &&
					lib.books[j].date.month == lib.books[j + 1].date.month &&
					lib.books[j].date.day > lib.books[j + 1].date.day)) {

				id_temp = lib.books[j].id;
				price_temp = lib.books[j].price;
				day_temp = lib.books[j].date.day;
				month_temp = lib.books[j].date.month;
				year_temp = lib.books[j].date.year;

				lib.books[j].id = lib.books[j + 1].id;
				lib.books[j].price = lib.books[j + 1].price;
				lib.books[j].date.day = lib.books[j + 1].date.day;
				lib.books[j].date.month = lib.books[j + 1].date.month;
				lib.books[j].date.year = lib.books[j + 1].date.year;

				lib.books[j + 1].id = id_temp;
				lib.books[j + 1].price = price_temp;
				lib.books[j + 1].date.day = day_temp;
				lib.books[j + 1].date.month = month_temp;
				lib.books[j + 1].date.year = year_temp;

			}
			else if (lib.books[j].date.year == lib.books[j + 1].date.year &&
				lib.books[j].date.month == lib.books[j + 1].date.month &&
				lib.books[j].date.day == lib.books[j + 1].date.day &&
				lib.books[j].id > lib.books[j + 1].id) {

				id_temp = lib.books[j].id;
				price_temp = lib.books[j].price;
				day_temp = lib.books[j].date.day;
				month_temp = lib.books[j].date.month;
				year_temp = lib.books[j].date.year;

				lib.books[j].id = lib.books[j + 1].id;
				lib.books[j].price = lib.books[j + 1].price;
				lib.books[j].date.day = lib.books[j + 1].date.day;
				lib.books[j].date.month = lib.books[j + 1].date.month;
				lib.books[j].date.year = lib.books[j + 1].date.year;

				lib.books[j + 1].id = id_temp;
				lib.books[j + 1].price = price_temp;
				lib.books[j + 1].date.day = day_temp;
				lib.books[j + 1].date.month = month_temp;
				lib.books[j + 1].date.year = year_temp;
			}
		}
	}
	
}
void sort_id(Library& lib) {
	int id_temp;
	double price_temp;
	int day_temp;
	int month_temp;
	int year_temp;
	for (int i = 0; i < lib.num - 1; i++) {
		for (int j = 0; j < lib.num - i - 1; j++) {
			if (lib.books[j].id > lib.books[j + 1].id) {
				id_temp = lib.books[j].id;
				price_temp = lib.books[j].price;
				day_temp = lib.books[j].date.day;
				month_temp = lib.books[j].date.month;
				year_temp = lib.books[j].date.year;

				lib.books[j].id = lib.books[j + 1].id;
				lib.books[j].price = lib.books[j + 1].price;
				lib.books[j].date.day = lib.books[j + 1].date.day;
				lib.books[j].date.month = lib.books[j + 1].date.month;
				lib.books[j].date.year = lib.books[j + 1].date.year;

				lib.books[j + 1].id = id_temp;
				lib.books[j + 1].price = price_temp;
				lib.books[j + 1].date.day = day_temp;
				lib.books[j + 1].date.month = month_temp;
				lib.books[j + 1].date.year = year_temp;

			}
		}
	}

}
void del(Library* lib) {
	int x;
	cout << "Enter the ID to be deleted " << endl;
	cin >> x;
	bool found = false;

	for (int i = 0; i < lib->num; i++) {
		if (lib->books[i].id == x) {
			for (int j = i; j < lib->num; j++) {
				lib->books[j] = lib->books[j + 1];
				found = true;
				lib->num--;

			}
		}
	}
	if (!found) {
		cout << "The ID cannot be found" << endl;
	}
}
void sort(Library* lib) {
	int n;
	cout << "1: Sort by ID" << endl;
	cout << "2: Sort by Date" << endl;
	cin >> n;
	if (n == 1) {
		sort_id(*lib);
	}
	else if (n == 2) {
		sort_date(*lib);
	}


}
void listOptions(Library& lib) {
	cout << "~~~~~~~~~Welcome!~~~~~~~~~~" << endl;
	cout << "0: Exit" << endl;
	cout << "1: Add" << endl;
	cout << "2: Show" << endl;
	cout << "3: Delete" << endl;
	cout << "4: Sort" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void init(Library* p) {
	p->books[p->num].id = 3;
	p->books[p->num].price = 10.5;
	p->books[p->num].date.day = 15;
	p->books[p->num].date.month = 1;
	p->books[p->num].date.year = 1990;
	(p->num)++;
	p->books[p->num].id = 2;
	p->books[p->num].price = 20.55;

	p->books[p->num].date.day = 15;
	p->books[p->num].date.month = 2;
	p->books[p->num].date.year = 2024;
	(p->num)++;
	p->books[p->num].id = 4;
	p->books[p->num].price = 10.5;
	p->books[p->num].date.day = 20;
	p->books[p->num].date.month = 2;
	p->books[p->num].date.year = 2021;
	(p->num)++;
	p->books[p->num].id = 1;
	p->books[p->num].price = 30.1;
	p->books[p->num].date.day = 20;
	p->books[p->num].date.month = 2;
	p->books[p->num].date.year = 2021;
	(p->num)++;
}



int main() {
	Library lib;
	lib.num = 0;

	init(&lib);

	int opt;
	do {
		listOptions(lib);
		cin >> opt;
		if (opt == 1) {
			add(&lib);
			cout << endl;

		}
		else if (opt == 2) {
			show(&lib);
			cout << endl;
		}
		else if (opt == 3) {
			del(&lib);
			cout << endl;
		}
		else if (opt == 4) {
			sort(&lib);
			cout << endl;
		}
	} while (opt != 0);
	cout << "Bye!";

	return 0;
}





