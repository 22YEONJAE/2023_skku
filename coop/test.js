const decimalArray = [255, 255, 8, 65, 2, 204, 0, 0, 0, 0, 235];
//const decimalArray = [255, 255, 6, 4, 0, 49, 0, 0, 199, 13, 10];
decimalToBinaryArray(decimalArray);

function padZeros(binaryStr, length) {
  const diff = length - binaryStr.length;
  if (diff <= 0) return binaryStr;
  return "0".repeat(diff) + binaryStr;
}

function decimalToBinaryArray(decimalArray) {
  const binaryArray = decimalArray.map((decimal) =>
    padZeros(decimal.toString(2), 8)
  );

  console.log(binaryArray);

  const startIndex_left = 54;
  const startIndex_right = 70;
  const numBits = 10;

  const selectedBinaryStr_left = binaryArray
    .join("")
    .substr(startIndex_left, numBits);
  const decimalValue_left = binaryToDecimal(selectedBinaryStr_left);

  const selectedBinaryStr_right = binaryArray
    .join("")
    .substr(startIndex_right, numBits);
  const decimalValue_right = binaryToDecimal(selectedBinaryStr_right);

  console.log(decimalValue_left);
  console.log(decimalValue_right);
}

function binaryToDecimal(binaryStr) {
  return parseInt(binaryStr, 2);
}
