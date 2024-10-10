#include "generalFunctions.h"

//! red msg
const void errorMsg(const string& msg) {
	cout << endl << "\033[1;31m" + msg + "\033[0m" << endl;
};
//! green msg
const void successMsg(const string& msg) {
	cout << endl << "\033[1;32m" + msg + "\033[0m" << endl;
};
//! blue msg
const void askMsg(const string& msg) {
	cout << endl << "\033[1;34m" + msg + "\033[0m";
};
//! purple msg
const void InfoMsg(const string& msg) {
	cout << endl << "\033[1;35m" + msg + "\033[0m" << endl;
};

//! 20.2359 => 20.23
const string toDec(const double& amount) {
	return to_string(amount).erase(to_string(amount).find('.') + 3);
}

//! Print user name in big size
void print_one_char_line(const char* s) {
	const char* x = "0123456789ABCDEF";
	unsigned z = 0;

	for (int i = 0; i < 2; ++i) {
		const char* q = strchr(x, s[i]);
		z |= (unsigned)(q - x) << ((1 - i) * 4);
	}

	for (unsigned y = 128; y; y >>= 1) {
		putchar((y & z) ? '@' : '  ');
	}
};
const void print_n_char_line(const vector<string>& strings) {
	int length = strings[0].size() / 2;

	for (int i = 0; i < length; ++i) {
		for (const auto& str : strings) {
			print_one_char_line(str.c_str() + 2 * i);
		}
		putchar('\n');
	}
};
void printText(string text) {
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	vector < string > v;
	for (int i = 0; i < text.size(); i++) {
		switch (text[i]) {
		case 'A':
			v.push_back("00001824427E42424200");
			break;
		case 'B':
			v.push_back("00007C42427C42427C00");
			break;
		case 'C':
			v.push_back("00003C42424042423C00");
			break;
		case 'D':
			v.push_back("00007844424242447800");
			break;
		case 'E':
			v.push_back("00007E40407C40407E00");
			break;
		case 'F':
			v.push_back("00007E40407C40404000");
			break;
		case 'G':
			v.push_back("00003C4242404E423A00");
			break;
		case 'H':
			v.push_back("00004242427E42424200");
			break;
		case 'I':
			v.push_back("00003E08080808083E00");
			break;
		case 'J':
			v.push_back("00001F04040444443800");
			break;
		case 'K':
			v.push_back("00004244586050484200");
			break;
		case 'L':
			v.push_back("00004040404040407E00");
			break;
		case 'M':
			v.push_back("00004242665A5A424200");
			break;
		case 'N':
			v.push_back("0000426252524A464200");
			break;
		case 'O':
			v.push_back("00003C42424242423C00");
			break;
		case 'P':
			v.push_back("00007C42427C40404000");
			break;
		case 'Q':
			v.push_back("00003C424242525A3C02");
			break;
		case 'R':
			v.push_back("00007C42427C48444200");
			break;
		case 'S':
			v.push_back("00003C42403C02423C00");
			break;
		case 'T':
			v.push_back("00007F08080808080800");
			break;
		case 'U':
			v.push_back("00004242424242423C00");
			break;
		case 'V':
			v.push_back("00004141222214080800");
			break;
		case 'W':
			v.push_back("000042425A5A66664200");
			break;
		case 'X':
			v.push_back("00004224181824424200");
			break;
		case 'Y':
			v.push_back("00004141221408080800");
			break;
		case 'Z':
			v.push_back("00007E02040810207E00");
			break;
		case '!':
			v.push_back("00000808080808000800");
			break;

		default:
			v.push_back("00000000000000000000");
			break;
		}
	}
	print_n_char_line(v);
};
void drawText(string text) {
	cout << "\033[1;35m";
	printText(text);
	cout << "\033[0m";
};
const void printUserName(const string& name) {
	string firstName = name.substr(0, name.find(' '));

	system("cls");

	if (firstName.size() > 8) {
		cout << "Hi!" + name << endl << endl;
	}
	else {
		cout << "\033[1;34m";
		printText("  HI! " + firstName);
		cout << "\033[0m" << endl;
	}
};
