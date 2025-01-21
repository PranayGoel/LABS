/ This is a single line comment
/* *****This is a
******Multiline Comment
**** */
#INCLUDE <stdio.h>
#DEFINE hello
void main()
{
	FILE *fopen(), *fp;
	int c ;
	fp = fopen( “prog.c”, “r” ); //Comment
	printf("\n#def");
		
		c = getc( fp ) ;
	WHILE ( c != EOF ) {
		putchar( c );
		c = getc ( fp );
	}
	FOR(int i=0;i<100;i++);
		fo
	r
	/*multiline
	comment */
	fclose(fp );
}