const { sendVirtualKeys, stringToVirtualKeys, CONSTANTS: { VK } } = require("./");

const vks = stringToVirtualKeys("hello world!");
console.log(vks);
setTimeout(() => {
    sendVirtualKeys(vks);
}, 2000);
