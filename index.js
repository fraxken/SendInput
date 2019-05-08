const { sendinput } = require("node-gyp-build")(__dirname);

setTimeout(() => {
    sendinput("h");
    sendinput("e");
    sendinput("5");
    sendinput("1");
    sendinput("o");
}, 2000);
