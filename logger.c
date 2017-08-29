/*H**********************************************************************
* FILENAME :        logger.c             
*
* DESCRIPTION :
*       System logging facility useful for debugging. 
*
* PUBLIC FUNCTIONS :
*       void log_print(filename, line, fmt, ...)    
*
* NOTES :
*       A macro has been created to create log entries.
*       Use the macro to invoke log entries.
*
*       Copyright Nytec, Inc. 2017.  All rights reserved.
* 
* AUTHOR :            
*
* START DATE :    08-16-2017
*
* CHANGES :
*
* REF NO  VERSION DATE     	DETAIL
* 
*
*H*/
/***************************************************
**  Simple Logger Facility
****************************************************/
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"


/*********************************************
**  DEFINES
*********************************************/
#define USE_STDOUT

/*********************************************
**  GLOBALS
*********************************************/
static FILE *fp;
static int SESSION_TRACKER; //Keeps track of session
static char Buffer[256]; 
 
/*********************************************
**  FUNCTIONS
*********************************************/
static char* print_time()
{	
    int size = 0;
    time_t t;
    char *buf;
     
    t=time(NULL); /* get current calendar time */
     
    char *timestr = asctime( localtime(&t) );
    timestr[strlen(timestr) - 1] = 0;  //Getting rid of \n
     
    size = strlen(timestr)+ 1 + 2; //Additional +2 for square braces
    buf = &Buffer[0];
     
    memset(buf, 0x0, size);
    snprintf(buf,size,"[%s]", timestr);
	
    return buf;
}


void log_print(char* filename, int line, char *fmt,...)
{
    va_list         list;
    char            *p, *r;
    int             e;
 
#ifndef USE_STDOUT
    if(SESSION_TRACKER > 0)
      fp = fopen ("log.txt","a+");
    else
      fp = fopen ("log.txt","w");
#else
	fp = stdout; 
#endif
	
    fprintf(fp,"%s ",print_time());
    fprintf(fp,"[%s][line: %d] ",filename,line);
    va_start( list, fmt );
 
    for ( p = fmt ; *p ; ++p )
    {
        if ( *p != '%' )//If simple string
        {
            fputc( *p,fp );
        }
        else
        {
            switch ( *++p )
            {
                /* string */
            case 's':
            {
                r = va_arg( list, char * );
 
                fprintf(fp,"%s", r);
                continue;
            }
 
            /* integer */
            case 'd':
            {
                e = va_arg( list, int );
 
                fprintf(fp,"%d", e);
                continue;
            }
 
            default:
                fputc( *p, fp );
            }
        }
    }
    va_end( list );
    SESSION_TRACKER++;
	
#ifndef USE_STDOUT	
    fclose(fp);
#endif	
}