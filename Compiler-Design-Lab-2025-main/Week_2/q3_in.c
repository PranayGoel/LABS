/ This is a single line comment
/* *****This is a
******Multiline Comment
**** */
#include <stdio.h>
#define hello
void main()
{
	FILE *fopen(), *fp;
	int c ;
	fp = fopen( “prog.c”, “r” ); //Comment
	printf("\n#def");
		
		c = getc( fp ) ;
	while ( c != EOF ) {
		putchar( c );
		c = getc ( fp );
	}
	for(int i=0;i<100;i++);
		fo
	r
	/*multiline
	comment */
	fclose(fp );
}