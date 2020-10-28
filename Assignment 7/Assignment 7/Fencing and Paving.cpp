//Written by Eddy Zhou
#define _USE_MATH_DEFINES

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

double triArea(double side1, double side2, double side3) 
{
	double area = 0, angle = 0;
	angle = acos((pow(side3, 2) - pow(side1, 2) - pow(side2, 2))/(-2 * side1 * side2));
	area = (side1 * side2 * sin(angle)) / 2;
	return area;
}

double triPerim(double side1, double side2, double side3) 
{
	double perimeter = side1 + side2 + side3;
	return perimeter;
}

double quadArea(double side1, double side2, double diagonal, double side3, double side4) 
{
	double area = 0;
	area = triArea(side1, side2, diagonal) + triArea(diagonal, side3, side4);
	return area;
}

double quadPerimeter(double side1, double side2, double side3, double side4) 
{
	double perimeter = side1 + side2 + side3 + side4;
	return perimeter;
}

double secArea(double radius, double angle) 
{
	double area = 0;
	angle = angle * (M_PI / 180);
	area = (pow(radius, 2) * angle) / 2;
	return area;
}

double secPerimeter(double radius, double angle) 
{
	double perimeter = 0;
	angle = angle * (M_PI/180);
	perimeter = (2 * radius) + (radius * angle);
	return perimeter;
}

double rawCost(double area, double fenceLength) 
{
	double rawCost = 0;
	const double PAVING_COST = 18.50, FENCE_COST = 26.00, GATE_COST = 120.00;
	rawCost = rawCost + ceil(area) * PAVING_COST;
	rawCost = rawCost + ceil(fenceLength) * FENCE_COST;
	if (fenceLength != 0) {
		rawCost = rawCost + GATE_COST;
	}
	return rawCost;
}



int main() 
{
	std::ifstream jobsIN("jobs.txt");
	if (!jobsIN) 
	{
		std::cout << "File not found.\n";
		return EXIT_FAILURE;
	}
	std::ofstream jout("report.txt");

	const int TEXT_WIDTH[6] = { 20, 12, 18, 13, 10, 14 }, NO_AREA = 0, NO_FENCE = 0;
	const double TAX = 0.13, ADMIN_COST = 35.00;
	int jobNum = 0;
	bool fenced = false;
	double side1 = 0, side2 = 0, side3 = 0, side4 = 0, diagonal = 0, radius = 0, angle = 0, area = 0,
		fenceLength = 0;
	std::string shape;

	jout << "Job#" << std::setw(TEXT_WIDTH[0]) << "Actual_Paved_Area" << std::setw(TEXT_WIDTH[1]) 
		<< "Pave_Cost" << std::setw(TEXT_WIDTH[2]) << "Actual_F_Length" << std::setw(TEXT_WIDTH[3]) 
		<< "Fence_Cost" << std::setw(TEXT_WIDTH[4]) << "Taxes" 
		<< std::setw(/*slight adjustment*/TEXT_WIDTH[5] + 1) 
		<< "Total_Cost\n";

	while (jobsIN >> jobNum) 
	{
		//input fenced? and shape
		jobsIN >> fenced >> shape;

		//Area and Perim
		if (shape == "tri") 
		{
			jobsIN >> side1 >> side2 >> side3;
			area = triArea(side1, side2, side3);
			fenceLength = triPerim(side1, side2, side3);
		}
		if (shape == "quad") 
		{
			jobsIN >> side1 >> side2 >> diagonal >> side3 >> side4;
			area = quadArea(side1, side2, diagonal, side3, side4);
			fenceLength = quadPerimeter(side1, side2, side3, side4);
		}
		if (shape == "sect") 
		{
			jobsIN >> radius >> angle;
			area = secArea(radius, angle);
			fenceLength = secPerimeter(radius, angle);
		}

		//fenced?
		if (fenced == false) 
		{
			fenceLength = 0;
		}

		//Job #
		jout << jobNum << std::setw(TEXT_WIDTH[0]) << std::fixed;
		//Actual Paved Area
		jout << std::setprecision(2) << area << std::setw(TEXT_WIDTH[1]);
		//Pave Cost
		jout << rawCost(area, NO_FENCE) << std::setw(TEXT_WIDTH[2]);
		//Actual Fence Length
		jout << fenceLength << std::setw(TEXT_WIDTH[3]);
		//Fence Cost
		jout << rawCost(NO_AREA, fenceLength) << std::setw(TEXT_WIDTH[4]);
		//Taxes
		jout << (rawCost(area, fenceLength) + ADMIN_COST) * TAX << std::setw(TEXT_WIDTH[5]);
		//Total Cost
		jout << (rawCost(area, fenceLength) + ADMIN_COST) * (1 + TAX) << std::endl;
	}

	jobsIN.close();
	jout.close();
}

/*
OUTPUT: ("report.txt") //Note: Output might be too wide to fit on PDF
Job#   Actual_Paved_Area   Pave_Cost   Actual_F_Length   Fence_Cost     Taxes    Total_Cost
7100              600.00    11100.00            120.00      3240.00   1868.75      16243.75
7102                2.36       55.50              0.00         0.00     11.77        102.26
7104              157.08     2923.00             51.42      1472.00    575.90       5005.90
7105               70.16     1313.50              0.00         0.00    175.31       1523.80
7107              197.04     3663.00              0.00         0.00    480.74       4178.74
7108             2400.00    44400.00              0.00         0.00   5776.55      50211.55
7109               89.92     1665.00             38.21      1134.00    368.42       3202.42
7110                8.39      166.50              0.00         0.00     26.20        227.69
7111                3.90       74.00              9.00       354.00     60.19        523.19
7112               33.54      629.00             23.60       744.00    183.04       1591.04
*/