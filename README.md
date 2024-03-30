# productmanage

(Vietnamese in requirement.txt)

Write a program to read the input file input.csv with the following content:

```
# Category, ID, Quantity, Import Date(DDMMYYYY), Description, Expired Date(DDMMYYYY),
Food, F0001, 10, 01022022, Fresh Meat, 04022022
Drink, D0003, 10, 02022022, Oolong Tea, 02022022
Food, F0003, 10, 03022022,Goat Milk, 03032022
Drink, D0001, 10, 01022022, Wine, 03022025
Utensil, U0002, 10, 05022022, Top Oven, 02072022
Food, F0002, 10, 01022022,Spinach, 10022022
Drink, D0002, 10, 09022022,Beer, 03022024
Utensil, U0001, 10, 07022022,Big Glass, 02072022
Utensil, U0003, 10, 10022022,Silver Spoon, 02072022
```

Tasks:
1. Write out files corresponding to Category, you can expand more data for testing.
    - For example, the output to the file Food.txt contains groups of goods belonging to Category Food.
2. Check whether the date is valid or not (eg: 01022022 -> OK, 32012022 -> NG)
3. Sort product items by expiration date (from near to far), then export the report in .csv format

General requirements:
1. The build program has no warnings, no cpplint check errors.
2. The program runs, runs correctly, does not crash or abort coredump.
