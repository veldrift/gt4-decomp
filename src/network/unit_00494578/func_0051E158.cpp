struct Message { unsigned type, kind, length, pending; char data[512]; };
struct Owner { char pad[0x44]; int dirty, kind; char pad2[0x84-0x4C]; Message message; };
extern "C" int func_0051FE10(Owner *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_0051E158(Owner *self, unsigned type, int kind, const void *data, unsigned length, int mark) {
    if (!data && length) return 2;
    if (length > 512) return 2;
    Message *msg = &self->message;
    int compatible;
    if (msg->pending) {
        compatible = 0;
        if ((unsigned)(type - 2) < 2 && msg->type == type && msg->kind == (unsigned)kind) {
            compatible = 1;
            if (msg->length + length > 512) compatible = 0;
        }
    } else compatible = 1;
    if (!compatible) {
        int status = func_0051FE10(self);
        if (status) return status;
    }
    msg->type = type;
    msg->kind = kind;
    func_005A4724((char *)msg + msg->length + 0x10, data, length);
    msg->length += length;
    msg->pending++;
    if ((unsigned)(type - 2) >= 2) func_0051FE10(self);
    if (mark) {
        if (self->dirty && self->kind != 0xFFFF) {
            if (self->kind != kind) {
                if (kind != 0xFFFF) self->kind = 0xFFFE;
            }
        } else self->kind = kind;
        self->dirty = 1;
    }
    return 0;
}
