data = """
File       Original Method Time (s)  Sliding Window Time (s)   Harvard Solution Time (s)  Kiang's Method Time (s)
1.txt      5.899999996472616e-05     1.950000000761065e-05     5.020000003241876e-05     2.8749998932653398e-06
2.txt      0.00010567499998614949    4.1137500090826506e-05    9.779999993497768e-05     3.87500000442742e-06
3.txt      9.308749997671839e-05     2.9687500045838533e-05    8.936250009128344e-05     4.762499941080023e-06
4.txt      7.020000003876703e-05     2.1437499924559233e-05    6.0862499935865344e-05    3.10000001491062e-06
5.txt      0.0023067750000222986     0.0008410499999627064     0.0020695000000046093     4.6362499915630906e-05
6.txt      0.0020708374999003354     0.0008812124999622029     0.0019188374998861946     3.902500003505338e-05
7.txt      0.0024239624999040643     0.0008655374999193555     0.002227324999978464      5.0600000008671486e-05
8.txt      0.002318475000095077      0.0008005124998362589     0.0020278499999903943     3.927499994915706e-05
9.txt      0.002210212499960562      0.0009722374999796557     0.001975875000027827      4.302500002495435e-05
10.txt     0.002130262499974833      0.0007743125000274631     0.0019174500000076478     4.0137499979664426e-05
11.txt     0.0024800124999728723     0.0008627749999732259     0.0022752625000634907     5.4787499948361074e-05
12.txt     0.002405962500063197      0.0008817500001327971     0.0023495875001344757     5.0475000080041355e-05
13.txt     0.0024524249998876257     0.0009003749999010324     0.002204974999983733      4.6612499943421426e-05
14.txt     0.002154550000113886      0.0007981499999232256     0.00197843749998583       4.2212500034111144e-05
15.txt     0.0021535999999287014     0.000822262499923454      0.0019278500000723398     3.941250020034204e-05
16.txt     0.0021972124999365406     0.0008761249998769927     0.0020367749999650187     3.936249993330421e-05
17.txt     0.0021912624999913533     0.0008060250000312408     0.001993575000085457      4.07125000947417e-05
18.txt     0.002622762499925102      0.0009713624999108106     0.0024417999999855056     5.553750008857605e-05
19.txt     0.0025390249999759362     0.0009575499999527892     0.0023989375000041946     4.307499989408825e-05
20.txt     0.0023363124998923013     0.0008841249998567946     0.001946012500013694      4.3500000003859896e-05 
"""

# Parse and process data
results = {}
lines = data.strip().split("\n")[1:]  # Skip the header line
for line in lines:
    parts = line.split(",")
    if "txt" in parts[0]:  # Check if the line likely contains valid data
        file = parts[0]
        times = list(map(float, parts[2:]))  # Convert time strings to floats

        if file not in results:
            results[file] = {'Original Method': [], 'Sliding Window Method': [], 'Harvard Solution': [], 'Kiang\'s Method': []}

        results[file]['Original Method'].append(times[0])
        results[file]['Sliding Window Method'].append(times[1])
        results[file]['Harvard Solution'].append(times[2])
        results[file]['Kiang\'s Method'].append(times[3])

# Calculate averages for each method per file
averages = {}
for file, methods in results.items():
    averages[file] = {}
    for method, times in methods.items():
        averages[file][method] = sum(times) / len(times)

# Function to extract numeric value for sorting filenames numerically
def file_sort_key(filename):
    return int(filename.split('.')[0])  # Assumes file names are like "1.txt"

# Print results in a formatted table
header = "File       Original Method Time (s)  Sliding Window Time (s)   Harvard Solution Time (s)  Kiang's Method Time (s)"
print(header)
for file, method_times in sorted(averages.items(), key=lambda x: file_sort_key(x[0])):
    print(f"{file:<10} {method_times['Original Method']:<25} {method_times['Sliding Window Method']:<25} {method_times['Harvard Solution']:<25} {method_times['Kiang\'s Method']:<25}")
