// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mRunViewer:hObject {void* const data;mRunViewer(void*) __asm__("func_001A7908");virtual ~mRunViewer();};
mRunViewer::mRunViewer(void* value):data(value){}
