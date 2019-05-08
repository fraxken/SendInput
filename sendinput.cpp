#define WINVER 0x0500
#include <windows.h>
#include <iostream>
#include "napi.h"

Napi::Value Input(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    INPUT ip;
    HKL kbl = GetKeyboardLayout(0);

    std::string key = info[0].As<Napi::String>().Utf8Value();
    // TODO: key must be a string with one charac (a char).
    const char* charKey = key.c_str();

    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = VkKeyScanExA(charKey[0], kbl);
    ip.ki.dwFlags = 0;

    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "sendinput"), Napi::Function::New(env, Input));

    return exports;
}

// Export Addon as sendinput
NODE_API_MODULE(sendinput, Init)
