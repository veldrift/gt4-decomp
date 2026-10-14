/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int a,b; unsigned int c; };
struct Stream { unsigned int base,end,pos; };
extern "C" void func_0045B678(Block *,Stream *) throw();
extern "C" void func_0045B740(Block *,Stream *) throw();
static inline bool eof(Stream *s) { return s->pos >= s->end; }
extern "C" Block *func_0045B7B0(Block *out,Stream *s,int tag) {
    Block b;
    b.c=0;
    b.b=-1;
    b.a=0;
    while(!eof(s)) {
        func_0045B678(&b,s);
        if(b.a==tag) {
            *out=b;
            goto done;
        }
        if(b.c<8) {
            out->b=-1;
            out->c=0;
            goto clear;
        }
        func_0045B740(&b,s);
    }
    out->c=0;
    out->b=-1;
clear:
    out->a=0;
done:
    return out;
}
