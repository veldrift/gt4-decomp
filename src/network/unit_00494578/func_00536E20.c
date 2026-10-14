unsigned func_00535780(int);
void *func_005A48D8(void *, int, unsigned);
void func_005A6AB0(void *, void *, int);
void func_00536F98();
typedef struct Packet { char data[256]; int address[2]; void (*callback)(); } Packet;
typedef struct Ops { char pad[0x68]; int (*open)(Packet *, struct Ops *); char pad6c[0x14]; int (*copy)(void *, void *); } Ops;
extern Ops *D_0064B4B0;
extern int D_0064B500;
int func_00536E20(char *self) {
 Packet packet; Ops *object; int code;
 if (!self) return 23;
 if (!*(int *)(self + 0x110)) return 23;
  func_005A48D8(&packet, 0, 0x10C);
  func_005A6AB0(&packet, self, 0x100);
  D_0064B4B0->copy(packet.address, self + 0x100);
  packet.callback = func_00536F98;
  object = D_0064B4B0;
  code = object->open(&packet, object);
  if (code == 0) D_0064B500 = *(int *)(self + 0x110);
  return func_00535780(code);
}
