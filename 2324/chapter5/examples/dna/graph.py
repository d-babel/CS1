import pandas as pd
import matplotlib.pyplot as plt

# Load data from CSV
df = pd.read_csv('data.csv')

# Set 'File' as the index
df.set_index('File', inplace=True)

# Plot all methods
plt.figure(figsize=(10, 6))
for column in df.columns:
    plt.plot(df.index, df[column], marker='o', label=column)

plt.title('Method Execution Time Comparison')
plt.xlabel('File')
plt.ylabel('Execution Time (seconds)')
plt.legend()
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()
