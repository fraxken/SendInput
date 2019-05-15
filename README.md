# sendinput
![version](https://img.shields.io/badge/version-1.0.0-blue.svg)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/SlimIO/is/commit-activity)
![MIT](https://img.shields.io/github/license/mashape/apistatus.svg)

Node.js C++ binding of SendInput method. (**WIP**)

## Requirements
- Node.js v10 or higher

## Getting Started

This package is available in the Node Package Repository and can be easily installed with [npm](https://docs.npmjs.com/getting-started/what-is-npm) or [yarn](https://yarnpkg.com).

```bash
$ npm i sendinput
# or
$ yarn add sendinput
```

## Usage example
```js
const { sendVirtualKeys, stringToVirtualKeys, VKCombo, CONSTANTS: { VK } } = require("sendinput");

setTimeout(() => {
    // Send 'hello' to the keyboard
    sendVirtualKeys([new VKCombo(VK.CAPITAL, VK.H), VK.E, VK.L, VK.L, VK.O]);

    // or use stringToVirtualKeys
    sendVirtualKeys(stringToVirtualKeys("Hello"));
}, 2000);
```

## API

VKey is described as follow:
```ts
type VKey = number | VKCombo;
```

### stringToVirtualKeys(str: string): VKey[];
Transform a given string to a list of Virtual Keys.

> ⚠️ This method may not be complete

### sendVirtualKeys(vks: Array<VKey> | VKey): void
Send virtual keys inputs to the keyboard. This method allow to send one or many inputs.
```js
sendVirtualKeys(VK.A);
```

Or send a VKCombo
```js
sendVirtualKeys(new VKCombo(VK.CAPITAL, VK.A));
```

### VKCombo
VKCombo is a class that allow you to mix to input together (Most special character are the result of the two keys at the same time).

## License
MIT
