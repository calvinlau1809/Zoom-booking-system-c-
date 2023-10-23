#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void category_A(string&, int&, string&, int&);
void category_B(string&, int&, string&, int&);
void record(string, string, string, int, string);
void slot1(int&, string&, string, string, string, int, string);
void slot2(int&, string&, string, string, string, int, string);
void slot3(int&, string&, string, string, string, int, string);
void slot4(int&, string&, string, string, string, int, string);
void update(string&, int&, string&, string&, string&);
void cancel(string&, int&, string&, string&, string&);
void output();
struct Booking_num
{
	string zoom;
	string slot;
	string course_name;
	string student_num;
	string date;
};
int verification_date(string);

string booking_1;
string booking_2;
string booking_3;
string booking_4;
string date_slot[5][100] = { {"15062020", "16062020", "17062020","18062020","19062020","22062020","23062020", "24062020", "25062020", "26062020", "29062020", "30062020","01072020","02072020","03072020","06072020","07072020","08072020", "09072020","10072020", "13072020","14072020","15072020","16072020","17072020","20072020","21072020","22072020","23072020","24072020","27072020","28072020","29072020","30072020","03082020","04082020","05082020","06082020","07082020","10082020","11082020","12082020","13082020","14082020","17082020","18082020","19082020","20082020","21082020","24082020","25082020","26082020","27082020","28082020","31082020","01092020","02092020","03092020","04092020","07092020","08092020","09092020","10092020","11092020","14092020","15092020","16092020","17092020","18092020" },{},{},{},{} };
string book_name[4][100];
int book_num[4][100];
Booking_num booking[100];
int ruc;

int main()
{
	int start = 1;
	string course_name;
	int student_num;
	string date;
	int confirm;

	while (start != 2)
	{
		cout << "\t\t~~~~~~~~~~~ ================================ ~~~~~~~~~~~~" << endl;
		cout << "\t\t~~~~~~~~~~~ |Welcome to UTAR Booking Center| ~~~~~~~~~~~~" << endl;
		cout << "\t\t~~~~~~~~~~~ ================================ ~~~~~~~~~~~~" << "\n\n";
		cout << "Due to recent pandemic outbreak , UTAR had decided to carry out online classes for June trimester starting from 15 June 2020 to 20 September 2020." << endl;
		cout << "Lecturer should book zoom accounts to carry on their teaching through online classes." << "\n\n";
		cout << "Maximum Student per class is 500" << endl << endl;
		cout << "Please enter the name of courses = ";
		cin.clear();
		getline(cin, course_name);
		cout << endl;
		cout << "Please enter the number of students = ";
		cin >> student_num;
		if (student_num <= 0 or student_num > 501)
		{
			cout << "The number of student you key in is invalid, Please key in between 1-500. TQ :D" << endl;
			system("pause");
			cin.ignore();
			system("cls");
			continue;
		}
		cout << endl;
		cout << "Please enter the date for your booking (DDMMYYYY) eg.(28072020) = ";
		cin.ignore();
		cin >> date;
		confirm = verification_date(date);
		if (confirm != 1)
		{
			cout << "The date you enter currently is not available, Please enter a new date again" << endl;
			start = 1;
			system("pause");
			cin.ignore();
			system("cls");
			continue;
		}
		if (student_num > 250 and student_num < 501)
		{
			system("cls");
			category_A(course_name, student_num, date, start);
		}
		else if (student_num > 0 and student_num <= 250)
		{
			system("cls");
			category_B(course_name, student_num, date, start);
		}
		system("cls");
	}
	output();

	system("pause");
	return 0;
}

void category_A(string& course_name, int& student_num, string& date, int& start)
{
	string zoom;
	string time;

	cout << "The Available Slots For This Course Are" << "\n\n";
	cout << "==========================================" << endl;
	cout << "Zoom Accounts		   Time           " << endl;
	cout << "1.) Zoom A		11am - 1pm        " << endl;
	cout << "2.) Zoom A		2pm - 4pm         " << endl;
	cout << "==========================================" << endl;
	cout << "Please Select The Available Slot (Please State the Time)" << endl;
	zoom = 'A';
	cout << endl;
	cin.ignore();
	cout << "Please Key in Time Available (with am/pm , exactly as stated above) = ";
	getline(cin, time);
	if (time == "11am - 1pm" && zoom == "A") // slot 1
	{
		string slot = "11am - 1pm";
		slot1(start, booking_1, zoom, slot, course_name, student_num, date);
	}

	else if (time == "2pm - 4pm" && zoom == "A") // slot 2
	{
		string slot = "2pm - 4pm";
		slot2(start, booking_2, zoom, slot, course_name, student_num, date);
	}
	else
	{
		cout << "The time you key in is unavailable, please try again " << endl;
	}
	cin.ignore();
}
void category_B(string& course_name, int& student_num, string& date, int& start)
{
	string zoom;
	string time;

	cout << "The Available Slots For This Course Are" << "\n\n";
	cout << "==========================================" << endl;
	cout << "Zoom Accounts			Time" << endl;
	cout << "1.) Zoom A			11am - 1pm" << endl;
	cout << "2.) Zoom A			2pm - 4pm" << endl;
	cout << "3.) Zoom B			11am - 1pm" << endl;
	cout << "4.) Zoom B			2pm - 4pm" << endl;
	cout << "==========================================" << endl;
	cout << "Please Select The Available Slot (Please State the Time)" << endl;
	cout << "Please key in the Zoom Account(A/B) = ";
	cin >> zoom;
	if (zoom != "A" || zoom != "B")
		cout << endl;
	cin.ignore();
	cout << "Please Key in Time Available (with am/pm , exactly as stated above) = ";
	getline(cin, time);
	if (time == "11am - 1pm" && zoom == "A") // slot 1
	{
		string slot = "11am - 1pm";
		slot1(start, booking_1, zoom, slot, course_name, student_num, date);
	}

	else if (time == "2pm - 4pm" && zoom == "A") // slot 2
	{
		string slot = "2pm - 4pm";
		slot2(start, booking_2, zoom, slot, course_name, student_num, date);
	}
	else if (time == "11am - 1pm" && zoom == "B") // slot 3
	{
		string slot = "11am - 1pm";
		slot3(start, booking_3, zoom, slot, course_name, student_num, date);
	}
	else if (time == "2pm - 4pm" && zoom == "B") // slot 4
	{
		string slot = "2pm - 4pm";
		slot4(start, booking_4, zoom, slot, course_name, student_num, date);
	}
	else
	{
		cout << "The time you key in or the zoom account is unavailable, please try again " << endl;
	}
	cin.ignore();
}

void slot1(int& start, string& booking_1, string zoom, string slot, string course_name, int student_num, string date)
{

	for (int j = 0; j < 100; j++)
	{
		if (date == date_slot[0][j])
		{
			if (date_slot[1][j] != "1")
			{
				date_slot[1][j] = "1";
				book_name[0][j] = course_name;
				book_num[0][j] = student_num;
				cout << "Booking Completed and Recorded";
				record(zoom, slot, course_name, student_num, date);
				cout << endl;
				cout << "\n Thank you for booking!" << endl;
				cout << "--------------------------------- " << endl;
				cout << " Your Booking are listed below: \n\n" << " Course code and name: " << course_name << endl;
				cout << " Number of Students: " << student_num << endl;
				cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl << endl << endl;
				cout << "Do you now wish to continue to book or exit the program?" << endl;
				cout << "Press 1 if you wish to continue the booking system " << endl;
				cout << "Press 2 if you wish to exit the program" << endl;
				cout << "Your pick is = ";
				cin >> start;
				booking_1 = course_name;
			}
			else
			{
				if (booking_1 == course_name)
				{
					cout << " =============================================== " << endl;
					cout << " You have already book this zoom slot previously " << endl;
					cout << " =============================================== " << endl;
				}
				else
				{
					cout << "Unfortunately this current slot is occupied by " << book_name[0][j] << endl;
					cout << "Press 1 to Remain (There will be no changes, everything remain unchange)" << endl;
					cout << "Press 2 to Update (Replace the current data with the previous data)" << endl;
					cout << "Press 3 to Cancel (Remove the current data and previous data)" << endl;
					cout << "Your Selection Is = ";
					cin >> ruc;
					if (ruc == 1)
					{
						cout << "\n Your previous booking is remained." << endl;
						cout << "------------------------------------- " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << book_name[0][j] << endl;
						cout << " Number of Students: " << book_num[0][j] << endl;
						cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl;
					}
					if (ruc == 2)
					{
						update(course_name, student_num, zoom, slot, date);
						cout << "\n Your booking has been updated " << endl;
						cout << "--------------------------------- " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << course_name << endl;
						cout << " Number of Students: " << student_num << endl;
						cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl;
					}
					if (ruc == 3)
					{
						date_slot[1][j] = "0";
						cancel(course_name, student_num, zoom, slot, date);
						cout << "\n Your bookings has been cancelled" << endl;
						cout << "------------------------------------ " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << "-" << endl;
						cout << " Number of Students: " << "-" << endl;
						cout << " Zoom Class: " << "-" << '\n' << " Time: " << "-" << '\n' << " Date: " << "-" << '\n' << endl;
					}
					else if (!(ruc == 1 || ruc == 2 || ruc == 3))
					{
						cout << "The selection you key in is unavailable, Please try again." << endl;
						system("pause");
						continue;
					}
					cout << endl;
					cout << "Do you now wish to continue to book or exit the program?" << endl;
					cout << "Press 1 if you wish to continue the booking system " << endl;
					cout << "Press 2 if you wish to exit the program" << endl;
					cout << "Your pick is = ";
					cin >> start;
				}
			}
		}
	}
}
void slot2(int& start, string& booking_2, string zoom, string slot, string course_name, int student_num, string date)
{
	int date_space = 2;
	for (int j = 0; j < 100; j++)
	{
		if (date == date_slot[0][j])
		{
			if (date_slot[2][j] != "1")
			{
				date_slot[2][j] = "1";
				book_name[1][j] = course_name;
				book_num[1][j] = student_num;
				cout << "Booking Completed and Recorded";
				record(zoom, slot, course_name, student_num, date);
				cout << endl;
				cout << "\n Thank you for booking!" << endl;
				cout << "--------------------------------- " << endl;
				cout << " Your Booking are listed below: \n\n" << " Course code and name: " << course_name << endl;
				cout << " Number of Students: " << student_num << endl;
				cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl << endl << endl;
				cout << "Do you now wish to continue to book or exit the program?" << endl;
				cout << "Press 1 if you wish to continue the booking system " << endl;
				cout << "Press 2 if you wish to exit the program" << endl;
				cout << "Your pick is = ";
				cin >> start;
				booking_2 = course_name;
			}
			else
			{
				if (booking_2 == course_name)
				{
					cout << " =============================================== " << endl;
					cout << " You have already book this zoom slot previously " << endl;
					cout << " =============================================== " << endl;
				}
				else
				{
					cout << "Unfortunately this current slot is occupied by " << book_name[1][j] << endl;
					cout << "Press 1 to Remain (There will be no changes, everything remain unchange)" << endl;
					cout << "Press 2 to Update (Replace the current data with the previous data)" << endl;
					cout << "Press 3 to Cancel (Remove the current data and previous data)" << endl;
					cout << "Your Selection Is = ";
					cin >> ruc;
					if (ruc == 1)
					{
						cout << "\n Your previous booking is remained." << endl;
						cout << "-------------------------------------" << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << book_name[1][j] << endl;
						cout << " Number of Students: " << book_num[1][j] << endl;
						cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl;

					}
					if (ruc == 2)
					{
						update(course_name, student_num, zoom, slot, date);
						cout << "\n Your booking has been updated \n" << endl;
						cout << "--------------------------------- " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << course_name << endl;
						cout << " Number of Students: " << student_num << endl;
						cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl;

					}
					if (ruc == 3)
					{
						date_slot[2][j] = "0";
						cancel(course_name, student_num, zoom, slot, date);
						cout << "\n Your bookings has been cancelled" << endl;
						cout << "------------------------------------" << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << "-" << endl;
						cout << " Number of Students: " << "-" << endl;
						cout << " Zoom Class: " << "-" << '\n' << " Time: " << "-" << '\n' << " Date: " << "-" << '\n' << endl;

					}
					else if (!(ruc == 1 || ruc == 2 || ruc == 3))
					{
						cout << "The selection you key in is unavailable, Please try again." << endl;
						system("pause");
						continue;
					}
					cout << endl;
					cout << "Do you now wish to continue to book or exit the program?" << endl;
					cout << "Press 1 if you wish to continue the booking system " << endl;
					cout << "Press 2 if you wish to exit the program" << endl;
					cout << "Your pick is = ";
					cin >> start;
				}
			}
		}
	}
}
void slot3(int& start, string& booking_3, string zoom, string slot, string course_name, int student_num, string date)
{
	int date_space = 3;
	for (int j = 0; j < 100; j++)
	{
		if (date == date_slot[0][j])
		{
			if (date_slot[3][j] != "1")
			{
				date_slot[3][j] = "1";
				book_name[2][j] = course_name;
				book_num[2][j] = student_num;
				cout << "Booking Completed and Recorded";
				record(zoom, slot, course_name, student_num, date);
				cout << endl;
				cout << "\n Thank you for booking! " << endl;
				cout << "--------------------------------- " << endl;
				cout << " Your Booking are listed below: \n\n" << " Course code and name: " << course_name << endl;
				cout << " Number of Students: " << student_num << endl;
				cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl << endl << endl;
				cout << "Do you now wish to continue to book or exit the program?" << endl;
				cout << "Press 1 if you wish to continue the booking system " << endl;
				cout << "Press 2 if you wish to exit the program" << endl;
				cout << "Your pick is = ";
				cin >> start;
				booking_3 = course_name;
			}
			else
			{
				if (booking_3 == course_name)
				{
					cout << " =============================================== " << endl;
					cout << " You have already book this zoom slot previously " << endl;
					cout << " =============================================== " << endl;
				}
				else
				{
					cout << "Unfortunately this current slot is occupied by " << book_name[2][j] << endl;
					cout << "Press 1 to Remain (There will be no changes, everything remain unchange)" << endl;
					cout << "Press 2 to Update (Replace the current data with the previous data)" << endl;
					cout << "Press 3 to Cancel (Remove the current data and previous data)" << endl;
					cout << "Your Selection Is = ";
					cin >> ruc;
					if (ruc == 1)
					{
						cout << "\n Your previous booking is remained." << endl;
						cout << "------------------------------------- " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << book_name[2][j] << endl;
						cout << " Number of Students: " << book_num[2][j] << endl;
						cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl;

					}
					if (ruc == 2)
					{
						update(course_name, student_num, zoom, slot, date);
						cout << "\n Your booking has been updated" << endl;
						cout << "--------------------------------- " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << course_name << endl;
						cout << " Number of Students: " << student_num << endl;
						cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl;

					}
					if (ruc == 3)
					{
						date_slot[3][j] = "0";
						cancel(course_name, student_num, zoom, slot, date);
						cout << "\n Your bookings has been cancelled" << endl;
						cout << "------------------------------------" << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << "-" << endl;
						cout << " Number of Students: " << "-" << endl;
						cout << " Zoom Class: " << "-" << '\n' << " Time: " << "-" << '\n' << " Date: " << "-" << '\n' << endl;

					}
					else if (!(ruc == 1 || ruc == 2 || ruc == 3))
					{
						cout << "The selection you key in is unavailable, Please try again." << endl;
						system("pause");
						continue;
					}
					cout << endl;
					cout << "Do you now wish to continue to book or exit the program?" << endl;
					cout << "Press 1 if you wish to continue the booking system " << endl;
					cout << "Press 2 if you wish to exit the program" << endl;
					cout << "Your pick is = ";
					cin >> start;
				}
			}
		}
	}
}
void slot4(int& start, string& booking_4, string zoom, string slot, string course_name, int student_num, string date)
{
	int date_space = 4;
	for (int j = 0; j < 100; j++)
	{
		if (date == date_slot[0][j])
		{
			if (date_slot[4][j] != "1")
			{
				date_slot[4][j] = "1";
				book_name[3][j] = course_name;
				book_num[3][j] = student_num;
				cout << "Booking Completed and Recorded";
				record(zoom, slot, course_name, student_num, date);
				cout << endl;
				cout << "\n Thank you for booking!" << endl;
				cout << "--------------------------------- " << endl;
				cout << " Your Booking are listed below: \n\n" << " Course code and name: " << course_name << endl;
				cout << " Number of Students: " << student_num << endl;
				cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl << endl << endl;
				cout << "Do you now wish to continue to book or exit the program?" << endl;
				cout << "Press 1 if you wish to continue the booking system " << endl;
				cout << "Press 2 if you wish to exit the program" << endl;
				cout << "Your pick is = ";
				cin >> start;
				booking_4 = course_name;
			}
			else
			{
				if (booking_4 == course_name)
				{
					cout << " =============================================== " << endl;
					cout << " You have already book this zoom slot previously " << endl;
					cout << " =============================================== " << endl;
				}
				else
				{
					cout << "Unfortunately this current slot is occupied by " << book_name[3][j] << endl;
					cout << "Press 1 to Remain (There will be no changes, everything remain unchange)" << endl;
					cout << "Press 2 to Update (Replace the current data with the previous data)" << endl;
					cout << "Press 3 to Cancel (Remove the current data and previous data)" << endl;
					cout << "Your Selection Is = ";
					cin >> ruc;
					if (ruc == 1)
					{
						cout << "\n Your previous booking is remained." << endl;
						cout << "------------------------------------- " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << book_name[3][j] << endl;
						cout << " Number of Students: " << book_num[3][j] << endl;
						cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl;
					}
					if (ruc == 2)
					{
						update(course_name, student_num, zoom, slot, date);
						cout << "\n Your booking has been updated" << endl;
						cout << "--------------------------------- " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << course_name << endl;
						cout << " Number of Students: " << student_num << endl;
						cout << " Zoom Class: " << zoom << '\n' << " Time: " << slot << '\n' << " Date: " << date << '\n' << endl;

					}
					if (ruc == 3)
					{
						date_slot[4][j] = "0";
						cancel(course_name, student_num, zoom, slot, date);
						cout << "\n Your bookings has been cancelled" << endl;
						cout << "------------------------------------ " << endl;
						cout << " Your Booking are listed below: \n\n" << " Course code and name: " << "-" << endl;
						cout << " Number of Students: " << "-" << endl;
						cout << " Zoom Class: " << "-" << '\n' << " Time: " << "-" << '\n' << " Date: " << "-" << '\n' << endl;

					}
					else if (!(ruc == 1 || ruc == 2 || ruc == 3))
					{
						cout << "The selection you key in is unavailable, Please try again." << endl;
						system("pause");
						continue;
					}
					cout << endl;
					cout << "Do you now wish to continue to book or exit the program?" << endl;
					cout << "Press 1 if you wish to continue the booking system " << endl;
					cout << "Press 2 if you wish to exit the program" << endl;
					cout << "Your pick is = ";
					cin >> start;
				}
			}
		}
	}
}

void record(string zoom, string slot, string course_name, int student_num, string date)
{
	ofstream booking_file;
	booking_file.open("booking.txt", ios::app);
	if (booking_file.is_open())
	{
		booking_file << zoom << endl;
		booking_file << slot << endl;
		booking_file << course_name << endl;
		booking_file << student_num << endl;
		booking_file << date << endl;
	}
	booking_file.close();
}
int verification_date(string date)
{
	int confirm = 0;
	for (int j = 0; j < 100; j++)
	{
		if (date == date_slot[0][j])
		{
			confirm = confirm + 1;
		}
	}
	return confirm;
}

void update(string& course_name, int& student_num, string& zoom, string& slot, string& date)
{
	int x = 0;
	int j = 0;
	int b = 1;
	ifstream booking_file;
	booking_file.open("booking.txt");
	if (booking_file.is_open())
	{
		while (!booking_file.eof())
		{
			getline(booking_file, booking[x].zoom);
			getline(booking_file, booking[x].slot);
			getline(booking_file, booking[x].course_name);
			getline(booking_file, booking[x].student_num);
			getline(booking_file, booking[x].date);
			x++;
		}
		booking_file.close();
	}
	x = x - 2;
	while (j <= x)
	{
		if (date == booking[j].date && zoom == booking[j].zoom && slot == booking[j].slot && j == 0)
		{
			ofstream booking_file;
			booking_file.open("booking.txt", ios::trunc);
			if (booking_file.is_open())
			{
			}
			booking_file.close();
		}
		else if (date != booking[j].date || zoom != booking[j].zoom || slot != booking[j].slot)
		{
			if (b == 1)
			{
				ofstream booking_file;
				booking_file.open("booking.txt", ios::trunc);
				if (booking_file.is_open())
				{
					booking_file << booking[j].zoom << endl;
					booking_file << booking[j].slot << endl;
					booking_file << booking[j].course_name << endl;
					booking_file << booking[j].student_num << endl;
					booking_file << booking[j].date << endl;
				}
				booking_file.close();
				b = b + 1;
			}
			else
			{
				ofstream booking_file;
				booking_file.open("booking.txt", ios::app);
				if (booking_file.is_open())
				{
					booking_file << booking[j].zoom << endl;
					booking_file << booking[j].slot << endl;
					booking_file << booking[j].course_name << endl;
					booking_file << booking[j].student_num << endl;
					booking_file << booking[j].date << endl;
				}
				booking_file.close();
			}
		}
		j++;
	}
	record(zoom, slot, course_name, student_num, date);
	for (int j = 0; j < 100; j++)
	{
		if (date == date_slot[0][j] and zoom == "A" and slot == "11am - 1pm")
		{
			book_name[0][j] = course_name;
			book_num[0][j] = student_num;
			booking_1 = course_name;
		}
		if (date == date_slot[0][j] and zoom == "A" and slot == "2pm - 4pm")
		{
			book_name[1][j] = course_name;
			book_num[1][j] = student_num;
			booking_2 = course_name;
		}
		if (date == date_slot[0][j] and zoom == "B" and slot == "11am - 1pm")
		{
			book_name[2][j] = course_name;
			book_num[2][j] = student_num;
			booking_3 = course_name;
		}
		if (date == date_slot[0][j] and zoom == "B" and slot == "2pm - 4pm")
		{
			book_name[3][j] = course_name;
			book_num[3][j] = student_num;
			booking_4 = course_name;
		}
	}
}
void cancel(string& course_name, int& student_num, string& zoom, string& slot, string& date)
{
	int x = 0;
	int j = 0;
	int c = 1;
	ifstream booking_file;
	booking_file.open("booking.txt");
	if (booking_file.is_open())
	{
		while (!booking_file.eof())
		{
			getline(booking_file, booking[x].zoom);
			getline(booking_file, booking[x].slot);
			getline(booking_file, booking[x].course_name);
			getline(booking_file, booking[x].student_num);
			getline(booking_file, booking[x].date);
			x++;
		}
		booking_file.close();
	}
	x = x - 2;
	while (j <= x)
	{
		if (date == booking[j].date && zoom == booking[j].zoom && slot == booking[j].slot && j == 0)
		{
			ofstream booking_file;
			booking_file.open("booking.txt", ios::trunc);
			if (booking_file.is_open())
			{
			}
			booking_file.close();
		}
		else if (date != booking[j].date || zoom != booking[j].zoom || slot != booking[j].slot)
		{
			if (c == 1)
			{
				ofstream booking_file;
				booking_file.open("booking.txt", ios::trunc);
				if (booking_file.is_open())
				{
					booking_file << booking[j].zoom << endl;
					booking_file << booking[j].slot << endl;
					booking_file << booking[j].course_name << endl;
					booking_file << booking[j].student_num << endl;
					booking_file << booking[j].date << endl;
				}
				booking_file.close();
				c = c + 1;
			}
			else
			{
				ofstream booking_file;
				booking_file.open("booking.txt", ios::app);
				if (booking_file.is_open())
				{
					booking_file << booking[j].zoom << endl;
					booking_file << booking[j].slot << endl;
					booking_file << booking[j].course_name << endl;
					booking_file << booking[j].student_num << endl;
					booking_file << booking[j].date << endl;
				}
				booking_file.close();
			}
		}
		j++;
	}
}

void output()
{
	int x = 0;

	int selection;
	int choice = 0;
	string dates;
	string course_name;
	string time;
	string zoom;

	ifstream booking_file;
	booking_file.open("booking.txt");
	if (booking_file.is_open())
	{
		while (!booking_file.eof())
		{
			getline(booking_file, booking[x].zoom);
			getline(booking_file, booking[x].slot);
			getline(booking_file, booking[x].course_name);
			getline(booking_file, booking[x].student_num);
			getline(booking_file, booking[x].date);
			x++;
		}
		booking_file.close();
	}
	while (choice != 2)
	{
		cout << "\t\t *&?!   ===============    !?#" << endl;
		cout << "\t\t   #*@  |Search Engine|   @!%" << endl;
		cout << "\t\t  %&&   ===============    *$# " << endl;
		cout << "There are a few preferences for searching to ease your findings for bookings :D" << endl << endl;
		cout << "\t\t||SEARCH PREFERENCES||" << endl;
		cout << "1.) Search By Dates" << endl;
		cout << "2.) Search By Course Name" << endl;
		cout << "3.) Search By Time Range" << endl;
		cout << "4.) Search By Zoom Account" << endl;
		cout << "5.) Search All (Every Booking)" << endl;
		cout << "6.) Exit Page" << endl;

		cout << "Please key in your preference (1/2/3/4/5/6) = ";
		cin >> selection;
		system("cls");
		if (selection == 1) // date
		{
			cout << "You have chosen the Search By Dates Options" << endl;
			cout << "Now key in the date you want to search = ";
			cin.ignore();
			getline(cin, dates);
			cout << endl;
			int j = 0;
			while (j <= x)
			{
				if (dates == booking[j].date)
				{
					cout << "Zoom = " << booking[j].zoom << endl;
					cout << "Slot = " << booking[j].slot << endl;
					cout << "Course Name = " << booking[j].course_name << endl;
					cout << "Student Number = " << booking[j].student_num << endl;
					cout << "Dates = " << booking[j].date << endl << endl;
					j++;
				}
				else
				{
					j++;
				}
			}
			cout << "Select 1 to return to Search Page" << endl;
			cout << "Select 2 to exit the page" << endl;
			cout << "Please key in your choice here (1/2) = ";
			cin >> choice;
			system("cls");

		}
		else if (selection == 2) //course_name
		{
			cout << "You have chosen the Search By Course Name Options" << endl;
			cout << "Now key in the course name you want to search = ";
			cin.ignore();
			getline(cin, course_name);
			cout << endl;
			int j = 0;
			while (j <= x)
			{
				if (course_name == booking[j].course_name)
				{
					cout << "Zoom = " << booking[j].zoom << endl;
					cout << "Slot = " << booking[j].slot << endl;
					cout << "Course Name = " << booking[j].course_name << endl;
					cout << "Student Number = " << booking[j].student_num << endl;
					cout << "Dates = " << booking[j].date << endl << endl;
					j++;
				}
				else
				{
					j++;
				}
			}
			cout << "Select 1 to return to Search Page" << endl;
			cout << "Select 2 to exit the page" << endl;
			cout << "Please key in your choice here (1/2) = ";
			cin >> choice;
			system("cls");
		}
		else if (selection == 3) // time
		{
			cout << "You have chosen the Search By Time Options" << endl;
			cout << "Now key in the time range you want to search = ";
			cin.ignore();
			getline(cin, time);
			cout << endl;
			int j = 0;
			while (j <= x)
			{
				if (time == booking[j].slot)
				{
					cout << "Zoom = " << booking[j].zoom << endl;
					cout << "Slot = " << booking[j].slot << endl;
					cout << "Course Name = " << booking[j].course_name << endl;
					cout << "Student Number = " << booking[j].student_num << endl;
					cout << "Dates = " << booking[j].date << endl << endl;
					j++;
				}
				else
				{
					j++;
				}
			}
			cout << "Select 1 to return to Search Page" << endl;
			cout << "Select 2 to exit the page" << endl;
			cout << "Please key in your choice here (1/2) = ";
			cin >> choice;
			system("cls");
		}
		else if (selection == 4) // zoom account
		{
			cout << "You have chosen the Search By Zoom Account Options" << endl;
			cout << "Now key in the zoom account you want to search. Please Use CAPS LOCK (A/B) = ";
			cin.ignore();
			getline(cin, zoom);
			cout << endl;
			int j = 0;
			while (j <= x)
			{
				if (zoom == booking[j].zoom)
				{
					cout << "Zoom = " << booking[j].zoom << endl;
					cout << "Slot = " << booking[j].slot << endl;
					cout << "Course Name = " << booking[j].course_name << endl;
					cout << "Student Number = " << booking[j].student_num << endl;
					cout << "Dates = " << booking[j].date << endl << endl;
					j++;
				}
				else
				{
					j++;
				}
			}
			cout << "Select 1 to return to Search Page" << endl;
			cout << "Select 2 to exit the page" << endl;
			cout << "Please key in your choice here (1/2) = ";
			cin >> choice;
			system("cls");
		}
		else if (selection == 5) // all
		{
			cout << "You have chosen the Search All Options" << endl;
			cout << endl;
			int j = 0;
			while (j < x - 1)
			{
				cout << "Zoom = " << booking[j].zoom << endl;
				cout << "Slot = " << booking[j].slot << endl;
				cout << "Course Name = " << booking[j].course_name << endl;
				cout << "Student Number = " << booking[j].student_num << endl;
				cout << "Dates = " << booking[j].date << endl << endl;
				j++;
			}
			cout << "Select 1 to return to Search Page" << endl;
			cout << "Select 2 to exit the page" << endl;
			cout << "Please key in your choice here (1/2) = ";
			cin >> choice;
			system("cls");
		}
		else if (selection == 6) //exit
		{
			choice = 2;
		}
		else
		{
			cout << "The input is invalid, Please try again :D " << endl;
			choice = 1;
			system("pause");
			system("cls");
		}
	}
	cout << "TQ for using Utar Booking System, Have a nice day :D" << endl;
}
