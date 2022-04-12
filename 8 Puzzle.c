#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3


void board_state(char new_board[N][N] ){
    char board[N][N] = {{'1',  '2',  '3' },
                        {'4',  '5',  '6' },
                        {'7',  '8', ' '}};


    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            new_board[row][col] = board[row][col];
        }
    }

}

void board_print(char new_board[N][N]){
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            printf(" %c ",new_board[row][col]);
        }
        printf("\n");
    }
}



void apply_move(char new_board[N][N],int move_key) {
    int blank_row, blank_col;
    int new_blank_row, new_blank_col;

    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if(new_board[row][col] == ' '){
                blank_row = row;
                blank_col = col;
            }

        }
    }
    new_blank_row = blank_row;
    new_blank_col = blank_col;


    switch (move_key) {
        case 1:
            new_blank_row = blank_row + 1;
            break;
        case 2:
            new_blank_row = blank_row - 1;
            break;
        case 3:
            new_blank_col = blank_col - 1;
            break;
        case 4:
            new_blank_col = blank_col + 1;
            break;
    }
    if ((new_blank_row >= 0 && new_blank_row < 3) && (new_blank_col >= 0 && new_blank_col < 3)) {
        new_board[blank_row][blank_col] = new_board[new_blank_row][new_blank_col];
        new_board[new_blank_row][new_blank_col] = ' ';

    }

}




void shuffle_board(char new_board[N][N]) {
    srand(time(NULL));
    for (int i = 0; i < 100; ++i) {
        int shuffler = rand() % 4;
        switch (shuffler) {
            case 0:
                apply_move(new_board,1);
                break;
            case 1:
                apply_move(new_board,2);
                break;
            case 2:
                apply_move(new_board,3);
                break;
            case 3:
                apply_move(new_board,4);
                break;

        }

    }
}




//void check_win(char board[][N], char new_board[N][N]){

void check_win(char new_board[N][N]){
    char board[N][N] = {{'1',  '2',  '3' },
                        {'4',  '5',  '6' },
                        {'7',  '8', ' '}};

    int count =0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {


            if(board[i][j] == new_board[i][j]){
                count++;
            }
        }
    }
    if(count==9){
        printf("Win\n\n");
    }

}






int main() {
    //char board[N][N];
    char new_board[N][N];

    int key;
    printf("Use 0 to Exit\n");

    board_state(new_board);
    shuffle_board(new_board);

    do {
        //system("cls");
        printf("Use 1(up),2(down),3(right),4(left) !\n\n");
        board_print(new_board);
        scanf("%d",&key);
        apply_move(new_board,key);
        //check_win(board,new_board);
        check_win(new_board);

    } while (key != 0);


    return 0;

}
