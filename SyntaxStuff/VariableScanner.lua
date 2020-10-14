function Get_Vars(Script)
   local Table = {}
   local IsLongVar = false
   local IsNormalVar = false
   local Variable = ''
   for I = 1, #Script do
      local Character = string.sub(Script,I,I)
      --// Characters Look for quotes
      if IsNormalVar == false and Character == [[']] then
         IsNormalVar = true
      elseif IsNormalVar == true and Character == [[']] then
         IsNormalVar = false
      elseif IsLongVar == false and  Character == [["]] then
         IsLongVar = true
      elseif  IsLongVar == true and Character == [["]] then
         IsLongVar = false
      end
      --// Get the shit nice things \\--
      if IsNormalVar == true  and Character ~= '' then
         if string.sub(Script,I+1,I+1) == [[']] then
            Variable = Variable .. Character
           Table[#Table+1] = {OriginalVar = [[']] .. Variable .. [[']]}
           Variable = ''
         elseif string.sub(Script,I+1,I+1) ~= [[']] then
            Variable = Variable .. Character
            Variable = string.gsub(Variable, [[']], '')
         end
          elseif IsLongVar == true and Character ~= '' then
          if string.sub(Script,I+1,I+1) == [["]] then
            Variable = Variable .. Character
           Table[#Table+1] = {OriginalVar = [["]] .. Variable .. [["]]}
           Variable = ''
         elseif string.sub(Script,I+1,I+1) ~= [["]] then
            Variable = Variable .. Character
            Variable = string.gsub(Variable, [["]], '')
         end
      end
     
   end
   
   return Table
end
