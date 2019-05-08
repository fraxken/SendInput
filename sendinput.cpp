#define WINVER 0x0500
#include <windows.h>
#include "napi.h"

Napi::Value TriggerKey(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    INPUT ip;

    // Get key code
    int32_t code = info[0].As<Napi::Number>().Int32Value();

    // Configure IP
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = code;
    ip.ki.dwFlags = 0;

    SendInput(1, &ip, sizeof(INPUT));

    // Release Key
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "sendinput"), Napi::Function::New(env, TriggerKey));

    return exports;
}

// Export Addon as sendinput
NODE_API_MODULE(sendinput, Init)
