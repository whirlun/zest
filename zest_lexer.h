//
// Created by bbrabbit on 11/18/20.
//

#ifndef ZEST_ZEST_LEXER_H
#define ZEST_ZEST_LEXER_H

#include "zest_object.h"

enum KEYWORDS_TOKEN {
    OP_AND=0, OP_OR, OP_PLUS, OP_MINUS,
    OP_MUL, OP_DIV, OP_MOD, OP_ASSIGN,
    OP_TILDE, OP_EQ,OP_NE,OP_GT,OP_LT,
    OP_GTE, OP_LTE, OP_ARROW, OP_FATARROW, OP_VARARG,
    KW_IF,KW_FOR,KW_WHILE,KW_ELSIF,
    KW_END,KW_CONTINUE,KW_BREAK, KW_CASE, KW_OF,
    KW_FUNC, KW_TRAIT, KW_CLASS, KW_FREEZE,
    DEL_LCURLY,DEL_RCURLY,DEL_LBRACKET,DEL_RBRACKET,
    DEL_LPAREN,DEL_RPAREN, DEL_COMMA, DEL_DOT, DEL_DQ,
    DEL_SQ, DEL_COLON, DEL_PIPE,DEL_QM, DEL_HASH,
    LIT_STRING,LIT_NUMBER, LIT_INTEGER, LIT_IDENTIFIER,
    EOF,
};

static const char* KEYWORDS[] =
        {"and", "or","+","-","*","/","%",":=","~","==","!=",">","<",">=","<=", "->", "=>", "...",
         "for","while","elsif","end","continue","break","case","of",
         "func", "trait", "class", "freeze",
         "{","}","[", "]","(",")",",",".","\"","'",":", "|", "?", "#",
        "<string>","<number>","<integer>","<identifier>",
        "<EOF>"};

typedef struct Token {
    enum KEYWORDS_TOKEN token;
    union {
        zest_integer i;
        zest_number n;
        zest_string* s;
    } c;
} Token;

typedef struct LexerState {
    int linenumber;

} LexerState;

#endif //ZEST_ZEST_LEXER_H
