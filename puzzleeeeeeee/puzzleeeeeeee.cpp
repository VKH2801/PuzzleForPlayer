#include <iostream>
#include <vector>
#include <string>
#include<windows.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>


#define REP(i , l , r) for(int i = l ; i <= r ; i++)
#define REPS(i , l , r) for(int i = l ; i < r ; i++)

using namespace std;

enum facing {
	LEFT, RIGHT, UP, DOWN, STAY
};

int puzzle_dau[3][3], puzzle_dich[3][3], posX, posY;
// khoi tao cac node nhu la cac trang thai cua puzzle
class node {
public:
	int arr[3][3], x, y;
	string way;
	facing canFace;

	node(int a[3][3], string way, facing canFace, int x, int y) {
		this->way = way;
		this->canFace = canFace;
		this->x = x;
		this->y = y;
		REP(i, 0, 2) {
			REP(j, 0, 2) {
				arr[i][j] = a[i][j];
			}
		}
	}

	bool canMoveLeft() {
		return canFace != LEFT && y > 0;
	}
	bool canMoveRight() {
		return canFace != RIGHT && y < 2;
	}
	bool canMoveUp() {
		return canFace != UP && x > 0;
	}
	bool canMoveDown() {
		return canFace != DOWN && x < 2;
	}

	void moveLeft() {
		swap(arr[x][y], arr[x][y - 1]);
		y--;
		canFace = RIGHT;
		way += "l";
	}
	void moveRight() {
		swap(arr[x][y], arr[x][y + 1]);
		y++;
		canFace = LEFT;
		way += "r";
	}
	void moveUp() {
		swap(arr[x][y], arr[x - 1][y]);
		x--;
		canFace = DOWN;
		way += "u";
	}
	void moveDown() {
		swap(arr[x][y], arr[x + 1][y]);
		x++;
		canFace = UP;
		way += "d";
	}

	bool checkFinish() {
		int dem = 0;
		REP(i, 0, 2)
		{
			REP(j, 0, 2)
			{
				if (arr[i][j] == puzzle_dich[i][j])
				{
					dem++;
				}
			}
		}
		if (dem == 9)
			return true;
		return false;
	}
};
//*
void moveLeft() {
	swap(puzzle_dau[posX][posY], puzzle_dau[posX][posY - 1]);
	posY--;
}
void moveRight() {
	swap(puzzle_dau[posX][posY], puzzle_dau[posX][posY + 1]);
	posY++;
}
void moveUp() {
	swap(puzzle_dau[posX][posY], puzzle_dau[posX - 1][posY]);
	posX--;
}
void moveDown() {
	swap(puzzle_dau[posX][posY], puzzle_dau[posX + 1][posY]);
	posX++;
}
// ham nhap du lieu
void initPuzzledau() {
	cout << "Nhap cac gia tri cho puzzle dau : ";
	cin >> puzzle_dau[0][0] >> puzzle_dau[0][1] >> puzzle_dau[0][2];
	cin >> puzzle_dau[1][0] >> puzzle_dau[1][1] >> puzzle_dau[1][2];
	cin >> puzzle_dau[2][0] >> puzzle_dau[2][1] >> puzzle_dau[2][2];

	bool checked = true;
	int sum = 0;
	REP(i, 0, 2) {
		REP(j, 0, 2) {
			sum += puzzle_dau[i][j];
			if (puzzle_dau[i][j] > 8) {
				checked = false;
				break;
			}
		}
	}
	if (sum != 36 || checked == false) {
		cout << "Nhap sai du lieu vui long nhap lai" << endl;
		return initPuzzledau();
	}

	REP(i, 0, 2) {
		REP(j, 0, 2) {
			if (puzzle_dau[i][j] == 0) {
				posX = i;
				posY = j;
				return;
			}
		}
	}
}
void initPuzzledich() {
	cout << "Nhap cac gia tri cho puzzle dich: ";
	cin >> puzzle_dich[0][0] >> puzzle_dich[0][1] >> puzzle_dich[0][2];
	cin >> puzzle_dich[1][0] >> puzzle_dich[1][1] >> puzzle_dich[1][2];
	cin >> puzzle_dich[2][0] >> puzzle_dich[2][1] >> puzzle_dich[2][2];

	bool checked = true;
	int sum = 0;
	REP(i, 0, 2) {
		REP(j, 0, 2) {
			sum += puzzle_dich[i][j];
			if (puzzle_dich[i][j] > 8) {
				checked = false;
				break;
			}
		}
	}
	if (sum != 36 || checked == false) {
		cout << "Nhap sai du lieu vui long nhap lai" << endl;
		return initPuzzledich();
	}
}
// ham in trang thai
void prin() {
		cout << "\t _________________\n";
		cout << "\t|     |     |     |\n";
		cout << "\t|  " << puzzle_dau[0][0] << "  |  " << puzzle_dau[0][1] << "  |  " << puzzle_dau[0][2] << "  |\n";
		cout << "\t|_____|_____|_____|\n";
		cout << "\t|     |     |     |\n";
		cout << "\t|  " << puzzle_dau[1][0] << "  |  " << puzzle_dau[1][1] << "  |  " << puzzle_dau[1][2] << "  |\n";
		cout << "\t|_____|_____|_____|\n";
		cout << "\t|     |     |     |\n";
		cout << "\t|  " << puzzle_dau[2][0] << "  |  " << puzzle_dau[2][1] << "  |  " << puzzle_dau[2][2] << "  |\n";
		cout << "\t|_____|_____|_____|\n";
	
}
// ham kiem tra xem da la trang thai dich chua		
bool checkFinish() {
	int dem = 0;
	REP(i, 0, 2)
	{
		REP(j, 0, 2) {
			if (puzzle_dau[i][j] == puzzle_dich[i][j])
			{
				dem++;
			}
		}
	}
	if (dem == 9)
		return true;
	return false;
}

int main() {
	
	
	initPuzzledau();
	initPuzzledich();
	cout << "Trang thai ban dau : " << endl;
	prin();
	cout << endl;
	cout << "Nhap 'x' de thoat." << endl;
	cout << "Nhap 'w' de di chuyen len." << endl;
	cout << "Nhap 'a' de di chuyen qua trai." << endl;
	cout << "Nhap 's' de di chuyen xuong duoi." << endl;
	cout << "Nhap 'd' de di chuyen qua phai" << endl;
	cout << "Nhap 'h' de nhan dap an va thoat chuong trinh." << endl;
	while (1) {

		bool check = checkFinish();
		string way = "";
		node nd(puzzle_dau, "", STAY, posX, posY);
		vector<node> vt; // hang doi
		vt.push_back(nd);
		// tao node phu de choi;
		node nd1(puzzle_dau, "", STAY, posX, posY);


		vector<node > open;
		open.push_back(nd);
		if (nd1.checkFinish())
		{
			cout << "Ban da thang";
			break;
		}
		cout << "Nhap lua chon cua ban: ";
		string option;
		cin >> option;

		if (option == "x") {
			continue;
		}
		if (option == "h") {
			while (!check) {
				vector<node> open;
				REPS(i, 0, vt.size()) {
					if (vt.at(i).checkFinish()) {
						way = vt.at(i).way;
						check = true;
						break;
					}
					else {
						if (vt.at(i).canMoveLeft()) {
							node nd = vt.at(i);
							nd.moveLeft();
							open.push_back(nd);
						}
						if (vt.at(i).canMoveRight()) {
							node nd = vt.at(i);
							nd.moveRight();
							open.push_back(nd);
						}
						if (vt.at(i).canMoveUp()) {
							node nd = vt.at(i);
							nd.moveUp();
							open.push_back(nd);
						}
						if (vt.at(i).canMoveDown()) {
							node nd = vt.at(i);
							nd.moveDown();
							open.push_back(nd);
						}
					}

				}
				vt.clear();
				REPS(i, 0, open.size()) {
					vt.push_back(open.at(i));
				}
			}
			REPS(i, 0, way.length()) {
				if (way[i] == 'l') {
					moveLeft();
					prin();
					cout << "di chuyen sang trai" << endl << endl;
				}
				else if (way[i] == 'r') {
					moveRight();
					prin();
					cout << "di chuyen sang phai" << endl << endl;
				}
				else if (way[i] == 'u') {
					moveUp();
					prin();
					cout << "di chuyen len tren" << endl << endl;
				}
				else if (way[i] == 'd') {
					moveDown();
					prin();
					cout << "di chuyen xuong duoi" << endl << endl;
				}
			}
			cout << "Thuat toan BFS : " << endl;
			cout << "So buoc di = " << way.length() << endl;
			break;
		}
		if (option == "w") {
			if (nd1.canMoveUp()) {
				moveUp();
				prin();
				cout << "Ban vua di chuyen len." << endl << endl;
			}
			else {
				cout << "Ban khong the di chuyen len." << endl << endl;
			}
		}
		if (option == "a") {
			if (nd1.canMoveLeft()) {
				moveLeft();
				prin();
				cout << "Ban vua di chuyen qua trai." << endl << endl;
			}
			else {
				cout << "Ban khong the di chuyen qua trai." << endl << endl;
			}
		}
		if (option == "s") {
			if (nd1.canMoveDown()) {
				moveDown();
				prin();
				cout << "Ban vua di chuyen xuong duoi." << endl << endl;
			}
			else {
				cout << "Ban khong the di chuyen xuong duoi." << endl << endl;
			}
		}
		if (option == "d") {
			if (nd1.canMoveRight()) {
				moveRight();
				prin();
				cout << "Ban vua di chuyen qua phai." << endl << endl;
			}
			else {
				cout << "Ban khong the di chuyen qua phai." << endl << endl;
			}
		}
	}




	return 0;
}