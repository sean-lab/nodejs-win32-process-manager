#include <napi.h>

class ProcessAddon : public Napi::Addon<ProcessAddon> {
 public:
  ProcessAddon(Napi::Env env, Napi::Object exports);

 private:
  /* 
  * Check if a process is running by its PID
  * 
  * @param {number} pid - The process ID
  * @returns {boolean} - True if the process is running, false otherwise
  */
  Napi::Value IsRunning(const Napi::CallbackInfo& info);
  
  /* 
  * Kill a process by its PID
  * 
  * @param {number} pid - The process ID
  * @param {number} exitCode - The exit code to return to the parent process: 0 for success, 1 for failure
  * @returns {undefined} (void)
  */
  Napi::Value Kill(const Napi::CallbackInfo& info);
};