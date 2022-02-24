/*
                                                         _____           _    _____
                                                        |_   _|         | |  |  __ \
                                                          | | __ _ _ __ | | _| /  \/ __ _ _ __  _   _
                                                          | |/ _` | '_ \| |/ | |    / _` | '_ \| | | |
                                                          | | (_| | | | |   <| \__/\ (_| | |_) | |_| |
                                                          \_/\__,_|_| |_|_|\_\____/ \__,_| .__(_)__,_|
                                                                                         | |           
                                                                                         |_|         

                                                                          SUBMITTED BY

Name....................Muhammad Usman Bin Farid
Roll NO.................2021-CS-142
Section.................C

                                                     *******************************************************
                                                     *                    LETS CODE BEGINS                 *
                                                     *******************************************************

*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;

fstream file;
void gotoxy(int x, int y);
void playerDisplay();
void enemyDisplay();
void enemy1Display();
void set_cursor(bool visible);
string mainMenu();
void header();
void highScoreF();
void loading();
void mainTank();
void readFile();
void maze();
void movePLeft();
void movePRight();
void movePUP();
void movePDown();
void drawBullets();
void genBullet();
void moveBullet();
void eraseBullet(int i);
void eraseBullets();
void moveEnemy();
void game_break();
void bulletHit();
void eraseEnemy1();
void enemy1B();
void enemy1Bupdate();
void bullet1Hit();
void enemy2B();
void enemy2Bupdate();
void moveEnemy1();
void eraseEnemy2();
void enemy2Display();
void moveEnemy2();
void enemy3Bupdate();
void enemy3B();
void eraseEnemy3();
void life_healthDisplay();
void erasePlayer();
void lifeEnemy();
void scoreDisplay();
string instructMenu();
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
char mazeA[30][141];
int bullets[2][128];
char mainA[24][100] = {
    {"                                                         _..----.._                                "},
    {"                                                        ]_.--._____[                               "},
    {"                                                      ___|`--`__..|--._                            "},
    {"                                  __               ```    ;            :                           "},
    {"                                ()_ `````---...__.```!`:  /    ___       :                         "},
    {"                                   ```---...__\\]..__] | /    [ 0 ]      :                         "},
    {"                                              ```!--./ /      ```        :                         "},
    {"                                       __  ...._____;```.__________..--..:_                        "},
    {"                                      /  !```````!``````````|````/` ` ` ` \\`--..__  __..          "},
    {"                                     /  /.--.    |          |  .`          \\` ` `.``--.{`.        "},
    {"                 _...__            >=7 //.-.:    |          |.`             \\ ._.__  ` ````.      "},
    {"              .-` /    ````----..../ ``>==7-.....:______    |                \\| |  ``;.;-`> \\    "},
    {"              ````;           __..`   .--`/`````----....`````----.....H_______\\_!....`----````]   "},
    {"              _..---|._ __..--``       _!.-=_.            ```````````````                   ;```   "},
    {"           /   .-`;-.`--...___     .` .-``; `;``-``-...^..__...-v.^___,  ,__v.__..--^`--``-v.^v,   "},
    {"          ;   ;   |`.         ```-/ ./;  ;   ;\\P.        ;   ;        ````____;  ;.--````// ```<, "},
    {"          ;   ;   | 1            ;  ;  `.: .`  ;<   ___.-`._.`------``````____`..`.--```;;`  o `;  "},
    {"          `.   \\__:/__           ;  ;--``()_   ;`  /___ .-` ____---``````` __.._ __._   `>.,  ,/; "},
    {"            \\   \\    /```<--...__;  `_.-`/; ``; ;.`.`  `-..`    `-.      /`/    `__. `.   `---`; "},
    {"             `.  `v ; ;     ;;    \\  \\ .`  \\ ; ///     _.-` `-._   ;    : ;   .-`__ `. ;   .^`.`"},
    {"               `.  `; `.   .`/     `. `-.__.` /;;;   .o__.---.__o. ;    : ;   ```;;``` ;v^` .^     "},
    {"                 `-. `-.___.`<__v.^,v`.  `-.-` ;|:   `    :      ` ;v^v^`.`.    .;`.__/_..-`       "},
    {"                    `-...__.___...---```-.   `-`.;\\     `WW\\     .`_____..>.`^`-````````         "},
    {"                                          `--..__ ``._..`  ``-;;```                                "}};

char player1[4][14] = {{'[', '[', '[', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '=', '=', '~', '~', '~', '>'},
                       {' ', ' ', '_', ',', '*', '\xDB', '\xDB', '*', ',', '_', ' ', ' ', ' ', ' '},
                       {' ', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', ']', ' '},
                       {' ', '\\', '_', '@', '_', '@', '_', '@', '_', '@', '_', '@', ' ', ' '}};

char enemy[4][14] = {{'<', '~', '~', '~', '=', '=', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', ']', ']', ']'},
                     {' ', ' ', ' ', ' ', '_', ',', '*', '\xDB', '\xDB', '*', ',', '_', ' ', ' '},
                     {' ', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', '\xDB', ']', ' '},
                     {' ', '\\', '_', '@', '_', '@', '_', '@', '_', '@', '_', '@', ' ', ' '}};
char enemy1[4][14] = {{"      ______ "},
                      {"<====(``````)"},
                      {"     \\(@)(@)/"},
                      {"      ****** "}};

double highScore = 0;
int pX = 11;
int pY = 1;
int e1X = 11;
int e1Y = 125;
int e2X = 1;
int e2Y = 125;
int e3X = 22;
int e3Y = 125;
int a = 21;
bool tf = false;
bool enemyBool = false;
bool enemy1Bool = false;
bool enemy2Bool = false;
bool horizontal = false;
bool horizontal1 = false;
bool horizontal2 = false;
bool gameBreak = true;
int bIndex = 0;
int temp = 0;
int enemy1Health = 20;
int enemy2Health = 20;
int enemy3Health = 20;
bool e1Bullet = false;
bool e2Bullet = false;
bool e3Bullet = false;
int e1BulletX = e1X;
int e1BulletY = 124;
int e1count = 0;
int e2count = 0;
int e3count = 0;
int playerHealth = 3;
int e2BulletX = e2X + 1;
int e2BulletY = e2Y - 1;
int e3BulletX = e3X + 1;
int e3BulletY = e3Y - 1;
int playerLife = 3;
int playerHealthPercentage = 0;
int score = 0;
main()
{
    string op;
    int count = 0;
    int b = 0;
    int c = 0;
    readFile();
    system("cls");
    SetConsoleTextAttribute(h, 2);
    mainTank();
    SetConsoleTextAttribute(h, 15);
    gotoxy(26, 50);
    loading();
    while (true)
    {
        system("cls");
        set_cursor(false);
        op = mainMenu();
        if (op == "1")
        {
            system("cls");
            set_cursor(false);
            maze();
            enemyBool = true;
            enemy1Bool = true;
            enemy2Bool = true;
            horizontal = true;
            horizontal1 = true;
            horizontal2 = true;
            highScore = 0;
            pX = 11;
            pY = 1;
            e1X = 11;
            e1Y = 125;
            e2X = 1;
            e2Y = 125;
            e3X = 22;
            e3Y = 125;
            a = 21;
            tf = false;
            gameBreak = true;
            bIndex = 0;
            temp = 0;
            enemy1Health = 20;
            enemy2Health = 20;
            enemy3Health = 20;
            e1Bullet = false;
            e2Bullet = false;
            e3Bullet = false;
            e1BulletX = e1X;
            e1BulletY = 124;
            e1count = 0;
            e2count = 0;
            e3count = 0;
            playerHealth = 3;
            e2BulletX = e2X + 1;
            e2BulletY = e2Y - 1;
            e3BulletX = e3X + 1;
            e3BulletY = e3Y - 1;
            playerLife = 3;
            playerHealthPercentage = 0;
            score = 0;
            enemyDisplay();
            enemy1Display();
            enemy2Display();
            playerDisplay();
            while (gameBreak)
            {
                a++;
                if (a >= 10)
                {
                    moveEnemy();
                    a = 0;
                }
                b++;
                if (b >= 15)
                {
                    moveEnemy1();
                    b = 0;
                }
                c++;
                if (c > 10)
                {
                    moveEnemy2();
                    c = 0;
                }
                e1count++;
                e2count++;
                e3count++;
                if (GetAsyncKeyState(VK_LEFT) && mazeA[pX][pY - 1] == ' ')
                {
                    movePLeft();
                }
                if (GetAsyncKeyState(VK_RIGHT) && mazeA[pX][pY + 14] == ' ')
                {
                    movePRight();
                }
                if (GetAsyncKeyState(VK_UP) && mazeA[pX - 1][pY] == ' ')
                {
                    movePUP();
                }
                if (GetAsyncKeyState(VK_DOWN) && mazeA[pX + 4][pY] == ' ')
                {
                    movePDown();
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    Sleep(50);
                    tf = true;
                    genBullet();
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    pX = 11;
                    pY = 1;
                    e1X = 11;
                    e1Y = 125;
                    a = 21;
                    tf = false;
                    enemyBool = false;
                    horizontal = false;
                    gameBreak = true;
                    bIndex = 0;
                    temp = 0;
                    break;
                }
                drawBullets();
                eraseBullets();
                moveBullet();
                bulletHit();
                enemy1B();
                enemy2B();
                enemy3B();
                enemy1Bupdate();
                enemy2Bupdate();
                enemy3Bupdate();
                lifeEnemy();
                life_healthDisplay();
                scoreDisplay();
                game_break();
            }
        }
        else if (op == "2")
        {
            while (true)
            {
                string a;
                system("cls");
                string op1 = instructMenu();
                if (op1 == "1")
                {
                    system("cls");
                    header();
                    SetConsoleTextAttribute(h, 5);
                    cout << "keys." << endl;
                    cout << "________________" << endl;
                    cout << "1. UP              Go up" << endl;
                    cout << "2. Down            Go down" << endl;
                    cout << "3. Left            Go Left" << endl;
                    cout << "4. Right           Go Right" << endl;
                    cout << "5. Space           Fire user" << endl;
                    cout << "6. ESC             Ent Game." << endl;
                    cout << "Press any key to continue : ";
                    fflush(stdin);
                    getch();
                }
                else if (op1 == "2")
                {
                    system("cls");
                    header();
                    SetConsoleTextAttribute(h, 5);
                    cout << "Instructions." << endl;
                    cout << "-----------------------" << endl;
                    cout << "1. Enemy died after 20 bullet hits." << endl;
                    cout << "2. You have 3 lives (each life has 3 health)" << endl;
                    cout << "3. if one bullet of enemy hit you then one health decrease(3 health = 1 life)" << endl;
                    cout << "4. If you hit with enemy you loose" << endl;
                    cout << "5. If enemy Collide with left wall you loose." << endl;
                    cout << "Press any key to continue : ";
                    fflush(stdin);
                    getch();
                }
                else if (op1 == "3")
                {
                    break;
                }
                else
                {
                    cout << "You entered wrong option." << endl;
                    cout << "Enter any key to continue : ";
                    cin >> a;
                }
            }
        }
        else if (op == "3")
        {
            system("cls");
            SetConsoleTextAttribute(h, 8);
            cout << "Thank you for playing." << endl;
            break;
        }
        else
        {
            cout << "You entered wrong option." << endl;
        }
    }
}
void header()
{
    SetConsoleTextAttribute(h, 6);
    cout << " _____           _    _____" << endl;
    cout << "|_   _|         | |  /  __ \\" << endl;
    cout << "  | | __ _ _ __ | | _| /  \\/ __ _ _ __  _   _" << endl;
    cout << "  | |/ _` | '_ \\| |/ / |    / _` | '_ \\| | | |" << endl;
    cout << "  | | (_| | | | |   <| \\__/\\ (_| | |_) | |_| |" << endl;
    cout << "  \\_/\\__,_|_| |_|_|\\_\\____/ \\__,_| .__(_)__,_|" << endl;
    cout << "                                 | |           " << endl;
    cout << "                                 |_|         " << endl;
    cout << endl;
    cout << endl;
}
string mainMenu()
{
    string op;
    header();
    SetConsoleTextAttribute(h, 15);
    cout << "Menu." << endl;
    cout << "__________________" << endl;
    cout << "1. Start" << endl;
    cout << "2. Option" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter one option : ";
    cin >> op;
    return op;
}
void set_cursor(bool visible)
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
void playerDisplay()
{
    SetConsoleTextAttribute(h, 3);
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 14; y++)
        {
            gotoxy(pX + x, pY + y);
            cout << char(player1[x][y]);
        }
        cout << endl;
    }
}
void enemyDisplay()
{
    SetConsoleTextAttribute(h, 4);
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 14; y++)
        {
            gotoxy(e1X + x, e1Y + y);
            cout << char(enemy[x][y]);
        }
        cout << endl;
    }
}
void enemy1Display()
{
    SetConsoleTextAttribute(h, 4);
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 14; y++)
        {
            gotoxy(e2X + x, e2Y + y);
            cout << char(enemy1[x][y]);
        }
        cout << endl;
    }
}
void enemy2Display()
{
    SetConsoleTextAttribute(h, 4);
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 14; y++)
        {
            gotoxy(e3X + x, e3Y + y);
            cout << char(enemy1[x][y]);
        }
        cout << endl;
    }
}
void mainTank()
{
    for (int x = 0; x < 24; x++)
    {
        for (int y = 0; y < 100; y++)
        {
            cout << mainA[x][y];
        }
        cout << endl;
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = y;
    coordinates.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void loading()
{
    cout << "        TankCap.u" << endl;
    cout << "\t\t\t\t\t\t   Please wait while loading\n\n";
    char a = 177, b = 219;
    cout << "\t\t\t\t\t\t       ";
    for (int i = 0; i <= 15; i++)
        cout << a;
    cout << "\r";
    cout << "\t\t\t\t\t\t       ";
    for (int i = 0; i <= 15; i++)
    {
        cout << b;
        Sleep(500);
    }
}
void readFile()
{
    string line;
    int x = 0;
    file.open("maze.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        for (int y = 0; y < 141; y++)
        {
            mazeA[x][y] = line[y];
        }
        x++;
    }
    file.close();
}
void maze()
{
    SetConsoleTextAttribute(h, 8);
    for (int x = 0; x < 30; x++)
    {
        for (int y = 0; y < 141; y++)
        {
            cout << mazeA[x][y];
        }
        cout << endl;
    }
}
void movePLeft()
{
    mazeA[pX][pY] = ' ';
    gotoxy(pX, pY);
    cout << " ";

    pY = pY - 1;
    gotoxy(pX, pY);
    playerDisplay();
    gotoxy(pX, pY + 14);
    cout << " ";
}
void movePRight()
{
    mazeA[pX][pY] = ' ';
    gotoxy(pX, pY);
    cout << " ";
    pY = pY + 1;
    gotoxy(pX, pY);
    playerDisplay();
}
void movePUP()
{
    mazeA[pX][pY] = ' ';
    for (int x = 0; x < 14; x++)
    {
        gotoxy(pX + 3, pY + x);
        cout << " ";
    }
    pX = pX - 1;
    gotoxy(pX, pY);
    playerDisplay();
}
void movePDown()
{
    mazeA[pX][pY] = ' ';
    for (int x = 0; x < 14; x++)
    {
        gotoxy(pX, pY + x);
        cout << " ";
    }

    pX = pX + 1;
    gotoxy(pX, pY);
    playerDisplay();
}
void genBullet()
{
    bullets[0][bIndex] = pY + 14;
    bullets[1][bIndex] = pX;
    bIndex++;
    if (bIndex == 128)
        bIndex = 0;
}
void drawBullets()
{
    for (int i = 0; i < 128; i++)
    {
        if (mazeA[bullets[1][i]][bullets[0][i]] == '#')
        {

            gotoxy(bullets[1][i], bullets[0][i]);
            cout << "#";
        }
        else
        {
            SetConsoleTextAttribute(h, 8);
            gotoxy(bullets[1][i], bullets[0][i]);
            cout << ">";
        }
    }
    temp = 0;
}
void moveBullet()
{
    for (int i = 0; i < 128; i++)
    {
        if (bullets[0][i] > 2 && i < 128)
        {
            bullets[0][i] = bullets[0][i] + 1;
            if (bullets[0][i] > 139)
            {
                bullets[0][i] = 0;
            }
        }
        else if (i > 127 && bullets[0][i] <= 2)
        {
            bullets[0][i] = 0;
        }
    }
}
void eraseBullets()
{
    for (int i = 0; i < 128; i++)
    {
        if (bullets[0][i] >= 1 && mazeA[bullets[1][i]][bullets[0][i]] == ' ' || (bullets[0][i] == e1Y && e1X + 4 - bullets[1][i] > 0 && e1X + 4 - bullets[1][i] < 8))
        {
            // Sleep(10);
            gotoxy(bullets[1][i], bullets[0][i]);
            cout << " ";
        }
    }
}
void moveEnemy()
{
    if (enemyBool)
    {
        if (horizontal)
        {

            if (mazeA[e1X][e1Y - 1] == '>')
            {
                horizontal = false;
            }
            if (mazeA[e1X][e1Y - 1] == ' ')
            {
                if (mazeA[e1X][e1Y] == '.')
                {
                    gotoxy(e1X, e1Y);
                    cout << '.';
                }
                else if (mazeA[e1X][e1Y] == ' ')
                {
                    gotoxy(e1X, e1Y);
                    cout << ' ';
                }
                else if (mazeA[e1X][e1Y] == '*')
                {
                    gotoxy(e1X, e1Y);
                    cout << '*';
                }
                e1Y = e1Y - 1;
                enemyDisplay();
            }
            gotoxy(e1X, e1Y + 14);
            cout << ' ';
        }
    }
}
void eraseBullet(int i)
{
    gotoxy(bullets[0][i], bullets[1][i]);
    cout << " ";
}
void bulletHit()
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < bIndex; j++)
        {
            if (bullets[i][j] != 0)
            {
                if (bullets[i + 1][j] >= e1X && bullets[i + 1][j] <= e1X + 4)
                {

                    if (bullets[i][j] >= e1Y && bullets[i][j] <= e1Y + 4)
                    {
                        eraseBullet(i);
                        bullets[i][j] = 0;
                        enemy1Health--;
                        score = score + 10;
                        if (enemy1Health == 0)
                        {
                            enemyBool = false;
                            eraseEnemy1();
                            e1X = 10000;
                            e1Y = 10000;
                        }
                    }
                }
                if (bullets[i + 1][j] >= e2X && bullets[i + 1][j] <= e2X + 4)
                {
                    if (bullets[i][j] >= e2Y && bullets[i][j] <= e2Y + 4)
                    {
                        eraseBullet(i);
                        bullets[i][j] = 0;
                        enemy2Health--;
                        score = score + 10;
                        if (enemy2Health == 0)
                        {
                            enemy1Bool = false;
                            eraseEnemy2();
                            e2X = 10000;
                            e2Y = 10000;
                        }
                    }
                }
                if (bullets[i + 1][j] >= e3X && bullets[i + 1][j] <= e3X + 4)
                {
                    if (bullets[i][j] >= e3Y && bullets[i][j] <= e3Y + 4)
                    {
                        eraseBullet(i);
                        bullets[i][j] = 0;
                        enemy3Health--;
                        score = score + 10;
                        if (enemy3Health == 0)
                        {
                            enemy2Bool = false;
                            eraseEnemy3();
                            e3X = 10000;
                            e3Y = 10000;
                        }
                    }
                }
            }
        }
    }
}
void eraseEnemy1()
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 14; y++)
        {
            gotoxy(e1X + x, e1Y + y);
            cout << " ";
        }
        cout << endl;
    }
}
void eraseEnemy2()
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 14; y++)
        {
            gotoxy(e2X + x, e2Y + y);
            cout << " ";
        }
        cout << endl;
    }
}
void eraseEnemy3()
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 14; y++)
        {
            gotoxy(e3X + x, e3Y + y);
            cout << " ";
        }
        cout << endl;
    }
}
void erasePlayer()
{
    SetConsoleTextAttribute(h, 3);
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 14; y++)
        {
            gotoxy(pX + x, pY + y);
            cout << " ";
        }
        cout << endl;
    }
}
void enemy1Bupdate()
{
    if (e1Bullet)
    {
        gotoxy(e1BulletX, e1BulletY - e1count);
        cout << "<";
        gotoxy(e1BulletX, e1BulletY - e1count + 1);
        cout << " ";
        if (e1BulletY - e1count == 1 || (e1BulletY - e1count == pY + 14 && e1BulletX <= pX + 3 && e1BulletX >= pX) || (pX + 3 == e1BulletX && pY <= e1BulletY - e1count && pY + 14 >= e1BulletY - e1count))
        {
            if (e1BulletY - e1count == 1)
            {
                gotoxy(e1BulletX, 1);
                cout << " ";
            }
            else
            {
                playerHealth--;
                gotoxy(e1BulletX, e1BulletY - e1count);
                cout << " ";
            }

            e1Bullet = false;
            e1count = 0;
        }
    }
}
void enemy1B()
{
    SetConsoleTextAttribute(h, 4);
    if (e1Bullet == false && enemyBool == true)
    {
        e1BulletX = e1X;
        e1BulletY = e1Y - 1;
        gotoxy(e1BulletX, e1BulletY - 1);
        cout << "<";
        e1Bullet = true;
    }
}
void enemy2B()
{
    SetConsoleTextAttribute(h, 4);
    if (e2Bullet == false && enemy1Bool == true)
    {
        e2BulletX = e2X + 1;
        e2BulletY = e2Y - 1;
        gotoxy(e2BulletX, e2BulletY);
        cout << "<";
        e2Bullet = true;
    }
}
void enemy2Bupdate()
{
    if (e2Bullet)
    {
        gotoxy(e2BulletX, e2BulletY - e2count);
        cout << "<";
        gotoxy(e2BulletX, e2BulletY - e2count + 1);
        cout << " ";
        if (e2BulletY - e2count == 1 || (e2BulletY - e2count == pY + 14 && e2BulletX <= pX + 3 && e2BulletX >= pX) || (pX + 1 == e2BulletX && pY <= e2BulletY - e2count && pY + 14 >= e2BulletY - e2count))
        {
            if (e2BulletY - e2count == 1)
            {
                gotoxy(e2BulletX, 1);
                cout << " ";
            }
            else
            {
                playerHealth--;
                gotoxy(e2BulletX, e2BulletY - e2count);
                cout << " ";
            }

            e2Bullet = false;
            e2count = 0;
        }
    }
}
void moveEnemy1()
{
    if (enemy1Bool)
    {
        if (horizontal1)
        {

            if (mazeA[e2X][e2Y - 1] == '>')
            {
                horizontal1 = false;
            }
            if (mazeA[e2X][e2Y - 1] == ' ')
            {
                if (mazeA[e2X][e2Y] == '.')
                {
                    gotoxy(e2X, e2Y);
                    cout << '.';
                }
                else if (mazeA[e2X][e2Y] == ' ')
                {
                    gotoxy(e2X, e2Y);
                    cout << ' ';
                }
                else if (mazeA[e2X][e2Y] == '*')
                {
                    gotoxy(e2X, e2Y);
                    cout << '*';
                }
                e2Y = e2Y - 1;
                enemy1Display();
            }
            gotoxy(e2X + 1, e2Y + 13);
            cout << ' ';
            gotoxy(e2X + 2, e2Y + 13);
            cout << ' ';
        }
    }
}
void enemy3B()
{
    SetConsoleTextAttribute(h, 4);
    if (e3Bullet == false && enemy2Bool == true)
    {
        e3BulletX = e3X + 1;
        e3BulletY = e3Y - 1;
        gotoxy(e3BulletX, e3BulletY);
        cout << "<";
        e3Bullet = true;
    }
}
void enemy3Bupdate()
{
    if (e3Bullet)
    {
        gotoxy(e3BulletX, e3BulletY - e3count);
        cout << "<";
        gotoxy(e3BulletX, e3BulletY - e3count + 1);
        cout << " ";
        if (e3BulletY - e3count == 1 || (e3BulletY - e3count == pY + 14 && e3BulletX <= pX + 3 && e3BulletX >= pX) || (pX + 1 == e3BulletX && pY <= e3BulletY - e3count && pY + 14 >= e3BulletY - e3count))
        {
            if (e3BulletY - e3count == 1)
            {
                gotoxy(e3BulletX, 1);
                cout << " ";
            }
            else
            {
                playerHealth--;
                gotoxy(e3BulletX, e3BulletY - e3count);
                cout << " ";
            }

            e3Bullet = false;
            e3count = 0;
        }
    }
}
void moveEnemy2()
{
    if (enemy2Bool)
    {
        if (horizontal2)
        {

            if (mazeA[e3X][e3Y - 1] == '>')
            {
                horizontal1 = false;
            }
            if (mazeA[e3X][e3Y - 1] == ' ')
            {
                if (mazeA[e3X][e3Y] == '.')
                {
                    gotoxy(e3X, e3Y);
                    cout << '.';
                }
                else if (mazeA[e3X][e3Y] == ' ')
                {
                    gotoxy(e3X, e3Y);
                    cout << ' ';
                }
                else if (mazeA[e3X][e3Y] == '*')
                {
                    gotoxy(e3X, e3Y);
                    cout << '*';
                }
                e3Y = e3Y - 1;
                enemy2Display();
            }
            gotoxy(e3X + 1, e3Y + 13);
            cout << ' ';
            gotoxy(e3X + 2, e3Y + 13);
            cout << ' ';
        }
    }
}
void game_break()
{
    string temp;
    if ((e1Y - (pY + 7) >= 0 && e1Y - (pY + 7) < 8 && e1X + 4 - pX > 0 && e1X + 4 - pX < 8) ||
        (e2Y - (pY + 7) >= 0 && e2Y - (pY + 7) < 8 && e2X + 4 - pX > 0 && e2X + 4 - pX < 8) ||
        (e3Y - (pY + 7) >= 0 && e3Y - (pY + 7) < 8 && e3X + 4 - pX > 0 && e3X + 4 - pX < 8) ||
        (pX == e1X + 3 && pY + 14 >= e1Y && pY <= e1Y + 11) ||
        (pX == e2X + 3 && pY + 14 >= e2Y && pY <= e2Y + 11) ||
        (pX + 3 == e1X && pY + 14 >= e1Y && pY <= e1Y + 14) ||
        (pX + 3 == e3X && pY + 14 >= e3Y && pY <= e3Y + 14) ||
        ((e1Y + 14) - (pY) >= 0 && (e1Y + 14) - (pY) < 8 && e1X + 4 - pX > 0 && e1X + 4 - pX < 8) ||
        ((e2Y + 14) - (pY) >= 0 && (e2Y + 14) - (pY) < 8 && e2X + 4 - pX > 0 && e2X + 4 - pX < 8) ||
        ((e3Y + 14) - (pY) >= 0 && (e3Y + 14) - (pY) < 8 && e3X + 4 - pX > 0 && e3X + 4 - pX < 8))
    {
        erasePlayer();
        pX = 11;
        pY = 1;
        playerDisplay();
        playerLife--;
    }
    if (playerHealth == 0)
    {
        playerHealth = 3;
        erasePlayer();
        pX = 11;
        pY = 1;
        playerDisplay();
        playerLife--;
    }
    if (playerLife == 0 || e1Y == 1 || e2Y == 1 || e3Y == 1)
    {
        eraseEnemy1();
        eraseEnemy2();
        eraseEnemy3();
        system("cls");
        SetConsoleTextAttribute(h, 4);
        cout << "You Lose!" << endl;
        cout << "Enter any key to continue : ";
        cin >> temp;
        gameBreak = false;
    }
    if (enemyBool == false && enemy1Bool == false && enemy2Bool == false)
    {
        system("cls");
        SetConsoleTextAttribute(h, 2);
        cout << "You Won!" << endl;
        cout << "Enter any key to continue : ";
        cin >> temp;
        gameBreak = false;
    }
}
void life_healthDisplay()
{
    SetConsoleTextAttribute(h, 6);
    gotoxy(0, 3);
    cout << "Life's : " << playerLife;
    gotoxy(0, 30);
    cout << "Health : " << playerHealth;
}
void lifeEnemy()
{
    SetConsoleTextAttribute(h, 6);
    gotoxy(0, 141);
    cout << "Enemy 1 health : " << enemy1Health;
    if (enemy1Health < 10)
    {
        gotoxy(0, 159);
        cout << " ";
    }
    gotoxy(2, 141);
    cout << "Enemy 2 health : " << enemy2Health;
    if (enemy2Health < 10)
    {
        gotoxy(2, 159);
        cout << " ";
    }
    gotoxy(4, 141);
    cout << "Enemy 3 health : " << enemy3Health;
    if (enemy3Health < 10)
    {
        gotoxy(4, 159);
        cout << " ";
    }
}
void scoreDisplay()
{
    gotoxy(29, 70);
    cout << "Score : " << score;
}
string instructMenu()
{
    string op1 = " ";
    header();
    SetConsoleTextAttribute(h, 15);
    cout << "1. Keys." << endl;
    cout << "2. Instructions." << endl;
    cout << "3. Exit" << endl;
    cout << "Enter any option : ";
    cin >> op1;
    return op1;
}