D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

void count();
void comment();
int check_type(); 
int struct_sign = 0, idx = 0, check_bracket = 0;
char *type[100];

%}

%%
"#include"[ ]*<.+\.h>   { return(INCLUDE); }
"#define"[ ]*{L}+[ ]*{D}+\.*{D}* 	{ return(DEFINE); }
"/*"                    { comment(); }
"auto"                  { count(); return(AUTO); }
"break"                 { count(); return(BREAK); }
"case"                  { count(); return(CASE); }
"char"                  { count(); return(CHAR); }
"const"                 { count(); return(CONST); }
"continue"              { count(); return(CONTINUE); }
"default"               { count(); return(DEFAULT); }
"do"                    { count(); return(DO); }
"double"                { count(); return(DOUBLE); }
"else"                  { count(); return(ELSE); }
"enum"                  { count(); return(ENUM); }
"extern"                { count(); return(EXTERN); }
"float"                 { count(); return(FLOAT); }
"for"                   { count(); return(FOR); }
"goto"                  { count(); return(GOTO); }
"if"                    { count(); return(IF); }
"int"                   { count(); return(INT); }
"long"                  { count(); return(LONG); }
"register"              { count(); return(REGISTER); }
"return"                { count(); return(RETURN); }
"short"                 { count(); return(SHORT); }
"signed"                { count(); return(SIGNED); }
"sizeof"                { count(); return(SIZEOF); }
"static"                { count(); return(STATIC); }
"struct"                { count(); struct_sign = 1; return(STRUCT); }
"switch"                { count(); return(SWITCH); }
"typedef"               { count(); return(TYPEDEF); }
"union"                 { count(); return(UNION); }
"unsigned"              { count(); return(UNSIGNED); }
"void"                  { count(); return(VOID); }
"volatile"              { count(); return(VOLATILE); }
"while"                 { count(); return(WHILE); }
"else if"		{ return(ELIF); }

{L}({L}|{D})*           { count(); return(check_type()); }

0[xX]{H}+{IS}?          { count(); return(CONSTANT); }
0{D}+{IS}?              { count(); return(CONSTANT); }
{D}+{IS}?               { count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'       { count(); return(CONSTANT); }

{D}+{E}{FS}?            { count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?  { count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?  { count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"     { count(); return(STRING_LITERAL); }

"..."                   { count(); return(ELLIPSIS); }
">>="                   { count(); return(RIGHT_ASSIGN); }
"<<="                   { count(); return(LEFT_ASSIGN); }
"+="                    { count(); return(ADD_ASSIGN); }
"-="                    { count(); return(SUB_ASSIGN); }
"*="                    { count(); return(MUL_ASSIGN); }
"/="                    { count(); return(DIV_ASSIGN); }
"%="                    { count(); return(MOD_ASSIGN); }
"&="                    { count(); return(AND_ASSIGN); }
"^="                    { count(); return(XOR_ASSIGN); }
"|="                    { count(); return(OR_ASSIGN); }
">>"                    { count(); return(RIGHT_OP); }
"<<"                    { count(); return(LEFT_OP); }
"++"                    { count(); return(INC_OP); }
"--"                    { count(); return(DEC_OP); }
"->"                    { count(); return(PTR_OP); }
"&&"                    { count(); return(AND_OP); }
"||"                    { count(); return(OR_OP); }
"<="                    { count(); return(LE_OP); }
">="                    { count(); return(GE_OP); }
"=="                    { count(); return(EQ_OP); }
"!="                    { count(); return(NE_OP); }
";"                     { count(); return(';'); }
("{"|"<%")              { count(); check_bracket = 1; return('{'); }
("}"|"%>")              { count(); check_bracket = 0; return('}'); }
","                     { count(); return(','); }
":"                     { count(); return(':'); }
"="                     { count(); return('='); }
"("                     { count(); return('('); }
")"                     { count(); return(')'); }
("["|"<:")              { count(); return('['); }
("]"|":>")              { count(); return(']'); }
"."                     { count(); return('.'); }
"&"                     { count(); return('&'); }
"!"                     { count(); return('!'); }
"~"                     { count(); return('~'); }
"-"                     { count(); return('-'); }
"+"                     { count(); return('+'); }
"*"                     { count(); return('*'); }
"/"                     { count(); return('/'); }
"%"                     { count(); return('%'); }
"<"                     { count(); return('<'); }
">"                     { count(); return('>'); }
"^"                     { count(); return('^'); }
"|"                     { count(); return('|'); }
"?"                     { count(); return('?'); }
"//"			{ /* ignore */ }

[ \t\v\n\f]             { count(); }
.                       { /* ignore bad characters */ }

%%

int yywrap(){
        return 1;
}

void comment(){
        char c, c1;
loop:
        while((c = input()) != '*' && c != 0)
                putchar(c);
        if ((c1 = input()) != '/' && c != 0)
        {
                unput(c1);
                goto loop;
        }

        if (c != 0)
                putchar(c1);
}

int column = 0;

void count()
{
        int i;
        for(i = 0; yytext[i] != '\0'; i++)
                if (yytext[i] == '\n')
                        column = 0;
                else if (yytext[i] == '\t')
                        column += 8 - (column % 8);
                else
                        column++;

        ECHO;
}

int check_type()
{
	/*
        1-1. struct_sign == 1 검사하기.
        2-1. yytext를 char *type에 넣기.

        1-2. struct_sign == 0이라면, type안에 있는 타입인지 검사하기.
                - 문자열이 같다는 것을 확인하기
        2-2 값이 있으면 type_name 값을,
        2-3 값이 없으면 IDENTIFIER을 반환함.
        */
        
        
        if(struct_sign == 1 && check_bracket == 0) {
//printf("yes!1");
                type[idx] = yytext;
                idx++;
                struct_sign = 0;
                return(IDENTIFIER);
        } else {
//printf("yes!2");
                if(idx == 0) return(IDENTIFIER); 
//printf("yes!3");
                for(int i=0; i<=idx; i++) {
                        if(strcmp(yytext, type[i]) == 0) {
                                return(TYPE_NAME);
                        }
                }
                return(IDENTIFIER);        
        }        
        
}
