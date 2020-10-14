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
   local new = string.gsub(BuiltScript, T[I].OriginalVar, 'e')
   BuiltScript = new
end
```
