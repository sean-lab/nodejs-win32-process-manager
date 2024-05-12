#include "process-addon.h"
#include <windows.h>

ProcessAddon::ProcessAddon(Napi::Env env, Napi::Object exports) {
  DefineAddon(exports,
                {
                  InstanceMethod("kill", &ProcessAddon::Kill, napi_enumerable),
                  InstanceMethod("isRunning", &ProcessAddon::IsRunning, napi_enumerable)});
}

Napi::Value ProcessAddon::IsRunning(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Expected a number as argument").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    int pid = info[0].As<Napi::Number>().Int32Value();
    
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
    if (hProcess == NULL) {
        return Napi::Boolean::New(env, false);
    }
    
    DWORD exitCode;
    if (GetExitCodeProcess(hProcess, &exitCode) == FALSE) {
        Napi::Error::New(env, "Could not get process exit code").ThrowAsJavaScriptException();
    }
    
    if (CloseHandle(hProcess) == FALSE) {
        Napi::Error::New(env, "Could not close process handle").ThrowAsJavaScriptException();
    }
    
    return Napi::Boolean::New(env, exitCode == STILL_ACTIVE);
}

Napi::Value ProcessAddon::Kill(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Expected numbers as arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    int pid = info[0].As<Napi::Number>().Int32Value();    
    int exitCode = info[1].As<Napi::Number>().Int32Value();    
    
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
    if (hProcess == NULL) {
        Napi::Error::New(env, "Could not open process").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    if (TerminateProcess(hProcess, exitCode) == FALSE) {        
        Napi::Error::New(env, "Could not terminate process").ThrowAsJavaScriptException();
        return env.Undefined();
    }
    
    if (CloseHandle(hProcess) == FALSE) {
        Napi::Error::New(env, "Could not close process handle").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    return env.Undefined();
}

NODE_API_ADDON(ProcessAddon)