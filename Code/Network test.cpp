#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;
using namespace sf;

void rabotaSpic() {
	Image thatPic;
	int width, hiegth;
	Color color;
	string picname;
	cout << "Enter file name\n";
	cin >> picname;
	ofstream filepictxt("txtpics/" + picname + ".txt");
	if (!thatPic.loadFromFile("pics/" + picname + ".png")) {
		cout << "\nWrong name file or smth!!!\n";
		system("pause");
		return;
	}
	width = thatPic.getSize().x;
	hiegth = thatPic.getSize().y;
	cout << width << endl << hiegth;
	system("pause");
	int y = 1;
	int shade = 0;
	for (int x = 0; x < width; x++) {
		color = thatPic.getPixel(x, y);
		shade = color.r;

		if (shade >= 0 & shade <=24) {
			filepictxt << "#";
		}
		if (shade >= 25 & shade <= 49) {
			filepictxt << "W";
		}
		if (shade >= 50 & shade <= 74) {
			filepictxt << "O";
		}
		if (shade >= 75 & shade <= 99) {
			filepictxt << "Y";
		}
		if (shade >= 100 & shade <= 124) {
			filepictxt << "V";
		}
		if (shade >= 125 & shade <= 149) {
			filepictxt << "L";
		}
		if (shade >= 150 & shade <= 174) {
			filepictxt << "U";
		}
		if (shade >= 175 & shade <= 199) {
			filepictxt << "!";
		}
		if (shade >= 200 & shade <= 224) {
			filepictxt << ":";
		}
		if (shade >= 225 & shade <= 255) {
			filepictxt << ".";
		}

		if (y == hiegth - 1) {
			filepictxt.close();
			cout << "Well done!\n";
			system("pause");
			return;
		}
		if (x == width - 1) {
			filepictxt << "|" << endl;
			x = 0;
			y++;
		}
	}

}
int main() {
	system("mode con cols=30 lines=10");
	rabotaSpic();
}