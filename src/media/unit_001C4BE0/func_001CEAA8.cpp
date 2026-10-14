/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef unsigned int u32; typedef unsigned char u8;
extern "C" void free(int) throw();
extern "C" char *func_00575E60(int, unsigned);
extern "C" char *func_005CDD50(char *, unsigned, const char *);
struct Vec {
 int allocator; char *first,*last,*limit; char spare[16];
 char *begin() {return first;}
 unsigned size() {return last-first;}
};
static inline int get(const int &v) {return v;}
static inline char *init(Vec *v,unsigned n) {
 v->first=0; v->last=0;v->limit=0;
 char *p=n ? func_00575E60(64,n) : 0;
 v->first=p; v->last=p;v->limit=p+n;
 return p;
}
struct VE0 { short off; short pad; s32 (*fn)(void *); };
struct VE1 { short off; short pad; void (*fn)(void *, void *); };
struct VE5 { short off; short pad; s32 (*fn)(void *, void *, void *, s32, s32); };
struct Stream { char *vtbl; };
struct Obj {
    char pad0[0x7D08];
    Stream stream;
    char pad7D0C[0x81C8 - 0x7D0C];
    s32 f81C8;
    s32 f81CC;
};

extern "C" s32 func_004359A8(void *);
extern "C" void func_00435630(void *);
extern "C" s32 func_001CE868(void *, void *, void *, s32, s32) throw();
extern "C" char *func_001CE460(void *, char *) throw();
extern "C" unsigned long func_00578560(void);
extern "C" u32 func_00572C90(void *, u32);
extern "C" int func_005792E8(void *, s32);
extern "C" u32 func_00579330(void *);
extern "C" void func_00579420(void *, s32);
extern "C" u32 func_005794C0(void *);
extern "C" void func_001D4B78(void *, s32, void *);

extern "C" s32 func_001CEAA8(void *arg0, Stream *arg1, Obj *arg2, s32 arg3) {
    s32 st[4];
    s32 ret = func_004359A8(arg2);
    if (ret != 0) {
        func_00435630(arg2);
        ret = func_001CE868(arg0, arg1, arg2, arg3, 0);
        st[0] = ret;
        if (ret != 0) return ret;
        {
            char buf[0x50];
            func_001CE460(arg0, buf);
            Vec v;
            char mt0[0x10];
            char mt1[0x9D0];
            char zero;
            int key = arg2->f81CC;
            int inc_copy;
            s32 inc = arg2->f81C8;
            if (inc >= 0) {
            inc_copy=inc;
            Stream *stream = &arg2->stream;
            VE0 *e = (VE0 *)(stream->vtbl + 0x10);
            u32 size = e->fn((char *)stream + e->off);
            u32 n = (size + 0x47) & ~0x3F;
            Vec *pv=&v;
            char *data=init(pv,n);
            *(char **)mt0=data;
            zero=0;
            pv->last=func_005CDD50(data,n,&zero);
            u32 i=0;
            u32 *hdr = (u32 *)v.begin();
            s32 seed = (s32)(func_00578560() & 0xFFFFFFFFUL);
            VE1 *e1 = (VE1 *)(stream->vtbl + 0x28);
            e1->fn((char *)stream + e1->off, (u8 *)hdr + 8);
            u32 checksum=func_00572C90((u8 *)hdr + 8, size);
            hdr[0] = seed;
            hdr[1] = checksum;
            func_00579420(mt1, key ^ seed);
            func_005792E8(mt0, hdr[1]);
            u32 cnt = (v.size() - 8) >> 2;
            if(cnt) {
            u32 *p = (u32 *)((u8 *)hdr + 8);
            do {
                i++;
                s32 w = *p ^ func_005794C0(mt1);
                *p = w - func_00579330(mt0);
                p++;
            } while(i<cnt);
            }
            func_00579420(mt1, key + inc);
            func_001D4B78(v.begin(), v.size(), mt1);
            VE5 *e5 = (VE5 *)(arg1->vtbl + 0x88);
            if (e5->fn((char *)arg1 + e5->off, buf, v.begin(), v.size(), inc_copy * v.size() + 0x40)) {
                if (v.first) free((int)v.first);
                return 1;
            }
            if (v.first) free((int)v.first);
        }
        }
        return 0;
    }
    return ret;
}
