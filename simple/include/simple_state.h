
/* 
	Copyright (c) 2017-2018 Azeez Adewale <azeezadewale98@gmail.com> 
	MIT License Copyright (c) 2017 simple 

*/

/* 
 * File:   simple.h
 * Author: Azeez Adewale
 *
 * Created on July 10, 2017, 1:10 PM
 */


#ifndef simple_state_h
#define simple_state_h
/* Data */
typedef struct SimpleState {
	/* First use by simple_scanner_readfile */
	char* main_file_path;
	List *files_list  ;
	List *files_stack  ;
	/* First use by simple_parser_new */
	List *generated_code  ;
	List *blocks_map  ;
	List *classes_map  ;
	List *modules_map  ;
	List *module_paths  ;
	/* First use by simple_vm_new */
	List *c_blocks  ;
	/* ISCGI is 1 if we are using the language as for CGI development */
	unsigned int nISCGI : 1  ;
	/* RUN is 0 if we need to compile only */
	unsigned int nRun : 1  ;
	/* PRINTIC is 1 if we need to print byte code before execution */
	unsigned int nPrintIC : 1  ;
	/* set to 1 if we need to print the fine byte code after execution */
	unsigned int nPrintICFinal : 1  ;
	/* set to 1 if we need to print the tokens */
	unsigned int nPrintTokens : 1  ;
	/* set to 1 if we need to print the grammar rules */
	unsigned int nPrintRules : 1  ;
	/* set to 1 if we need to print the  current instruction executed */
	unsigned int nPrintInstruction : 1  ;
	/* set to 1 if we need to generate the object file (ringo) */
	unsigned int generate_object : 1  ;
	/* set to 1 if we need to display warnings */
	unsigned int nWarning : 1  ;
	/* Set to 1 to tell the scanner to don't delete the VM after execution */
	int skip_error  ;
	/* Set to 1 to tell the skip all the error instance */
	unsigned int nDontDeleteTheVM : 1  ;
	/* command line parameters */
	int argc  ;
	char  **argv  ;
	/* Virtual Machine */
	struct VM *vm  ;
	/* Startup File */
	char lStartup  ;
	/* Pool Manager */
	PoolManager vPoolManager  ;
	/* Avoid line number ( when we use executeCode() from VM ) */
	char lNoLineNumber  ;
	/* Custom Global Scope */
	int nCustomGlobalScopeCounter  ;
	List *aCustomGlobalScopeStack  ;
	/* Condition to prevent loading cblocks more than once */
	int loaded_cblocks;
#ifdef __ANDROID__
	ANativeActivity* simple_ANativeActivity;
	ANativeWindow* simple_ANativeWindow;
	ANativeWindow_Buffer simple_ANativeWindow_Buffer;
#endif
} SimpleState ;
/* Blocks */

SIMPLE_API SimpleState * simple_state_new ( void ) ;

#if defined(__ANDROID__)
SIMPLE_API SimpleState * simple_add_android_paths(SimpleState *sState); 
#endif

SIMPLE_API SimpleState * finalize_simple_state ( SimpleState *sState ) ;

void simple_state_cgiheader ( SimpleState *sState ) ;

SIMPLE_API void print_line ( void ) ;

SIMPLE_API SimpleState * init_simple_state ( void ) ;

SIMPLE_API void execute_simple_code ( SimpleState *sState,const char *cStr ) ;

SIMPLE_API List * simple_state_findvar ( SimpleState *sState,const char *cStr ) ;

SIMPLE_API List * simple_state_newvar ( SimpleState *sState,const char *cStr ) ;

SIMPLE_API void simple_state_main ( int argc, char *argv[] ) ;

SIMPLE_API void execute_simple_file ( SimpleState *sState,char *file_name ) ;

SIMPLE_API void simple_state_runobjectstring ( SimpleState *sState,char *string,const char *file_name ) ;

SIMPLE_API void simple_state_runobjectfile ( SimpleState *sState,char *file_name ) ;

SIMPLE_API void simple_execute_object ( SimpleState *sState,char *string,const char *file_name ) ;

/* General Blocks */

SIMPLE_API int simple_fexists ( const char *file_name ) ;

SIMPLE_API int simple_currentdir ( char *cDirPath ) ;

SIMPLE_API int simple_exefilename ( char *cDirPath ) ;

SIMPLE_API int simple_chdir ( const char *cDir ) ;

SIMPLE_API void simple_exefolder ( char *cDirPath ) ;

SIMPLE_API void simple_distro_folder(char *dirPath) ;

SIMPLE_API void simple_switchtofilefolder ( char *file_name ) ;

SIMPLE_API int simple_justfilepath ( char *file_name ) ;

SIMPLE_API void simple_justfilename ( char *file_name ) ;

/* MACRO */
#define SIMPLE_STATE_CHECKPRINTRULES if ( parser->sState->nPrintRules )

#endif
