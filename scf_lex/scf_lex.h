#ifndef SCF_LEX_H
#define SCF_LEX_H

#include "scf_lex_word.h"
#include "scf_lex_char.h"
#include "scf_lex_error.h"

typedef struct
{
    char*              text;
    enum scf_lex_words type;
}scf_lex_key_word_t;

typedef struct
{
    char    origin;
    char    escape;
}scf_lex_escape_char_t;

typedef struct
{
    char c;
    enum scf_lex_words t;
    char  c1[2][2];
    enum scf_lex_words t1[2][2];
    int n[2];
}scf_lex_op_t;


typedef struct
{
    scf_list_t  word_list_head;
    scf_list_t  error_list_head;

    scf_list_t  char_list_head;

    FILE*       fp;

    int         num_id;
    
    scf_string_t* file;
    int         read_lines;
    int         read_pos;
}scf_lex_t;

int scf_lex_open(scf_lex_t** plex, const char* path);
int scf_lex_close(scf_lex_t* lex);

int scf_lex_push_word(scf_lex_t* lex, scf_lex_word_t* word);
int scf_lex_pop_word(scf_lex_t* lex, scf_lex_word_t** pword);

static int _find_key_word(const char *text);
static int _find_escape_char(const char c);
static int _is_overflow(scf_lex_word_t* w, int base);

static void             _lex_push_char(scf_lex_t* lex, scf_lex_char_t*c);
static scf_lex_char_t*  _lex_pop_char(scf_lex_t* lex);
static void             _lex_jump_space(scf_lex_t* lex);

static int              _lex_plus(scf_lex_t * lex, scf_lex_word_t** pword, scf_lex_char_t* c);
static int              _lex_minus(scf_lex_t * lex, scf_lex_word_t** pword, scf_lex_char_t* c);
static int              _lex_op_ll1(scf_lex_t* lex, scf_lex_word_t** pword, scf_lex_char_t* c,
                        enum scf_lex_words t, char c1[2][2],enum scf_lex_words t1[2][2], int n[2]);
static int              _lex_char(scf_lex_t *lex, scf_lex_word_t **pword, scf_lex_char_t *c);
static int              _lex_string(scf_lex_t* t, scf_lex_word_t** pword, scf_lex_char_t* c);
static int              _lex_number(scf_lex_t* lex, scf_lex_word_t** pword, scf_lex_char_t* c);
static int              _lex_identity(scf_lex_t* lex, scf_lex_word_t** pword, scf_lex_char_t* c);

#endif