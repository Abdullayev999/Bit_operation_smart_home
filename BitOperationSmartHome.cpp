#include<iostream>

using namespace std;


/*
		ДЗ 1:
		1. В программе должно быть три опции
		2. Для хранения этих опций используйте переменную типа uint8_t
		3. Реализуйте возможность включать/отключать опции на основе ввода пользователя
		4. Реализуйте возможность распечатать состояние опций

		ДЗ 2:
		1. Создайте переменную типа uint8_t и присвойте ей некоторое значение (например 1)
		2. Напишите функцию, которая печатает биты переменной типа uint8_t
		Пример:
		uint8_t n = 1; // 00000001
		f(n); // печатает 00000001

*/


void uint8_tToBit(uint8_t number)
{
	int size = 8;
	for (int i = 0; i < size; i++)
		if (number & (1 << (size - i - 1))) {
			cout << '1';
		}
		else {
			cout << '0';
		}
}

enum { EXIT, WATER, GAS, ELECTRICITY, TV, WASH_MASHIN };

int main() {

	cout << "Home work 1\n\n";

	uint8_t a = 1;
	uint8_tToBit(a);


	cout << "\n\nHome work 2\n\n";

	const int One = 1;
	const int Two = 2;
	const int ComeBack = 3;

	uint8_t fullOption = 31;			// 00011111

	const uint8_t water = 1;   			// 00000001  
	const uint8_t gas = 2;				// 00000010  
	const uint8_t electricity = 4;	    // 00000100 
	const uint8_t tv = 8;				// 00001000  
	const uint8_t washMachin = 16;		// 00010000  


	unsigned short action;

	do
	{
		cout << "1) Water\t  -\t";
		water == (fullOption & water) ? cout << "on\n" : cout << "off\n";

		cout << "2) Gas\t\t  -\t";
		gas == (fullOption & gas) ? cout << "on\n" : cout << "off\n";

		cout << "3) Electricity\t  -\t";
		electricity == (fullOption & electricity) ? cout << "on\n" : cout << "off\n";

		cout << "4) Tv\t\t  -\t";
		tv == (fullOption & tv) ? cout << "on\n" : cout << "off\n";

		cout << "5) Washing Machin -\t";
		washMachin == (fullOption & washMachin) ? cout << "on\n" : cout << "off\n";



		cout << R"(
0  -  Exit
1  -  WATER ( on / off )
2  -  GAS ( on / off )
3  -  ELECTRICITY ( on / off )
4  -  TV ( on / off )
5  -  Washing Mashin ( on / off )

)";

		cin >> action;
		system("cls");

		if (action == EXIT)
		{
			cout << "You have left the program\n";
			break;
		}
		else if (action == WATER)
		{
			do
			{
				cout << "\nWater : \n1 - on\n2 - off\n3 - come back\n\n";
				cin >> action;
				system("cls");
				if (action == One) {
					if (water == (fullOption & water)) {
						cout << "You cannot turn on the water because it is already on\n";
					}
					else {
						fullOption |= water;
						cout << "You turned ON the water\n";
					}
				}
				else if (action == Two)
				{
					if (water == (fullOption & water)) {
						cout << "You turned OFF the water\n";
						fullOption &= ~water;
						if (washMachin == (fullOption & washMachin))
						{
							fullOption &= ~washMachin;
							cout << "due to lack of water, the Wash Macin turned OFF\n";
						}
					}
					else {
						cout << "You cannot turn off the water because it is already turned off\n";
					}
				}
				else if (action == ComeBack)
				{
					cout << "You come back\n";
					break;
					system("cls");
				}
				else {
					cout << "Wrong choice , try again \n";
				}
			} while (true);
		}
		else if (action == GAS)
		{
			do
			{
				cout << "\nGas : \n1 - on\n2 - off\n3 - come back\n\n";
				cin >> action;
				system("cls");
				if (action == One) {
					if (gas == (fullOption & gas)) {
						cout << "You cannot turn ON the gas because it is already ON\n";
					}
					else {
						fullOption |= gas;
						cout << "You turned ON the gas\n";
					}
				}
				else if (action == Two)
				{
					if (gas != (fullOption & gas)) {
						cout << "You cannot turn OFF the gas because it is already turned OFF\n";
					}
					else {
						fullOption &= ~gas;
						cout << "You turned OFF the gas\n";
					}
				}
				else if (action == ComeBack)
				{
					cout << "You come back\n";
					break;
					system("cls");
				}
				else {
					cout << "Wrong choice , try again \n";
				}
			} while (true);
		}
		else if (action == ELECTRICITY)
		{
			do
			{
				cout << "\nElectricity : \n1 - on\n2 - off\n3 - come back\n\n";
				cin >> action;
				system("cls");
				if (action == One) {
					if (electricity == (fullOption & electricity)) {
						cout << "You cannot turn ON the electricity because it is already turned ON\n";
					}
					else {
						fullOption |= electricity;
						cout << "You turned ON the electricity\n";
					}
				}
				else if (action == Two)
				{
					if (electricity == (fullOption & electricity)) {
						cout << "You turned OFF the electricity\n";
						fullOption &= ~electricity;
						if (tv == (fullOption & tv))
						{
							fullOption &= ~tv;
							cout << "due to lack of electricity, the TV turned OFF\n";
						}
						if (washMachin == (fullOption & washMachin))
						{
							fullOption &= ~washMachin;
							cout << "due to lack of electricity, the Wash Macin turned OFF\n";
						}
					}
					else {
						cout << "You cannot turn OFF the electricity because it is already turned OFF\n";
					}
				}
				else if (action == ComeBack)
				{
					cout << "You come back\n";
					break;
					system("cls");
				}
				else {
					cout << "Wrong choice , try again \n";
				}
			} while (true);
		}
		else if (action == TV)
		{
			do
			{
				cout << "\nTv : \n1 - on\n2 - off\n3 - come back\n\n";
				cin >> action;
				system("cls");
				if (action == One) {
					if (electricity == (fullOption & electricity)) {
						if (tv != (fullOption & tv))
						{
							fullOption |= tv;
							cout << "You turned ON the tv\n";
						}
						else {
							cout << "You cannot turn ON the tv because it is already turned ON\n";
						}
					}
					else {
						cout << "TV does not work due to lack of electricity\n";
					}
				}
				else if (action == Two)
				{
					if (electricity == (fullOption & electricity)) {
						if (tv != (fullOption & tv))
						{
							cout << "You cannot turn OFF the tv because it is already turned OFF\n";
						}
						else {
							fullOption &= ~tv;
							cout << "You turned OFF the Tv\n";
						}
					}
					else {
						cout << "You cannot turn OFF the tv because it is already turned OFF\n";
					}
				}
				else if (action == ComeBack)
				{
					cout << "You come back\n";
					break;
					system("cls");
				}
				else {
					cout << "Wrong choice , try again \n";
				}
			} while (true);
		}
		else if (action == WASH_MASHIN) {
			do
			{
				cout << "\nWashing Machin : \n1 - on\n2 - off\n3 - come back\n\n";
				cin >> action;
				system("cls");
				if (action == One) {
					if (electricity == (fullOption & electricity)) {
						if (water == (fullOption & water)) {
							if (washMachin != (fullOption & washMachin)) {
								cout << "You turned ON the Wash Machin\n";
								fullOption |= washMachin;
							}
							else {
								cout << "You cannot turn ON the Wash Machin because it is already turned ON\n";
							}
						}
						else {
							cout << "Washing Machin does not work due to lack of water\n";
						}
					}
					else {
						cout << "Washing Machin does not work due to lack of electricity\n";
					}
				}
				else if (action == Two)
				{
					if (electricity == (fullOption & electricity)) {
						if (water == (fullOption & water)) {
							if (washMachin == (fullOption & washMachin)) {
								cout << "You turned OFF the Wash Machin\n";
								fullOption &= ~washMachin;
							}
							else {
								cout << "You cannot turn OFF the Wash Machin because it is already turned OFF\n";
							}
						}
						else {
							cout << "You cannot turn OFF the Wash Machin because it is already turned OFF\n";
						}
					}
					else {
						cout << "You cannot turn OFF the Wash Machin because it is already turned OFF\n";
					}
				}
				else if (action == ComeBack) {
					cout << "You come back\n";
					break;
					
				}
				else {
					cout << "Wrong choice , try again \n";
				}
			} while (true);
		}
		else {
			cout << "Wrong choice , try again \n";
		}
	} while (true);



}

