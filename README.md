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

## Practical Example: Windows Process Manager in JavaScript

Steps to build a Node.js project using the `node-addon-api` to manage Windows processes, including process checks and termination methods.

## Building and Using the Addon

Detailed instructions are provided for setting up `node-gyp`, writing `binding.gyp`, and implementing and building the C++ Addon to interact with system-level features using Node.js.

## Example Usage

The document includes JavaScript code examples that demonstrate how to interact with the built C++ Addon for managing processes, such as checking if a process is running and terminating it.

## Conclusion

This guide serves as an introduction to extending Node.js capabilities using C++ Addons, focusing on practical implementation and real-world application scenarios.

## References

- Node.js Official Addons Documentation: [Node.js API Addons](https://nodejs.org/api/addons.html)
- node-addon-api GitHub Repository: [node-addon-api](https://github.com/nodejs/node-addon-api)

