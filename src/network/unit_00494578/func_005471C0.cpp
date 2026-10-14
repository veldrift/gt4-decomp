struct State { unsigned int a,b,c,d,e,f; };
extern "C" void func_005471C0(State *s) {
    unsigned int a = 0x67452301;
    unsigned int b = 0xefcdab89;
    unsigned int c = 0x98badcfe;
    unsigned int d = 0x10325476;
    s->d = d;
    s->a = a;
    s->b = b;
    s->c = c;
    s->e = 0;
    s->f = 0;
}
