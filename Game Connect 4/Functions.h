#include<stdio.h>
#include <stdlib.h>
#define c 7
#define r 6
void empty_grid(int grid[r][c]){
	for (int i =0;i<r;i++){
		for (int j=0;j<c;j++){
			grid[i][j]=0;
		}
	}
}

void print_grid(int grid[r][c]){
	for (int i =0;i<r;i++){
		printf("|");
		for (int j=0;j<c;j++){
			printf("%d\t",grid[i][j]);
		}
		printf("|\n");
	}
	for (int k=0;k<57;k++){
		printf("-");
	}
	printf("\n");
	for(int i=1;i<c+1;i++){
		printf("(%d)\t",i);
	}
}

int check_horizontal(int grid[r][c], int row, int column, int num) {
    int connect = 1;
    for (int i = column + 1; i < c; i++) {
        if (num != grid[row][i]) {
            break;
        }
        connect += 1;
    }

    if (connect >= 4) {
        return 1;
    }
    for (int i = column - 1; i >= 0; i--) {
        if (num != grid[row][i]) {
            break;
        }
        connect += 1;
    }
    if (connect >= 4) {
        return 1;
    }
    return 0;
}

int check_vertical(int grid[r][c], int row, int column, int num) {
    if (row > 2) {
        return 0;
    }
    return (num == grid[row + 1][column] && num == grid[row + 2][column] && num == grid[row + 3][column]);
}

int check_diag(int grid[r][c], int row, int column, int num) {
    int connect = 1;
    // Check '\'
    for (int i = 1; i < 4; i++) {
        if (row + i >= r || column + i >= c || num != grid[row + i][column + i]) {
            break;
        }
        connect += 1;
    }
    for (int i = 1; i < 4; i++) {
        if (row - i < 0 || column - i < 0 || num != grid[row - i][column - i]) {
            break;
        }
        connect += 1;
    }
    if (connect >= 4) {
        return 1;
    }
    // Check '/'
    connect = 1;
    for (int i = 1; i < 4; i++) {
        if (row - i < 0 || column + i >= c || num != grid[row - i][column + i]) {
            break;
        }
        connect += 1;
    }
    for (int i = 1; i < 4; i++) {
        if (row + i >= r || column - i < 0 || num != grid[row + i][column - i]) {
            break;
        }
        connect += 1;
    }
    if (connect >= 4) {
        return 1;
    }
    return 0;
}

int win(int grid[r][c], int row, int column, int num) {
    if (check_horizontal(grid, row, column, num)) {
    	printf("------------------------------------------------------------------\n");
    	printf("                      CONGRATULATIONS                             \n");
    	printf("------------------------------------------------------------------\n");

        printf("Player %d Won by connecting 4 horizontally in row %d\n", num, row+1);
        return 1;
    }
    if (check_vertical(grid, row, column, num)) {
    	printf("------------------------------------------------------------------\n");
    	printf("                      CONGRATULATIONS                             \n");
    	printf("------------------------------------------------------------------\n");
        printf("Player %d Won by connecting 4 vertically in column %d\n", num, column+1);
        return 1;
        
    }
    if (check_diag(grid, row, column, num)) {
    	printf("------------------------------------------------------------------\n");
    	printf("                      CONGRATULATIONS                             \n");
    	printf("------------------------------------------------------------------\n");
        printf("Player %d Won by connecting 4 diagonally\n", num);
        return 1;
    }
    return 0;
}

int game(int grid[r][c]){
	int x;
	int u;
	while(1){	
		u=0;
		printf("\nPlayer 1 choose your column : ");
		scanf("%i",&x);
		x--;
		while(grid[u+1][x]==0 && u<5){
			u++;
		}
		grid[u][x]=1;
		if(win(grid,u,x,1)){
			return 0;
		}
		print_grid(grid);
		
		printf("\nPlayer 2 choose your column : ");
		scanf("%d",&x);
		x--;
		u=0;
		while(grid[u+1][x]==0 && u<5){
			u++;
		}
		grid[u][x]=2;
		if(win(grid,u,x,2)){
			return 0;
		}
		print_grid(grid);
	}
}
