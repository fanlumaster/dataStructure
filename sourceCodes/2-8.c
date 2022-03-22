#include <stdio.h>

void Swap( int X, int Y )
{ /* ´íÎóµÄ½»»»º¯Êý */
	int tmp;	
	tmp = X; X = Y; Y = tmp;
} 

int main()
{
	int X = 10, Y = 20;

	Swap( X, Y );
	printf("X = %d, Y = %d", X, Y);
	
	return 0;
}
