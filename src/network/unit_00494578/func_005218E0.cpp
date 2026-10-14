typedef unsigned char u8;
typedef unsigned short u16;
extern "C" int func_00538EC8(u8 *, int);
extern "C" int func_00539160(void *, unsigned int);
extern u16 D_0064B440;
struct Obj { char pad[0x14]; u8 data[0x200]; int size; u16 id; };
extern "C" int func_005218E0(Obj *obj, char *name) {
    int pos = 13;
    int len = 0;
    int start = 12;
    u16 i = 1;
    u8 *data = obj->data;
    u16 id = D_0064B440;
    D_0064B440 = id + 1;
    obj->id = id;
    func_00539160(data, obj->id);
    func_00539160(data + 2, 0x100);
    func_00539160(data + 4, 1);
    func_00539160(data + 6, 0);
    func_00539160(data + 8, 0);
    func_00539160(data + 10, 0);
    do {
        if (*name == '.') {
            func_00538EC8(data + start, (u8)len);
            start = pos;
            len = 0;
            pos++;
        } else if (*name == 0) {
            func_00538EC8(data + start, (u8)len);
            func_00538EC8(data + pos++, 0);
            break;
        } else {
            func_00538EC8(data + pos++, (u8)*name);
            len++;
        }
        i++;
        name++;
    } while (i < 256);
    func_00539160(data + pos, 1);
    pos += 2;
    func_00539160(data + pos, 1);
    pos += 2;
    obj->size = pos;
    return 0;
}
