%{
#include <stdio.h>
int yylex();
void yyerror(const char* str);
int ary[9] = {0,0,0,0,0,0,0,0,0};
int id_cnt = 0;
int check_int = 0, check_char = 0;
int int_cnt =0, int_char = 0;
int buffer = 0;
#define YYDEBUG 1
%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN INCLUDE DEFINE ELIF

%start translation_unit
%%

primary_expression
      	: IDENTIFIER
        | CONSTANT
        | STRING_LITERAL
        | '(' expression ')'
        ;

postfix_expression
	: primary_expression
        | postfix_expression '[' expression ']'
        | postfix_expression '(' ')'
        | postfix_expression '(' argument_expression_list ')' { ary[0]++; }
        | postfix_expression '.' IDENTIFIER
        | postfix_expression PTR_OP IDENTIFIER
        | postfix_expression INC_OP { ary[1]++; }
        | postfix_expression DEC_OP { ary[1]++; }
	;

argument_expression_list
    	: assignment_expression
        | argument_expression_list ',' assignment_expression
        ;

unary_expression
        : postfix_expression
        | INC_OP unary_expression { ary[1]++; }
        | DEC_OP unary_expression { ary[1]++; }
        | unary_operator cast_expression
        | SIZEOF unary_expression
        | SIZEOF '(' type_name ')'
        ;

unary_operator
        : '&'
        | '*'
        | '+'
        | '-'
        | '~'
        | '!'
        ;
cast_expression
        : unary_expression
        | '(' type_name ')' cast_expression { ary[1]++; }
        ;

multiplicative_expression
        : cast_expression
        | multiplicative_expression '*' cast_expression { ary[1]++; }
        | multiplicative_expression '/' cast_expression { ary[1]++; }
        | multiplicative_expression '%' cast_expression { ary[1]++; }
        ;

additive_expression
        : multiplicative_expression
        | additive_expression '+' multiplicative_expression { ary[1]++; }
        | additive_expression '-' multiplicative_expression { ary[1]++; }
        ;

shift_expression
        : additive_expression
        | shift_expression LEFT_OP additive_expression { ary[1]++; }
        | shift_expression RIGHT_OP additive_expression { ary[1]++; }
        ;

relational_expression
        : shift_expression
        | relational_expression '<' shift_expression { ary[1]++; }
        | relational_expression '>' shift_expression { ary[1]++; }
        | relational_expression LE_OP shift_expression { ary[1]++; }
        | relational_expression GE_OP shift_expression { ary[1]++; }
        ;

equality_expression
        : relational_expression
        | equality_expression EQ_OP relational_expression { ary[1]++; }
        | equality_expression NE_OP relational_expression { ary[1]++; }
        ;

and_expression
        : equality_expression
        | and_expression '&' equality_expression { ary[1]++; }
        ;

exclusive_or_expression
        : and_expression
        | exclusive_or_expression '^' and_expression { ary[1]++; }
        ;

inclusive_or_expression
        : exclusive_or_expression
        | inclusive_or_expression '|' exclusive_or_expression { ary[1]++; }
        ;

logical_and_expression
        : inclusive_or_expression
        | logical_and_expression AND_OP inclusive_or_expression { ary[1]++; }
        ;


logical_or_expression
        : logical_and_expression
        | logical_or_expression OR_OP logical_and_expression { ary[1]++; }
        ;

conditional_expression
        : logical_or_expression
        | logical_or_expression '?' expression ':' conditional_expression
        ;

assignment_expression
        : conditional_expression
        | unary_expression assignment_operator assignment_expression
        ;

assignment_operator
        : '=' { ary[1]++; }
        | MUL_ASSIGN { ary[1]++; }
        | DIV_ASSIGN { ary[1]++; }
        | MOD_ASSIGN { ary[1]++; }
        | ADD_ASSIGN { ary[1]++; }
        | SUB_ASSIGN { ary[1]++; }
        | LEFT_ASSIGN { ary[1]++; }
        | RIGHT_ASSIGN { ary[1]++; }
        | AND_ASSIGN { ary[1]++; }
        | XOR_ASSIGN { ary[1]++; }
        | OR_ASSIGN { ary[1]++; }
        ;

expression
        : assignment_expression
        | expression ',' assignment_expression
        ;

constant_expression
        : conditional_expression
        ;

declaration
        : declaration_specifiers ';'
        | declaration_specifiers init_declarator_list ';' { if(check_int){ ary[2] += id_cnt; check_int = id_cnt = 0; } if(check_char){ ary[3] += id_cnt; check_char = id_cnt = 0; } }

declaration_specifiers
        : storage_class_specifier
        | storage_class_specifier declaration_specifiers
        | type_specifier
        | type_specifier declaration_specifiers
        | type_qualifier
        | type_qualifier declaration_specifiers
        ;

init_declarator_list
        : init_declarator 
        | init_declarator_list ',' init_declarator
        ;

// variables
init_declarator
        : declarator
        | declarator '=' initializer { ary[1]++; }
        ;

storage_class_specifier
        : TYPEDEF
        | EXTERN
        | STATIC
        | AUTO
        | REGISTER
        ;

type_specifier
        : VOID
        | CHAR { check_char = 1; buffer = 0; printf("pin_check_char\n"); }
	| SHORT
        | INT { check_int = 1; buffer = 1; printf("pin_check_int\n"); }
        | LONG
        | FLOAT
        | DOUBLE
        | SIGNED
        | UNSIGNED
        | struct_or_union_specifier
        | enum_specifier
        | TYPE_NAME
        ;

struct_or_union_specifier
        : struct_or_union IDENTIFIER '{' struct_declaration_list '}'
        | struct_or_union '{' struct_declaration_list '}'	
        | struct_or_union IDENTIFIER
        ;

struct_or_union
        : STRUCT
        | UNION
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : specifier_qualifier_list struct_declarator_list ';'
        ;

specifier_qualifier_list
        : type_specifier specifier_qualifier_list
        | type_specifier
        | type_qualifier specifier_qualifier_list
        | type_qualifier
        ;

struct_declarator_list
        : struct_declarator
        | struct_declarator_list ',' struct_declarator
        ;

struct_declarator
        : declarator
        | ':' constant_expression
        | declarator ':' constant_expression
        ;

enum_specifier
        : ENUM '{' enumerator_list '}'
        | ENUM IDENTIFIER '{' enumerator_list '}'
        | ENUM IDENTIFIER
        ;

enumerator_list
        : enumerator
        | enumerator_list ',' enumerator
        ;

enumerator
        : IDENTIFIER
        | IDENTIFIER '=' constant_expression
        ;

type_qualifier
        : CONST
        | VOLATILE
        ;

declarator
        : pointer direct_declarator { ary[4]++; }
        | direct_declarator
        ;

direct_declarator
        : IDENTIFIER { id_cnt++; }
        | '(' declarator ')'
        | direct_declarator '[' constant_expression ']' { ary[5]++; } 
        | direct_declarator '[' ']' { ary[5]++; }
        | direct_declarator '(' parameter_type_list ')' { id_cnt = 0; check_int = check_char = 0; printf("pin_zerop\n"); ary[0]++; }
        | direct_declarator '(' identifier_list ')' { id_cnt = 0; check_int = check_char = 0; printf("pin_zeroi\n"); ary[0]++; }
        | direct_declarator '(' ')' { id_cnt = 0; check_int = check_char = 0; printf("pin_zero\n"); ary[0]++; } 
        ;

pointer
        : '*' 
        | '*' type_qualifier_list
        | '*' pointer
        | '*' type_qualifier_list pointer
        ;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;

parameter_type_list
        : parameter_list 
        | parameter_list ',' ELLIPSIS
        ;

parameter_list
        : parameter_declaration
        | parameter_list ',' parameter_declaration
        ;


parameter_declaration
        : declaration_specifiers declarator { if(buffer){ ary[2]++; }else{ ary[3]++; } } 
        | declaration_specifiers abstract_declarator
        | declaration_specifiers
        ;

identifier_list
        : IDENTIFIER
        | identifier_list ',' IDENTIFIER
        ;

type_name
        : specifier_qualifier_list
        | specifier_qualifier_list abstract_declarator
        ;

abstract_declarator
        : pointer
        | direct_abstract_declarator
        | pointer direct_abstract_declarator
        ;

direct_abstract_declarator
        : '(' abstract_declarator ')'
        | '[' ']' 
        | '[' constant_expression ']'
        | direct_abstract_declarator '[' ']'
        | direct_abstract_declarator '[' constant_expression ']'
        | '(' ')'
        | '(' parameter_type_list ')'
        | direct_abstract_declarator '(' ')'
        | direct_abstract_declarator '(' parameter_type_list ')'
        ;

initializer
        : assignment_expression
        | '{' initializer_list '}'
       	| '{' initializer_list ',' '}'
        ;

initializer_list
        : initializer
        | initializer_list ',' initializer
        ;

statement
     	: labeled_statement
        | compound_statement
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement
        ;

labeled_statement
        : IDENTIFIER ':' statement
        | CASE constant_expression ':' statement
        | DEFAULT ':' statement
        ;

compound_statement
        : '{' '}'
        | '{' statement_list '}'
        | '{' declaration_list '}'
        | '{' declaration_list statement_list '}'
        ;

declaration_list
        : declaration
        | declaration_list declaration
        | declaration_list statement_list
        ;

statement_list
        : statement
        | statement_list statement
        ;

expression_statement
        : ';'
        | expression ';'
        ;

selection_statement
        : IF '(' expression ')' statement { ary[6]++; }
        | IF '(' expression ')' statement ELSE statement { ary[6]++; } 
	| ELIF '(' expression ')' statement 
	| ELIF '(' expression ')' statement ELSE statement 
        | SWITCH '(' expression ')' statement { ary[6]++; }
        ;

iteration_statement
        : WHILE '(' expression ')' statement { ary[7]++; }
        | DO statement WHILE '(' expression ')' ';' { ary[7]++; }
        | FOR '(' expression_statement expression_statement ')' statement { ary[7]++; }
        | FOR '(' expression_statement expression_statement expression ')' statement { ary[7]++; }
	| FOR '(' declaration expression_statement expression ')' statement { ary[7]++; }
	;

jump_statement
        : GOTO IDENTIFIER ';'
        | CONTINUE ';'
        | BREAK ';'
        | RETURN ';' { ary[8]++; }
        | RETURN expression ';' { ary[8]++; }
        ;

header
        : INCLUDE
	| DEFINE
	| header INCLUDE
	| header DEFINE 
        ;

translation_unit
        : external_declaration
        | header external_declaration
        | translation_unit external_declaration
        ;

external_declaration
        : function_definition  
        | declaration
        ;

function_definition
        : declaration_specifiers declarator declaration_list compound_statement
        | declaration_specifiers declarator compound_statement
        | declarator declaration_list compound_statement
        | declarator compound_statement
	;



%%

int main(void)
{
        #if YYDEBUG
                yydebug = 1;
        #endif
        yyparse();
        printf("function = %d\n", ary[0]);
        printf("operator = %d\n", ary[1]);
        printf("int = %d\n", ary[2]);
        printf("char = %d\n", ary[3]);
        printf("pointer = %d\n", ary[4]);
        printf("array = %d\n", ary[5]);
        printf("selection = %d\n", ary[6]);
        printf("loop = %d\n", ary[7]);
        printf("return = %d\n", ary[8]);
        return 0;
}


void yyerror(const char * str){
        fprintf(stderr, "error : %s\n", str);
}




