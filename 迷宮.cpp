#include <iostream>
#include <unistd.h>
#define MAX_STACK_SIZE m * p

#define m 12
#define p 15
using namespace std;

int maze[m + 2][p + 2] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

const int EXIT_ROW = m;
const int EXIT_COL = p;

struct element {
    short int row;
    short int col;
    short int dir;
};

element Stack[MAX_STACK_SIZE];
int top = -1;

bool isEmpty(void);
bool isFull(void);
void push(element);
element pop(void);

struct offsets {
    short int vert;
    short int horiz;
};

offsets moved[8] = {
    {-1,  0},  // 北
    {-1,  1},  // 東北
    { 0,  1},  // 東
    { 1,  1},  // 東南
    { 1,  0},  // 南
    { 1, -1},  // 西南
    { 0, -1},  // 西
    {-1, -1}   // 西北
};

int mark[m + 2][p + 2] = {0};

void path(void);
void printMaze(void);

int main() {
    path();
    return 0;
}

void path(void) {
    int row, col, nextRow, nextCol, dir;
    bool found = false;
    element position;

    mark[1][1] = 1;
    top = 0;
    Stack[0].row = 1;
    Stack[0].col = 1;
    Stack[0].dir = 0;

    while (top != -1 && !found) {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;

        while (dir < 8 && !found) {
            nextRow = row + moved[dir].vert;
            nextCol = col + moved[dir].horiz;

            if (nextRow == EXIT_ROW && nextCol == EXIT_COL) {
                found = true;
            } else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
                position.row = row;
                position.col = col;
                position.dir = dir;
                push(position);

                row = nextRow;
                col = nextCol;
                dir = 0;
                mark[row][col] = 1;
            } else {
                dir++;
            }
        }
    }

    if (found) {
        for (int i = 0; i <= top; i++) {
            maze[Stack[i].row][Stack[i].col] = 2;
            printMaze();
            usleep(100);
            cout << "____________________" << endl;
            }
            maze[row][col]=2;
            printMaze();
            usleep(500);
            cout << "____________________" << endl;;
            maze[EXIT_ROW][EXIT_COL]=2;
            printMaze();
        }
        else {
        cout << "無法找到路徑!" << endl;
    }
}

void printMaze(void) {
    for (int i = 0; i < m + 2; i++) {
        for (int j = 0; j < p + 2; j++) {
            if (maze[i][j] == 0) {
                cout << " ";
            } else if (maze[i][j] == 1) {
                cout << "0";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}

bool isEmpty(void) {
    return top < 0;
}

bool isFull(void) {
    return top >= (MAX_STACK_SIZE - 1);
}

void push(element item) {
    if (isFull()) {
        fprintf(stderr, "堆疊已滿，不能再加入元素");
        exit(EXIT_FAILURE);
    }
    Stack[++top] = item;
}

element pop(void) {
    if (isEmpty()) {
        fprintf(stderr, "堆疊為空");
        exit(EXIT_FAILURE);
    }
    return Stack[top--];
}
