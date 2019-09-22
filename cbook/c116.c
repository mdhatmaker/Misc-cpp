#include <stdio.h>
#define MAXVAL 100      /* maximum depth of val stack */
#define BUFSIZE 256     /* buffer size */

/* Functions and Program Structure */

// EXTERNAL VARIABLES (variables defined outside of any function)

// DEFINITION of external variables (causes storage to be set aside)
int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

// DECLARATION of external variables (declares for rest of source file that sp is int and val is double array)
// does not create the variables or reserve storage for them
extern int sp;
extern double val[];

// STATIC VARIABLES (ensures names will not conflict with the same names in other files of the same program)
static char buf[BUFSIZE];   /* buffer for ungetch */
static int bufp = 0;        /* next free position in buf */

// MACRO SUBSTITUTION
#define forever     for (;;)                    /* infinite loop */
#define max(A, B)   ((A) > (B) ? (A) : (B))     /* macro with arguments */


/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);    
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// Names may be undefined with #undef, usually to ensure that a routine is really a function, not a macro.
#undef getchar
int getchar(void)
{
}

#define paste(front, back) front ## back    // preprocessor argument ## concatenates actual arguments during macro expansion

// CONDITIONAL INCLUSION
#ifndef RXX     // or longer form:  #if !defined(RXX)
#define RXX
/* contents of rxx.h go here */
#endif

/* The following wouldn't actually work 
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR
*/

int main()
{
    push(1.2);
    push(2.3);
    push(3.4);
    printf("%g\n", pop());
    printf("%g\n", pop());
    printf("%g\n", pop());

    // REGISTER VARIABLES (advises compiler that variable will be heavily used)
    register char c;
    register int i = 0;

    forever {
        printf("%d ", ++i);
        if (i >= 20)
            break;
    }

    printf("\n\n%d\n", max(8,9));

    char* name1 = "hello";
    printf("%s\n", paste(name, 1));     // macro expands to token "name1"

}

