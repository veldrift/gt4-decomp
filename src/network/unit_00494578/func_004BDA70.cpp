/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x24]; char *table; };
extern "C" int func_004BC868(unsigned char *, const unsigned short *, int) throw();
extern "C" int func_004BDA70(Obj *o, unsigned short code, int off, int flag) {
    unsigned short value;
    int c = code & 0xffff;
    unsigned char *p;
    if (flag == 0) value = 0;
    else value = 0x100;
    int type = c & 0xff00;
    if (type == 0x200) p = *(unsigned char **)((c & 0xff) * 16 + (int)o->table + 0x40) + off;
    else p = *(unsigned char **)((c & 0xff) * 16 + (int)o->table + 0x50) + off;
    func_004BC868(p, &value, 1);
    return 0;
}
