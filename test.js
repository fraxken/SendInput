const { sendVirtualKeys, CONSTANTS: { VK } } = require("./");

setTimeout(() => {
    sendVirtualKeys([
        VK.H, VK.E, VK.L, VK.L, VK.O
    ]);
}, 2000);
