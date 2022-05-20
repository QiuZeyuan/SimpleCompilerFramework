#ifndef SCF_ERROR_H
#define SCF_ERROR_H

typedef struct
{
    scf_list_t      list;

    scf_string_t*   message;
    
    scf_string_t*   file;
    int             line;
    int             pos;
}scf_lex_error_t;

#endif