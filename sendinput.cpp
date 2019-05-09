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

Napi::Value TriggerDoubleKey(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    INPUT ip_first;
    INPUT ip_second;

    // Get key(s) code
    int32_t code_first = info[0].As<Napi::Number>().Int32Value();
    int32_t code_second = info[1].As<Napi::Number>().Int32Value();

    // Configure First Key
    ip_first.type = INPUT_KEYBOARD;
    ip_first.ki.wScan = 0;
    ip_first.ki.time = 0;
    ip_first.ki.dwExtraInfo = 0;
    ip_first.ki.wVk = code_first;
    ip_first.ki.dwFlags = 0;

    // Configure Second Key
    ip_second.type = INPUT_KEYBOARD;
    ip_second.ki.wScan = 0;
    ip_second.ki.time = 0;
    ip_second.ki.dwExtraInfo = 0;
    ip_second.ki.wVk = code_second;
    ip_second.ki.dwFlags = 0;

    SendInput(1, &ip_first, sizeof(INPUT));
    SendInput(1, &ip_second, sizeof(INPUT));

    // Release Key(s)
    ip_first.ki.dwFlags = KEYEVENTF_KEYUP;
    ip_second.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip_second, sizeof(INPUT));
    SendInput(1, &ip_first, sizeof(INPUT));

    return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "sendinput"), Napi::Function::New(env, TriggerKey));
    exports.Set(Napi::String::New(env, "doubleinput"), Napi::Function::New(env, TriggerDoubleKey));

    return exports;
}

// Export Addon as sendinput
NODE_API_MODULE(sendinput, Init)
