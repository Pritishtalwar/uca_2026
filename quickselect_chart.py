import matplotlib.pyplot as plt

n = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]
runtime = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

plt.figure(figsize=(8,5))
plt.plot(n, runtime, marker='o')
plt.title("Quickselect Average Runtime")
plt.xlabel("Dataset Size (n)")
plt.ylabel("Runtime (ms)")
plt.grid(True)

plt.savefig("quickselect_runtime.png")
plt.show()
