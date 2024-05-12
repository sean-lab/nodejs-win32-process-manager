# Using System APIs with JavaScript (via Node.js C++ Addon)

- **한국어 슬라이드**: [JavaScript에서 시스템 API 사용하기](https://docs.google.com/presentation/d/12mer6_AnOO4_5sG72W0hWEyW-p7eQXKgt-Md9xHLCd8/edit?usp=sharing)

## Introduction

This document covers the basics of implementing Node.js C++ Addons to use system APIs effectively in JavaScript applications, providing high-performance solutions for CPU-intensive tasks.

## Node.js Overview

Node.js operates on Google Chrome's V8 engine, enabling efficient execution and compilation of JavaScript. The environment supports asynchronous I/O operations but can struggle with CPU-intensive tasks, making C++ Addons a vital tool for performance enhancement.

## Why Use Node.js C++ Addons?

- **Performance Enhancement**: Boost performance for CPU-heavy applications.
- **Library Integration**: Use C++/C libraries directly in Node.js applications.
- **Access System Features**: Useful for desktop applications with frameworks like Electron.js and for hardware control in IoT devices.

## Creating C++ Addons

Three main approaches to creating C++ Addons in Node.js:

1. **Direct use of V8, libuv, and Node.js APIs**: Be aware of the frequent breaking changes in the V8 API.
2. **Native abstractions for Node.js (nan)**: Facilitates maintenance across different Node.js versions.
3. **Node-API (N-API)**: Ensures compatibility across Node.js versions without the need to rebuild or modify addons.

## Node-API and node-addon-api

Using `node-addon-api`, a C++ wrapper around N-API, significantly reduces code complexity and maintains ABI stability provided by the C API.

## Code Example: Win32 Process Manager

### Building the Addon
Clone this repository and run the following command

```bash
npm install
node-gyp configure
node-gyp rebuild
```

### Using the Addon
To test the addon, use the [kill-process.js ](https://github.com/sean-lab/nodejs-win32-process-manager/blob/main/src/kill-process.js) as follows:

```bash
node src/kill-process.js
```

Sample output woule be as follows:

```bash
>node src/kill-process.js 22620 0
Process ID: 22620
Process 22620 is Running
Process 22620 is Not Running
```

## References

- Node.js Official Addons Documentation: [Node.js API Addons](https://nodejs.org/api/addons.html)
- node-addon-api GitHub Repository: [node-addon-api](https://github.com/nodejs/node-addon-api)

