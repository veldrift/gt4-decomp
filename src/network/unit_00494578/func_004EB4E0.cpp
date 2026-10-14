/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len,cap,ref,sel; };
struct Str;
extern Rep D_00659E20;
extern char D_006BFFD0[], D_006BFF30[], D_006C0190[];
extern "C" char *strobe__toUpper(Rep *);
extern "C" void free(void *) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_005A5AD8(const char *,const char *,...) throw();
extern "C" Str *func_0060DC18(Str *,u32,u32,const Str *,u32,u32);
extern "C" Str *func_00605888(Str *,u32,u32,u32,char);
extern "C" u32 func_0060DEE0(const Str *,const char *,u32,u32);
struct Str {
    char *data; char pad[12];
    Rep *rep() const { return (Rep *)data - 1; }
    int length() const { return rep()->len; }
    const char *c_str() const {
        if (!rep()->len) return D_006BFF30;
        data[rep()->len] = 0;
        return data;
    }
};
struct Obj { char pad0[16]; int (*cb)(const char *,int,void *); void *ctx; char pad18[0x3c]; Str s; char pad64[0x70]; int chunk,done,left,total,read,time; };
static inline int min(int a,int b) { return a < b ? a : b; }
extern "C" int func_004EB4E0(Obj *o) {
    if (o->chunk && !o->done) {
        const char *token = D_006BFFD0;
        int start = o->left;
        start += 2;
        Str *s = &o->s;
        unsigned pos = func_0060DEE0(s,token,start,func_0057F260(token));
        if (pos != (u32)-1) {
            unsigned n = pos - o->left - 2;
            int substart = o->left + 2;
            Str tmp;
            Str *p = &tmp;
            Rep *r = &D_00659E20;
            char *d;
            if (r->sel) d = strobe__toUpper(r);
            else { d = (char *)(r+1); ++r->ref; }
            p->data = d;
            func_0060DC18(p,0,-1,s,substart,n);
            func_00605888(s,o->left,pos-o->left+2,0,0);
            int amount;
            func_005A5AD8(tmp.c_str(),D_006C0190,&amount);
            o->left += amount;
            o->read += amount;
            if (!amount) o->done = 1;
            Rep *q = tmp.rep();
            if (--q->ref == 0) free(q);
        }
    }
    if (o->cb && o->time < 400) {
        Str *s = &o->s;
        const char *text = s->c_str();
        if (o->cb(text,o->s.length(),o->ctx)) {
            int len = s->length();
            int n;
            if (o->chunk) {
                n = min(o->left,len);
                o->left -= n;
            } else {
                n = min(o->total,len);
                o->total -= n;
            }
            func_00605888(s,0,n,0,0);
        }
    }
    if (o->chunk) {
        if (!o->done) return 0;
        return o->s.length() >= o->left;
    }
    return o->s.length() >= o->total;
}
