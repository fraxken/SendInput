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

VKey is described by the following TypeScript interface:
```ts
type VKey = number | VKCombo;
```

<details><summary>stringToVirtualKeys(str: string): VKey[]</summary>
<br />

Transform a given string to a list of Virtual Keys.
```js
const { deepEqual } = require("assert").strict;
const { stringToVirtualKeys, CONSTANTS: { VK } } = require("sendinput");

const vkList = stringToVirtualKeys("hello");
deepEqual(vkList, [VK.H, VK.E, VK.L, VK.L, VK.O]);
```

> ⚠️ This method may not support all available characters.

</details>

<details><summary>sendVirtualKeys(vks: Array< VKey > | VKey): void</summary>
<br />

Send virtual keys inputs to the keyboard. This method allow to send **one** or **many** inputs.
```js
sendVirtualKeys(VK.A); // a
// or
sendVirtualKeys(new VKCombo(VK.CAPITAL, VK.A)); // A
```

To send many inputs, just send an Array:
```js
sendVirtualKeys([VK.A, new VKCombo(VK.CAPITAL, VK.A)]); // aA
```

</details>

<details><summary>VKCombo(vkL: number, vkR: number)</summary>
<br />

VKCombo is a class that allow you to mix to input together (Most special character are the result of the two keys at the same time).
</details>

## License
MIT
