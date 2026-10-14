struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Reader { void *vt; void *dst; char pad[8]; };
struct Vec { float x,y,z; };
union Temp { Str s; Reader r; Vec v; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char MstringReader__vtable[], MboolReader__vtable[], MintReader__vtable[];
extern "C" char *func_005C2560(Rep *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *, unsigned, unsigned, const char *, unsigned);
extern "C" int mSlideShowFace__virtual_61(void *, void *);
extern "C" int func_0020FD38(void *, Str *, Reader *);
extern "C" void MReaderBase__structor_0(Reader *, int);
extern "C" Str *func_0020FE28(Str *, void *, Str *);
extern "C" int MVector3Reader__structor_0(Reader *, void *);
extern "C" void MVector3Reader__structor_1(Reader *, int);
extern "C" void func_0021A828(char *, Vec *);
extern "C" void func_0021A858(char *, Vec *);
extern "C" int MfloatReader__structor_1(char *, void *);
extern "C" int MboolReader__structor_3(char *, void *);
static inline void init(Str *s) {
    Rep *r = &D_00659FA8;
    char *p;
    if (r->sel) p = func_005C2560(r);
    else { p = (char *)(r+1); ++r->ref; }
    s->p = p;
}
static inline void key(Str *s, const char *text) {
    init(s);
    func_005C2630(s, 0, -1, text, func_0057F260(text));
}
static inline void release(Str *s) {
    Rep *r = (Rep *)(s->p - 16);
    if (--r->ref == 0) {
        int cap = r->cap + 16;
        func_00326798(r, cap, 4, func_005C11A8()->name);
    }
}
static inline int read(void *event, Str *key, Reader *r, void *dst, void *vt) {
    r->vt = vt; r->dst = dst;
    int found = func_0020FD38(event, key, r);
    r->vt = vt; MReaderBase__structor_0(r, 0);
    return found;
}
extern char D_0069C308[];
extern "C" void func_002BE800(char *, Str *);
extern char D_0069C318[];
extern "C" void func_002BE908(char *, int);
extern char D_0069C328[];
extern "C" void func_002BE938(char *, int);
extern char D_0069C340[];
extern "C" void func_002BE968(char *, int);
extern char D_0069C350[];
extern "C" void func_002BE9E8(char *, Str *);
extern char D_0069C360[];
extern "C" void func_002BEAE0(char *, int);
extern char D_0069C370[];
extern "C" void func_002BEB10(char *, int);
extern char D_0069C388[];
extern "C" void func_002BEB40(char *, int);
extern char D_0069C398[];
extern "C" void func_002BEB68(char *, Str *);
extern char D_0069C3B0[];
extern char D_0069C2A0[];
extern char D_0069C2B8[];
extern char D_0069C2D8[];
extern "C" int MboolReader__structor_13(char *self, void *event) {
    Str value;
    Temp a;
    Reader first;
    Str x;
    int flag[4];
    Temp b;
    Str y;
    Str z;
    Temp c;
    Temp *pa, *pb, *pc;
    if (mSlideShowFace__virtual_61(self, event)) return 1;
    init(&value);
    // block 1
    {
        pa = &a;
        key(&pa->s, D_0069C308);
        Reader *reader = &first;
        reader->vt = MstringReader__vtable;
        first.dst = &value;
        int found = func_0020FD38(event, &pa->s, reader);
        reader->vt = MstringReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pa->s);
        if (found) {
            Str *p = &x;
            func_0020FE28(p, event, &value);
            func_002BE800(self, p);
            release(p);
            release(&value);
            return 1;
        }
    }
    // block 2
    {
        key(&pa->s, D_0069C318);
        pb = &b;
        Reader *reader = &pb->r;
        reader->vt = MboolReader__vtable;
        b.r.dst = flag;
        int found = func_0020FD38(event, &pa->s, reader);
        reader->vt = MboolReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pa->s);
        if (found) {
            func_002BE908(self, flag[0]);
            release(&value);
            return 1;
        }
    }
    // block 3
    {
        key(&pb->s, D_0069C328);
        Reader *reader = &pa->r;
        reader->vt = MboolReader__vtable;
        a.r.dst = flag;
        int found = func_0020FD38(event, &pb->s, reader);
        reader->vt = MboolReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pb->s);
        if (found) {
            func_002BE938(self, flag[0]);
            release(&value);
            return 1;
        }
    }
    // block 4
    {
        key(&pb->s, D_0069C340);
        Reader *reader = &pa->r;
        reader->vt = MboolReader__vtable;
        a.r.dst = flag;
        int found = func_0020FD38(event, &pb->s, reader);
        reader->vt = MboolReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pb->s);
        if (found) {
            func_002BE968(self, flag[0]);
            release(&value);
            return 1;
        }
    }
    // block 5
    {
        key(&pb->s, D_0069C350);
        Reader *reader = &pa->r;
        reader->vt = MstringReader__vtable;
        a.r.dst = &value;
        int found = func_0020FD38(event, &pb->s, reader);
        reader->vt = MstringReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pb->s);
        if (found) {
            Str *p = &y;
            func_0020FE28(p, event, &value);
            func_002BE9E8(self, p);
            release(p);
            release(&value);
            return 1;
        }
    }
    // block 6
    {
        key(&pb->s, D_0069C360);
        Reader *reader = &pa->r;
        reader->vt = MboolReader__vtable;
        a.r.dst = flag;
        int found = func_0020FD38(event, &pb->s, reader);
        reader->vt = MboolReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pb->s);
        if (found) {
            func_002BEAE0(self, flag[0]);
            release(&value);
            return 1;
        }
    }
    // block 7
    {
        key(&pb->s, D_0069C370);
        Reader *reader = &pa->r;
        reader->vt = MboolReader__vtable;
        a.r.dst = flag;
        int found = func_0020FD38(event, &pb->s, reader);
        reader->vt = MboolReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pb->s);
        if (found) {
            func_002BEB10(self, flag[0]);
            release(&value);
            return 1;
        }
    }
    // block 8
    {
        key(&pb->s, D_0069C388);
        Reader *reader = &pa->r;
        reader->vt = MboolReader__vtable;
        a.r.dst = flag;
        int found = func_0020FD38(event, &pb->s, reader);
        reader->vt = MboolReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pb->s);
        if (found) {
            func_002BEB40(self, flag[0]);
            release(&value);
            return 1;
        }
    }
    // block 9
    {
        key(&pb->s, D_0069C398);
        Reader *reader = &pa->r;
        reader->vt = MstringReader__vtable;
        a.r.dst = &value;
        int found = func_0020FD38(event, &pb->s, reader);
        reader->vt = MstringReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pb->s);
        if (found) {
            Str *p = &z;
            func_0020FE28(p, event, &value);
            func_002BEB68(self, p);
            release(p);
            release(&value);
            return 1;
        }
    }
    // block 10
    {
        key(&pb->s, D_0069C3B0);
        Reader *reader = &pa->r;
        void *quality = self + 0x2E0;
        reader->vt = MintReader__vtable;
        a.r.dst = quality;
        int found = func_0020FD38(event, &pb->s, reader);
        reader->vt = MintReader__vtable;
        MReaderBase__structor_0(reader, 0);
        release(&pb->s);
        if (found) {
            release(&value);
            return 1;
        }
    }
    // block 11
    {
        key(&pa->s, D_0069C2A0);
        pc = &c;
        MVector3Reader__structor_0(&pc->r, &pb->v);
        int found = func_0020FD38(event, &pa->s, &pc->r);
        MVector3Reader__structor_1(&pc->r, 2);
        release(&pa->s);
        if (found) {
            func_0021A828(self + 0xA0, &pb->v);
            release(&value);
            return 1;
        }
    }
    // block 12
    {
        key(&pc->s, D_0069C2B8);
        MVector3Reader__structor_0(&pa->r, &pb->v);
        int found = func_0020FD38(event, &pc->s, &pa->r);
        MVector3Reader__structor_1(&pa->r, 2);
        release(&pc->s);
        if (found) {
            func_0021A858(self + 0xA0, &pb->v);
            release(&value);
            return 1;
        }
    }
    // block 13
    {
        key(&pc->s, D_0069C2D8);
        MVector3Reader__structor_0(&pa->r, self + 0x2FC);
        int found = func_0020FD38(event, &pc->s, &pa->r);
        MVector3Reader__structor_1(&pa->r, 2);
        release(&pc->s);
        if (found) {
            release(&value);
            return 1;
        }
    }
    if (MfloatReader__structor_1(self + 0xEC, event)) { release(&value); return 1; }
    if (MboolReader__structor_3(self + 0x154, event)) { release(&value); return 1; }
    release(&value);
    return 0;
}
