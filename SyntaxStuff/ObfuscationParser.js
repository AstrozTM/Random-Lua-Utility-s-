// Parser made by Astroz \\
const Version = "v0.0.2";

// Function to understand  \\
function PSU_Parsing(Code) {
  // Finding the index of the 5th break \\
  let FirstIndex = Code.indexOf("break;");
  FirstIndex = Code.indexOf("break;", FirstIndex + 1);
  FirstIndex = Code.indexOf("break;", FirstIndex + 1);
  FirstIndex = Code.indexOf("break;", FirstIndex + 1);
  FirstIndex = Code.indexOf("break;", FirstIndex + 1);
  // Parsing till we find where the variable contaning eq hook vul \\
  let FoundIndex;
  for (let i = 1; i < 100; i++) {
    if (Code[FirstIndex - i] == "=" && Code[FirstIndex - (i - 1)] != "d") {

      FoundIndex = FirstIndex - i;
      break;
    }
  }
  // Checking if index is valid \\
  let VersionRegex = /This file was obfuscated using PSU Obfuscator (.*?) \|/
  let Version = '???'
  if(Code.match(VersionRegex)){
    Version = Code.match(VersionRegex)[1]
  }
  if (FoundIndex != NaN || FoundIndex != undefined || FoundIndex != -1) {
    // Returning the constructed variable \\
    let regex = /= (.*?)\;/;
    let Formated = Code.replace(Code.substring(1, FoundIndex - 1), "");
    return [Formated.match(regex)[1], `${Version}`]
  } else {
    return ["Invalid", '???']
  }
}

function Detect(Input) {
      return PSU_Parsing(Input)
}

exports.version = Version;
exports.Parse = Detect;
