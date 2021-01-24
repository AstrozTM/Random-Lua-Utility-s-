## Random Lua Utilitys

# Must Read
## This is made open sourced and free to be used by anyone.
## Please try to give me credits I would appriciate it.

# Variable Scanner
This can be used as shown bellow.
```lua
local Code = [[
local A = 'Hello'
print(A)
]]

local T = Get_Vars(Code)
local BuiltScript = Code
for I,v in pairs(T) do
   local new = string.gsub(BuiltScript, T[I].OriginalVar, [['e']])
   BuiltScript = new
end
```

# Obfuscation Parser
This can be used as bellow.
```js
const Parser = require("./Parser.js");
const fs = require('fs')

// Code \\
let Code = fs.readFileSync("./PSU.lua", { encoding: "utf-8" }).toString() // Using PSU for an example (premium version is not possible to do this with good obfuscator tho discord.gg/psu

let Args = Parser.Parse(Code)
let ConstructedVariable = Args[0]
let DetectedObfuscator = Args[1]
let Version = Parser.Version

console.log(`${ConstructedVariable} is the vulnerability, and the obfuscator detected is ${DetectedObfuscator}. Obtained this info with ObfuscationParser ${Version}`)
```
