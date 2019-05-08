const { sendinput } = require("node-gyp-build")(__dirname);

// CONSTANTS
const VK = Object.freeze({
    MOUSE_LEFT: 0x01,
    MOUSE_RIGHT: 0x02,
    CANCEL: 0x03,
    MOUSE_MID: 0x04,
    MOUSE_X1: 0x05,
    MOUSE_X2: 0x06,
    BACK: 0x08,
    TAB: 0x09,
    CLEAR: 0x0C,
    RETURN: 0x0D,
    SHIFT: 0x10,
    CONTROL: 0x11,
    MENU: 0x12,
    PAUSE: 0x13,
    CAPITAL: 0x14,
    KANA: 0x15,
    HANGUEL: 0x15,
    HANGUL: 0x15,
    JUNJA: 0x17,
    FINAL: 0x18,
    HANJA: 0x19,
    KANJI: 0x19,
    ESCAPE: 0x1B,
    CONVERT: 0x1C,
    NONCONVERT: 0x1D,
    ACCEPT: 0x1E,
    MODECHANGE: 0x1F,
    SPACE: 0x20,
    PRIOR: 0x21,
    NEXT: 0x22,
    END: 0x23,
    HOME: 0x24,
    ARROW_LEFT: 0x25,
    ARROW_UP: 0x26,
    ARROW_RIGHT: 0x27,
    ARROW_DOWN: 0x28,
    SELECT: 0x29,
    PRINT: 0x2A,
    EXECUTE: 0x2B,
    SNAPSHOT: 0x2C,
    INSERT: 0x2D,
    DELETE: 0x2E,
    HELP: 0x2F,
    0: 0x30,
    1: 0x31,
    2: 0x32,
    3: 0x33,
    4: 0x34,
    5: 0x35,
    6: 0x36,
    7: 0x37,
    8: 0x38,
    9: 0x39,
    A: 0x41,
    B: 0x42,
    C: 0x43,
    D: 0x44,
    E: 0x45,
    F: 0x46,
    G: 0x47,
    H: 0x48,
    I: 0x49,
    J: 0x4A,
    K: 0x4B,
    L: 0x4C,
    M: 0x4D,
    N: 0x4E,
    O: 0x4F,
    P: 0x50,
    Q: 0x51,
    R: 0x52,
    S: 0x53,
    T: 0x54,
    U: 0x55,
    V: 0x56,
    W: 0x57,
    X: 0x58,
    Y: 0x59,
    Z: 0x5A
});
const VK_HEX = new Set(Object.values(VK));

/**
 * @func stringToVirtualKeys
 * @desc Transform a string to virtual keys
 * @param {!String} str string
 * @returns {Array<Number>}
 */
function stringToVirtualKeys(str) {

}

/**
 * @func sendVirtualKeys
 * @desc Trigger one or many virtual keys
 * @param {Array<Number> | Number} vk virtual key(s)
 * @returns {void}
 */
function sendVirtualKeys(vk) {
    if (Array.isArray(vk)) {
        vk.filter((code) => VK_HEX.has(code)).forEach((code) => sendinput(code));
    }
    else if (VK_HEX.has(vk)) {
        sendinput(vk);
    }
}

module.exports = {
    sendVirtualKeys,
    stringToVirtualKeys,
    CONSTANTS: Object.freeze({ VK })
};
