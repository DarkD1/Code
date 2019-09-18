// Frequency Count Method

function validAnagram(a, b) {
    if (a.length != b.length) return false;
    if (a == b) return true;
    let frequencyOfA = {},
        frequencyOfB = {};
    for (let val of a) {
        frequencyOfA[val] = (frequencyOfA[val] || 0) + 1;
    }
    for (let val of b) {
        frequencyOfB[val] = (frequencyOfB[val] || 0) + 1;
    }

    for (let key of a) {
        if (frequencyOfA[key] != frequencyOfB[key]) return false;
    }

    return true;
}

console.log(validAnagram("iceman", "cinema"));
console.log(validAnagram("iceman", "cineme"));