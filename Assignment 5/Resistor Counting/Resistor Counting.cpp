//Written By Eddy Zhou
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream resistorIn("resist1.txt");
	if (!resistorIn)
	{
		cout << "File not Found\n";
		return EXIT_FAILURE;
	}
	ofstream rout("report.txt");

	int resistNumber = 0, singularResistColour = 0, mostInventoryValue = 0, mostInventoryColour = 0;
	const int RESISTOR_VALUES = 10, ARRAY_COLUMNS = 2, RESIST_MULTIPLE = 100, RESISTOR_MINIMUM = 275;
	int resistColour[RESISTOR_VALUES][ARRAY_COLUMNS];

	for (int colourRow = 0; colourRow < RESISTOR_VALUES; colourRow++)
	{
		for (int column = 0; column < ARRAY_COLUMNS; column++)
		{
			if (column == 0)
			{
				resistColour[colourRow][column] = RESIST_MULTIPLE + RESIST_MULTIPLE * colourRow;
			}
			else
			{
				resistColour[colourRow][column] = 0;
			}
		}
	}

	while (resistorIn >> resistNumber)
	{
		for (int resistCounter = 0; resistCounter < resistNumber; resistCounter++)
		{
			resistorIn >> singularResistColour;
			for (int colourRow = 0; colourRow < RESISTOR_VALUES; colourRow++)
			{
				if (singularResistColour == resistColour[colourRow][0])
				{
					resistColour[colourRow][1]++;
					break;
				}
			}
		}
	}

	rout << "Resistor #" << setw(18) << "Order Amount\n";
	for (int colourRow = 0; colourRow < RESISTOR_VALUES; colourRow++)
	{
		for (int column = 0; column < ARRAY_COLUMNS; column++)
		{
			if (column == 0)
			{
				rout << setw(10) << resistColour[colourRow][column];
			}
			else if (resistColour[colourRow][column] < RESISTOR_MINIMUM)
			{
				rout << setw(17) << RESISTOR_MINIMUM;
			}
			else 
			{
				rout << setw(17) << resistColour[colourRow][column];
			}
		}
		rout << endl;
	}
	
	for (int colourRow = 0; colourRow < RESISTOR_VALUES; colourRow++) 
	{
		if (mostInventoryValue < resistColour[colourRow][1]) 
		{
			mostInventoryValue = resistColour[colourRow][1];
			mostInventoryColour = resistColour[colourRow][0];
		}
	}

	rout << "The highest resistor count is " << mostInventoryValue << "\nin colour value(s): " << mostInventoryColour;

	for (int colourRow = 0; colourRow < RESISTOR_VALUES; colourRow++)
	{
		if (mostInventoryValue == resistColour[colourRow][1] && mostInventoryColour != resistColour[colourRow][0])
		{
			rout << ", " << resistColour[colourRow][0];
		}
	}

	rout << ".\n";

	resistorIn.close();
	rout.close();

	return 0;
}
/*
Output:

Resistor #     Order Amount
	   100              280
	   200              310
	   300              275
	   400              275
	   500              277
	   600              275
	   700              280
	   800              275
	   900              293
	  1000              310
The highest resistor count is 310
in colour value(s): 200, 1000.

*/

