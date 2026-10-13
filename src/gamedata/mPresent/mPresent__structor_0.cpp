// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mPresent:hObject {void* const data;mPresent(void*) __asm__("func_001A0268");virtual ~mPresent();};
mPresent::mPresent(void* value):data(value){}
