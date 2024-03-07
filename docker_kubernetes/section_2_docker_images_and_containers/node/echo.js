const delay = (ms) => {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
};

for (let i = 1; i <= 30; i++) {
    delay(i * 1000).then(() => {
        console.log(`Delayed message from: ${i}`);
    });
}

console.log('hello world from section 2!')