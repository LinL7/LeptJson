#ifndef LEPTJSON_H__
#define LEPTJSON_H__

//JSON 中数据类型
typedef enum {
LEPT_NULL, 
LEPT_FALSE,
LEPT_TRUE,
LEPT_NUMBER,
LEPT_STRING,
LEPT_ARRAY,
LEPT_OBJECT
}lept_type;

//JSON中数据结构
typedef struct {
    lept_type type;
}lept_value;

//JSON解析  
int lept_parse(lept_value* v, const char* json);

//
lept_type lept_get_type(const lept_value* v);

#endif 
