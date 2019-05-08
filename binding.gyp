{
    "targets": [
        {
            "target_name": "sendinput",
            "sources": [
                "sendinput.cpp"
            ],
            "include_dirs": [
                "include",
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            "dependencies": [
                "<!(node -p \"require('node-addon-api').gyp\")"
            ],
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            "msvs_settings": {
                "VCCLCompilerTool": {
                    "ExceptionHandling": 1
                }
            },
            "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
        }
    ]
}
