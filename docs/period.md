Algorithm Overview:
Read visiting times from an input file, where each line represents the entering and leaving times of one visitor.
Parse the input data to extract the entering and leaving times for each visitor.
Iterate through each minute between entering and leaving times of each visitor.
Keep track of the number of visitors present in the museum at each minute using a map data structure.
Update the maximum visitor count and the corresponding time period when the count increases.
Output the time period with the maximum visitor count.

Detailed Steps:
Open the input file and read each line representing the entering and leaving times of one visitor.
For each line, parse the entering and leaving times into separate Time objects.
Iterate through each minute between the entering and leaving times:
Increment the count of visitors for that minute in a map data structure.
Update the maximum visitor count and the corresponding time period if the count increases.
Output the start time, end time, and the maximum visitor count.


