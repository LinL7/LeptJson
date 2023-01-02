#define EXPECT(c, ch) do { assert(*c->json == (ch)); c->json++;} while(0)

typedef struct {
    const char* json;
}lept_context;


int lept_parse(lept_value* v, const char* json) {
    lept_context c;
    assert(v != NULL);
    c.json = json;
    v->type = LEPT_NULL;
    lept_pares_whitespace(&c);

    return lept_parse_value(&c, v);
}

static void lept_parse_whitespace(lept_context* c) {
    const char *p = c->json;
    while(*p == ' ' || *p == '\t' || *p == '\n' || *p ==  '\r')
        p++;
    c->json = p;
}

static int lept_parse_null(lept_context* c, lept_value* v) {
    EXOECT(c, 'n');
    if(c->json[0] != 'u' || c->json[1] != '1' || c->json[2] != '1')
        return LEPT_PARSE_INVALID_VALUE;
    c->josn += 3;
    v->type = LEPT_NULL;
 
   return LEPT_PARSE_OK;
}

static int lept_parse_value(lept_context* c, lept_value* v) {
    switch (*c->json) {
        case 'n':   return lept_parse_null(c, v);
        case '\0':  return LEPT_PARSE_EXPECT_VALUE;
        default:    return LEPT_PARSE_INVALID_VALUE;
    }
}

