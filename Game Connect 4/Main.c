#include<stdio.h>
#include"Functions.h"


int main(){
	int grid[r][c];
	empty_grid(grid);
	print_grid(grid);
	game(grid);
	print_grid(grid);
}
