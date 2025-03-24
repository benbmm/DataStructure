#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_ROWS 10
#define MAZE_COLS 10
#define EXIT_ROW 8
#define EXIT_COL 8

typedef struct {
    int row;
    int col;
    int dir;
} element;

typedef struct {
    int vert;
    int horiz;
} offsets;

element stack[MAX_STACK_SIZE];
int top = -1;
int maze[MAZE_ROWS][MAZE_COLS];
int mark[MAZE_ROWS][MAZE_COLS];

offsets move[8] = {
    {-1,  0}, {-1,  1}, { 0,  1}, { 1,  1},
    { 1,  0}, { 1, -1}, { 0, -1}, {-1, -1}
};

// 堆疊相關函式
void push(element item) {
    if (top >= MAX_STACK_SIZE - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = item;
}

element pop(void) {
    if (top < 0) {
        printf("Stack underflow\n");
        element dummy = {-1, -1, -1};
        return dummy;
    }
    return stack[top--];
}

// 初始化迷宮及標記
void init_maze() {
    memset(maze, 0, sizeof(maze));
    memset(mark, 0, sizeof(mark));

    // 範例迷宮牆面設定 (1:牆, 0:通路)
    int example_maze[MAZE_ROWS][MAZE_COLS] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,1,1,1,1,1},
        {1,1,1,0,1,1,1,1,1,1},
        {1,1,1,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,1,1,1,1},
        {1,1,1,1,1,0,0,0,1,1},
        {1,1,1,1,1,1,1,0,1,1},
        {1,1,1,1,1,1,1,0,0,1},
        {1,1,1,1,1,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    memcpy(maze, example_maze, sizeof(example_maze));
}

void path(void) {
    int i, row, col, next_row, next_col, dir, found = 0;
    element position;

    mark[1][1] = 1;
    top = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;

    while (top > -1 && !found) {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;

        while (dir < 8 && !found) {
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;

            if (next_row == EXIT_ROW && next_col == EXIT_COL) {
                found = 1;
                push((element){row, col, dir});
            } else if (next_row >= 0 && next_row < MAZE_ROWS &&
                       next_col >= 0 && next_col < MAZE_COLS &&
                       !maze[next_row][next_col] && !mark[next_row][next_col]) {
                mark[next_row][next_col] = 1;
                push((element){row, col, dir + 1});
                row = next_row;
                col = next_col;
                dir = 0;
            } else {
                dir++;
            }
        }
    }

    if (found) {
        printf("🟢 找到出口！路徑為：\n");
        printf("row col\n");
        for (i = 0; i <= top; i++)
            printf("%2d %4d\n", stack[i].row, stack[i].col);
        printf("%2d %4d\n", EXIT_ROW, EXIT_COL);
    } else {
        printf("🔴 無法找到出口的路徑\n");
    }
}
void init_complex_maze() {
    memset(maze, 0, sizeof(maze));
    memset(mark, 0, sizeof(mark));

    // 複雜迷宮 (1:牆, 0:通路)
    int complex_maze[MAZE_ROWS][MAZE_COLS] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,1,1,1,1},
        {1,0,1,0,1,0,0,0,1,1},
        {1,0,1,0,1,1,1,0,1,1},
        {1,0,0,0,0,0,1,0,1,1},
        {1,1,1,1,1,0,1,0,0,1},
        {1,1,0,0,1,0,1,1,0,1},
        {1,1,0,1,1,0,0,1,0,1},
        {1,1,0,0,0,1,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    memcpy(maze, complex_maze, sizeof(complex_maze));
}

int main(void) {
    init_complex_maze();
    path();
    return 0;
}
