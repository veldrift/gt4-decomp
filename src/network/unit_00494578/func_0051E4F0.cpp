/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Peer { unsigned int id; int pad4; int state; };
struct Conn { int pad0[2]; unsigned int id; int state; char pad10[0x2C]; int count; };
typedef int (*Handler)(Peer *, int, unsigned char *, int);
struct Net { char pad[0x24]; int (*notify)(unsigned int, unsigned int, unsigned char *); char pad28[0x18]; int (*relay)(unsigned int, int, int, unsigned char *, int); };
extern "C" struct Net *D_0064B710;
extern "C" int func_00538F98(unsigned char *, unsigned short *);
extern "C" int func_005390A0(unsigned char *, int *);
extern "C" int func_0051F0F0(Conn *, int, unsigned char *, int);
extern "C" int func_0051EB70(Peer *, int, unsigned char *, int);
extern "C" int func_0051E798(Peer *, int, unsigned char *, int);
extern "C" int func_0051EFD0(Peer *, int, unsigned char *, int);
extern "C" int func_0051EA08(Peer *, int, unsigned char *, int);
extern "C" int func_0051EC08(Peer *, int, unsigned char *, int);
extern "C" int func_0051ED98(Peer *, int, unsigned char *, int);
extern "C" int func_0051EE70(Peer *, int, unsigned char *, int);
extern "C" int func_0051EF10(Peer *, int, unsigned char *, int);
extern "C" int func_0051F0A8(Peer *, int, unsigned char *, int);
extern "C" int func_0051F8B8(Peer *, int, unsigned char *, int);
extern "C" int func_0051E4F0(Peer *peer, Conn *conn, int type, unsigned char *data, int len) {
    int result = 0;
    int forward = (type >> 7) & 1;
    type &= 0x7F;
    int netid = 0;
    if (peer->id != conn->id) return 2;
    if (forward && len) {
        unsigned char *p = data;
        data += 4;
        func_005390A0(p, &netid);
        if (conn->state != 1) return 0xCB30;
        if (netid == 0) return 0xCB31;
        if (type == 3 || type == 27) {
            int port = 0;
            func_00538F98(data, (unsigned short *)&port);
            port = 0xFFFF;
            D_0064B710->relay(peer->id & 0x7FFFFFFF, 0xFFFF, netid, data + 2, len - 2);
        } else {
            D_0064B710->relay(peer->id & 0x7FFFFFFF, 0xFFFF, netid, data, len);
        }
    }
    Handler handler = 0;
    switch (type) {
    case 26: handler = func_0051EB70; break;
    case 6: case 7: handler = func_0051E798; break;
    case 24: handler = func_0051EFD0; break;
    case 25: if (peer->state == 6) handler = func_0051EA08; break;
    case 8: case 9: handler = func_0051EC08; break;
    case 2: case 3: case 10: if (peer->state == 8) handler = func_0051ED98; break;
    case 5: conn->count--; break;
    case 17: handler = func_0051EE70; break;
    case 19: case 27: handler = func_0051EF10; break;
    case 20: D_0064B710->notify(peer->id & 0x7FFFFFFF, peer->id, data); break;
    case 28: handler = func_0051F0A8; break;
    case 29: result = func_0051F0F0(conn, type, data, len); break;
    case 30: handler = func_0051F8B8; break;
    default: result = 4; break;
    }
    if (handler) result = handler(peer, type, data, len);
    return result;
}
