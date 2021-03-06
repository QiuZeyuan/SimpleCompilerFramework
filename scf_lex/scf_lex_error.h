#ifndef SCF_LEX_ERROR_H
#define SCF_LEX_ERROR_H

#include"scf_string.h"
#include"scf_list.h"

typedef struct
{
    scf_list_t      list;

    scf_string_t*   message;
    
    scf_string_t*   file;
    int             line;
    int             pos;
}scf_lex_error_t;

scf_lex_error_t*    scf_lex_error_alloc(scf_string_t* file, int line, int pos);
void                scf_lex_error_free(scf_lex_error_t* e);

#endif