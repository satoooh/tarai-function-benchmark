function tarai(x, y, z) {
  if (x <= y) {
    return y;
  } else {
    return tarai(tarai(x - 1, y, z), tarai(y - 1, z, x), tarai(z - 1, x, y));
  }
}

const n_iter = 10;
const times = [];

for (let i = 0; i < n_iter; i++) {
  const start_time = Date.now();
  tarai(13, 5, 0);
  const end_time = Date.now();
  const elapsed_time = (end_time - start_time) / 1000;
  times.push(elapsed_time);
}

const average_time = times.reduce((a, b) => a + b, 0) / n_iter;
const std_time = Math.sqrt(times
  .map((t) => Math.pow(t - average_time, 2))
  .reduce((a, b) => a + b, 0) / n_iter);

console.log(`JavaScript version: ${process.version}`);
console.log(`Average elapsed_time: ${average_time} sec`);
console.log(`Standard deviation: ${std_time} sec`);
