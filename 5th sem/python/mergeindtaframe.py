import pandas as pd

# Create two sample DataFrames
df1 = pd.DataFrame({
    'key': ['K0', 'K0', 'K1', 'K2'],
    'A': ['A0', 'A1', 'A2', 'A3'],
    'B': ['B0', 'B1', 'B2', 'B3']
})

df2 = pd.DataFrame({
    'key': ['K0', 'K1', 'K1', 'K2'],
    'C': ['C0', 'C1', 'C2', 'C3'],
    'D': ['D0', 'D1', 'D2', 'D3']
})

# Perform an inner merge on the 'key' column
df_merged = pd.merge(df1, df2, on='key',how='inner')

print(df_merged)