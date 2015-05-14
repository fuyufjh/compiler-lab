#ifndef _SYMBOL_TYPE_H
#define _SYMBOL_TYPE_H

struct symbol {
    char* name;
    struct var_type *type;
};

struct var_type {
    enum { BASIC, ARRAY, STRUCTURE, FUNCTION } kind;
    union {
        int basic;
        struct {
            struct var_type *elem;
            int size;
        } array;
        //struct field_list *fields;
        struct struct_type* struct_type;
        struct {
            struct var_type* ret;
            struct func_param_list *params;
        } func;
    };
};

struct struct_symbol {
    char *name;
    struct struct_type *type;
};

struct struct_type {
    struct field_list *fields;
};

struct field_list {
    char *name;
    struct var_type *type;
    struct field_list *tail;
};

struct func_param_list {
    struct var_type *type;
    struct func_param_list *tail;
};

#endif
