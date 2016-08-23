#include <stdio.h>
#include <string.h>
int Check(char*);
/*
 *status:
 *0 : is not a palindrome
 *1 : is a regular palidrome
 *2 : is a mirrored string
 *3 : is a mirrored palidrome
 */
int Check_status(char A, char B){/*{{{*/
	if ( A != B) {
		switch(A){
			case 'E':
				if ( B == '3') 
					return 2;	
			case '3':
				if ( B == 'E') 
					return 2;	
			case 'J':
				if ( B == 'L')
					return 2;	
			case 'L':
				if ( B == 'J')
					return 2;	
			case 'S':
				if ( B == '2') 
					return 2;	
			case '2':
				if ( B == 'S') 
					return 2;	
			case 'Z':
				if ( B == '5') 
					return 2;	
			case '5':
				if ( B == 'Z') 
					return 2;	
			default: 
				return 0;
		}
	}
	switch(A){
		case 'A':
		case 'H':
		case 'I':
		case 'M':
		case 'O':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case '1':
		case '8':
			return 3;
		default:
			return 1;
	}
}/*}}}*/

int main(void)
{
	char data[21];
	int status;

	while ( gets(data) != NULL) {
		status = Check(data);
		if ( status ==  0 ) {
			printf("%s -- is not a palindrome.\n", data);
		}
		else if ( status ==  1 ) {
			printf("%s -- is a regular palindrome.\n", data);
		}
		else if ( status ==  2 ) {
			printf("%s -- is a mirrored string.\n", data);
		}
		else if ( status ==  3 ) {
			printf("%s -- is a mirrored palindrome.\n", data);
		}
		printf("\n");
	}
	return 0;
}

int Check( char* data ){
	int i = 0, len = strlen(data), status = 3;
	while ( (len - i) - i > 0) {
		switch(	Check_status(data[i], data[len -1 -i]) ){
			case 0:
				return 0 ;
			case 1:
				if ( status == 2) {
					return 0;	
				}
				status = 1;
				break;
			case 2:
				if ( status == 1) {
					return 0;	
				}
				status = 2;
				break;
			case 3:
				if ( status == 1) {
					status = 1;
				}
				else if ( status == 2) {
					status = 2;
				}
				else 
					status = 3;
				break;
		}
		i++;
	}
	return status;
}
