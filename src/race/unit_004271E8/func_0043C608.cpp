struct __attribute__((packed)) Packet {
    unsigned long word;
    signed char byte8, byte9, byteA;
};
struct Source { char unknown[0x10]; Packet packet; };
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" char *func_0043C608(Source *source, char *destination) {
    func_005A48D8(destination, 0, 12);
    *(Packet *)destination = source->packet;
    return destination + 12;
}
