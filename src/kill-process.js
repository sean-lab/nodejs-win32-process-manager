const pssAddon = require('../build/Release/process-addon');

try {
    const args = process.argv.slice(2);
    const pid = parseInt(args[0]);
    const exitCode = parseInt(args[1]); // 0: Success, 1: Failure

    console.log(`Process ID: ${pid}`);
    console.log(`Process ${pid} is`, pssAddon.isRunning(pid) ? 'Running' : 'Not Running');
    pssAddon.kill(pid, exitCode);
    console.log(`Process ${pid} is`, pssAddon.isRunning(pid) ? 'Running' : 'Not Running');
} catch (error) {
    console.log(error);
}
