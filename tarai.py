import time
import sys
import numpy as np


def tarai(x: int, y: int, z: int) -> int:
    if x <= y:
        return y
    else:
        return tarai(tarai(x - 1, y, z),
                     tarai(y - 1, z, x),
                     tarai(z - 1, x, y))


n_iter = 10
times = []
for _ in range(n_iter):
    start_time = time.time()
    tarai(13, 5, 0)
    end_time = time.time()
    elapsed_time = end_time - start_time
    times.append(elapsed_time)

average_time = np.mean(times)
std_time = np.std(times)

print(f"Python version: {sys.version_info}")
print(f"Average elapsed_time: {average_time} sec")
print(f"Standard deviation: {std_time} sec")
