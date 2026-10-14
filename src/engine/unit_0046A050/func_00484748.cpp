/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Val { int type; char pad[12]; };
struct Node { char pad[0x58]; Node *parent; };
struct Obj { char pad[0x14]; Node *node; };
extern Rep D_00659E20;
extern char D_006ADF70[], D_006AE2F8[];
extern "C" void *func_00476790(Val *, Val *) throw();
extern "C" void func_004768C0(Val *) throw();
extern "C" void func_00477208(Val *, Node *) throw();
extern "C" Val *func_004774F8(Val *, Val *, Str *) throw();
extern "C" void func_00480FE8(Str *) throw();
extern "C" Val *func_00484530(Val *, Obj *, Str *, int, int, int) throw();
extern "C" void free(void *) throw();
extern "C" void func_0057D9C0(const char *, ...);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Node *func_00608FB0(Node *);
extern "C" Str *func_00609BB8(Str *, char *, char *, const char *, const char *);
extern "C" void func_00484748(Obj *self, char *p, int a2, int a3, int a4, char **start, Val *value) {
    Str s;
    Val tmp;
    func_004768C0(value);
    if (*p == '/') {
        Node *n = self->node;
        if (n->parent) n = func_00608FB0(n->parent);
        func_00477208(value,n);
        p++;
    }
    *start = p;
    char c;
    while ((c = *p++) != 0) {
        if ((unsigned)(c - '.') < 2 || c == ':') {
            char *first = *start;
            if (p - first >= 2) {
                Str *ps = &s;
                char *last = p-1;
                char *d;
                if (D_00659E20.sel) d = strobe__toUpper(&D_00659E20);
                else { d = (char *)(&D_00659E20+1); D_00659E20.ref++; }
                ps->p = d;
                func_00609BB8(ps,d,d+((Rep *)d)[-1].len,first,last);
                func_00480FE8(&s);
                if ((value->type ^ 1) == 0) {
                    func_00484530(&tmp,self,&s,a2,a3,a4);
                    func_00476790(value,&tmp);
                    func_004768C0(&tmp);
                } else {
                    func_004774F8(&tmp,value,&s);
                    func_00476790(value,&tmp);
                    func_004768C0(&tmp);
                }
                if ((value->type ^ 1) == 0) {
                    const char *text;
                    int len = ((Rep *)s.p)[-1].len;
                    if (len == 0) text = D_006ADF70;
                    else { s.p[len] = 0; text = s.p; }
                    func_0057D9C0(D_006AE2F8,text);
                }
                Rep *r = (Rep *)(s.p - 16);
                if (--r->ref == 0) free(r);
            }
            *start = p;
        }
    }
}
